#ifndef r557_driver_conf_h
#define r557_driver_conf_h

#include "stm32f4xx_hal.h"
#include <errno.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

extern UART_HandleTypeDef huart2;
#define uart_port huart2
#define uart_debug_port

#define _debug 1

#endif