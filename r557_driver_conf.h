/**
 * @file r557_driver_conf.h
 * @author Mike (michael.a.strangewood@gmail.com)
 * @version 0.2
 * @date 2026-02-04
 * 
 */

#ifndef r557_driver_conf_h
#define r557_driver_conf_h

/*--Includes-----------------------------------------------------------------*/

#include "stm32f4xx_hal.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#ifdef __linux__
    #include <errno.h>
#endif
#ifdef _WIN32
    //then i dont have something to offer to ya
#endif

/*--Extern objects and defs of it for driver---------------------------------*/

extern UART_HandleTypeDef huart_fingerprint;
#define uart_port huart_fingerprint
extern UART_HandleTypeDef huart1;
#define uart_debug_port huart1

/*--Interface of defining the global project values--------------------------*/
/*
    here you can use interface of library
    for now there's no any file for implementations of __weak functions, but
    you have an ability to add your own implementation of funcs:
    1. `void debug_callback(conast uint8_t* mesg)`
*/

#define r557_frame_size 0
#define uart_timeout 100
#define __debug 0

/*---------------------------------------------------------------------------*/

#endif