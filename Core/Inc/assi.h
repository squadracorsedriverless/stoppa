#ifndef ASSI_H
#define ASSI_H

#include <inttypes.h>
#include <stdbool.h>

typedef enum
{
    AS_OFF = 1,
    AS_READY,
    AS_DRIVING,
    AS_EMERGENCY,
    AS_FINISHED,
    AS_TEST,
    AS_STATE_NUM
} as_state_t;

void assi_init();
as_state_t assi_get_state();
void assi_set_state(as_state_t state);
void assi_sync(bool light_state);

#endif