
--------------------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity UDP_analyze is
    port 
    (
        ------------------------------------------------------------------------
        --reset and clock
        ------------------------------------------------------------------------
        CpSl_Clk125M_i                  : in  std_logic;
        CpSl_Rst_iN                     : in  std_logic;
        
        ------------------------------------------------------------------------
        -- GMII RX interface
        ------------------------------------------------------------------------
        CpSl_EthernetRxEr_i             : in  std_logic;                        -- Ethernet data errer point
        CpSl_EthernetRxDv_i             : in  std_logic;                        -- Ethernet data valid
        --CpSl_Clk125M_i          : in  std_logic;                      -- Ethernet clk, use sys clock 125M
        CpSv_EthernetRxDate_i           : in  std_logic_vector( 7 downto 0);    -- Ethernet rx data
        
        ------------------------------------------------------------------------
        -- Serial data send out interface;
        ------------------------------------------------------------------------
        CpSl_UDPdataValid_o         : out std_logic;
        CpSv_UDPdata_o              : out std_logic_vector(7 downto 0)     -- UDP port address output
       );
end UDP_analyze;

architecture rtl of UDP_analyze is
    ----------------------------------------------------------------------------
    -- constant declaration
    ----------------------------------------------------------------------------
    --constant PrSv_DataForMatchBegin_c   : std_logic_vector(31 downto 0) := "00010010011001011001101011101101"; -- 1265 9AED
    
    ----------------------------------------------------------------------------
    -- signal declaration
    ----------------------------------------------------------------------------
    Type GMIIState is (Idle, FindMacHead, GetMacHead, GetIPHead, GetUDPHead, GetTCPHead, GetUDPDate);
    -- Ethernet GMII
    signal PrSl_EthernetRxErDly1_s      : std_logic;                            -- latch CpSl_EthernetRxEr_i 
    signal PrSl_EthernetRxErDly2_s      : std_logic;                            -- latch CpSl_EthernetRxEr_i 
    signal PrSl_EthernetRxDvDly1_s      : std_logic;                            -- latch CpSl_EthernetRxDv_i 
    signal PrSv_EthernetRxDateDly1_s    : std_logic_vector( 7 downto 0);        -- latch CpSv_EthernetRxDate_i
    signal PrSv_EthernetRxDateDly2_s    : std_logic_vector( 7 downto 0);        -- latch CpSv_EthernetRxDate_i
    signal PrSv_EthernetRxDateDly3_s    : std_logic_vector( 7 downto 0);        -- latch CpSv_EthernetRxDate_i
    
    signal PrSv_UDPTCPFlag_s            : std_logic_vector( 7 downto 0);        -- stand for UDP or TCP 
    
    --signal PrSl_RcvEthernetDataEn_s     : std_logic;                            -- receive Ethernet rx Data enable.
    signal PrSv_CntFindMacHead_s        : std_logic_vector( 3 downto 0);        -- count Mac precursor
    signal PrSv_CntMacHead_s            : std_logic_vector( 7 downto 0);        -- count Mac head
    signal PrSv_CntIPHead_s             : std_logic_vector( 7 downto 0);        -- count IP head
    signal PrSv_CntUDPHead_s            : std_logic_vector( 7 downto 0);        -- count UDP head
    signal PrSv_CntTCPHead_s            : std_logic_vector( 7 downto 0);        -- count TCP head
    signal PrSv_CntUDPData_s            : std_logic_vector( 7 downto 0);        -- count UDP Data
   
    
	signal PrSv_GMIIState_s             : GMIIState;
    
--    signal PrSv_MacType_s               : std_logic_vector(15 downto 0);        -- Mac Type, 0x0800--> IP
--    signal PrSv_IPType_s                : std_logic_vector( 7 downto 0);        -- IP Type, 17--> UDP
    signal PrSv_IPHeadLength_s          : std_logic_vector( 7 downto 0);        -- Ip head length
    signal PrSv_UDPLength_s             : std_logic_vector( 15 downto 0);        -- UDP total length(include head)
    
	signal PrSv_UDPdata_s               : std_logic_vector(7 downto 0) := X"00";        -- UDP port
    signal PrSl_UDPdataValid_s          : std_logic;                            -- UDP Port valid
	
	
begin
    ----------------------------------------------------------------------------
    --
    ----------------------------------------------------------------------------
    -- Latch PrSl_EthernetRxDv_s
    process (CpSl_Clk125M_i) 
    begin
        if rising_edge(CpSl_Clk125M_i) then
            PrSl_EthernetRxErDly1_s     <= CpSl_EthernetRxEr_i;  
            PrSl_EthernetRxDvDly1_s     <= CpSl_EthernetRxDv_i; 
            PrSv_EthernetRxDateDly1_s   <= CpSv_EthernetRxDate_i;      
            
            PrSl_EthernetRxErDly2_s     <= PrSl_EthernetRxErDly1_s;
            PrSv_EthernetRxDateDly2_s   <= PrSv_EthernetRxDateDly1_s;
            PrSv_EthernetRxDateDly3_s   <= PrSv_EthernetRxDateDly2_s;
            
			CpSv_UDPdata_o <= PrSv_UDPdata_s;
			CpSl_UDPdataValid_o <= PrSl_UDPdataValid_s;
        end if;
    end process;
    
    -- PrSv_GMIIState_s (Idle, FindMacHead, GetMacHead, GetIPHead, GetUDPHead, GetUDPDate)
    process (CpSl_Clk125M_i, CpSl_Rst_iN) begin
        if CpSl_Rst_iN = '0' then
            PrSv_GMIIState_s <= Idle;
        elsif rising_edge(CpSl_Clk125M_i) then
            -- rising edge of CpSl_EthernetRxDv_i
            if CpSl_EthernetRxDv_i = '1' and PrSl_EthernetRxDvDly1_s = '0' then
                PrSv_GMIIState_s <= FindMacHead;
            else
                if PrSl_EthernetRxErDly2_s = '0' then
                    case PrSv_GMIIState_s is
                        when Idle =>
                            -- rising edge of CpSl_EthernetRxDv_i
                            if CpSl_EthernetRxDv_i = '1' and PrSl_EthernetRxDvDly1_s = '0' then
                                PrSv_GMIIState_s <= FindMacHead;
                            else -- hold
                            end if;
                        when FindMacHead =>
                            if PrSv_CntFindMacHead_s = 10 then
                                PrSv_GMIIState_s <= Idle;
                            else
                                if PrSv_EthernetRxDateDly1_s = X"D5" then
                                    PrSv_GMIIState_s <= GetMacHead;
                                elsif PrSv_EthernetRxDateDly1_s = X"55" then
                                    null;
                                else
                                    PrSv_GMIIState_s <= Idle;
                                end if;
                            end if;
                        when GetMacHead =>
                            if PrSv_CntMacHead_s = 13 then  -- get Mac type  X"0800" -> IP
                                if PrSv_EthernetRxDateDly2_s & PrSv_EthernetRxDateDly1_s = X"0800" then
                                    PrSv_GMIIState_s <= GetIPHead;
                                else
                                    PrSv_GMIIState_s <= Idle;
                                end if;
                            else --hold
                            end if;
                        when GetIPHead =>
                            if PrSv_CntIPHead_s <= 8 then
                                null;
                            elsif PrSv_CntIPHead_s = 9 then -- get Ip type 17 -> UDP 
                                PrSv_UDPTCPFlag_s <= PrSv_EthernetRxDateDly1_s;
--                                if PrSv_EthernetRxDateDly1_s = 17 or PrSv_EthernetRxDateDly1_s = 6 then
--                                    null;
--                                else
--                                    PrSv_GMIIState_s <= Idle;
--                                end if;
                            elsif PrSv_CntIPHead_s = PrSv_IPHeadLength_s then
                                if PrSv_UDPTCPFlag_s = 17 then
                                    PrSv_GMIIState_s <= GetUDPHead;
                                elsif PrSv_UDPTCPFlag_s = 6 then
                                    PrSv_GMIIState_s <= GetTCPHead;
                                else
                                    PrSv_GMIIState_s <= Idle;
                                end if;
--                                PrSv_GMIIState_s <= GetUDPHead;
                            end if;
                        when GetUDPHead =>
                            if PrSv_CntUDPHead_s = 8 then
                                PrSv_GMIIState_s <= GetUDPDate;
                            else -- hold
                            end if;
                        when GetTCPHead =>
                            if PrSv_CntTCPHead_s = 193 then
                                PrSv_GMIIState_s <= Idle;
                            else -- hold
                            end if;
						
						when GetUDPDate =>
                            if PrSv_CntUDPData_s = (PrSv_UDPLength_s -8)then
                                PrSv_GMIIState_s <= Idle;
                            else -- hold
                            end if;	
							
                        when others =>
                            PrSv_GMIIState_s <= Idle;
                    end case;
                else
                    PrSv_GMIIState_s <= Idle; -- if RxEr = 1 , then return to idle
                end if;
            end if;
        end if;
    end process;

    -- PrSv_IPHeadLength_s -- the header length meaning how many(4 bytes as a unit) data there are in ip header
    process (CpSl_Clk125M_i, CpSl_Rst_iN) begin
        if CpSl_Rst_iN = '0' then
            PrSv_IPHeadLength_s <= (others => '0');
        elsif rising_edge(CpSl_Clk125M_i) then
            if PrSv_GMIIState_s = GetIPHead then
                if PrSv_CntIPHead_s = 0 then -- the first byte is (vertion & header length)
                    PrSv_IPHeadLength_s <= ("00" & PrSv_EthernetRxDateDly1_s(3 downto 0) & "00") - 1; -- when header length is 5,it means there are 20 bytes ip header
                else -- hold
                end if;
            else --hold
            end if;
        end if;
    end process;
    
    -- PrSv_UDPLength_s  
    process (CpSl_Clk125M_i, CpSl_Rst_iN) begin
        if CpSl_Rst_iN = '0' then
            PrSv_UDPLength_s <= (others => '0');
        elsif rising_edge(CpSl_Clk125M_i) then
            if PrSv_GMIIState_s = GetUDPHead then
                if PrSv_CntUDPHead_s = 5 then -- after cntUDPheader is 5,there will be the UDP  Length  
                    PrSv_UDPLength_s <= PrSv_EthernetRxDateDly2_s & PrSv_EthernetRxDateDly1_s;
                else -- hold
                end if;
            else --hold
            end if;
        end if;
    end process;
    
	-- PrSv_UDPdata_s  
    process (CpSl_Clk125M_i, CpSl_Rst_iN) begin
        if CpSl_Rst_iN = '0' then
            PrSv_UDPdata_s <= (others => '0');
        elsif rising_edge(CpSl_Clk125M_i) then
            if PrSv_GMIIState_s = GetUDPDate then
                if PrSv_CntUDPData_s = 10 then -- after CntUDPData_s is 10,there will be the UDP data (because there are 128byte data)  
                    PrSv_UDPdata_s <= PrSv_EthernetRxDateDly1_s;
                else -- hold
                end if;
            else --hold
            end if;
        end if;
    end process;   
    
    -- PrSl_UDPDataValid_s
    process (CpSl_Clk125M_i, CpSl_Rst_iN) begin
        if CpSl_Rst_iN = '0' then
            PrSl_UDPdataValid_s <= '1';
        elsif rising_edge(CpSl_Clk125M_i) then
            if PrSv_GMIIState_s = GetUDPDate then
                if PrSv_CntUDPData_s = 10 then -- after CntUDPData_s is 10,there will be the UDP data (because there are 128byte data)
                    PrSl_UDPdataValid_s <= '1';
                else -- hold
                end if;
            else
                PrSl_UDPdataValid_s <= '1';
            end if;
        end if;
    end process;
    
    
    ----------------------------------------------------------------------------
    -- counter
    ----------------------------------------------------------------------------
    -- PrSv_CntFindMacHead_s
    process (CpSl_Clk125M_i, CpSl_Rst_iN) begin
        if CpSl_Rst_iN = '0' then
            PrSv_CntFindMacHead_s <= (others => '0');
        elsif rising_edge(CpSl_Clk125M_i) then
            if PrSv_GMIIState_s = FindMacHead then
                PrSv_CntFindMacHead_s <= PrSv_CntFindMacHead_s + 1;
            else
                PrSv_CntFindMacHead_s <= (others => '0');
            end if;
        end if;
    end process;

    -- PrSv_CntMacHead_s
    process (CpSl_Clk125M_i, CpSl_Rst_iN) begin
        if CpSl_Rst_iN = '0' then
            PrSv_CntMacHead_s <= (others => '0');
        elsif rising_edge(CpSl_Clk125M_i) then
            if PrSv_GMIIState_s = GetMacHead then
                PrSv_CntMacHead_s <= PrSv_CntMacHead_s + 1;
            else
                PrSv_CntMacHead_s <= (others => '0');
            end if;
        end if;
    end process;
    
    -- PrSv_CntIPHead_s
    process (CpSl_Clk125M_i, CpSl_Rst_iN) begin
        if CpSl_Rst_iN = '0' then
            PrSv_CntIPHead_s <= (others => '0');
        elsif rising_edge(CpSl_Clk125M_i) then
            if PrSv_GMIIState_s = GetIPHead then
                PrSv_CntIPHead_s <= PrSv_CntIPHead_s + 1;
            else
                PrSv_CntIPHead_s <= (others => '0');
            end if;
        end if;
    end process;
    
    -- PrSv_CntUDPHead_s
    process (CpSl_Clk125M_i, CpSl_Rst_iN) begin
        if CpSl_Rst_iN = '0' then
            PrSv_CntUDPHead_s <= (others => '0');
        elsif rising_edge(CpSl_Clk125M_i) then
            if PrSv_GMIIState_s = GetUDPHead then
                PrSv_CntUDPHead_s <= PrSv_CntUDPHead_s + 1;
            else
                PrSv_CntUDPHead_s <= (others => '0');
            end if;
        end if;
    end process;
    
    -- PrSv_CntTCPHead_s
    process (CpSl_Clk125M_i, CpSl_Rst_iN) begin
        if CpSl_Rst_iN = '0' then
            PrSv_CntTCPHead_s <= (others => '0');
        elsif rising_edge(CpSl_Clk125M_i) then
            if PrSv_GMIIState_s = GetTCPHead then
                PrSv_CntTCPHead_s <= PrSv_CntTCPHead_s + 1;
            else
                PrSv_CntTCPHead_s <= (others => '0');
            end if;
        end if;
    end process;
	
	-- PrSv_CntUDPData_s
    process (CpSl_Clk125M_i, CpSl_Rst_iN) begin
        if CpSl_Rst_iN = '0' then
            PrSv_CntUDPData_s <= (others => '0');
        elsif rising_edge(CpSl_Clk125M_i) then
            if PrSv_GMIIState_s = GetUDPDate then
                PrSv_CntUDPData_s <= PrSv_CntUDPData_s + 1;
            else
                PrSv_CntUDPData_s <= (others => '0');
            end if;
        end if;
    end process;
    
    
end rtl;
