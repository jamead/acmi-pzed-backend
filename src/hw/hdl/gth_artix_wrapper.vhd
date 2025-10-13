
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
  


-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;


library UNISIM;
use UNISIM.VComponents.all;

entity gth_artix_wrapper is
  port (
  sys_clk          : in std_logic;
  gth_freerun_clk  : in std_logic;
  
  sys_rst          : in std_logic;
  gth_reset        : in std_logic;
  
  gth_txusr_clk    : out std_logic;
  gth_tx_data      : in std_logic_vector(31 downto 0); 
  gth_tx_data_enb  : in std_logic;
  
  gth_refclk_p     : in std_logic;
  gth_refclk_n     : in std_logic;

  gth_rx_data      : out std_logic_vector(31 downto 0);
  gth_rx_data_enb  : out std_logic;
  gth_rxusr_clk    : out std_logic;

  gth_rx_p         : in std_logic;
  gth_rx_n         : in std_logic;
  gth_tx_p         : out std_logic;
  gth_tx_n         : out std_logic 

);  
 

end gth_artix_wrapper;

architecture behv of gth_artix_wrapper is


component gth_artix
  port (
    gthrxn_in                            : in std_logic; 
    gthrxp_in                            : in std_logic;  
    gthtxn_out                           : out std_logic;  
    gthtxp_out                           : out std_logic;    
    gtwiz_reset_clk_freerun_in           : in std_logic;  
    gtwiz_reset_all_in                   : in std_logic;           
    drpclk_in                            : in std_logic; 
    gtrefclk0_in                         : in std_logic;  
    gtpowergood_out                      : out std_logic;  
    --cpllfbclklost_out                    : out std_logic;  
    cplllock_out                         : out std_logic;  
    --cpllrefclklost_out                   : out std_logic;       
     
    gtwiz_reset_tx_pll_and_datapath_in   : in std_logic;  
    gtwiz_reset_tx_datapath_in           : in std_logic;  
    gtwiz_reset_rx_pll_and_datapath_in   : in std_logic;  
    gtwiz_reset_rx_datapath_in           : in std_logic;  
    gtwiz_reset_rx_cdr_stable_out        : out std_logic;  
    gtwiz_reset_tx_done_out              : out std_logic;  
    gtwiz_reset_rx_done_out              : out std_logic;  
     
     gtwiz_userdata_tx_in                : in std_logic_vector(31 downto 0);  
     txctrl0_in                          : in std_logic_vector(15 downto 0);  
     txctrl1_in                          : in std_logic_vector(15 downto 0);   
     txctrl2_in                          : in std_logic_vector(7 downto 0);      
     tx8b10ben_in                        : in std_logic;  
     txoutclk_out                        : out std_logic;  
     txusrclk_in                         : in std_logic;  
     txusrclk2_in                        : in std_logic;  
     txpmaresetdone_out                  : out std_logic;       
     gtwiz_userclk_tx_reset_in           : in std_logic;  
     gtwiz_userclk_tx_active_in          : in std_logic; 

     gtwiz_userdata_rx_out               : out std_logic_vector(31 downto 0); 
     rxctrl0_out                         : out std_logic_vector(15 downto 0);     
     rxctrl1_out                         : out std_logic_vector(15 downto 0);  
     rxctrl2_out                         : out std_logic_vector(7 downto 0);  
     rxctrl3_out                         : out std_logic_vector(7 downto 0);   
     rxpolarity_in                       : in std_logic;
     rx8b10ben_in                        : in std_logic; 
     rxcommadeten_in                     : in std_logic;  
     rxmcommaalignen_in                  : in std_logic;  
     rxpcommaalignen_in                  : in std_logic; 
     rxoutclk_out                        : out std_logic;        
     rxusrclk_in                         : in std_logic;  
     rxusrclk2_in                        : in std_logic;  
     rxbyteisaligned_out                 : out std_logic; 
     rxbyterealign_out                   : out std_logic;  
     rxcommadet_out                      : out std_logic;  
     rxpmaresetdone_out                  : out std_logic;  
     gtwiz_userclk_rx_active_in          : in std_logic

);
end component; 




   
 
  signal gth_powergood   :  std_logic;
  signal gth_cpllfbclklost : std_logic;
  signal gth_cplllock      : std_logic;
  signal gth_cpllrefclklost  : std_logic;  
   
  signal gth_userclk_tx_srcclk : std_logic;
  signal gth_userclk_tx_usrclk : std_logic;
  signal gth_userclk_tx_usrclk2 : std_logic;
  signal gth_userclk_tx_active : std_logic; 
  signal gth_reset_tx_done     : std_logic;
  signal gth_txpmaresetdone    : std_logic;
  signal gth_txdata_in        : std_logic_vector(31 downto 0);
  signal gth_txcharisk_in      : std_logic_vector(7 downto 0);

  signal gth_userclk_rx_srcclk : std_logic;
  signal gth_userclk_rx_usrclk : std_logic;
  signal gth_userclk_rx_usrclk2 : std_logic;
  signal gth_userclk_rx_active : std_logic;
  signal gth_reset_rx_done     : std_logic;
  signal gth_rxpmaresetdone    : std_logic;
  signal gth_reset_rx_cdr_stable : std_logic;  
  signal gth_rxbyteisaligned   : std_logic;
  signal gth_rxbyterealign     : std_logic;
  signal gth_rxcommadet        : std_logic; 
  signal gth_rx_userdata       : std_logic_vector(31 downto 0);
  signal gth_rxctrl0           : std_logic_vector(15 downto 0);
  signal gth_rxctrl1           : std_logic_vector(15 downto 0);
  signal gth_rxctrl2           : std_logic_vector(7 downto 0);
  signal gth_rxctrl3           : std_logic_vector(7 downto 0);

  signal gth_refclk            : std_logic;
  signal gth_rxout_clk         : std_logic;
  signal gth_txout_clk         : std_logic;

  signal temp : std_logic;  
   

   attribute mark_debug     : string;
   attribute mark_debug of gth_txdata_in: signal is "true";  
   attribute mark_debug of gth_txcharisk_in: signal is "true";
   attribute mark_debug of gth_rx_userdata: signal is "true";
   attribute mark_debug of gth_rxctrl0: signal is "true";
   attribute mark_debug of gth_cplllock: signal is "true";
   attribute mark_debug of gth_powergood: signal is "true";
   attribute mark_debug of gth_reset_rx_done: signal is "true";
   attribute mark_debug of gth_tx_data: signal is "true";
   attribute mark_debug of gth_tx_data_enb: signal is "true";






begin 

gth_txdata_in(7 downto 0) <= x"BC" when (gth_tx_data_enb = '0') else gth_tx_data(7 downto 0);
gth_txdata_in(31 downto 8) <= x"525150" when (gth_tx_data_enb = '0') else gth_tx_data(31 downto 8);

gth_txcharisk_in <= x"01" when (gth_tx_data_enb = '0') else x"00";


gth_rx_data <= gth_rx_userdata;
gth_rx_data_enb <= not gth_rxctrl0(0);


BUFG_GT_RX_inst : BUFG_GT
   port map (
      O => gth_rxusr_clk,     
      CE => '1',       
      CEMASK => '0',  
      CLR => gth_reset,     
      CLRMASK => '0', 
      DIV => "000",         
      I => gth_rxout_clk             
   );


BUFG_GT_TX_inst : BUFG_GT
   port map (
      O => gth_txusr_clk,          
      CE => '1',          
      CEMASK => '0',  
      CLR => gth_reset,       
      CLRMASK => '0',
      DIV => "000",       
      I => gth_txout_clk            
   );




refclk0_buf : IBUFDS_GTE4
  generic map (
    REFCLK_EN_TX_PATH => '0',   
    REFCLK_HROW_CK_SEL => "00", 
    REFCLK_ICNTL_RX => "00"     
 )
  port map (
      O => gth_refclk,         
      ODIV2 => open, 
      CEB => '0',    
      I => gth_refclk_p,         
      IB => gth_refclk_n      
   );




  
gth : gth_artix 
    port map(
     gthrxn_in => gth_rx_n,
     gthrxp_in => gth_rx_p, 
     gthtxn_out => gth_tx_n, 
     gthtxp_out => gth_tx_p,   
     gtwiz_reset_clk_freerun_in => gth_freerun_clk, --sys_clk, 
     gtwiz_reset_all_in => gth_reset,          
     drpclk_in => gth_freerun_clk, --sys_clk,
     gtrefclk0_in => gth_refclk, 
     gtpowergood_out => gth_powergood, 
--     cpllfbclklost_out => gth_cpllfbclklost, 
     cplllock_out => gth_cplllock, 
--     cpllrefclklost_out => gth_cpllrefclklost,      
     
     gtwiz_reset_tx_pll_and_datapath_in => gth_reset, 
     gtwiz_reset_tx_datapath_in => gth_reset, 
     gtwiz_reset_rx_pll_and_datapath_in => gth_reset, 
     gtwiz_reset_rx_datapath_in => gth_reset, 
     gtwiz_reset_rx_cdr_stable_out => gth_reset_rx_cdr_stable, 
     gtwiz_reset_tx_done_out => gth_reset_tx_done, 
     gtwiz_reset_rx_done_out => gth_reset_rx_done, 
     
     gtwiz_userdata_tx_in => gth_txdata_in, 
     txctrl0_in  => x"0000",
     txctrl1_in => x"0000", 
     txctrl2_in => gth_txcharisk_in,      
     tx8b10ben_in => '1', 
     txoutclk_out => gth_txout_clk, 
     txusrclk_in => gth_txusr_clk, 
     txusrclk2_in => gth_txusr_clk, 
     txpmaresetdone_out => gth_txpmaresetdone,      
     gtwiz_userclk_tx_reset_in => gth_reset, 
     gtwiz_userclk_tx_active_in => not gth_reset,

     gtwiz_userdata_rx_out => gth_rx_userdata,
     rxctrl0_out => gth_rxctrl0, 
     rxctrl1_out => gth_rxctrl1, 
     rxctrl2_out => gth_rxctrl2, 
     rxctrl3_out => gth_rxctrl3, 
     rxpolarity_in => '1', 
     rx8b10ben_in  => '1',
     rxcommadeten_in => '1', 
     rxmcommaalignen_in => '1', 
     rxpcommaalignen_in => '1',
     rxoutclk_out => gth_rxout_clk,       
     rxusrclk_in => gth_rxusr_clk, 
     rxusrclk2_in => gth_rxusr_clk, 
     rxbyteisaligned_out => gth_rxbyteisaligned, 
     rxbyterealign_out => gth_rxbyterealign, 
     rxcommadet_out => gth_rxcommadet, 
     rxpmaresetdone_out => gth_rxpmaresetdone, 
     gtwiz_userclk_rx_active_in  => not gth_reset 

);














end behv;
