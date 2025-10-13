
library IEEE;
use IEEE.std_logic_1164.ALL;
use ieee.numeric_std.all;
use ieee.std_logic_unsigned.all;


  
package acmi_package is


type t_reg_o_spi is record
   dout      : std_logic_vector(31 downto 0);
   addr      : std_logic_vector(31 downto 0);
   we        : std_logic;
end record t_reg_o_spi;


type t_reg_i_wvfm is record
   fifo_dout     : std_logic_vector(31 downto 0);
   fifo_rdcnt    : std_logic_vector(15 downto 0); 
end record t_reg_i_wvfm;

type t_reg_o_wvfm is record
   spi_data      : std_logic_vector(31 downto 0);
   spi_addr      : std_logic_vector(31 downto 0);
   spi_we        : std_logic;
   fifo_enb      : std_logic;
   fifo_rst      : std_logic;
   fifo_rdstr    : std_logic;
end record t_reg_o_wvfm;






type t_reg_i_evr is record
   ts_ns      : std_logic_vector(31 downto 0);
   ts_s       : std_logic_vector(31 downto 0);
   ts_ns_lat  : std_logic_vector(31 downto 0);
   ts_s_lat   : std_logic_vector(31 downto 0);
end record t_reg_i_evr;


type t_reg_o_evr is record
   reset          : std_logic;
   inj_eventno    : std_logic_vector(7 downto 0);
   onehz_eventno  : std_logic_vector(7 downto 0);
end record;


type t_evr_trigs is record
   rcvd_clk           : std_logic;
   tbt_trig           : std_logic; 
   fa_trig            : std_logic;  
   sa_trig            : std_logic; 
   sa_trig_stretch    : std_logic;
   onehz_trig         : std_logic;
   onehz_trig_stretch : std_logic;
   inj_trig           : std_logic;
   inj_trig_stretch   : std_logic;  

end record;  


type ivt_regs_type is record
   temp0 : std_logic_vector(15 downto 0);
   temp1 : std_logic_vector(15 downto 0);
   temp2 : std_logic_vector(15 downto 0);
   temp3 : std_logic_vector(15 downto 0);
   Vreg0 : std_logic_vector(15 downto 0);
   Vreg1 : std_logic_vector(15 downto 0);
   Vreg2 : std_logic_vector(15 downto 0);
   Vreg3 : std_logic_vector(15 downto 0);
   Vreg4 : std_logic_vector(15 downto 0);
   Vreg5 : std_logic_vector(15 downto 0);
   Vreg6 : std_logic_vector(15 downto 0);
   Vreg7 : std_logic_vector(15 downto 0);
   Ireg0 : std_logic_vector(15 downto 0);
   Ireg1 : std_logic_vector(15 downto 0);
   Ireg2 : std_logic_vector(15 downto 0);
   Ireg3 : std_logic_vector(15 downto 0);
   Ireg4 : std_logic_vector(15 downto 0);
   Ireg5 : std_logic_vector(15 downto 0);
   Ireg6 : std_logic_vector(15 downto 0);
   Ireg7 : std_logic_vector(15 downto 0);
end record ivt_regs_type;



--########################################################################
--                         Components
--########################################################################
component system is
  port (
    DDR_cas_n : inout STD_LOGIC;
    DDR_cke : inout STD_LOGIC;
    DDR_ck_n : inout STD_LOGIC;
    DDR_ck_p : inout STD_LOGIC;
    DDR_cs_n : inout STD_LOGIC;
    DDR_reset_n : inout STD_LOGIC;
    DDR_odt : inout STD_LOGIC;
    DDR_ras_n : inout STD_LOGIC;
    DDR_we_n : inout STD_LOGIC;
    DDR_ba : inout STD_LOGIC_VECTOR ( 2 downto 0 );
    DDR_addr : inout STD_LOGIC_VECTOR ( 14 downto 0 );
    DDR_dm : inout STD_LOGIC_VECTOR ( 3 downto 0 );
    DDR_dq : inout STD_LOGIC_VECTOR ( 31 downto 0 );
    DDR_dqs_n : inout STD_LOGIC_VECTOR ( 3 downto 0 );
    DDR_dqs_p : inout STD_LOGIC_VECTOR ( 3 downto 0 );
    FIXED_IO_mio : inout STD_LOGIC_VECTOR ( 53 downto 0 );
    FIXED_IO_ddr_vrn : inout STD_LOGIC;
    FIXED_IO_ddr_vrp : inout STD_LOGIC;
    FIXED_IO_ps_srstb : inout STD_LOGIC;
    FIXED_IO_ps_clk : inout STD_LOGIC;
    FIXED_IO_ps_porb : inout STD_LOGIC;
    m_axi_awaddr : out STD_LOGIC_VECTOR ( 31 downto 0 );
    m_axi_awprot : out STD_LOGIC_VECTOR ( 2 downto 0 );
    m_axi_awvalid : out STD_LOGIC;
    m_axi_awready : in STD_LOGIC;
    m_axi_wdata : out STD_LOGIC_VECTOR ( 31 downto 0 );
    m_axi_wstrb : out STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axi_wvalid : out STD_LOGIC;
    m_axi_wready : in STD_LOGIC;
    m_axi_bresp : in STD_LOGIC_VECTOR ( 1 downto 0 );
    m_axi_bvalid : in STD_LOGIC;
    m_axi_bready : out STD_LOGIC;
    m_axi_araddr : out STD_LOGIC_VECTOR ( 31 downto 0 );
    m_axi_arprot : out STD_LOGIC_VECTOR ( 2 downto 0 );
    m_axi_arvalid : out STD_LOGIC;
    m_axi_arready : in STD_LOGIC;
    m_axi_rdata : in STD_LOGIC_VECTOR ( 31 downto 0 );
    m_axi_rresp : in STD_LOGIC_VECTOR ( 1 downto 0 );
    m_axi_rvalid : in STD_LOGIC;
    m_axi_rready : out STD_LOGIC;     
    pl_clk0 : out STD_LOGIC;
    pl_resetn : out STD_LOGIC_VECTOR(0 downto 0);
    pl_temp: out std_logic_vector(11 downto 0)
  );
  end component;
  



component evr_gtx
 
port
(
    SYSCLK_IN                               : in   std_logic;
    SOFT_RESET_RX_IN                        : in   std_logic;
    DONT_RESET_ON_DATA_ERROR_IN             : in   std_logic;
    GT0_TX_FSM_RESET_DONE_OUT               : out  std_logic;
    GT0_RX_FSM_RESET_DONE_OUT               : out  std_logic;
    GT0_DATA_VALID_IN                       : in   std_logic;

    --_________________________________________________________________________
    --GT0  (X1Y0)
    --____________________________CHANNEL PORTS________________________________
    --------------------------------- CPLL Ports -------------------------------
    gt0_cpllfbclklost_out                   : out  std_logic;
    gt0_cplllock_out                        : out  std_logic;
    gt0_cplllockdetclk_in                   : in   std_logic;
    gt0_cpllreset_in                        : in   std_logic;
    -------------------------- Channel - Clocking Ports ------------------------
    gt0_gtrefclk0_in                        : in   std_logic;
    gt0_gtrefclk1_in                        : in   std_logic;
    ---------------------------- Channel - DRP Ports  --------------------------
    gt0_drpaddr_in                          : in   std_logic_vector(8 downto 0);
    gt0_drpclk_in                           : in   std_logic;
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
    ------------------ Receive Ports - FPGA RX Interface Ports -----------------
    gt0_rxusrclk_in                         : in   std_logic;
    gt0_rxusrclk2_in                        : in   std_logic;
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
    gt0_rxoutclk_out                        : out  std_logic;
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


    --____________________________COMMON PORTS________________________________
     GT0_QPLLOUTCLK_IN  : in std_logic;
     GT0_QPLLOUTREFCLK_IN : in std_logic

);

end component;  


	


end acmi_package;
  
