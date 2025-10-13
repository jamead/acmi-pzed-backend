


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

--library UNISIM;
--use UNISIM.VComponents.all;


entity artix_cntrl is
  port (
    sys_clk         : in std_logic;
    gth_txusr_clk   : in std_logic;
    reset           : in std_logic;
    evr_usr_trig    : in std_logic;
    addr            : in std_logic_vector(31 downto 0);
    data            : in std_logic_vector(31 downto 0);
    we              : in std_logic;
    gth_tx_data     : out std_logic_vector(31 downto 0);
    gth_tx_data_enb : out std_logic

   );
end artix_cntrl;

architecture behv of artix_cntrl is

  type     state_type is (IDLE, TX_PREAMBLE, TX_ADDR, TX_DATA); 
  signal   state            : state_type  := idle;



   signal we_sync1  : std_logic;
   signal we_sync2  : std_logic;
   signal we_sync3  : std_logic;
   
   signal trig_sync1  : std_logic;
   signal trig_sync2  : std_logic;
   signal trig_sync3  : std_logic; 
   
   
   attribute ASYNC_REG : string;
   attribute ASYNC_REG of we_sync1: signal is "true";
   attribute ASYNC_REG of we_sync2: signal is "true";
   attribute ASYNC_REG of we_sync3: signal is "true"; 
   
   attribute ASYNC_REG of trig_sync1: signal is "true";
   attribute ASYNC_REG of trig_sync2: signal is "true";
   attribute ASYNC_REG of trig_sync3: signal is "true";   

   attribute mark_debug     : string;
   attribute mark_debug of we: signal is "true";  
   attribute mark_debug of state: signal is "true";



begin

sync_we : process (gth_txusr_clk)
begin
  if (rising_edge(gth_txusr_clk)) then
     we_sync1 <= we;
     we_sync2 <= we_sync1;
     we_sync3 <= we_sync2;
  end if;
end process;


sync_trig : process (gth_txusr_clk)
begin
  if (rising_edge(gth_txusr_clk)) then
     trig_sync1 <= evr_usr_trig;
     trig_sync2 <= trig_sync1;
     trig_sync3 <= trig_sync2;
  end if;
end process;




gen_data: process (gth_txusr_clk)
begin 
  if (rising_edge(gth_txusr_clk)) then
    if (reset = '1') then
      state <= idle;
      gth_tx_data <= 32d"0";
      gth_tx_data_enb <= '0';
    else
      case state is 
        
        when IDLE => 
          gth_tx_data <= 32d"0";
          gth_tx_data_enb <= '0';
          if ((we_sync3 = '0') and (we_sync2 = '1')) or ((trig_sync3 = '0') and (trig_sync2 = '1')) then
            state <= tx_preamble;
          end if;
          
        when TX_PREAMBLE =>
            gth_tx_data <= x"ba5eba11";
            gth_tx_data_enb <= '1';
            state <= tx_addr;
            
        when TX_ADDR =>
            gth_tx_data <= addr;
            gth_tx_data_enb <= '1';
            state <= tx_data;
                    
        when TX_DATA =>
            gth_tx_data <= data;
            gth_tx_data_enb <= '1';
            state <= idle;
                   
        when others => 
          state <= idle;
      end case;
    end if;
  end if;
end process;
      



end behv;
