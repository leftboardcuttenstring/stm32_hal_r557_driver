/**
 * @file r557_driver.h
 * @author Mike (michael.a.strangewood@gmail.com)
 * @version 0.2
 * @date 2026-02-04
 * 
 */

/*--Includes-----------------------------------------------------------------*/

#include "r557_driver_conf.h"

/*--Error codes--------------------------------------------------------------*/

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

/*--Command codes------------------------------------------------------------*/

#define r557_cmd_genimg (uint8_t)0x01
#define r557_cmd_img2tz (uint8_t)0x02
#define r557_cmd_match (uint8_t)0x03
#define r557_cmd_search (uint8_t)0x04
#define r557_cmd_regmodel (uint8_t)0x05
#define r557_cmd_store (uint8_t)0x06
#define r557_cmd_loadchar (uint8_t)0x07
#define r557_cmd_upchar (uint8_t)0x08
#define r557_cmd_downchr (uint8_t)0x09
#define r557_cmd_upimage (uint8_t)0x0A
#define r557_cmd_downimage (uint8_t)0x0B
#define r557_cmd_deletechar (uint8_t)0x0C
#define r557_cmd_empty (uint8_t)0x0D
#define r557_cmd_setsyspara (uint8_t)0x0E
#define r557_cmd_readsyspara (uint8_t)0x0F
#define r557_cmd_setpwd (uint8_t)0x12
#define r557_cmd_vfypwd (uint8_t)0x13
#define r557_cmd_getrandomcode (uint8_t)0x14
#define r557_cmd_setadder (uint8_t)0x15
#define r557_cmd_control (uint8_t)0x17
#define r557_cmd_writenotepad (uint8_t)0x18
#define r557_cmd_readnotepad (uint8_t)0x19
#define r557_cmd_templatenum (uint8_t)0x1D

/*--Other defines------------------------------------------------------------*/

#define r557_startcode_byte0 0xEF
#define r557_startcode_byte1 0x01
#define r557_commandpacket 0x1
#define r557_datapacket 0x2
#define r557_ackpacket 0x7
#define r557_enddatapacket 0x8
#define r557_timeout 0xFF
#define r557_badpacket 0xFE
#ifndef r557_frame_size
    #define r557_frame_size 0
#endif

/*--R557 package static values-----------------------------------------------*/

#define r557_header_1st_byte (uint8_t)0xEF
#define r557_header_2d_byte (uint8_t)0x01
#define r557_device_addr_1 (uint8_t)0xFF
#define r557_device_addr_2 (uint8_t)0xFF
#define r557_device_addr_3 (uint8_t)0xFF
#define r557_device_addr_4 (uint8_t)0xFF
#define r557_trasnmitting_package_id (uint8_t)0x01
#define r557_receiving_package_id (uint8_t)0x07
/* no define for package's lenth */
/* and next comes user data */

/*--Derivative definitions---------------------------------------------------*/

#define package_size (32 * (r557_frame_size + 1))

/*--Function headers---------------------------------------------------------*/

/**
 * @brief Weak implementation of debug_callback
 * 
 * @param msg 
 */
__weak void debug_callback(const uint8_t* msg);

/**
 * @brief Function for initialize the transmitting data package
 * 
 * @param cmd 
 * @param args
 */
static void r557_init_data_package(uint8_t* cmd, uint8_t* args);

/**
 * @brief Function for calling the R557 command what's name is 'genimg'. See
 * manual for more details
 * 
 * @param huart 
 * @return uint8_t 
 */
uint8_t r557_gen_img(UART_HandleTypeDef* huart);

/**
 * @brief Function for calling the R557 command what's name is 'pwdfvy'. See
 * manual for more details
 * 
 * @param huart 
 * @return uint8_t 
 */
uint8_t r557_pwd_vfy(UART_HandleTypeDef* huart);

/**
 * @brief Function for calling the R557 command what's name is 'empty'. See
 * manual for more details
 * 
 * @param huart 
 * @return uint8_t 
 */
uint8_t r557_empty(UART_HandleTypeDef* huart);

/**
 * @brief Function for calling the R557 command what's name is 'img2tz'. See
 * manual for more details
 * 
 * @param huart 
 * @param buf 
 * @return uint8_t 
 */
uint8_t r557_img_2_tz(UART_HandleTypeDef* huart, uint8_t buf);

/**
 * @brief Function for calling the R557 command what's name is 'regmodel'. See
 * manual for more details
 * 
 * @param huart 
 * @return uint8_t 
 */
uint8_t r557_reg_model(UART_HandleTypeDef* huart);

/**
 * @brief Function for calling the R557 command what's name is 'search'. See
 * manual for more details
 * 
 * @param huart 
 * @param buf 
 * @return uint8_t 
 */
uint8_t r557_search(UART_HandleTypeDef* huart, uint8_t buf);

/**
 * @brief Function for calling the R557 command what's name is 'showsysdata'. See
 * manual for more details
 * 
 * @param huart 
 * @return uint8_t 
 */
uint8_t r557_showsystemdata(UART_HandleTypeDef* huart);

/**
 * @brief Function for calling the R557 command what's name is 'store'. See
 * manual for more details
 * 
 * @param huart 
 * @param current_page 
 * @return uint8_t 
 */
uint8_t r557_store(UART_HandleTypeDef* huart, uint8_t current_page);
