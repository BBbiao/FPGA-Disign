----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    16:37:19 02/25/2019 
-- Design Name: 
-- Module Name:    bit2std_logic - Behavioral 
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

function  bit_to_std_logic(constant bit_in : bit) return std_logic is
  
  variable temp_bit : bit;
  variable temp_result : std_logic;

begin
  
  temp_bit := bit_in;
  if temp_bit = '1' then
     temp_result := '1';
  else
     temp_result := '0';
  end if;

  return(temp_result);

end bit_to_std_logic;

begin

   std_logic_vector_signal(0) <= bit_to_std_logic(bit_in);

end;

