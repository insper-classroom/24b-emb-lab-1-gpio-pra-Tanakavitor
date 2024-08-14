#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int LED_PIN_R = 13;
const int BTN_PINR = 12;
const int LED_PIN1 = 16;
const int LED_PIN2 = 17;
const int LED_PIN3 = 18;
const int LED_PIN4 = 19;





int main() {
    stdio_init_all();
    gpio_init(BTN_PINR);
    gpio_set_dir(BTN_PINR, GPIO_IN);
    gpio_pull_up(BTN_PINR);

    gpio_init(LED_PIN_R);
    gpio_set_dir(LED_PIN_R, GPIO_OUT);
    gpio_init(LED_PIN1);
    gpio_set_dir(LED_PIN1, GPIO_OUT);
    gpio_init(LED_PIN2);
    gpio_set_dir(LED_PIN2, GPIO_OUT);
    gpio_init(LED_PIN3);
    gpio_set_dir(LED_PIN3, GPIO_OUT);
    gpio_init(LED_PIN4);
    gpio_set_dir(LED_PIN4, GPIO_OUT);

    while (true) {
        if (!gpio_get(BTN_PINR)) {
            int current_value = gpio_get(LED_PIN_R);    
            

            int inverted_value = !current_value; 
            

            gpio_put(LED_PIN_R, inverted_value);
            for (int i = 0; i < 512; i++)
            {

                gpio_put(LED_PIN1, 1);
                sleep_ms(10);
                gpio_put(LED_PIN1, 0);
                gpio_put(LED_PIN2, 1);
                sleep_ms(10);
                gpio_put(LED_PIN2, 0);
                gpio_put(LED_PIN3, 1);
                sleep_ms(10);
                gpio_put(LED_PIN3, 0);
                gpio_put(LED_PIN4, 1);
                sleep_ms(10);
                gpio_put(LED_PIN4, 0);






            }
            

            sleep_ms(250);




            
        }
    }
}
