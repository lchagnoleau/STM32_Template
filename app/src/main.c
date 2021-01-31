#include <stdlib.h>
#include "stm32f4xx.h"
#include "board.h"
#include "FreeRTOS.h"
#include "task.h"

TaskHandle_t xTaskLedHandle1 = NULL;

void vTask_Led_handler_1(void *params);

int main(void)
{
    /* Hardware board init */
    board_hardware_init();

    /* Create task */
    xTaskCreate(vTask_Led_handler_1, "Task-1", 500, NULL, 1, &xTaskLedHandle1);

    /* Start scheduler */
    vTaskStartScheduler();

    while(1)
    {
        /* Never go here */
    }

    return 0;
}

void vTask_Led_handler_1(void *params)
{
	while(1)
	{
        toggle_led();
        vTaskDelay(pdMS_TO_TICKS(1000));
	}
}