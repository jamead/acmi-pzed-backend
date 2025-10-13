##################################################################
# CHECK VIVADO VERSION
##################################################################

set scripts_vivado_version 2022.2
set current_vivado_version [version -short]

if { [string first $scripts_vivado_version $current_vivado_version] == -1 } {
  catch {common::send_msg_id "IPS_TCL-100" "ERROR" "This script was generated using Vivado <$scripts_vivado_version> and is being run in <$current_vivado_version> of Vivado. Please run the script in Vivado <$scripts_vivado_version> then open the design in Vivado <$current_vivado_version>. Upgrade the design by running \"Tools => Report => Report IP Status...\", then run write_ip_tcl to create an updated script."}
  return 1
}

##################################################################
# START
##################################################################

# To test this script, run the following commands from Vivado Tcl console:
# source wvfm_fifo.tcl
# If there is no project opened, this script will create a
# project, but make sure you do not have an existing project
# in the current working folder.

set list_projs [get_projects -quiet]
if { $list_projs eq "" } {
  create_project vivado vivado -part xc7z030sbg485-1
  set_property target_language VHDL [current_project]
  set_property simulator_language Mixed [current_project]
}

##################################################################
# CHECK IPs
##################################################################

set bCheckIPs 1
set bCheckIPsPassed 1
if { $bCheckIPs == 1 } {
  set list_check_ips { xilinx.com:ip:fifo_generator:13.2 }
  set list_ips_missing ""
  common::send_msg_id "IPS_TCL-1001" "INFO" "Checking if the following IPs exist in the project's IP catalog: $list_check_ips ."

  foreach ip_vlnv $list_check_ips {
  set ip_obj [get_ipdefs -all $ip_vlnv]
  if { $ip_obj eq "" } {
    lappend list_ips_missing $ip_vlnv
    }
  }

  if { $list_ips_missing ne "" } {
    catch {common::send_msg_id "IPS_TCL-105" "ERROR" "The following IPs are not found in the IP Catalog:\n  $list_ips_missing\n\nResolution: Please add the repository containing the IP(s) to the project." }
    set bCheckIPsPassed 0
  }
}

if { $bCheckIPsPassed != 1 } {
  common::send_msg_id "IPS_TCL-102" "WARNING" "Will not continue with creation of design due to the error(s) above."
  return 1
}

##################################################################
# CREATE IP wvfm_fifo
##################################################################

set wvfm_fifo [create_ip -name fifo_generator -vendor xilinx.com -library ip -version 13.2 -module_name wvfm_fifo]

# User Parameters
set_property -dict [list \
  CONFIG.Data_Count_Width {16} \
  CONFIG.Empty_Threshold_Assert_Value {4} \
  CONFIG.Empty_Threshold_Negate_Value {5} \
  CONFIG.Enable_Safety_Circuit {false} \
  CONFIG.Fifo_Implementation {Independent_Clocks_Block_RAM} \
  CONFIG.Full_Flags_Reset_Value {1} \
  CONFIG.Full_Threshold_Assert_Value {65535} \
  CONFIG.Full_Threshold_Negate_Value {65534} \
  CONFIG.Input_Data_Width {16} \
  CONFIG.Input_Depth {65536} \
  CONFIG.Output_Data_Width {32} \
  CONFIG.Output_Depth {32768} \
  CONFIG.Performance_Options {First_Word_Fall_Through} \
  CONFIG.Read_Data_Count {true} \
  CONFIG.Read_Data_Count_Width {16} \
  CONFIG.Reset_Type {Asynchronous_Reset} \
  CONFIG.Use_Extra_Logic {true} \
  CONFIG.Write_Data_Count_Width {17} \
] [get_ips wvfm_fifo]

# Runtime Parameters
set_property -dict { 
  GENERATE_SYNTH_CHECKPOINT {1}
} $wvfm_fifo

##################################################################

