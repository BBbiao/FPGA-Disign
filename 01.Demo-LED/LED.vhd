----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:53:32 12/13/2018 
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity LED is
	port(
		KEY0,KEY1,KEY2,KEY3,KEY4,KEY5,KEY6,KEY7  :  in std_logic;
		LED0,LED1,LED2,LED3,LED4,LED5,LED6,LED7  :  out std_logic
		);
end LED;

architecture Behavioral of LED is

begin
	LED0 <= not KEY0;
	LED1 <= not KEY1;
	LED2 <= not KEY2;
	LED3 <= not KEY3;
	LED4 <= not KEY4;
	LED5 <= not KEY5;
	LED6 <= not KEY6;
	LED7 <= not KEY7;

end Behavioral;

