#include "r557_driver_conf.h"

/* error codes */
#define r557_status_ok 0x00
#define r557_status_package_recieve_err 0x01
#define r557_status_no_finger 0x02
#define r557_status_image_fail 0x03
#define r557_status_image_mess 0x06
#define r557_status_feature_fail 0x07
#define r557_status_no_match 0x08
#define r557_status_not_found 0x09
#define r557_status_enroll_mismatch 0x0A
#define r557_status_bad_location 0x0B
#define r557_status_dbrange_fail 0x0C
#define r557_status_upload_feature_fail 0x0D
#define r557_status_packet_response_fail 0x0E
#define r557_status_upload_fail 0x0F
#define r557_status_delete_fail 0x10
#define r557_status_db_clear_fail 0x11
#define r557_status_pass_fail 0x13
#define r557_status_invalid_image 0x15
#define r557_status_flash_err 0x18
#define r557_status_invalid_reg 0x1A
#define r557_status_add_code 0x20
#define r557_status_password_verify 0x21

/* commands codes */
#define r557_cmd_genimg 0x01
#define r557_cmd_img2tz 0x02
#define r557_cmd_match 0x03
#define r557_cmd_search 0x04
#define r557_cmd_regmodel 0x05
#define r557_cmd_store 0x06
#define r557_cmd_loadchar 0x07
#define r557_cmd_upchar 0x08
#define r557_cmd_downchr 0x09
#define r557_cmd_upimage 0x0A
#define r557_cmd_downimage 0x0B
#define r557_cmd_deletechar 0x0C
#define r557_cmd_empty 0x0D
#define r557_cmd_setsyspara 0x0E
#define r557_cmd_readsyspara 0x0F
#define r557_cmd_setpwd 0x12
#define r557_cmd_vfypwd 0x13
#define r557_cmd_getrandomcode 0x14
#define r557_cmd_setadder 0x15
#define r557_cmd_control 0x17
#define r557_cmd_writenotepad 0x18
#define r557_cmd_readnotepad 0x19
#define r557_cmd_templatenum 0x1D

/* other defines */
#define r557_startcode_byte0 0xEF
#define r557_startcode_byte1 0x01
#define r557_commandpacket 0x1
#define r557_datapacket 0x2
#define r557_ackpacket 0x7
#define r557_enddatapacket 0x8
#define r557_timeout 0xFF
#define r557_badpacket 0xFE
#define r557_frame_size 0

/* addresses */
#define r557_addr_1 0xFF
#define r557_addr_2 0xFF
#define r557_addr_3 0xFF
#define r557_addr_4 0xFF

extern uint32_t scanner_irq_flag;
extern uint8_t current_template_count;
extern char mesg[32];

uint8_t r557_gen_img(UART_HandleTypeDef* huart);
uint8_t r557_pwd_vfy(UART_HandleTypeDef* huart);
uint8_t r557_empty(UART_HandleTypeDef* huart);
uint8_t r557_img_2_tz(UART_HandleTypeDef* huart, uint8_t buf);
uint8_t r557_reg_model(UART_HandleTypeDef* huart);
uint8_t r557_search(UART_HandleTypeDef* huart, uint8_t buf);
uint8_t r557_showsystemdata(UART_HandleTypeDef* huart);
uint8_t r557_store(UART_HandleTypeDef* huart, uint8_t current_page);

int FingerPrint_RecieveMessage(uint16_t rxData[(32 * (r557_frame_size + 1))]);
int FingerPrint_RecieveDebugMessages(uint16_t* rxDebugData);
uint8_t FingerPrint_GenImg(void);
uint8_t FingerPrint_PwdVfy(void);
uint8_t FingerPrint_Empty(void);
uint8_t FingerPrint_GenImg(void);
uint8_t FingerPrint_Img2Tz(uint8_t buf);
uint8_t FingerPrint_RegModel(void);
//uint8_t FingerPrint_Store(uint16_t BufferId, uint16_t PageID);
int FingerPrint_Search(uint8_t buf, uint16_t StartPage, uint16_t PageNum);
uint8_t FingerPrint_ShowSystemData(UART_HandleTypeDef* huart);

uint16_t System_GetControlSum(uint8_t* Data, int StartIndex, int StopIndex);
int System_EchoViaUART(UART_HandleTypeDef* huart, char* Message);

uint8_t GetBusyState(void);
uint8_t FingerPrint_Store(int current_page);
void FingerPrint_InitDelay(void);
