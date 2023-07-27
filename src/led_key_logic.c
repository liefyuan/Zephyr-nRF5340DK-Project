#include <zephyr/sys/printk.h>

#include "led_key_logic.h"
#include <dk_buttons_and_leds.h>

#define SetBit(x, y)   (x |= (1<<y))      // 特定位置1,x为目标,y为第几位
#define ClearBit(x, y) (x &= ~(1<<y))     // 特定位清0
#define GetBit(x, y)   (x &= (1<<y))      // 特定位取值
#define ReveBit(x, y)  (x ^= (1<<y))      // 特定位取反

static void button_changed(uint32_t button_state, uint32_t has_changed)
{
	uint32_t buttons = button_state & has_changed;
    static uint8_t state = 0;

    if (buttons & DK_BTN1_MSK) {
        printk("Button_1 Click\r\n");
        if(GetBit(state, 1) == 0)
        {
            dk_set_led_on(DK_LED1);
            SetBit(state, 1);
        }
        else
        {
            dk_set_led_off(DK_LED1);
            ClearBit(state, 1);
        }
    }

    if (buttons & DK_BTN2_MSK) {
        printk("Button_2 Click\r\n");
        if(GetBit(state, 2) == 0)
        {
            dk_set_led_on(DK_LED2);
            SetBit(state, 2);
        }
        else
        {
            dk_set_led_off(DK_LED2);
            ClearBit(state, 2);
        }
    }

    if (buttons & DK_BTN3_MSK) {
        printk("Button_3 Click\r\n");
        if(GetBit(state, 3) == 0)
        {
            dk_set_led_on(DK_LED3);
            SetBit(state, 3);
        }
        else
        {
            dk_set_led_off(DK_LED3);
            ClearBit(state, 3);
        }
    }

    if (buttons & DK_BTN4_MSK) {

        printk("Button_4 Click\r\n");
        if(GetBit(state, 4) == 0)
        {
            dk_set_led_on(DK_LED4);
            SetBit(state, 4);
        }
        else
        {
            dk_set_led_off(DK_LED4);
            ClearBit(state, 4);
        }
    }
}

void led_key_gpio_init(void)
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

    printk("leds keys init ok!\r\n");
}
