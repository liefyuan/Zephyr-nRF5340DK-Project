#include <zephyr/sys/printk.h>
#include <zephyr/kernel.h>

#include "led_key_logic.h"
#include "uart_logic.h"

void main(void)
{
    led_key_gpio_init();
    uart_init();

    for(;;)
    {
        uart_event_handle();
        //printk("FirstProject test start !!!\r\n");
        //k_sleep(K_MSEC(1000));
    }
}