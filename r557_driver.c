#include "r557_driver.h"

uint8_t r557_pwd_vfy(UART_HandleTypeDef* huart) {
  uint16_t checksum = 0;
 	uint8_t txd[32] = {0};
	uint8_t rxd[32] = {0};
 	txd[0] = r557_startcode_byte0;
	txd[1] = r557_startcode_byte1;
	txd[2] = r557_addr_1;
	txd[3] = r557_addr_2;
	txd[4] = r557_addr_3;
	txd[5] = r557_addr_4;
	txd[6] = 0x01;
	txd[7] = 0x00;
	txd[8] = 0x07;
	txd[9] = 0x13;
 	txd[10] = 0x00;
 	txd[11] = 0x00;
 	txd[12] = 0x00;
 	txd[13] = 0x00;
 	for (int i = 6; i < 13; i++) {
	   checksum += txd[i];
  }
  txd[14] = checksum >> 8;
  txd[15] = checksum & 0x00FF;
  HAL_UART_Transmit(&uart_port, txd, 32, 250);
  HAL_UART_Receive(&uart_port, rxd, 32, 250);
  return rxd[9];
}

uint8_t r557_empty(UART_HandleTypeDef* huart) {
	uint16_t checksum = 0;
  uint8_t txd[32] = {0};
	uint8_t rxd[32] = {0};
	txd[0] = r557_startcode_byte0;
	txd[1] = r557_startcode_byte1;
	txd[2] = r557_addr_1;
	txd[3] = r557_addr_2;
	txd[4] = r557_addr_3;
	txd[5] = r557_addr_4;
	txd[6] = 0x01;
	txd[7] = 0x00;
	txd[8] = 0x03;
	txd[9] = 0x0D;
	for(uint8_t  i=6 ; i<=9 ; i++) {
		checksum+=txd[i];
	}
	txd[10] = checksum >> 8;
	txd[11] = checksum & 0x00FF;
	HAL_UART_Transmit(&uart_port, txd, 32, 250);
	HAL_UART_Receive(&uart_port, rxd, 32, 250);
	return rxd[9];
}

uint8_t r557_gen_img(UART_HandleTypeDef* huart) {
	uint16_t checksum = 0;
  	uint8_t txd[32] = {0};
	uint8_t rxd[32] = {0};
	txd[0] = r557_startcode_byte0;
	txd[1] = r557_startcode_byte1;
	txd[2] = r557_addr_1;
	txd[3] = r557_addr_2;
	txd[4] = r557_addr_3;
	txd[5] = r557_addr_4;
	txd[6] = 0x01;
	txd[7] = 0x00;
	txd[8] = 0x03;
	txd[9] = 0x01;
	for(uint8_t  i = 6 ; i <= 9 ; i++) {
		checksum+=txd[i];
	}
	txd[10] = checksum >> 8; ;
	txd[11] = checksum & 0x00FF;
	HAL_UART_Transmit(&uart_port, txd, 32, 250);
	HAL_UART_Receive(&uart_port, rxd, 32, 250);
	return 0;
}

uint8_t r557_img_2_tz(UART_HandleTypeDef* huart, uint8_t buf) {
	uint16_t checksum = 0;
  	uint8_t txd[32] = {0};
	uint8_t rxd[32] = {0};
	txd[0] = r557_startcode_byte0;
	txd[1] = r557_startcode_byte1;
	txd[2] = r557_addr_1;
	txd[3] = r557_addr_2;
	txd[4] = r557_addr_3;
	txd[5] = r557_addr_4;
	txd[6] = 0x01;
	txd[7] = 0x00;
	txd[8] = 0x04;
	txd[9] = 0x02;
	if (buf == 0x1) {
		txd[10] = 0x1;
	}
	else {
		txd[10] = 0x2;
	}
	for(uint8_t  i = 6 ; i <= 10; i++) {
		checksum+=txd[i];
	}
	txd[11] = checksum >> 8;
	txd[12] = checksum & 0x00FF;
	HAL_UART_Transmit(&uart_port, txd, 32, 250);
	HAL_UART_Receive(&uart_port, rxd, 32, 250);
	return 0;
}

uint8_t r557_reg_model(UART_HandleTypeDef* huart) {
	uint16_t checksum = 0;
  	uint8_t txd[32] = {0};
	uint8_t rxd[32] = {0};
	txd[0] = r557_startcode_byte0;
	txd[1] = r557_startcode_byte1;
	txd[2] = r557_addr_1;
	txd[3] = r557_addr_2;
	txd[4] = r557_addr_3;
	txd[5] = r557_addr_4;
	txd[6] = 0x01;
	txd[7] = 0x00;
	txd[8] = 0x03;
	txd[9] = 0x05;
	for(uint8_t  i = 6 ; i <= 9; i++) {
		checksum+=txd[i];
	}
	txd[10] = checksum >> 8;
	txd[11] = checksum & 0x00FF;
	HAL_UART_Transmit(&uart_port, txd, 32, 250);
	HAL_UART_Receive(&uart_port, rxd, 32, 250);
	return rxd[9];
}

uint8_t r557_search(uint8_t buf, UART_HandleTypeDef* huart) {
	uint16_t checksum = 0;
  uint8_t txd[32] = {0};
	uint8_t rxd[32] = {0};
	txd[0] = r557_startcode_byte0;
	txd[1] = r557_startcode_byte1;
	txd[2] = r557_addr_1;
	txd[3] = r557_addr_2;
	txd[4] = r557_addr_3;
	txd[5] = r557_addr_4;
	txd[6] = 0x01;
	txd[7] = 0x00;
	txd[8] = 0x08;
	txd[9] = 0x04;
	txd[10] = buf;
	txd[11] = 0x00;
  txd[12] = 0x00;
	txd[13] = 0x77 >> 8;
  txd[14] = 0x77 & 0x00FF;
	for(uint8_t  i = 6 ; i <= 14; i++) {
		checksum+=txd[i];
	}
	txd[15] = checksum >> 8;
	txd[16] = checksum & 0x00FF;
	HAL_UART_Transmit(&uart_port, txd, 32, 250);
	HAL_UART_Receive(&uart_port, rxd, 32, 250);
	if (rxd[9] != 0x00) {
		return -1;
	}
	return rxd[11];
}

void FingerPrint_InitDelay(void) {
  HAL_Delay(1000);
}

uint8_t r557_store(UART_HandleTypeDef* huart, uint8_t current_page) {
	uint16_t checksum = 0;
  uint8_t txd[32] = {0};
	uint8_t rxd[32] = {0};
	txd[0] = r557_startcode_byte0;
  txd[1] = r557_startcode_byte1;
  txd[2] = r557_addr_1;
  txd[3] = r557_addr_2;
  txd[4] = r557_addr_3;
  txd[5] = r557_addr_4;
  txd[6] = 0x01;
  txd[7] = 0x00;
  txd[8] = 0x06;
  txd[9] = 0x06;
  txd[10] = 0x1;
	txd[11] = current_page >> 8;
	txd[12] = current_page & 0x00FF;
  for(uint8_t  i = 6 ; i <= 12; i++) {
    checksum+=txd[i];
  }
  txd[13] = checksum >> 8;
  txd[14] = checksum & 0x00FF;
  HAL_UART_Transmit(&uart_port, txd, 32, 100);
  HAL_UART_Receive(&uart_port, rxd, 32, 100);
	return rxd[9];
}

uint8_t r557_showsystemdata(UART_HandleTypeDef* huart) {
	uint16_t checksum = 0;
	uint8_t txData[32 * (r557_frame_size + 1)] = {0};
	uint8_t rxData[32 * (r557_frame_size + 1)] = {0};
	
	txData[0]  = r557_startcode_byte0;
	txData[1]  = r557_startcode_byte1;
	txData[2]  = r557_addr_1;
	txData[3]  = r557_addr_2;
	txData[4]  = r557_addr_3;
	txData[5]  = r557_addr_4;
	txData[6]  = 0x01;
	txData[7]  = 0x00;
	txData[8]  = 0x03;
	txData[9]  = 0x0F;
	for (int i = 6; i <= 9; i++) {
		checksum += txData[i];
	}
	txData[10] = checksum >> 8;
	txData[11] = checksum & 0x00FF;
	if (HAL_UART_Transmit(huart, rxData, (32 * r557_frame_size + 1), 250) == HAL_OK) {
		HAL_UART_Receive(huart, rxData, (32 * r557_frame_size + 1), 250);
	};
	uint8_t BusyState = rxData[12] & 0x00000001;
	return BusyState;
}

uint8_t GetBusyState(void) {
	uint16_t checksum = 0;
	uint8_t txData[32] = {0};
	txData[0] = r557_startcode_byte0;
	txData[1] = r557_startcode_byte1;
	txData[2] = r557_addr_1;
	txData[3] = r557_addr_2;
	txData[4] = r557_addr_3;
	txData[5] = r557_addr_4;
	txData[6] = 0x01;
	txData[7] = 0x00;
	txData[8] = 0x03;
	txData[9] = 0x0F;
	for (uint8_t i = 6; i <= 9; i++) {
		checksum += i;
	}
	txData[10] = checksum >> 8;
	txData[11] = checksum & 0x00FF;
	uint8_t rxData[32] = {0};
	HAL_UART_Transmit(&uart_port, txData, (32), 100);
	HAL_UART_Receive(&uart_port, rxData, (32), 100);
	uint8_t BusyState = rxData[12] & 0x00000001;
	return BusyState;
}