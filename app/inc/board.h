#ifndef __BOARD_H
#define __BOARD_H

#include <stdbool.h>


void board_hardware_init();
bool is_button_pressed();
void toggle_led();

#endif