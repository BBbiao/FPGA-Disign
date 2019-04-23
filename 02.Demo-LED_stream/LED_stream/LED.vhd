----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:48:22 02/25/2019 
-- Design Name: 
-- Module Name:    LED - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
--use ieee.std_logic_arith.all;

--use ieee.numeric_std.all;
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity LED is
    Port ( led0 : out  STD_LOGIC;
           led1 : out  STD_LOGIC;
           led2 : out  STD_LOGIC;
           led3 : out  STD_LOGIC;
           led4 : out  STD_LOGIC;
           led5 : out  STD_LOGIC;
           led6 : out  STD_LOGIC;
           led7 : out  STD_LOGIC;
           clk : in  STD_LOGIC);
end LED;

architecture Behavioral of LED is
	signal clk1: std_logic;					  -- 时钟分频
	signal LED : std_logic_vector (0 to 7);   -- 控制灯的整体变量 
	
begin
	
	process (clk)                             -- 66MHz时钟分频 成2Hz
		variable cnt: integer range 0 to 33000000 :=0;
	begin 
		if(clk'event and clk='1')then 
			if cnt=32999999 then 
				cnt:=0;
				else 
				cnt:=cnt+1;
			end if;
			if cnt<=16499999 then 
				clk1<='1';
				else 
				clk1<='0';
			end if ;
		end if;
	end process;
	
	process (clk1)											  --使用移位操作符SLL移位，但只能
		variable count :bit_vector(8 downto 0):="000000001";  --bit_vector类型才可以使用移位操作符
		begin
			if(clk1'event and clk1 = '1')then
				if count = "100000000" then
					count:="000000001";
				else 
					LED <= To_StdLogicVector(count(7 downto 0));
					count := count SLL 1;
				end if ;
			end if ;	
			led0 <= LED(0);
			led1 <= LED(1);
			led2 <= LED(2);
			led3 <= LED(3);
			led4 <= LED(4);
			led5 <= LED(5);
			led6 <= LED(6);
			led7 <= LED(7);
	end process;
end Behavioral;

