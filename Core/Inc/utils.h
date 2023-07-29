#ifndef UTILS_H_
#define UTILS_H_
#include <inttypes.h>

typedef enum
{
    BOARD_NOT_SAMPLED = -1,
    BOARD_00 = 0b00,
    BOARD_01 = 0b01,
    BOARD_10 = 0b10,
    BOARD_11 = 0b11
} board_t;

board_t utils_get_board_id();

#endif