--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   17:22:58 02/25/2019
-- Design Name:   
-- Module Name:   D:/Xilinx/workspace/LED_stream/LED_stream/LED_stream_test.vhd
-- Project Name:  LED_stream
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: LED
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY LED_stream_test IS
END LED_stream_test;
 
ARCHITECTURE behavior OF LED_stream_test IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT LED
    PORT(
         led0 : OUT  std_logic;
         led1 : OUT  std_logic;
         led2 : OUT  std_logic;
         led3 : OUT  std_logic;
         led4 : OUT  std_logic;
         led5 : OUT  std_logic;
         led6 : OUT  std_logic;
         led7 : OUT  std_logic;
         clk : IN  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal clk : std_logic := '0';

 	--Outputs
   signal led0 : std_logic;
   signal led1 : std_logic;
   signal led2 : std_logic;
   signal led3 : std_logic;
   signal led4 : std_logic;
   signal led5 : std_logic;
   signal led6 : std_logic;
   signal led7 : std_logic;

   -- Clock period definitions
   constant clk_period : time := 10 ns;
   signal BLED : std_logic_vector (0 to 7);   -- 控制灯的整体变量
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: LED PORT MAP (
          led0 => led0,
          led1 => led1,
          led2 => led2,
          led3 => led3,
          led4 => led4,
          led5 => led5,
          led6 => led6, 
          led7 => led7,
          clk => clk
        );

   -- Clock process definitions
   clk_process :process
   begin
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process(clk)
   variable count :bit_vector(7 downto 0):="00000001";
   begin		
      -- hold reset state for 100 ns.

		if(clk'event and clk = '1')then
				if count = "10000000" then
					count:="00000001";
				else 
					BLED <= To_StdLogicVector(count);
					count := count SLL 1;
					led0 <= BLED(0);
					led1 <= BLED(1);
					led2 <= BLED(2);
					led3 <= BLED(3);
					led4 <= BLED(4); 
					led5 <= BLED(5);
					led6 <= BLED(6);
					led7 <= BLED(7);
				end if ;
		end if ;	
			
   end process;

END;
