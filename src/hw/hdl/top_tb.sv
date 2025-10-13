`timescale 1ns / 1ps
`define ZYNQ_VIP top_tb.dut.system_i.zynq_ultra_ps_e_0.inst

//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/04/2024 08:26:29 AM
// Design Name: 
// Module Name: top_tb
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module top_tb; 

    reg tb_ACLK; 
    reg tb_ARESETn; 
    wire temp_clk; 
    wire temp_rstn;  
    reg [31:0] read_data; 
    wire [7:0] leds; 
    reg resp; 
    
    reg gth_fe_refclk_p;
    reg gth_fe_refclk_n;


    initial  
    begin        
        tb_ACLK = 1'b0; 
        tb_ARESETn = 0;
        gth_fe_refclk_p = 0;
        gth_fe_refclk_n = 1;    
        
    end 

     

    //------------------------------------------------------------------------ 
    // Simple Clock Generator 
    //------------------------------------------------------------------------ 
    always #10 tb_ACLK = !tb_ACLK; 
    
    // Clock Generation for gth_fe_refclk_p and gth_fe_refclk_n (156.25 MHz)
    always #3.2 begin
        gth_fe_refclk_p = ~gth_fe_refclk_p;
        gth_fe_refclk_n = ~gth_fe_refclk_n;
    end

        

    initial 
    begin 

        $display ("running the tb"); 
        tb_ARESETn = 1'b0; 
        repeat(20)@(posedge tb_ACLK);         
        tb_ARESETn = 1'b1; 
        @(posedge tb_ACLK); 
        repeat(5) @(posedge tb_ACLK); 

           
  	    `ZYNQ_VIP.por_srstb_reset(1'b1); 
        #200; 
        `ZYNQ_VIP.por_srstb_reset(1'b0); 
        `ZYNQ_VIP.fpga_soft_reset(32'h1); 
        #2000 ;  // This delay depends on your clock frequency. It should be at least 16 clock cycles.  
        `ZYNQ_VIP.por_srstb_reset(1'b1); 
        `ZYNQ_VIP.fpga_soft_reset(32'h0); 
        #2000 ; 

        #50000;
        //Write the artix spi
        `ZYNQ_VIP.write_data(32'hA0000020,4, 32'h1, resp);      
        #200
        `ZYNQ_VIP.write_data(32'hA0000024,4, 32'h3, resp);    
        #200
        `ZYNQ_VIP.write_data(32'hA0000028,4, 32'h1, resp);    
        #200  
        `ZYNQ_VIP.write_data(32'hA0000028,4, 32'h0, resp);         
            
//        #10000;  
//         //Write the artix spi
//        `ZYNQ_VIP.write_data(32'hA0000020,4, 32'h2, resp);      
//        #200
//        `ZYNQ_VIP.write_data(32'hA0000024,4, 32'h5, resp);    
//        #200
//        `ZYNQ_VIP.write_data(32'hA0000028,4, 32'h1, resp);    
//        #200  
//        `ZYNQ_VIP.write_data(32'hA0000028,4, 32'h0, resp);         
            
//        #50000;
        `ZYNQ_VIP.read_data(32'hA0000108,4, read_data, resp); 
        #500;
         `ZYNQ_VIP.read_data(32'hA0000108,4, read_data, resp);  
        #500;       
        
        //This drives the LEDs on the GPIO output 
       `ZYNQ_VIP.write_data(32'hA0000140,4, 32'h55, resp); 
        `ZYNQ_VIP.read_data(32'hA0000140,4, read_data, resp); 
        $display ("LEDs are toggled, observe the waveform"); 

        //Write into the BRAM through GP0 and read back 
        //`ZYNQ_VIP.write_data(32'hA0010000,4, 32'hDEADBEEF, resp); 
        //`ZYNQ_VIP.read_data(32'hA0010000,4,read_data,resp); 
        //$display ("%t, running the testbench, data read from BRAM was 32'h%x",$time, read_data); 

    if(read_data == 32'hDEADBEEF) begin 
           $display ("AXI VIP Test PASSED"); 
        end 
        else begin 
           $display ("AXI VIP Test FAILED"); 
        end 
        $display ("Simulation completed"); 
        $stop; 
    end 

  

    assign temp_clk = tb_ACLK; 
    assign temp_rstn = tb_ARESETn; 

 
   top dut (
        .gth_fe_refclk_p(gth_fe_refclk_p),
        .gth_fe_refclk_n(gth_fe_refclk_n)
        // Connect other DUT ports
    ); 
 
 
//top dut (); 

  

   

  

  

endmodule 