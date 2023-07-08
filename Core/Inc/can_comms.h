#ifndef CAN_COMMS_H_
#define CAN_COMMS_H_
#include "can.h"

#define CAN_BOOTLOADER_ID 0x0A6
#define CAN_BRAKE_STATUS_ID 0x050

void can_recv(CAN_HandleTypeDef *hcan, uint8_t fifo);
void can_msg_send(CAN_HandleTypeDef *hcan, uint16_t id, uint8_t aData[], uint8_t dlc, uint32_t TimeOut);
#endif