#include <stdlib.h>
#include "stm32f4xx.h"
#include "board.h"


int main(void)
{
    /* Hardware board init */
    board_hardware_init();

    while(1)
    {
        if(is_button_pressed())
            toggle_led();
    }

    return 0;
}