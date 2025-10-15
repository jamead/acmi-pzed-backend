----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 06/14/2021 05:02:14 PM
-- Design Name: 
-- Module Name: adcdata_fifo - behv
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.std_logic_unsigned.all;

library work;
use work.acmi_package.ALL;

entity artix_data_rdout is
  port (
    sys_clk         : in std_logic; 
    reg_o           : in t_reg_o_wvfm;
    reg_i           : out t_reg_i_wvfm;
    wvfm_clk        : in std_logic; 
    wvfm_data       : in std_logic_vector(15 downto 0);
    wvfm_enb        : in std_logic; 
    wvfm_sel        : in std_logic
 );
end artix_data_rdout;

architecture behv of artix_data_rdout is


component wvfm_fifo
  port (
    rst : IN STD_LOGIC;
    wr_clk : IN STD_LOGIC;
    rd_clk : IN STD_LOGIC;
    din : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
    wr_en : IN STD_LOGIC;
    rd_en : IN STD_LOGIC;
    dout : OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
    full : OUT STD_LOGIC;
    empty : OUT STD_LOGIC;
    rd_data_count : OUT STD_LOGIC_VECTOR(14 DOWNTO 0)
  );
end component; 


  type state_type is (IDLE, FIFO_WRITE_HDR, FIFO_WRITE_DATA);                    
  signal   state   : state_type   := idle;

  signal fifo_rdstr_prev  : std_logic  := '0';
  signal fifo_rdstr_fe    : std_logic  := '0';
  signal fifo_din         : std_logic_vector(15 downto 0) := 16d"0";
  signal fifo_wren        : std_logic := '0';  
  signal fifo_rdcnt       : std_logic_vector(14 downto 0);

  



  attribute mark_debug                 : string;

  attribute mark_debug of fifo_wren: signal is "true";
  attribute mark_debug of fifo_din: signal is "true";
  attribute mark_debug of fifo_rdstr_fe: signal is "true";
  attribute mark_debug of wvfm_data: signal is "true";
  attribute mark_debug of wvfm_enb: signal is "true";
  attribute mark_debug of wvfm_sel: signal is "true";
  attribute mark_debug of reg_o: signal is "true";
  attribute mark_debug of reg_i: signal is "true";


begin


reg_i.fifo_rdcnt <= '0' & fifo_rdcnt;

--since fifo is fall-through mode, want the rdstr
--to happen after the current word is read.
process (sys_clk)
  begin
    if (rising_edge(sys_clk)) then
      fifo_rdstr_prev <= reg_o.fifo_rdstr;
      if (reg_o.fifo_rdstr = '0' and fifo_rdstr_prev = '1') then
        fifo_rdstr_fe <= '1'; --falling edge
      else
        fifo_rdstr_fe <= '0';
      end if;
    end if;
end process;
        

--register input waveform data
process(wvfm_clk)
  begin
    if (rising_edge(wvfm_clk)) then
      fifo_wren <= wvfm_enb;
      fifo_din <= wvfm_data;
    end if;
end process;



fifo_inst : wvfm_fifo
  PORT MAP (
    rst => reg_o.fifo_rst,
    wr_clk => wvfm_clk,
    rd_clk => sys_clk,
    din => fifo_din,
    wr_en => fifo_wren,
    rd_en => reg_o.fifo_rdstr, --fifo_rdstr_fe,
    dout => reg_i.fifo_dout,
    full => open,
    empty => open,
    rd_data_count => fifo_rdcnt
  );



end behv;
