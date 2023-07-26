#include <zephyr/sys/printk.h>
#include <zephyr/kernel.h>

void main(void)
{
    for(;;)
    {
        printk("FirstProject test start !!!\r\n");
        k_sleep(K_MSEC(1000));
    }
}