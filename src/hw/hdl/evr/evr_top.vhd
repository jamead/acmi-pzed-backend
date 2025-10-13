
--//////////////////////////////////////////////////////////////////////////////////
--// Company: 
--// Engineer: 
--// 
--// Create Date: 05/14/2015 02:56:06 PM
--// Design Name: 
--// Module Name: evr_top
--// Project Name: 
--// Target Devices: 
--// Tool Versions: 
--// Description: 
--// 
--// Dependencies: 
--// 
--// Revision:
--// Revision 0.01 - File Created
--// Additional Comments:
--//
--//
--//	SFP 5    - X0Y1
--//	SFP 6    - X0Y2   --- EVR Port
--//
--// 
--//////////////////////////////////////////////////////////////////////////////////

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.std_logic_unsigned.all;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;


entity evr_top is
   port(

    sys_clk        : in std_logic;
    sys_rst        : in std_logic;
    wvfm_enb       : in std_logic;
    
    refclk         : out std_logic;
    refclk_p       : in std_logic;	 -- 312.5 MHz reference clock
    refclk_n       : in std_logic;
    rx_p           : in std_logic;
    rx_n           : in std_logic;

    trignum        : in std_logic_vector(7 downto 0);
    trigdly        : in std_logic_vector(31 downto 0);
    
    tbt_trig       : out std_logic;
    fa_trig        : out std_logic;
    sa_trig        : out std_logic;
    usr_trig       : out std_logic;
    gps_trig       : out std_logic;
    timestamp      : out std_logic_vector(63 downto 0);
    timestamp_lat  : out std_logic_vector(63 downto 0);
    
    evr_rcvd_clk   : out std_logic;
    
    dbg            : out std_logic_vector(19 downto 0)
    
);
end evr_top;
 
 
architecture behv of evr_top is
	

component timeofDayReceiver is
   port (
       clock        : in std_logic;
       reset        : in std_logic; 
       eventstream  : in std_logic_vector(7 downto 0);
       timestamp    : out std_logic_vector(63 downto 0); 
       seconds      : out std_logic_vector(31 downto 0); 
       offset       : out std_logic_vector(31 downto 0); 
       position     : out std_logic_vector(4 downto 0);
       eventclock   : out std_logic
 );
end component;


component EventReceiverChannel is 
    port (
       clock        : in std_logic;
       reset        : in std_logic;
       eventstream  : in std_logic_vector(7 downto 0); 
       myevent      : in std_logic_vector(7 downto 0);
       mydelay      : in std_logic_vector(31 downto 0); 
       mywidth      : in std_logic_vector(31 downto 0); 
       mypolarity   : in std_logic;
       trigger      : out std_logic 
);
end component;


component evr_gtx_support
generic
(
    -- Simulation attributes
    EXAMPLE_SIM_GTRESET_SPEEDUP    : string    := "FALSE";    -- Set to TRUE to speed up sim reset
    STABLE_CLOCK_PERIOD            : integer   := 10 
);
port
(
    SOFT_RESET_RX_IN                        : in   std_logic;
    DONT_RESET_ON_DATA_ERROR_IN             : in   std_logic;
    Q0_CLK0_GTREFCLK_PAD_N_IN               : in   std_logic;
    Q0_CLK0_GTREFCLK_PAD_P_IN               : in   std_logic;
    q0_clk0_refclk_i                        : out  std_logic;

    GT0_TX_FSM_RESET_DONE_OUT               : out  std_logic;
    GT0_RX_FSM_RESET_DONE_OUT               : out  std_logic;
    GT0_DATA_VALID_IN                       : in   std_logic;
 
    GT0_RXUSRCLK_OUT                        : out  std_logic;
    GT0_RXUSRCLK2_OUT                       : out  std_logic;

    --_________________________________________________________________________
        --GT0  (X1Y0)
    --____________________________CHANNEL PORTS________________________________
    --------------------------------- CPLL Ports -------------------------------
    gt0_cpllfbclklost_out                   : out  std_logic;
    gt0_cplllock_out                        : out  std_logic;
    gt0_cpllreset_in                        : in   std_logic;
    ---------------------------- Channel - DRP Ports  --------------------------
    gt0_drpaddr_in                          : in   std_logic_vector(8 downto 0);
    gt0_drpdi_in                            : in   std_logic_vector(15 downto 0);
    gt0_drpdo_out                           : out  std_logic_vector(15 downto 0);
    gt0_drpen_in                            : in   std_logic;
    gt0_drprdy_out                          : out  std_logic;
    gt0_drpwe_in                            : in   std_logic;
    --------------------------- Digital Monitor Ports --------------------------
    gt0_dmonitorout_out                     : out  std_logic_vector(7 downto 0);
    --------------------- RX Initialization and Reset Ports --------------------
    gt0_eyescanreset_in                     : in   std_logic;
    gt0_rxuserrdy_in                        : in   std_logic;
    -------------------------- RX Margin Analysis Ports ------------------------
    gt0_eyescandataerror_out                : out  std_logic;
    gt0_eyescantrigger_in                   : in   std_logic;
    ------------------ Receive Ports - FPGA RX interface Ports -----------------
    gt0_rxdata_out                          : out  std_logic_vector(15 downto 0);
    ------------------ Receive Ports - RX 8B/10B Decoder Ports -----------------
    gt0_rxdisperr_out                       : out  std_logic_vector(1 downto 0);
    gt0_rxnotintable_out                    : out  std_logic_vector(1 downto 0);
    --------------------------- Receive Ports - RX AFE -------------------------
    gt0_gtxrxp_in                           : in   std_logic;
    ------------------------ Receive Ports - RX AFE Ports ----------------------
    gt0_gtxrxn_in                           : in   std_logic;
    -------------- Receive Ports - RX Byte and Word Alignment Ports ------------
    gt0_rxcommadet_out                      : out  std_logic;
    --------------------- Receive Ports - RX Equalizer Ports -------------------
    gt0_rxdfelpmreset_in                    : in   std_logic;
    gt0_rxmonitorout_out                    : out  std_logic_vector(6 downto 0);
    gt0_rxmonitorsel_in                     : in   std_logic_vector(1 downto 0);
    --------------- Receive Ports - RX Fabric Output Control Ports -------------
    gt0_rxoutclkfabric_out                  : out  std_logic;
    ------------- Receive Ports - RX Initialization and Reset Ports ------------
    gt0_gtrxreset_in                        : in   std_logic;
    gt0_rxpmareset_in                       : in   std_logic;
    ------------------- Receive Ports - RX8B/10B Decoder Ports -----------------
    gt0_rxchariscomma_out                   : out  std_logic_vector(1 downto 0);
    gt0_rxcharisk_out                       : out  std_logic_vector(1 downto 0);
    -------------- Receive Ports -RX Initialization and Reset Ports ------------
    gt0_rxresetdone_out                     : out  std_logic;
    --------------------- TX Initialization and Reset Ports --------------------
    gt0_gttxreset_in                        : in   std_logic;
   

GT0_DRPADDR_COMMON_IN                   : in   std_logic_vector(7 downto 0);
GT0_DRPDI_COMMON_IN                     : in   std_logic_vector(15 downto 0);
GT0_DRPDO_COMMON_OUT                    : out  std_logic_vector(15 downto 0);
GT0_DRPEN_COMMON_IN                     : in   std_logic;
GT0_DRPRDY_COMMON_OUT                   : out  std_logic;
GT0_DRPWE_COMMON_IN                     : in   std_logic;
    --____________________________COMMON PORTS________________________________
     GT0_QPLLOUTCLK_OUT  : out std_logic;
     GT0_QPLLOUTREFCLK_OUT : out std_logic;
        sysclk_in : in std_logic
);
end component;


   type  state_type is (IDLE, ACTIVE);  
   signal state :  state_type;

   signal datastream        : std_logic_vector(7 downto 0);
   signal eventstream       : std_logic_vector(7 downto 0);
   signal gt0_rxdata        : std_logic_vector(15 downto 0);
   
   signal gt0_rxusrclk      : std_logic;
   signal gt0_rxusrclk2     : std_logic;
   signal gt0_rxdisperr     : std_logic;
   signal gt0_rxchariscomma : std_logic_vector(1 downto 0);
   signal gt0_rxcharisk     : std_logic_vector(1 downto 0);
   
   signal eventclock        : std_logic;
   
   signal prev_datastream   : std_logic_vector(3 downto 0);
   signal tbt_trig_i        : std_logic;
   signal tbt_trig_stretch  : std_logic;
   signal tbt_cnt           : std_logic_vector(2 downto 0);
   signal wvfm_enb_s        : std_logic_vector(2 downto 0);


--   --debug signals (connect to ila)
   attribute mark_debug     : string;
   --attribute mark_debug of eventstream: signal is "true";
   --attribute mark_debug of datastream: signal is "true";
   attribute mark_debug of timestamp: signal is "true";
   attribute mark_debug of timestamp_lat: signal is "true";
   --attribute mark_debug of eventclock: signal is "true";
   --attribute mark_debug of prev_datastream: signal is "true";
   attribute mark_debug of tbt_trig: signal is "true";
   --attribute mark_debug of tbt_trig_i: signal is "true";   
   --attribute mark_debug of trignum: signal is "true";
   --attribute mark_debug of trigdly: signal is "true";
   --attribute mark_debug of tbt_trig_stretch: signal is "true";
   --attribute mark_debug of tbt_cnt: signal is "true";   
   attribute mark_debug of gt0_rxdata: signal is "true";
   attribute mark_debug of gt0_rxcharisk: signal is "true";

begin

evr_rcvd_clk <= gt0_rxusrclk;

tbt_trig <= tbt_trig_stretch;


process(gt0_rxusrclk)
begin 
  if (rising_edge(gt0_rxusrclk)) then
     wvfm_enb_s(0) <= wvfm_enb;
     wvfm_enb_s(1) <= wvfm_enb_s(0);
     wvfm_enb_s(2) <= wvfm_enb_s(1);
     if (wvfm_enb_s(2) = '0' and wvfm_enb_s(1) = '1') then
        timestamp_lat <= timestamp;
     end if;   
  end if;
end process;





process (sys_rst, gt0_rxusrclk)
begin
   if (sys_rst = '1') then
      tbt_trig_stretch <= '0';
      tbt_cnt <= "000";
      state <= idle;
   elsif (gt0_rxusrclk'event and gt0_rxusrclk = '1') then
      case state is 
         when IDLE => 
             if (tbt_trig_i = '1') then
                tbt_trig_stretch <= '1';
                state <= active;
             end if;

         when ACTIVE =>
             tbt_cnt <= tbt_cnt + 1;
             if (tbt_cnt = "111") then
                tbt_trig_stretch <= '0';
                tbt_cnt <= "000";
                state <= idle;
             end if;         
          end case;          
      end if;
end process;



--tbt_trig <= datastream(0);
--datastream 0 toggles high/low for half of Frev.  Filter on the first low to high transition
--and ignore the rest
process (sys_rst, gt0_rxusrclk)
begin
    if (sys_rst = '1') then
       tbt_trig_i <= '0';
    elsif (gt0_rxusrclk'event and gt0_rxusrclk = '1') then
       prev_datastream(0) <= datastream(0);
       prev_datastream(1) <= prev_datastream(0);
       prev_datastream(2) <= prev_datastream(1);
       prev_datastream(3) <= prev_datastream(2);
       if (prev_datastream = "0001") then
           tbt_trig_i <= '1';
       else
           tbt_trig_i <= '0';
       end if;
    end if;
end process;


--datastream <= gt0_rxdata(7 downto 0);
--eventstream <= gt0_rxdata(15 downto 8);
--switch byte locations of datastream and eventstream  9-20-18
datastream <= gt0_rxdata(15 downto 8);
eventstream <= gt0_rxdata(7 downto 0);



--assign tbtclk = DataStream[0];
--assign {DataStream[7:0], EventStream[7:0]} = gt0_rxdata_i;






	
	
--// GTX wrapper from example design
--evr_gtx_wrapper 	evr_gtx_wrapper
--(
--    .Q0_CLK1_GTREFCLK_PAD_N_IN(Q0_CLK1_GTREFCLK_PAD_N_IN),	// 312.5 MHz
--    .Q0_CLK1_GTREFCLK_PAD_P_IN(Q0_CLK1_GTREFCLK_PAD_P_IN),
--	.sysclk_in_i(sysclk_in_i),		//60 MHz clock
--    .RXN_IN(RXN_IN),
--    .RXP_IN(RXP_IN),
--	.LocalReset(LocalReset),
--	.gtxRxClk(gt0_rxusrclk2_i),
--	.gtxRxData(gt0_rxdata_i),
--	.gtxRxcharisk(gt0_rxcharisk_i),
--	.track_data_out(track_data_out)
		
--);

	
-- timestamp decoder
ts : timeofDayReceiver
   port map(
       clock => gt0_rxusrclk,
       reset => sys_rst,
       eventstream => eventstream,
       timestamp => timestamp,
       seconds => open, 
       offset => open, 
       position => open, 
       eventclock => eventclock
 );


	
-- 1 Hz GPS tick	
event_gps : EventReceiverChannel
    port map(
       clock => gt0_rxusrclk,
       reset => sys_rst,
       eventstream => eventstream,
       myevent => (x"7D"),     -- 125d
       mydelay => (x"00000001"),
       mywidth => (x"00000175"),   -- //creates a pulse about 3us long
       mypolarity => ('0'),
       trigger => gps_trig
);



-- 10 Hz 	
event_10Hz : EventReceiverChannel
    port map(
       clock => gt0_rxusrclk,
       reset => sys_rst,
       eventstream => eventstream,
       myevent => (x"1E"),     -- 30d
       mydelay => (x"00000001"),
       mywidth => (x"00000175"),   -- //creates a pulse about 3us long
       mypolarity => ('0'),
       trigger => sa_trig
);


-- 10 KHz 	
event_10KHz : EventReceiverChannel
    port map(
       clock => gt0_rxusrclk,
       reset => sys_rst,
       eventstream => eventstream,
       myevent => (x"1F"),     -- 31d
       mydelay => (x"00000001"),
       mywidth => (x"00000175"),   -- //creates a pulse about 3us long
       mypolarity => ('0'),
       trigger => fa_trig
);
		
		
-- On demand 	
event_usr : EventReceiverChannel
    port map(
       clock => gt0_rxusrclk,
       reset => sys_rst,
       eventstream => eventstream,
       myevent => trignum,
       mydelay => trigdly, 
       mywidth => (x"00000175"),   -- //creates a pulse about 3us long
       mypolarity => ('0'),
       trigger => usr_trig
);


	
evr_gtx_support_i : evr_gtx_support
    generic map(
     EXAMPLE_SIM_GTRESET_SPEEDUP     =>     "TRUE",
     STABLE_CLOCK_PERIOD             =>      10
 )
 port map
 (
     SOFT_RESET_RX_IN                =>      ('0'), 
     DONT_RESET_ON_DATA_ERROR_IN     =>      ('1'), 
     Q0_CLK0_GTREFCLK_PAD_N_IN       =>  refclk_n, 
     Q0_CLK0_GTREFCLK_PAD_P_IN       =>  refclk_p, 
     q0_clk0_refclk_i                =>  refclk, 
     GT0_TX_FSM_RESET_DONE_OUT       =>  open,
     GT0_RX_FSM_RESET_DONE_OUT       =>  open,
     GT0_DATA_VALID_IN               =>  ('1'), 

     GT0_RXUSRCLK_OUT                => gt0_rxusrclk,
     GT0_RXUSRCLK2_OUT               => gt0_rxusrclk2,



     --_____________________________________________________________________
     --_____________________________________________________________________
     --GT0  (X1Y0)

     --------------------------------- CPLL Ports -------------------------------
     gt0_cpllfbclklost_out           =>      open, 
     gt0_cplllock_out                =>      open, 
     gt0_cpllreset_in                =>      sys_rst, --('0'), 
     ---------------------------- Channel - DRP Ports  --------------------------
     gt0_drpaddr_in                  =>      (others => '0'),
     gt0_drpdi_in                    =>      (others => '0'),
     gt0_drpdo_out                   =>      open,
     gt0_drpen_in                    =>      ('0'),
     gt0_drprdy_out                  =>      open,
     gt0_drpwe_in                    =>      ('0'),
     --------------------------- Digital Monitor Ports --------------------------
     gt0_dmonitorout_out             =>      open,
     --------------------- RX Initialization and Reset Ports --------------------
     gt0_eyescanreset_in             =>      ('0'),
     gt0_rxuserrdy_in                =>      ('1'), 
     -------------------------- RX Margin Analysis Ports ------------------------
     gt0_eyescandataerror_out        =>      open, 
     gt0_eyescantrigger_in           =>      ('0'), 
     ------------------ Receive Ports - FPGA RX interface Ports -----------------
     gt0_rxdata_out                  =>      gt0_rxdata,
     ------------------ Receive Ports - RX 8B/10B Decoder Ports -----------------
     gt0_rxdisperr_out               =>      open, 
     gt0_rxnotintable_out            =>      open, 
     --------------------------- Receive Ports - RX AFE -------------------------
     gt0_gtxrxp_in                   =>      rx_p, 
     ------------------------ Receive Ports - RX AFE Ports ----------------------
     gt0_gtxrxn_in                   =>      rx_n, 
     -------------- Receive Ports - RX Byte and Word Alignment Ports ------------
     gt0_rxcommadet_out              =>      open,
     --------------------- Receive Ports - RX Equalizer Ports -------------------
     gt0_rxdfelpmreset_in            =>      ('0'), 
     gt0_rxmonitorout_out            =>      open,
     gt0_rxmonitorsel_in             =>      "00",
     --------------- Receive Ports - RX Fabric Output Control Ports -------------
     gt0_rxoutclkfabric_out          =>      open, 
     ------------- Receive Ports - RX Initialization and Reset Ports ------------
     gt0_gtrxreset_in                =>      sys_rst, --('0'), 
     gt0_rxpmareset_in               =>      sys_rst, --('0'), 
     ------------------- Receive Ports - RX8B/10B Decoder Ports -----------------
     gt0_rxchariscomma_out           =>      gt0_rxchariscomma,
     gt0_rxcharisk_out               =>      gt0_rxcharisk,
     -------------- Receive Ports -RX Initialization and Reset Ports ------------
     gt0_rxresetdone_out             =>      open, 
     --------------------- TX Initialization and Reset Ports --------------------
     gt0_gttxreset_in                =>      sys_rst, --('0'), 



     GT0_DRPADDR_COMMON_IN => "00000000",
     GT0_DRPDI_COMMON_IN => "0000000000000000",
     GT0_DRPDO_COMMON_OUT => open,
     GT0_DRPEN_COMMON_IN => '0',
     GT0_DRPRDY_COMMON_OUT => open,
     GT0_DRPWE_COMMON_IN => '0',
     --____________________________COMMON PORTS________________________________
     GT0_QPLLOUTCLK_OUT  => open,
     GT0_QPLLOUTREFCLK_OUT => open,
     sysclk_in => sys_clk
 );




		 
		

			 
end behv;
