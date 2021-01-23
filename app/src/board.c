#include "board.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"

static void led_init();
static void button_init();

void board_hardware_init()
{
    /* Set default RCC clock -> 16MHz */
    RCC_DeInit();
    SystemCoreClockUpdate();

    /* Init Led */
    led_init();

    /* Init button */
    button_init();
}

static void led_init()
{
    /* GREEN Led to PA5
    * 
    * the I/O is HIGH, the LED is on
    * the I/O is LOW,  the LED is off
    *
    */

    /* Init struct */
    GPIO_InitTypeDef gpio_init_struct;

    memset(&gpio_init_struct, 0, sizeof(gpio_init_struct));

    GPIO_StructInit(&gpio_init_struct);

    /* Start clock APB1 (GPIOA) */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

    /* Init GPIO PA5 */
    gpio_init_struct.GPIO_Pin = GPIO_Pin_5;
    gpio_init_struct.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_Init(GPIOA, &gpio_init_struct);
}

static void button_init()
{
    /* B1 to PC13 */

    /* Init struct */
    GPIO_InitTypeDef gpio_init_struct;

    memset(&gpio_init_struct, 0, sizeof(gpio_init_struct));

    GPIO_StructInit(&gpio_init_struct);

    /* Start clock APB1 (GPIOC) */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

    /* Init GPIO PA5 */
    gpio_init_struct.GPIO_Pin = GPIO_Pin_13;
    gpio_init_struct.GPIO_Mode = GPIO_Mode_IN;
    GPIO_Init(GPIOC, &gpio_init_struct);
}

bool is_button_pressed()
{
    return (bool) !GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13);
}

void toggle_led()
{
    GPIO_ToggleBits(GPIOA, GPIO_Pin_5);
}