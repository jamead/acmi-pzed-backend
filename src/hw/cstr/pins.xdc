
#fp LEDS
set_property PACKAGE_PIN AA19 [get_ports {leds[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {leds[0]}]
set_property DRIVE 12 [get_ports {leds[0]}]
set_property SLEW FAST [get_ports {leds[0]}]

set_property PACKAGE_PIN AA20 [get_ports {leds[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {leds[1]}]
set_property DRIVE 12 [get_ports {leds[1]}]
set_property SLEW FAST [get_ports {leds[1]}]

set_property PACKAGE_PIN AB18 [get_ports {leds[2]}]
set_property IOSTANDARD LVCMOS33 [get_ports {leds[2]}]
set_property DRIVE 12 [get_ports {leds[2]}]
set_property SLEW FAST [get_ports {leds[2]}]

set_property PACKAGE_PIN AB19 [get_ports {leds[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {leds[3]}]
set_property DRIVE 12 [get_ports {leds[3]}]
set_property SLEW FAST [get_ports {leds[3]}]





set_property PACKAGE_PIN AA14 [get_ports {dbg[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {dbg[0]}]
set_property DRIVE 12 [get_ports {dbg[0]}]
set_property SLEW FAST [get_ports {dbg[0]}]

set_property PACKAGE_PIN AA15 [get_ports {dbg[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {dbg[1]}]
set_property DRIVE 12 [get_ports {dbg[1]}]
set_property SLEW FAST [get_ports {dbg[1]}]

set_property PACKAGE_PIN Y14 [get_ports {dbg[2]}]
set_property IOSTANDARD LVCMOS33 [get_ports {dbg[2]}]
set_property DRIVE 12 [get_ports {dbg[2]}]
set_property SLEW FAST [get_ports {dbg[2]}]

set_property PACKAGE_PIN Y15 [get_ports {dbg[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {dbg[3]}]
set_property DRIVE 12 [get_ports {dbg[3]}]
set_property SLEW FAST [get_ports {dbg[3]}]

set_property PACKAGE_PIN U19 [get_ports {dbg[4]}]
set_property IOSTANDARD LVCMOS33 [get_ports {dbg[4]}]
set_property DRIVE 12 [get_ports {dbg[4]}]
set_property SLEW FAST [get_ports {dbg[4]}]

set_property PACKAGE_PIN V19 [get_ports {dbg[5]}]
set_property IOSTANDARD LVCMOS33 [get_ports {dbg[5]}]
set_property DRIVE 12 [get_ports {dbg[5]}]
set_property SLEW FAST [get_ports {dbg[5]}]

set_property PACKAGE_PIN V18 [get_ports {dbg[6]}]
set_property IOSTANDARD LVCMOS33 [get_ports {dbg[6]}]
set_property DRIVE 12 [get_ports {dbg[6]}]
set_property SLEW FAST [get_ports {dbg[6]}]

set_property PACKAGE_PIN W18 [get_ports {dbg[7]}]
set_property IOSTANDARD LVCMOS33 [get_ports {dbg[7]}]
set_property DRIVE 12 [get_ports {dbg[7]}]
set_property SLEW FAST [get_ports {dbg[7]}]

set_property PACKAGE_PIN AB21 [get_ports {dbg[8]}]
set_property IOSTANDARD LVCMOS33 [get_ports {dbg[8]}]
set_property DRIVE 12 [get_ports {dbg[8]}]
set_property SLEW FAST [get_ports {dbg[8]}]



set_property PACKAGE_PIN AB22 [get_ports gen_bad_pwr_fault]
set_property IOSTANDARD LVCMOS33 [get_ports gen_bad_pwr_fault]
set_property DRIVE 12 [get_ports gen_bad_pwr_fault]
set_property SLEW FAST [get_ports gen_bad_pwr_fault]

set_property PACKAGE_PIN T16 [get_ports gen_no_clk_fault]
set_property IOSTANDARD LVCMOS33 [get_ports gen_no_clk_fault]
set_property DRIVE 12 [get_ports gen_no_clk_fault]
set_property SLEW FAST [get_ports gen_no_clk_fault]




#picozed to artix spi
set_property PACKAGE_PIN Y13 [get_ports artix_spi_dout]
set_property IOSTANDARD LVCMOS33 [get_ports artix_spi_dout]
set_property DRIVE 12 [get_ports artix_spi_dout]
set_property SLEW FAST [get_ports artix_spi_dout]

set_property PACKAGE_PIN R17 [get_ports artix_spi_din]
set_property IOSTANDARD LVCMOS33 [get_ports artix_spi_din]

set_property PACKAGE_PIN V13 [get_ports artix_spi_sclk]
set_property IOSTANDARD LVCMOS33 [get_ports artix_spi_sclk]
set_property DRIVE 12 [get_ports artix_spi_sclk]
set_property SLEW FAST [get_ports artix_spi_sclk]

set_property PACKAGE_PIN V14 [get_ports artix_spi_cs]
set_property IOSTANDARD LVCMOS33 [get_ports artix_spi_cs]
set_property DRIVE 12 [get_ports artix_spi_cs]
set_property SLEW FAST [get_ports artix_spi_cs]


# voltage, current and temp i2c
set_property PACKAGE_PIN A7 [get_ports {ivt_i2c_sda}]
set_property IOSTANDARD LVCMOS18 [get_ports {ivt_i2c_sda}]
set_property DRIVE 12 [get_ports {ivt_i2c_sda}]
set_property SLEW SLOW [get_ports {ivt_i2c_sda}]

set_property PACKAGE_PIN A6 [get_ports {ivt_i2c_scl}]
set_property IOSTANDARD LVCMOS18 [get_ports {ivt_i2c_scl}]
set_property DRIVE 12 [get_ports {ivt_i2c_scl}]
set_property SLEW SLOW [get_ports {ivt_i2c_scl}]




# waveform data (artix to picoZed)
set_property PACKAGE_PIN M4 [get_ports {waveform_data_p[0]}]
set_property IOSTANDARD LVDS [get_ports {waveform_data_p[0]}]
set_property IOSTANDARD LVDS [get_ports {waveform_data_n[0]}]

set_property PACKAGE_PIN J2 [get_ports {waveform_data_p[1]}]
set_property IOSTANDARD LVDS [get_ports {waveform_data_p[1]}]
set_property IOSTANDARD LVDS [get_ports {waveform_data_n[1]}]

set_property PACKAGE_PIN K7 [get_ports {waveform_data_p[2]}]
set_property IOSTANDARD LVDS [get_ports {waveform_data_p[2]}]
set_property IOSTANDARD LVDS [get_ports {waveform_data_n[2]}]

set_property PACKAGE_PIN J3 [get_ports {waveform_data_p[3]}]
set_property IOSTANDARD LVDS [get_ports {waveform_data_p[3]}]
set_property IOSTANDARD LVDS [get_ports {waveform_data_n[3]}]

set_property PACKAGE_PIN P7 [get_ports {waveform_data_p[4]}]
set_property IOSTANDARD LVDS [get_ports {waveform_data_p[4]}]
set_property IOSTANDARD LVDS [get_ports {waveform_data_n[4]}]

set_property PACKAGE_PIN L2 [get_ports {waveform_data_p[5]}]
set_property IOSTANDARD LVDS [get_ports {waveform_data_p[5]}]
set_property IOSTANDARD LVDS [get_ports {waveform_data_n[5]}]

set_property PACKAGE_PIN N4 [get_ports {waveform_data_p[6]}]
set_property IOSTANDARD LVDS [get_ports {waveform_data_p[6]}]
set_property IOSTANDARD LVDS [get_ports {waveform_data_n[6]}]

set_property PACKAGE_PIN P3 [get_ports {waveform_data_p[7]}]
set_property IOSTANDARD LVDS [get_ports {waveform_data_p[7]}]
set_property IOSTANDARD LVDS [get_ports {waveform_data_n[7]}]

set_property PACKAGE_PIN M2 [get_ports {waveform_data_p[8]}]
set_property IOSTANDARD LVDS [get_ports {waveform_data_p[8]}]
set_property IOSTANDARD LVDS [get_ports {waveform_data_n[8]}]

set_property PACKAGE_PIN N1 [get_ports {waveform_data_p[9]}]
set_property IOSTANDARD LVDS [get_ports {waveform_data_p[9]}]
set_property IOSTANDARD LVDS [get_ports {waveform_data_n[9]}]

set_property PACKAGE_PIN K4 [get_ports {waveform_data_p[10]}]
set_property IOSTANDARD LVDS [get_ports {waveform_data_p[10]}]
set_property IOSTANDARD LVDS [get_ports {waveform_data_n[10]}]

set_property PACKAGE_PIN U2 [get_ports {waveform_data_p[11]}]
set_property IOSTANDARD LVDS [get_ports {waveform_data_p[11]}]
set_property IOSTANDARD LVDS [get_ports {waveform_data_n[11]}]

set_property PACKAGE_PIN T2 [get_ports {waveform_data_p[12]}]
set_property IOSTANDARD LVDS [get_ports {waveform_data_p[12]}]
set_property IOSTANDARD LVDS [get_ports {waveform_data_n[12]}]

set_property PACKAGE_PIN L6 [get_ports {waveform_data_p[13]}]
set_property IOSTANDARD LVDS [get_ports {waveform_data_p[13]}]
set_property IOSTANDARD LVDS [get_ports {waveform_data_n[13]}]

set_property PACKAGE_PIN R3 [get_ports {waveform_data_p[14]}]
set_property IOSTANDARD LVDS [get_ports {waveform_data_p[14]}]
set_property IOSTANDARD LVDS [get_ports {waveform_data_n[14]}]

set_property PACKAGE_PIN R5 [get_ports {waveform_data_p[15]}]
set_property IOSTANDARD LVDS [get_ports {waveform_data_p[15]}]
set_property IOSTANDARD LVDS [get_ports {waveform_data_n[15]}]

set_property PACKAGE_PIN P6 [get_ports waveform_enb_p]
set_property IOSTANDARD LVDS [get_ports waveform_enb_p]
set_property IOSTANDARD LVDS [get_ports waveform_enb_n]

set_property PACKAGE_PIN J7 [get_ports waveform_sel_p]
set_property IOSTANDARD LVDS [get_ports waveform_sel_p]
set_property IOSTANDARD LVDS [get_ports waveform_sel_n]

set_property PACKAGE_PIN L5 [get_ports waveform_clk_p]
set_property IOSTANDARD LVDS [get_ports waveform_clk_p]
set_property IOSTANDARD LVDS [get_ports waveform_clk_n]






