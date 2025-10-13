
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;

library desyrdl;
use desyrdl.common.all;
use desyrdl.pkg_pl_regs.all;

library work;
use work.acmi_package.ALL;

library xil_defaultlib;
use xil_defaultlib.acmi_package.ALL;


entity top is
generic(
    FPGA_VERSION			: integer := 10;
    SIM_MODE				: integer := 0
    );
  port (
    ddr_addr                : inout std_logic_vector ( 14 downto 0 );
    ddr_ba                  : inout std_logic_vector ( 2 downto 0 );
    ddr_cas_n               : inout std_logic;
    ddr_ck_n                : inout std_logic;
    ddr_ck_p                : inout std_logic;
    ddr_cke                 : inout std_logic;
    ddr_cs_n                : inout std_logic;
    ddr_dm                  : inout std_logic_vector ( 3 downto 0 );
    ddr_dq                  : inout std_logic_vector ( 31 downto 0 );
    ddr_dqs_n               : inout std_logic_vector ( 3 downto 0 );
    ddr_dqs_p               : inout std_logic_vector ( 3 downto 0 );
    ddr_odt                 : inout std_logic;
    ddr_ras_n               : inout std_logic;
    ddr_reset_n             : inout std_logic;
    ddr_we_n                : inout std_logic;
    fixed_io_ddr_vrn        : inout std_logic;
    fixed_io_ddr_vrp        : inout std_logic;
    fixed_io_mio            : inout std_logic_vector ( 53 downto 0 );
    fixed_io_ps_clk         : inout std_logic;
    fixed_io_ps_porb        : inout std_logic;
    fixed_io_ps_srstb       : inout std_logic;
    
    
   -- waveform data from Artix
    waveform_data_p         : in std_logic_vector(15 downto 0);
    waveform_data_n         : in std_logic_vector(15 downto 0);
    waveform_clk_p          : in std_logic;
    waveform_clk_n          : in std_logic;
    waveform_sel_p          : in std_logic;
    waveform_sel_n          : in std_logic;
    waveform_enb_p          : in std_logic;
    waveform_enb_n          : in std_logic;    

    -- artix spi
    artix_spi_sclk          : out std_logic;                    
    artix_spi_din           : in std_logic; 
    artix_spi_dout          : out std_logic; 
    artix_spi_cs            : out std_logic;  
    
   -- Embedded Event Receiver
    gtx_evr_refclk_p        : in std_logic;
    gtx_evr_refclk_n        : in std_logic;
    gtx_evr_rx_p            : in std_logic;
    gtx_evr_rx_n            : in std_logic;    
    
    -- Current, voltage and temperature i2c
    ivt_i2c_sda             : inout std_logic;
    ivt_i2c_scl             : out std_logic;
   
    gen_bad_pwr_fault       : out std_logic;
    gen_no_clk_fault        : out std_logic;

    leds                    : out std_logic_vector(3 downto 0);
    dbg                     : out std_logic_vector(8 downto 0)


  );
end top;

 

architecture behv of top is

  
  signal pl_clk0         : std_logic;
  signal pl_clk1         : std_logic;
  signal pl_resetn       : std_logic_vector(0 downto 0);
  signal pl_reset        : std_logic;
  signal pl_temp         : std_logic_vector(11 downto 0);
  
  signal gtx_refclk0     : std_logic;
 
  signal ps_leds         : std_logic_vector(7 downto 0);
  
  signal m_axi4_m2s      : t_pl_regs_m2s;
  signal m_axi4_s2m      : t_pl_regs_s2m;
  
  signal reg_o_evr       : t_reg_o_evr;
  signal reg_i_evr       : t_reg_i_evr;
  signal evr_trigs       : t_evr_trigs;  
   
  signal reg_o_spi       : t_reg_o_spi;
  
  signal reg_i_wvfm      : t_reg_i_wvfm;
  signal reg_o_wvfm      : t_reg_o_wvfm;
  
  signal waveform_data   : std_logic_vector(15 downto 0);
  signal waveform_enb    : std_logic;
  signal waveform_clk    : std_logic;
  signal waveform_sel    : std_logic;  

  signal ps_fpled_stretch: std_logic;


  --attribute mark_debug     : string;
  --attribute mark_debug of reg_o: signal is "true";

 

begin


dbg(0) <= pl_clk0;
dbg(1) <= artix_spi_cs; 
dbg(2) <= artix_spi_sclk; 
dbg(3) <= artix_spi_dout; 
dbg(4) <= gtx_refclk0; 
dbg(5) <= '0'; --evr_rcvd_clk; 
dbg(8 downto 6) <= ps_leds(2 downto 0); 

leds <= ps_leds(3 downto 0); 


gen_no_clk_fault <= 'Z'; --'0' when gen_no_clk_fault_i = '1' else 'Z';
gen_bad_pwr_fault <= 'Z'; --'0' when gen_bad_pwr_fault_i = '1' else 'Z';


pl_reset <= not pl_resetn(0);


-- lvds input buffers 
waveform_enb_lvds      : IBUFDS  port map (O => waveform_enb, IB => waveform_enb_n, I => waveform_enb_p);
waveform_sel_lvds      : IBUFDS  port map (O => waveform_sel, IB => waveform_sel_n, I => waveform_sel_p);
waveform_clk_lvds      : IBUFDS  port map (O => waveform_clk, IB => waveform_clk_n, I => waveform_clk_p);
waveform_lvds : for i in 0 to 15 generate
 begin
    data_inst : IBUFDS port map (O => waveform_data(i), IB => waveform_data_n(i), I => waveform_data_p(i));
end generate;
 



wvfm_fifo: entity work.artix_data_rdout
  port map (
    sys_clk => pl_clk0,
    reg_o => reg_o_wvfm,
    reg_i => reg_i_wvfm,
    wvfm_clk => waveform_clk,
    wvfm_data => waveform_data,
    wvfm_enb => waveform_enb,
    wvfm_sel => waveform_sel 
 );
 
 
fe_spi: entity work.artix_spi
  port map (
    clk => pl_clk0,                    
    reset => pl_reset, 
    reg_o => reg_o_spi,                     
    sclk => artix_spi_sclk,                    
    din => artix_spi_din, 
    dout => artix_spi_dout, 
    cs => artix_spi_cs                 
  );    


ivt_i2c : entity work.qafe_monitors
  port map(
	clock => pl_clk0,  
	reset => pl_reset, 
	scl => ivt_i2c_scl, 
	sda => ivt_i2c_sda,
	registers => open --ivt_regs  
);    
 


--embedded event receiver
evr: entity work.evr_top 
  port map(
    sys_clk => pl_clk0, 
    sys_rst => pl_reset,
    reg_o => reg_o_evr,
    reg_i => reg_i_evr,
    wvfm_enb => waveform_enb,
    gtx_refclk => gtx_refclk0,
    gtx_evr_refclk_p  => gtx_evr_refclk_p,  -- 312.5 MHz reference clock
    gtx_evr_refclk_n  => gtx_evr_refclk_n,
    rx_p => gtx_evr_rx_p,
    rx_n => gtx_evr_rx_n,
    evr_trigs => evr_trigs
);	 
 



ps_pl: entity work.ps_io
  port map (
    pl_clock => pl_clk0, 
    pl_reset => pl_reset, 
    m_axi4_m2s => m_axi4_m2s, 
    m_axi4_s2m => m_axi4_s2m, 
    fp_leds => ps_leds,   
    reg_o_spi => reg_o_spi,
    reg_o_wvfm => reg_o_wvfm, 
	reg_i_wvfm => reg_i_wvfm,
	reg_o_evr => reg_o_evr, 
	reg_i_evr => reg_i_evr
          
  );





sys: system
  port map (
    ddr_addr(14 downto 0) => ddr_addr(14 downto 0),
    ddr_ba(2 downto 0) => ddr_ba(2 downto 0),
    ddr_cas_n => ddr_cas_n,
    ddr_ck_n => ddr_ck_n,
    ddr_ck_p => ddr_ck_p,
    ddr_cke => ddr_cke,
    ddr_cs_n => ddr_cs_n,
    ddr_dm(3 downto 0) => ddr_dm(3 downto 0),
    ddr_dq(31 downto 0) => ddr_dq(31 downto 0),
    ddr_dqs_n(3 downto 0) => ddr_dqs_n(3 downto 0),
    ddr_dqs_p(3 downto 0) => ddr_dqs_p(3 downto 0),
    ddr_odt => ddr_odt,
    ddr_ras_n => ddr_ras_n,
    ddr_reset_n => ddr_reset_n,
    ddr_we_n  => ddr_we_n,
    fixed_io_ddr_vrn => fixed_io_ddr_vrn,
    fixed_io_ddr_vrp => fixed_io_ddr_vrp,
    fixed_io_mio(53 downto 0) => fixed_io_mio(53 downto 0),
    fixed_io_ps_clk => fixed_io_ps_clk,
    fixed_io_ps_porb => fixed_io_ps_porb,
    fixed_io_ps_srstb => fixed_io_ps_srstb, 
    pl_clk0 => pl_clk0,
    pl_resetn => pl_resetn,  
    pl_temp => pl_temp,
    m_axi_araddr => m_axi4_m2s.araddr, 
    m_axi_arprot => m_axi4_m2s.arprot,
    m_axi_arready => m_axi4_s2m.arready,
    m_axi_arvalid => m_axi4_m2s.arvalid,
    m_axi_awaddr => m_axi4_m2s.awaddr,
    m_axi_awprot => m_axi4_m2s.awprot,
    m_axi_awready => m_axi4_s2m.awready,
    m_axi_awvalid => m_axi4_m2s.awvalid,
    m_axi_bready => m_axi4_m2s.bready,
    m_axi_bresp => m_axi4_s2m.bresp,
    m_axi_bvalid => m_axi4_s2m.bvalid,
    m_axi_rdata => m_axi4_s2m.rdata,
    m_axi_rready => m_axi4_m2s.rready,
    m_axi_rresp => m_axi4_s2m.rresp,
    m_axi_rvalid => m_axi4_s2m.rvalid,
    m_axi_wdata => m_axi4_m2s.wdata,
    m_axi_wready => m_axi4_s2m.wready,
    m_axi_wstrb => m_axi4_m2s.wstrb,
    m_axi_wvalid => m_axi4_m2s.wvalid        
  );






--stretch the sa_trig signal so can be seen on LED
sa_led : entity work.stretch
  port map (
	clk => pl_clk0,
	reset => pl_reset, 
	sig_in => evr_trigs.sa_trig, 
	len => 3000000, -- ~25ms;
	sig_out => evr_trigs.sa_trig_stretch
);	  	


--stretch the inj_trig signal so can be seen on LED
use_led : entity work.stretch
  port map (
	clk => pl_clk0,
	reset => pl_reset, 
	sig_in => evr_trigs.inj_trig, 
	len => 3000000, -- ~25ms;
	sig_out => evr_trigs.inj_trig_stretch
);	  	



--stretch the pscmsg (ioc write to device) signal so can be seen on LED
pscmsg_led : entity work.stretch
  port map (
	clk => pl_clk0,
	reset => pl_reset, 
	sig_in => ps_leds(0), 
	len => 3000000, -- ~25ms;
	sig_out => ps_fpled_stretch
);	  	



end behv;
