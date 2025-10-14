####################### GT reference clock constraints #########################

create_clock -period 3.200 [get_ports gtx_evr_refclk_p]
create_clock -period 5.000 [get_ports waveform_clk_p]


#MGTREFCLK0 - U14 (312.5Hz)
set_property PACKAGE_PIN U9 [get_ports gtx_evr_refclk_p]
set_property PACKAGE_PIN V9 [get_ports gtx_evr_refclk_n]



##---------- Set placement for gt0_gtx_wrapper_i/GTXE2_CHANNEL ------

set_property LOC GTXE2_CHANNEL_X0Y0 [get_cells evr/evr_gtx_init_i/U0/evr_gtx_i/gt0_evr_gtx_i/gtxe2_i]










