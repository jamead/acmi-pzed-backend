
library ieee;
use ieee.std_logic_1164.all;
--use ieee.std_logic_arith.all;
--use ieee.std_logic_unsigned.all;
use ieee.numeric_std.all;
  

library xil_defaultlib;
use xil_defaultlib.acmi_package.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;


library UNISIM;
use UNISIM.VComponents.all;

entity gth_artix_io is
  port (
  sys_clk          : in std_logic;
  sys_rst          : in std_logic;
  gth_reset        : in std_logic;
  
  reg_o            : in t_reg_o_chaina; 
  reg_i            : out t_reg_i_chaina;
  
  evr_usr_trig     : in std_logic;
  
  gth_txusr_clk    : out std_logic;
  gth_rxusr_clk    : out std_logic;
  
  gth_refclk_p     : in std_logic;
  gth_refclk_n     : in std_logic;

  gth_rx_p         : in std_logic;
  gth_rx_n         : in std_logic;
  gth_tx_p         : out std_logic;
  gth_tx_n         : out std_logic 

);  
 

end gth_artix_io;

architecture behv of gth_artix_io is

  signal gth_tx_data         : std_logic_vector(31 downto 0);
  signal gth_tx_data_enb     : std_logic;
 
  signal gth_rx_data         : std_logic_vector(31 downto 0);
  signal gth_rx_data_enb     : std_logic;
  
  signal gth_freerun_clk     : std_logic;
  signal gth_clk_plllocked   : std_logic;
  



begin


--generate 25MHz clock for GTH FE transceivers
gth_clk_gen : entity work.gth_freerun_clk
  port map ( 
   clk_in1 => sys_clk,
   clk_out1 => gth_freerun_clk,            
   reset => sys_rst,
   locked => gth_clk_plllocked
 );



--SPI link to Artix Front End
to_artix: entity work.artix_cntrl
  port map(
    sys_clk => sys_clk, 
    gth_txusr_clk => gth_txusr_clk, 
    reset => sys_rst, 
    evr_usr_trig => evr_usr_trig,
    addr => reg_o.spi_addr, 
    data => reg_o.spi_data,  
    we => reg_o.spi_we,  
    gth_tx_data => gth_tx_data, 
    gth_tx_data_enb => gth_tx_data_enb 
   );



-- readback from Artix
from_artix: entity work.artix_data_rdout
  port map (
    sys_clk => sys_clk,
    gth_rxusr_clk => gth_rxusr_clk,
    gth_rx_data => gth_rx_data,
    gth_rx_data_enb => gth_rx_data_enb,
    fifo_rst => reg_o.fifo_rst,
    fifo_rdstr => reg_o.fifo_rdstr,
    fifo_dout => reg_i.fifo_dout,
    fifo_rdcnt => reg_i.fifo_rdcnt
 );




artix_link: entity work.gth_artix_wrapper
  port map (
    sys_clk => sys_clk, 
    gth_freerun_clk => gth_freerun_clk, 
  
    sys_rst => sys_rst, 
    gth_reset => gth_reset,  
    
    gth_txusr_clk => gth_txusr_clk,   
    gth_tx_data  => gth_tx_data,  
    gth_tx_data_enb => gth_tx_data_enb, 
  
    gth_rxusr_clk => gth_rxusr_clk,   
    gth_rx_data  => gth_rx_data,  
    gth_rx_data_enb => gth_rx_data_enb,   
  
    gth_refclk_p => gth_refclk_p, 
    gth_refclk_n => gth_refclk_n, 

    gth_rx_p => gth_rx_p, 
    gth_rx_n => gth_rx_n, 
    gth_tx_p => gth_tx_p, 
    gth_tx_n => gth_tx_n 

);  













end behv;
