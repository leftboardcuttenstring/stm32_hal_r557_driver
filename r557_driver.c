/**
 * @file r557_driver.c
 * @author Mike (michael.a.strangewood@gmail.com)
 * @version 0.2
 * @date 2026-02-04
 * 
 */

/*--Includes-----------------------------------------------------------------*/

#include "r557_driver.h"

/*--Global static variables--------------------------------------------------*/

static uint8_t receive_data[32] = {0};
static uint8_t transmit_data[package_size] = {0};
static uint32_t checksum = 0;

/*--Debug weak func implementation-------------------------------------------*/

__weak void debug_callback(const uint8_t* msg) {
	HAL_UART_Transmit(&uart_port, msg, 32, uart_timeout);
}

/*--Function bodies----------------------------------------------------------*/

static void r557_init_data_package(uint8_t* cmd, uint8_t* args) {
	memset(transmit_data, 0, package_size);
	memset(receive_data, 0, 32);
	transmit_data[0] = r557_header_1st_byte;
	transmit_data[1] = r557_header_2d_byte;
	transmit_data[2] = r557_device_addr_1;
	transmit_data[3] = r557_device_addr_2;
	transmit_data[4] = r557_device_addr_3;
	transmit_data[5] = r557_device_addr_4;
	transmit_data[6] = r557_trasnmitting_package_id;
	transmit_data[7] = 0;
}

void r557_transmit_command(uint8_t cmd, uint8_t* args) {

}