/**
 * @file r557_driver.c
 * @author Mike (michael.a.strangewood@gmail.com)
 * @version 1.0
 * @date 2026-02-04
 * 
 */

/*--Includes-----------------------------------------------------------------*/

#include "r557_driver.h"

/*--Debug weak func implementation-------------------------------------------*/

__weak void debug_callback(const uint8_t* msg) {
	HAL_UART_Transmit(&uart_port, msg, 32, uart_timeout);
}

/*--Function bodies----------------------------------------------------------*/

static void r557_init_data_package(uint8_t* transmit_data, uint8_t cmd, uint8_t* args, uint16_t args_len) {
	uint16_t checksum = 0;
	transmit_data[0] = r557_header_1st_byte;
	transmit_data[1] = r557_header_2d_byte;
	transmit_data[2] = r557_device_addr_1;
	transmit_data[3] = r557_device_addr_2;
	transmit_data[4] = r557_device_addr_3;
	transmit_data[5] = r557_device_addr_4;
	transmit_data[6] = r557_trasnmitting_package_id;
	uint16_t checksum_tmp = (1 + (uint8_t)args_len + 2);
	transmit_data[7] = (checksum_tmp >> 8) & 0xFF;
	transmit_data[8] = checksum_tmp & 0xFF;
	transmit_data[9] = cmd;
	checksum = r557_trasnmitting_package_id + ((checksum_tmp >> 8) & 0xFF) + (checksum_tmp & 0xFF) + cmd;
	for (uint8_t i = 0; i < args_len; i++) {
		transmit_data[i + 10] = args[i];
		checksum += args[i];
	}
	transmit_data[10 + args_len] = checksum >> 8;
	transmit_data[11 + args_len] = checksum & 0x00FF;
}

void r557_transmit_command(uint8_t cmd, uint8_t* args, uint16_t args_len) {
	if (args_len > 33) return E2BIG;
	uint8_t transmit_data[10 + args_len + 2];
	uint8_t receive_data[receiving_package_size] = {0};
	r557_init_data_package(transmit_data, cmd, args, args_len);
	HAL_UART_Transmit(&uart_port, transmit_data, sizeof(transmit_data), uart_timeout);
	#if __debug == 1
		if (HAL_UART_Receive(&uart_port, receive_data, sizeof(receive_data), uart_timeout) == HAL_OK) {
			debug_callback("Package received succesfully\n");
		}
	#endif
}