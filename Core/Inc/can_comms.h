#ifndef CAN_COMMS_H_
#define CAN_COMMS_H_
#include "can.h"

#define CAN_BOOTLOADER_ID 0x0A5
#define CAN_AS_STATE_ID 0x008
#define CAN_ASSI_SYNC_ID 0x2

void can_recv(CAN_HandleTypeDef *hcan, uint8_t fifo);
void can_msg_send(CAN_HandleTypeDef *hcan, uint16_t id, uint8_t aData[], uint8_t dlc, uint32_t TimeOut);
#endif