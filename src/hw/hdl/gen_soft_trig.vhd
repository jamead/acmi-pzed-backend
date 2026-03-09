library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity gen_soft_trig is
    port (
        clk      : in  std_logic;  -- 100 MHz clock
        reset    : in  std_logic;
        trig_1hz : out std_logic
    );
end entity;

architecture behv of gen_soft_trig is

    constant CLK_FREQ : integer := 100_000_000;
    constant PULSE_W  : integer := 10;

    signal cnt : unsigned(26 downto 0) := (others => '0'); 
    -- 2^27 = 134M > 100M

begin

process(clk)
begin
    if rising_edge(clk) then
        if reset = '1' then
            cnt <= (others => '0');
            trig_1hz <= '0';

        else
            -- counter
            if cnt = CLK_FREQ-1 then
                cnt <= (others => '0');
            else
                cnt <= cnt + 1;
            end if;

            -- generate 10-clock pulse
            if cnt < PULSE_W then
                trig_1hz <= '1';
            else
                trig_1hz <= '0';
            end if;

        end if;
    end if;
end process;

end architecture;