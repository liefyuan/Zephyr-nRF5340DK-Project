#include <zephyr/sys/printk.h>
#include <zephyr/kernel.h>

#include <dk_buttons_and_leds.h>

void button_changed(uint32_t button_state, uint32_t has_changed)
{
	uint32_t buttons = button_state & has_changed;

    if (buttons & DK_BTN1_MSK) {
        printk("Button_1 Click\r\n");
    }

    if (buttons & DK_BTN2_MSK) {
        printk("Button_2 Click\r\n");
    }

    if (buttons & DK_BTN3_MSK) {
        printk("Button_3 Click\r\n");
    }

    if (buttons & DK_BTN4_MSK) {

        printk("Button_4 Click\r\n");
    }
}

static void configure_gpio(void)
{
	int err;

	err = dk_buttons_init(button_changed);
	if (err) {
		printk("Cannot init buttons (err: %d)", err);
	}

	err = dk_leds_init();
	if (err) {
		printk("Cannot init LEDs (err: %d)", err);
	}
}

void main(void)
{
    configure_gpio();

    for(;;)
    {
        printk("FirstProject test start !!!\r\n");
        k_sleep(K_MSEC(1000));
    }
}