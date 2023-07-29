#include "utils.h"
#include "main.h"

board_t utils_get_board_id()
{
    static board_t board = BOARD_NOT_SAMPLED;

    if (board == BOARD_NOT_SAMPLED)
    {
        board = HAL_GPIO_ReadPin(BOARD_ID_0_GPIO_Port, BOARD_ID_0_Pin) | (HAL_GPIO_ReadPin(BOARD_ID_1_GPIO_Port, BOARD_ID_1_Pin) << 1);
    }

    return BOARD_11; // bypass above code since
}
