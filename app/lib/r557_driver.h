#include "r557_driver_conf.h"

#define FINGERPRINT_STATUS_OK 0x00
#define FINGERPRINT_STATUS_PACKETRECIEVEERR 0x01
#define FINGERPRINT_STATUS_NOFINGER 0x02
#define FINGERPRINT_STATUS_IMAGEFAIL 0x03
#define FINGERPRINT_STATUS_IMAGEMESS 0x06
#define FINGERPRINT_STATUS_FEATUREFAIL 0x07
#define FINGERPRINT_STATUS_NOMATCH 0x08
#define FINGERPRINT_STATUS_NOTFOUND 0x09
#define FINGERPRINT_STATUS_ENROLLMISMATCH 		0x0A
#define FINGERPRINT_STATUS_BADLOCATION 0x0B
#define FINGERPRINT_STATUS_DBRANGEFAIL 		0x0C
#define FINGERPRINT_STATUS_UPLOADFEATUREFAIL 	0x0D
#define FINGERPRINT_STATUS_PACKETRESPONSEFAIL  0x0E
#define FINGERPRINT_STATUS_UPLOADFAIL 			0x0F
#define FINGERPRINT_STATUS_DELETEFAIL 			0x10
#define FINGERPRINT_STATUS_DBCLEARFAIL 		0x11
#define FINGERPRINT_STATUS_PASSFAIL 			0x13
#define FINGERPRINT_STATUS_INVALIDIMAGE 		0x15
#define FINGERPRINT_STATUS_FLASHERR 			0x18
#define FINGERPRINT_STATUS_INVALIDREG 			0x1A
#define FINGERPRINT_STATUS_ADDRCODE 			0x20
#define FINGERPRINT_STATUS_PASSVERIFY 			0x21

#define FINGERPRINT_CMD_GENIMG        0x01
#define FINGERPRINT_CMD_IMG2TZ        0x02
#define FINGERPRINT_CMD_MATCH         0x03
#define FINGERPRINT_CMD_SEARCH        0x04
#define FINGERPRINT_CMD_REGMODEL      0x05
#define FINGERPRINT_CMD_STORE         0x06
#define FINGERPRINT_CMD_LOADCHAR      0x07
#define FINGERPRINT_CMD_UPCHAR        0x08
#define FINGERPRINT_CMD_DOWNCHR       0x09
#define FINGERPRINT_CMD_UPIMAGE       0x0A
#define FINGERPRINT_CMD_DOWNIMAGE     0x0B
#define FINGERPRINT_CMD_DELETCHAR     0x0C
#define FINGERPRINT_CMD_EMPTY         0x0D
#define FINGERPRINT_CMD_SETSYSPARA    0x0E
#define FINGERPRINT_CMD_READSYSPARA   0x0F
#define FINGERPRINT_CMD_SETPWD        0x12
#define FINGERPRINT_CMD_VFYPWD        0x13
#define FINGERPRINT_CMD_GETRANDOMCODE 0x14
#define FINGERPRINT_CMD_SETADDER      0x15
#define FINGERPRINT_CMD_CONTROL       0x17
#define FINGERPRINT_CMD_WRITENOTEPAD  0x18
#define FINGERPRINT_CMD_READNOTEPAD   0x19
#define FINGERPRINT_CMD_TEMPLATENUM   0x1D

#define FINGERPRINT_STARTCODE_BYTE0		0xEF
#define FINGERPRINT_STARTCODE_BYTE1		0x01
#define FINGERPRINT_COMMANDPACKET 		0x1
#define FINGERPRINT_DATAPACKET 			0x2
#define FINGERPRINT_ACKPACKET 			0x7
#define FINGERPRINT_ENDDATAPACKET 		0x8
#define FINGERPRINT_TIMEOUT 			0xFF
#define FINGERPRINT_BADPACKET 			0xFE

#define FINGERPRINT_ADDR_1              0xFF
#define FINGERPRINT_ADDR_2              0xFF
#define FINGERPRINT_ADDR_3              0xFF
#define FINGERPRINT_ADDR_4              0xFF

#define FINGERPRINT_FRAME_SIZE           0


extern uint32_t scanner_irq_flag;
extern uint8_t current_template_count;
extern char mesg[32];


uint8_t r557_gen_img();
uint8_t r557_pwd_vfy();
uint8_t r557_empty();
uint8_t r557_img_2_tz();
uint8_t r557_reg_model();
uint8_t r557_search();


int FingerPrint_RecieveMessage(uint16_t rxData[(32 * (FINGERPRINT_FRAME_SIZE + 1))]);
int FingerPrint_RecieveDebugMessages(uint16_t* rxDebugData);
uint8_t FingerPrint_GenImg(void);
uint8_t FingerPrint_PwdVfy(void);
uint8_t FingerPrint_Empty(void);
uint8_t FingerPrint_GenImg(void);
uint8_t FingerPrint_Img2Tz(uint8_t buf);
uint8_t FingerPrint_RegModel(void);
//uint8_t FingerPrint_Store(uint16_t BufferId, uint16_t PageID);
int FingerPrint_Search(uint8_t buf, uint16_t StartPage, uint16_t PageNum);

/**
 * @brief  Getting a metadata about P557 fingerprint scanner.
 * 
 * This function generates a data transmission packet, which is 
 * received and processed on the R557 fingerprint scanner side 
 * (sending is done using the HAL function HAL_UART_Transmit; 
 * the response packet is also received using the HAL function 
 * HAL_UART_Receive)
 * 
 * @param  UART_HandleTypeDef* huart
 * @retval int
 */
uint8_t FingerPrint_ShowSystemData(UART_HandleTypeDef* huart);

uint16_t System_GetControlSum(uint8_t* Data, int StartIndex, int StopIndex);
int System_EchoViaUART(UART_HandleTypeDef* huart, char* Message);

uint8_t GetBusyState(void);
uint8_t FingerPrint_Store(int current_page);
void FingerPrint_InitDelay(void);
void GlobalHandler(void);
