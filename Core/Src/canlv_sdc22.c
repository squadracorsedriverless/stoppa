/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2018-2019 Erik Moqvist
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * This file was generated by cantools version 38.0.2 Thu Jul 27 14:47:09 2023.
 */

#include <string.h>

#include "canlv_sdc22.h"

static inline uint8_t pack_left_shift_u8(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value << shift) & mask);
}

static inline uint8_t pack_left_shift_u16(
    uint16_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value << shift) & mask);
}

static inline uint8_t pack_right_shift_u16(
    uint16_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value >> shift) & mask);
}

static inline uint16_t unpack_left_shift_u16(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint16_t)((uint16_t)(value & mask) << shift);
}

static inline uint8_t unpack_right_shift_u8(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value & mask) >> shift);
}

static inline uint16_t unpack_right_shift_u16(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint16_t)((uint16_t)(value & mask) >> shift);
}

int canlv_sdc22_dspace_ack_rtd_pack(
    uint8_t *dst_p,
    const struct canlv_sdc22_dspace_ack_rtd_t *src_p,
    size_t size)
{
    if (size < 1u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 1);

    dst_p[0] |= pack_left_shift_u8(src_p->ack, 0u, 0xffu);

    return (1);
}

int canlv_sdc22_dspace_ack_rtd_unpack(
    struct canlv_sdc22_dspace_ack_rtd_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 1u) {
        return (-EINVAL);
    }

    dst_p->ack = unpack_right_shift_u8(src_p[0], 0u, 0xffu);

    return (0);
}

uint8_t canlv_sdc22_dspace_ack_rtd_ack_encode(float value)
{
    return (uint8_t)(value);
}

float canlv_sdc22_dspace_ack_rtd_ack_decode(uint8_t value)
{
    return ((float)value);
}

bool canlv_sdc22_dspace_ack_rtd_ack_is_in_range(uint8_t value)
{
    return ((value >= 1u) && (value <= 2u));
}

int canlv_sdc22_dspace_pwm_cooling_pack(
    uint8_t *dst_p,
    const struct canlv_sdc22_dspace_pwm_cooling_t *src_p,
    size_t size)
{
    if (size < 3u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 3);

    dst_p[0] |= pack_left_shift_u8(src_p->pwm_pump, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->pwm_rad_fan, 0u, 0xffu);
    dst_p[2] |= pack_left_shift_u8(src_p->pwm_bp_fan, 0u, 0xffu);

    return (3);
}

int canlv_sdc22_dspace_pwm_cooling_unpack(
    struct canlv_sdc22_dspace_pwm_cooling_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 3u) {
        return (-EINVAL);
    }

    dst_p->pwm_pump = unpack_right_shift_u8(src_p[0], 0u, 0xffu);
    dst_p->pwm_rad_fan = unpack_right_shift_u8(src_p[1], 0u, 0xffu);
    dst_p->pwm_bp_fan = unpack_right_shift_u8(src_p[2], 0u, 0xffu);

    return (0);
}

uint8_t canlv_sdc22_dspace_pwm_cooling_pwm_pump_encode(float value)
{
    return (uint8_t)(value);
}

float canlv_sdc22_dspace_pwm_cooling_pwm_pump_decode(uint8_t value)
{
    return ((float)value);
}

bool canlv_sdc22_dspace_pwm_cooling_pwm_pump_is_in_range(uint8_t value)
{
    return (value <= 100u);
}

uint8_t canlv_sdc22_dspace_pwm_cooling_pwm_rad_fan_encode(float value)
{
    return (uint8_t)(value);
}

float canlv_sdc22_dspace_pwm_cooling_pwm_rad_fan_decode(uint8_t value)
{
    return ((float)value);
}

bool canlv_sdc22_dspace_pwm_cooling_pwm_rad_fan_is_in_range(uint8_t value)
{
    return (value <= 100u);
}

uint8_t canlv_sdc22_dspace_pwm_cooling_pwm_bp_fan_encode(float value)
{
    return (uint8_t)(value);
}

float canlv_sdc22_dspace_pwm_cooling_pwm_bp_fan_decode(uint8_t value)
{
    return ((float)value);
}

bool canlv_sdc22_dspace_pwm_cooling_pwm_bp_fan_is_in_range(uint8_t value)
{
    return (value <= 100u);
}

int canlv_sdc22_dash_cmd_rtd_pack(
    uint8_t *dst_p,
    const struct canlv_sdc22_dash_cmd_rtd_t *src_p,
    size_t size)
{
    if (size < 1u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 1);

    dst_p[0] |= pack_left_shift_u8(src_p->dash_button, 0u, 0xffu);

    return (1);
}

int canlv_sdc22_dash_cmd_rtd_unpack(
    struct canlv_sdc22_dash_cmd_rtd_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 1u) {
        return (-EINVAL);
    }

    dst_p->dash_button = unpack_right_shift_u8(src_p[0], 0u, 0xffu);

    return (0);
}

uint8_t canlv_sdc22_dash_cmd_rtd_dash_button_encode(float value)
{
    return (uint8_t)(value);
}

float canlv_sdc22_dash_cmd_rtd_dash_button_decode(uint8_t value)
{
    return ((float)value);
}

bool canlv_sdc22_dash_cmd_rtd_dash_button_is_in_range(uint8_t value)
{
    return ((value >= 1u) && (value <= 2u));
}

int canlv_sdc22_sensorboard_adc_0_3_pack(
    uint8_t *dst_p,
    const struct canlv_sdc22_sensorboard_adc_0_3_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_right_shift_u16(src_p->throttle1, 8u, 0xffu);
    dst_p[1] |= pack_left_shift_u16(src_p->throttle1, 0u, 0xffu);
    dst_p[2] |= pack_right_shift_u16(src_p->throttle2, 8u, 0xffu);
    dst_p[3] |= pack_left_shift_u16(src_p->throttle2, 0u, 0xffu);
    dst_p[4] |= pack_right_shift_u16(src_p->brake_strain_gauge1, 8u, 0xffu);
    dst_p[5] |= pack_left_shift_u16(src_p->brake_strain_gauge1, 0u, 0xffu);
    dst_p[6] |= pack_right_shift_u16(src_p->brake_strain_gauge2, 8u, 0xffu);
    dst_p[7] |= pack_left_shift_u16(src_p->brake_strain_gauge2, 0u, 0xffu);

    return (8);
}

int canlv_sdc22_sensorboard_adc_0_3_unpack(
    struct canlv_sdc22_sensorboard_adc_0_3_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->throttle1 = unpack_left_shift_u16(src_p[0], 8u, 0xffu);
    dst_p->throttle1 |= unpack_right_shift_u16(src_p[1], 0u, 0xffu);
    dst_p->throttle2 = unpack_left_shift_u16(src_p[2], 8u, 0xffu);
    dst_p->throttle2 |= unpack_right_shift_u16(src_p[3], 0u, 0xffu);
    dst_p->brake_strain_gauge1 = unpack_left_shift_u16(src_p[4], 8u, 0xffu);
    dst_p->brake_strain_gauge1 |= unpack_right_shift_u16(src_p[5], 0u, 0xffu);
    dst_p->brake_strain_gauge2 = unpack_left_shift_u16(src_p[6], 8u, 0xffu);
    dst_p->brake_strain_gauge2 |= unpack_right_shift_u16(src_p[7], 0u, 0xffu);

    return (0);
}

uint16_t canlv_sdc22_sensorboard_adc_0_3_throttle1_encode(float value)
{
    return (uint16_t)((value - -128.6628f) / 0.1428f);
}

float canlv_sdc22_sensorboard_adc_0_3_throttle1_decode(uint16_t value)
{
    return (((float)value * 0.1428f) + -128.6628f);
}

bool canlv_sdc22_sensorboard_adc_0_3_throttle1_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t canlv_sdc22_sensorboard_adc_0_3_throttle2_encode(float value)
{
    return (uint16_t)((value - 447.0f) / -0.1428f);
}

float canlv_sdc22_sensorboard_adc_0_3_throttle2_decode(uint16_t value)
{
    return (((float)value * -0.1428f) + 447.0f);
}

bool canlv_sdc22_sensorboard_adc_0_3_throttle2_is_in_range(uint16_t value)
{
    return ((value >= 3130u) && (value <= -25546u));
}

uint16_t canlv_sdc22_sensorboard_adc_0_3_brake_strain_gauge1_encode(float value)
{
    return (uint16_t)(value / -0.0033f);
}

float canlv_sdc22_sensorboard_adc_0_3_brake_strain_gauge1_decode(uint16_t value)
{
    return ((float)value * -0.0033f);
}

bool canlv_sdc22_sensorboard_adc_0_3_brake_strain_gauge1_is_in_range(uint16_t value)
{
    return ((value >= 30303u) && (value <= -526193u));
}

uint16_t canlv_sdc22_sensorboard_adc_0_3_brake_strain_gauge2_encode(float value)
{
    return (uint16_t)(value / -0.0033f);
}

float canlv_sdc22_sensorboard_adc_0_3_brake_strain_gauge2_decode(uint16_t value)
{
    return ((float)value * -0.0033f);
}

bool canlv_sdc22_sensorboard_adc_0_3_brake_strain_gauge2_is_in_range(uint16_t value)
{
    return ((value >= 30303u) && (value <= -526195u));
}

int canlv_sdc22_sensorboard_adc_4_7_pack(
    uint8_t *dst_p,
    const struct canlv_sdc22_sensorboard_adc_4_7_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_right_shift_u16(src_p->adc4, 8u, 0xffu);
    dst_p[1] |= pack_left_shift_u16(src_p->adc4, 0u, 0xffu);
    dst_p[2] |= pack_right_shift_u16(src_p->adc5, 8u, 0xffu);
    dst_p[3] |= pack_left_shift_u16(src_p->adc5, 0u, 0xffu);
    dst_p[4] |= pack_right_shift_u16(src_p->steering_angle, 8u, 0xffu);
    dst_p[5] |= pack_left_shift_u16(src_p->steering_angle, 0u, 0xffu);
    dst_p[6] |= pack_right_shift_u16(src_p->brake_press_front, 8u, 0xffu);
    dst_p[7] |= pack_left_shift_u16(src_p->brake_press_front, 0u, 0xffu);

    return (8);
}

int canlv_sdc22_sensorboard_adc_4_7_unpack(
    struct canlv_sdc22_sensorboard_adc_4_7_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->adc4 = unpack_left_shift_u16(src_p[0], 8u, 0xffu);
    dst_p->adc4 |= unpack_right_shift_u16(src_p[1], 0u, 0xffu);
    dst_p->adc5 = unpack_left_shift_u16(src_p[2], 8u, 0xffu);
    dst_p->adc5 |= unpack_right_shift_u16(src_p[3], 0u, 0xffu);
    dst_p->steering_angle = unpack_left_shift_u16(src_p[4], 8u, 0xffu);
    dst_p->steering_angle |= unpack_right_shift_u16(src_p[5], 0u, 0xffu);
    dst_p->brake_press_front = unpack_left_shift_u16(src_p[6], 8u, 0xffu);
    dst_p->brake_press_front |= unpack_right_shift_u16(src_p[7], 0u, 0xffu);

    return (0);
}

uint16_t canlv_sdc22_sensorboard_adc_4_7_adc4_encode(float value)
{
    return (uint16_t)(value / 0.0012207f);
}

float canlv_sdc22_sensorboard_adc_4_7_adc4_decode(uint16_t value)
{
    return ((float)value * 0.0012207f);
}

bool canlv_sdc22_sensorboard_adc_4_7_adc4_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t canlv_sdc22_sensorboard_adc_4_7_adc5_encode(float value)
{
    return (uint16_t)(value / 0.0012207f);
}

float canlv_sdc22_sensorboard_adc_4_7_adc5_decode(uint16_t value)
{
    return ((float)value * 0.0012207f);
}

bool canlv_sdc22_sensorboard_adc_4_7_adc5_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t canlv_sdc22_sensorboard_adc_4_7_steering_angle_encode(float value)
{
    return (uint16_t)((value - -199.0f) / 0.08754f);
}

float canlv_sdc22_sensorboard_adc_4_7_steering_angle_decode(uint16_t value)
{
    return (((float)value * 0.08754f) + -199.0f);
}

bool canlv_sdc22_sensorboard_adc_4_7_steering_angle_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t canlv_sdc22_sensorboard_adc_4_7_brake_press_front_encode(float value)
{
    return (uint16_t)((value - -9.5f) / 0.027f);
}

float canlv_sdc22_sensorboard_adc_4_7_brake_press_front_decode(uint16_t value)
{
    return (((float)value * 0.027f) + -9.5f);
}

bool canlv_sdc22_sensorboard_adc_4_7_brake_press_front_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int canlv_sdc22_sensorboard_adc_8_11_pack(
    uint8_t *dst_p,
    const struct canlv_sdc22_sensorboard_adc_8_11_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_right_shift_u16(src_p->adc8, 8u, 0xffu);
    dst_p[1] |= pack_left_shift_u16(src_p->adc8, 0u, 0xffu);
    dst_p[2] |= pack_right_shift_u16(src_p->adc9, 8u, 0xffu);
    dst_p[3] |= pack_left_shift_u16(src_p->adc9, 0u, 0xffu);
    dst_p[4] |= pack_right_shift_u16(src_p->adc10, 8u, 0xffu);
    dst_p[5] |= pack_left_shift_u16(src_p->adc10, 0u, 0xffu);
    dst_p[6] |= pack_right_shift_u16(src_p->adc11, 8u, 0xffu);
    dst_p[7] |= pack_left_shift_u16(src_p->adc11, 0u, 0xffu);

    return (8);
}

int canlv_sdc22_sensorboard_adc_8_11_unpack(
    struct canlv_sdc22_sensorboard_adc_8_11_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->adc8 = unpack_left_shift_u16(src_p[0], 8u, 0xffu);
    dst_p->adc8 |= unpack_right_shift_u16(src_p[1], 0u, 0xffu);
    dst_p->adc9 = unpack_left_shift_u16(src_p[2], 8u, 0xffu);
    dst_p->adc9 |= unpack_right_shift_u16(src_p[3], 0u, 0xffu);
    dst_p->adc10 = unpack_left_shift_u16(src_p[4], 8u, 0xffu);
    dst_p->adc10 |= unpack_right_shift_u16(src_p[5], 0u, 0xffu);
    dst_p->adc11 = unpack_left_shift_u16(src_p[6], 8u, 0xffu);
    dst_p->adc11 |= unpack_right_shift_u16(src_p[7], 0u, 0xffu);

    return (0);
}

uint16_t canlv_sdc22_sensorboard_adc_8_11_adc8_encode(float value)
{
    return (uint16_t)(value / 0.0012207f);
}

float canlv_sdc22_sensorboard_adc_8_11_adc8_decode(uint16_t value)
{
    return ((float)value * 0.0012207f);
}

bool canlv_sdc22_sensorboard_adc_8_11_adc8_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t canlv_sdc22_sensorboard_adc_8_11_adc9_encode(float value)
{
    return (uint16_t)(value / 0.0012207f);
}

float canlv_sdc22_sensorboard_adc_8_11_adc9_decode(uint16_t value)
{
    return ((float)value * 0.0012207f);
}

bool canlv_sdc22_sensorboard_adc_8_11_adc9_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t canlv_sdc22_sensorboard_adc_8_11_adc10_encode(float value)
{
    return (uint16_t)(value / 0.0012207f);
}

float canlv_sdc22_sensorboard_adc_8_11_adc10_decode(uint16_t value)
{
    return ((float)value * 0.0012207f);
}

bool canlv_sdc22_sensorboard_adc_8_11_adc10_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t canlv_sdc22_sensorboard_adc_8_11_adc11_encode(float value)
{
    return (uint16_t)(value / 0.0012207f);
}

float canlv_sdc22_sensorboard_adc_8_11_adc11_decode(uint16_t value)
{
    return ((float)value * 0.0012207f);
}

bool canlv_sdc22_sensorboard_adc_8_11_adc11_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int canlv_sdc22_sensorboard_adc_12_15_pack(
    uint8_t *dst_p,
    const struct canlv_sdc22_sensorboard_adc_12_15_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_right_shift_u16(src_p->adc12, 8u, 0xffu);
    dst_p[1] |= pack_left_shift_u16(src_p->adc12, 0u, 0xffu);
    dst_p[2] |= pack_right_shift_u16(src_p->adc13, 8u, 0xffu);
    dst_p[3] |= pack_left_shift_u16(src_p->adc13, 0u, 0xffu);
    dst_p[4] |= pack_right_shift_u16(src_p->adc14, 8u, 0xffu);
    dst_p[5] |= pack_left_shift_u16(src_p->adc14, 0u, 0xffu);
    dst_p[6] |= pack_right_shift_u16(src_p->adc15, 8u, 0xffu);
    dst_p[7] |= pack_left_shift_u16(src_p->adc15, 0u, 0xffu);

    return (8);
}

int canlv_sdc22_sensorboard_adc_12_15_unpack(
    struct canlv_sdc22_sensorboard_adc_12_15_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->adc12 = unpack_left_shift_u16(src_p[0], 8u, 0xffu);
    dst_p->adc12 |= unpack_right_shift_u16(src_p[1], 0u, 0xffu);
    dst_p->adc13 = unpack_left_shift_u16(src_p[2], 8u, 0xffu);
    dst_p->adc13 |= unpack_right_shift_u16(src_p[3], 0u, 0xffu);
    dst_p->adc14 = unpack_left_shift_u16(src_p[4], 8u, 0xffu);
    dst_p->adc14 |= unpack_right_shift_u16(src_p[5], 0u, 0xffu);
    dst_p->adc15 = unpack_left_shift_u16(src_p[6], 8u, 0xffu);
    dst_p->adc15 |= unpack_right_shift_u16(src_p[7], 0u, 0xffu);

    return (0);
}

uint16_t canlv_sdc22_sensorboard_adc_12_15_adc12_encode(float value)
{
    return (uint16_t)(value / 0.0012207f);
}

float canlv_sdc22_sensorboard_adc_12_15_adc12_decode(uint16_t value)
{
    return ((float)value * 0.0012207f);
}

bool canlv_sdc22_sensorboard_adc_12_15_adc12_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t canlv_sdc22_sensorboard_adc_12_15_adc13_encode(float value)
{
    return (uint16_t)(value / 0.0012207f);
}

float canlv_sdc22_sensorboard_adc_12_15_adc13_decode(uint16_t value)
{
    return ((float)value * 0.0012207f);
}

bool canlv_sdc22_sensorboard_adc_12_15_adc13_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t canlv_sdc22_sensorboard_adc_12_15_adc14_encode(float value)
{
    return (uint16_t)(value / 0.0012207f);
}

float canlv_sdc22_sensorboard_adc_12_15_adc14_decode(uint16_t value)
{
    return ((float)value * 0.0012207f);
}

bool canlv_sdc22_sensorboard_adc_12_15_adc14_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t canlv_sdc22_sensorboard_adc_12_15_adc15_encode(float value)
{
    return (uint16_t)(value / 0.0012207f);
}

float canlv_sdc22_sensorboard_adc_12_15_adc15_decode(uint16_t value)
{
    return ((float)value * 0.0012207f);
}

bool canlv_sdc22_sensorboard_adc_12_15_adc15_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int canlv_sdc22_sensorboard_adc_16_19_pack(
    uint8_t *dst_p,
    const struct canlv_sdc22_sensorboard_adc_16_19_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_right_shift_u16(src_p->adc16, 8u, 0xffu);
    dst_p[1] |= pack_left_shift_u16(src_p->adc16, 0u, 0xffu);
    dst_p[2] |= pack_right_shift_u16(src_p->adc17, 8u, 0xffu);
    dst_p[3] |= pack_left_shift_u16(src_p->adc17, 0u, 0xffu);
    dst_p[4] |= pack_right_shift_u16(src_p->adc18, 8u, 0xffu);
    dst_p[5] |= pack_left_shift_u16(src_p->adc18, 0u, 0xffu);
    dst_p[6] |= pack_right_shift_u16(src_p->adc19, 8u, 0xffu);
    dst_p[7] |= pack_left_shift_u16(src_p->adc19, 0u, 0xffu);

    return (8);
}

int canlv_sdc22_sensorboard_adc_16_19_unpack(
    struct canlv_sdc22_sensorboard_adc_16_19_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->adc16 = unpack_left_shift_u16(src_p[0], 8u, 0xffu);
    dst_p->adc16 |= unpack_right_shift_u16(src_p[1], 0u, 0xffu);
    dst_p->adc17 = unpack_left_shift_u16(src_p[2], 8u, 0xffu);
    dst_p->adc17 |= unpack_right_shift_u16(src_p[3], 0u, 0xffu);
    dst_p->adc18 = unpack_left_shift_u16(src_p[4], 8u, 0xffu);
    dst_p->adc18 |= unpack_right_shift_u16(src_p[5], 0u, 0xffu);
    dst_p->adc19 = unpack_left_shift_u16(src_p[6], 8u, 0xffu);
    dst_p->adc19 |= unpack_right_shift_u16(src_p[7], 0u, 0xffu);

    return (0);
}

uint16_t canlv_sdc22_sensorboard_adc_16_19_adc16_encode(float value)
{
    return (uint16_t)(value / 0.0012207f);
}

float canlv_sdc22_sensorboard_adc_16_19_adc16_decode(uint16_t value)
{
    return ((float)value * 0.0012207f);
}

bool canlv_sdc22_sensorboard_adc_16_19_adc16_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t canlv_sdc22_sensorboard_adc_16_19_adc17_encode(float value)
{
    return (uint16_t)(value / 0.0012207f);
}

float canlv_sdc22_sensorboard_adc_16_19_adc17_decode(uint16_t value)
{
    return ((float)value * 0.0012207f);
}

bool canlv_sdc22_sensorboard_adc_16_19_adc17_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t canlv_sdc22_sensorboard_adc_16_19_adc18_encode(float value)
{
    return (uint16_t)(value / 0.0012207f);
}

float canlv_sdc22_sensorboard_adc_16_19_adc18_decode(uint16_t value)
{
    return ((float)value * 0.0012207f);
}

bool canlv_sdc22_sensorboard_adc_16_19_adc18_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t canlv_sdc22_sensorboard_adc_16_19_adc19_encode(float value)
{
    return (uint16_t)(value / 0.0012207f);
}

float canlv_sdc22_sensorboard_adc_16_19_adc19_decode(uint16_t value)
{
    return ((float)value * 0.0012207f);
}

bool canlv_sdc22_sensorboard_adc_16_19_adc19_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int canlv_sdc22_sensorboard_ping_pack(
    uint8_t *dst_p,
    const struct canlv_sdc22_sensorboard_ping_t *src_p,
    size_t size)
{
    if (size < 1u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 1);

    dst_p[0] |= pack_left_shift_u8(src_p->sensorboard_on_ack, 0u, 0xffu);

    return (1);
}

int canlv_sdc22_sensorboard_ping_unpack(
    struct canlv_sdc22_sensorboard_ping_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 1u) {
        return (-EINVAL);
    }

    dst_p->sensorboard_on_ack = unpack_right_shift_u8(src_p[0], 0u, 0xffu);

    return (0);
}

uint8_t canlv_sdc22_sensorboard_ping_sensorboard_on_ack_encode(float value)
{
    return (uint8_t)(value);
}

float canlv_sdc22_sensorboard_ping_sensorboard_on_ack_decode(uint8_t value)
{
    return ((float)value);
}

bool canlv_sdc22_sensorboard_ping_sensorboard_on_ack_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

int canlv_sdc22_dash_timer_pack(
    uint8_t *dst_p,
    const struct canlv_sdc22_dash_timer_t *src_p,
    size_t size)
{
    if (size < 4u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 4);

    dst_p[0] |= pack_left_shift_u8(src_p->dash_seconds, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->dash_minutes, 0u, 0xffu);
    dst_p[2] |= pack_left_shift_u8(src_p->dash_hours, 0u, 0xffu);
    dst_p[3] |= pack_left_shift_u8(src_p->dash_days, 0u, 0xffu);

    return (4);
}

int canlv_sdc22_dash_timer_unpack(
    struct canlv_sdc22_dash_timer_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 4u) {
        return (-EINVAL);
    }

    dst_p->dash_seconds = unpack_right_shift_u8(src_p[0], 0u, 0xffu);
    dst_p->dash_minutes = unpack_right_shift_u8(src_p[1], 0u, 0xffu);
    dst_p->dash_hours = unpack_right_shift_u8(src_p[2], 0u, 0xffu);
    dst_p->dash_days = unpack_right_shift_u8(src_p[3], 0u, 0xffu);

    return (0);
}

uint8_t canlv_sdc22_dash_timer_dash_seconds_encode(float value)
{
    return (uint8_t)(value);
}

float canlv_sdc22_dash_timer_dash_seconds_decode(uint8_t value)
{
    return ((float)value);
}

bool canlv_sdc22_dash_timer_dash_seconds_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t canlv_sdc22_dash_timer_dash_minutes_encode(float value)
{
    return (uint8_t)(value);
}

float canlv_sdc22_dash_timer_dash_minutes_decode(uint8_t value)
{
    return ((float)value);
}

bool canlv_sdc22_dash_timer_dash_minutes_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t canlv_sdc22_dash_timer_dash_hours_encode(float value)
{
    return (uint8_t)(value);
}

float canlv_sdc22_dash_timer_dash_hours_decode(uint8_t value)
{
    return ((float)value);
}

bool canlv_sdc22_dash_timer_dash_hours_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t canlv_sdc22_dash_timer_dash_days_encode(float value)
{
    return (uint8_t)(value);
}

float canlv_sdc22_dash_timer_dash_days_decode(uint8_t value)
{
    return ((float)value);
}

bool canlv_sdc22_dash_timer_dash_days_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

int canlv_sdc22_dash_status_pack(
    uint8_t *dst_p,
    const struct canlv_sdc22_dash_status_t *src_p,
    size_t size)
{
    if (size < 6u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 6);

    dst_p[0] |= pack_left_shift_u8(src_p->dash_on_ack, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->rtd_fsm_status, 0u, 0xffu);
    dst_p[2] |= pack_left_shift_u8(src_p->bms_led, 0u, 0x01u);
    dst_p[2] |= pack_left_shift_u8(src_p->nohv_led, 1u, 0x02u);
    dst_p[2] |= pack_left_shift_u8(src_p->imd_led, 2u, 0x04u);
    dst_p[3] |= pack_left_shift_u8(src_p->pwm_pump_ack, 0u, 0xffu);
    dst_p[4] |= pack_left_shift_u8(src_p->pwm_rad_fan_ack, 0u, 0xffu);
    dst_p[5] |= pack_left_shift_u8(src_p->pwm_bp_fan_ack, 0u, 0xffu);

    return (6);
}

int canlv_sdc22_dash_status_unpack(
    struct canlv_sdc22_dash_status_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 6u) {
        return (-EINVAL);
    }

    dst_p->dash_on_ack = unpack_right_shift_u8(src_p[0], 0u, 0xffu);
    dst_p->rtd_fsm_status = unpack_right_shift_u8(src_p[1], 0u, 0xffu);
    dst_p->bms_led = unpack_right_shift_u8(src_p[2], 0u, 0x01u);
    dst_p->nohv_led = unpack_right_shift_u8(src_p[2], 1u, 0x02u);
    dst_p->imd_led = unpack_right_shift_u8(src_p[2], 2u, 0x04u);
    dst_p->pwm_pump_ack = unpack_right_shift_u8(src_p[3], 0u, 0xffu);
    dst_p->pwm_rad_fan_ack = unpack_right_shift_u8(src_p[4], 0u, 0xffu);
    dst_p->pwm_bp_fan_ack = unpack_right_shift_u8(src_p[5], 0u, 0xffu);

    return (0);
}

uint8_t canlv_sdc22_dash_status_dash_on_ack_encode(float value)
{
    return (uint8_t)(value);
}

float canlv_sdc22_dash_status_dash_on_ack_decode(uint8_t value)
{
    return ((float)value);
}

bool canlv_sdc22_dash_status_dash_on_ack_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t canlv_sdc22_dash_status_rtd_fsm_status_encode(float value)
{
    return (uint8_t)(value);
}

float canlv_sdc22_dash_status_rtd_fsm_status_decode(uint8_t value)
{
    return ((float)value);
}

bool canlv_sdc22_dash_status_rtd_fsm_status_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t canlv_sdc22_dash_status_bms_led_encode(float value)
{
    return (uint8_t)(value);
}

float canlv_sdc22_dash_status_bms_led_decode(uint8_t value)
{
    return ((float)value);
}

bool canlv_sdc22_dash_status_bms_led_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t canlv_sdc22_dash_status_nohv_led_encode(float value)
{
    return (uint8_t)(value);
}

float canlv_sdc22_dash_status_nohv_led_decode(uint8_t value)
{
    return ((float)value);
}

bool canlv_sdc22_dash_status_nohv_led_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t canlv_sdc22_dash_status_imd_led_encode(float value)
{
    return (uint8_t)(value);
}

float canlv_sdc22_dash_status_imd_led_decode(uint8_t value)
{
    return ((float)value);
}

bool canlv_sdc22_dash_status_imd_led_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t canlv_sdc22_dash_status_pwm_pump_ack_encode(float value)
{
    return (uint8_t)(value);
}

float canlv_sdc22_dash_status_pwm_pump_ack_decode(uint8_t value)
{
    return ((float)value);
}

bool canlv_sdc22_dash_status_pwm_pump_ack_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t canlv_sdc22_dash_status_pwm_rad_fan_ack_encode(float value)
{
    return (uint8_t)(value);
}

float canlv_sdc22_dash_status_pwm_rad_fan_ack_decode(uint8_t value)
{
    return ((float)value);
}

bool canlv_sdc22_dash_status_pwm_rad_fan_ack_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t canlv_sdc22_dash_status_pwm_bp_fan_ack_encode(float value)
{
    return (uint8_t)(value);
}

float canlv_sdc22_dash_status_pwm_bp_fan_ack_decode(uint8_t value)
{
    return ((float)value);
}

bool canlv_sdc22_dash_status_pwm_bp_fan_ack_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

int canlv_sdc22_dspace_dash_timer_pack(
    uint8_t *dst_p,
    const struct canlv_sdc22_dspace_dash_timer_t *src_p,
    size_t size)
{
    if (size < 2u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 2);

    dst_p[0] |= pack_left_shift_u8(src_p->cmd_count0, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->cmd_count1, 0u, 0xffu);

    return (2);
}

int canlv_sdc22_dspace_dash_timer_unpack(
    struct canlv_sdc22_dspace_dash_timer_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 2u) {
        return (-EINVAL);
    }

    dst_p->cmd_count0 = unpack_right_shift_u8(src_p[0], 0u, 0xffu);
    dst_p->cmd_count1 = unpack_right_shift_u8(src_p[1], 0u, 0xffu);

    return (0);
}

uint8_t canlv_sdc22_dspace_dash_timer_cmd_count0_encode(float value)
{
    return (uint8_t)(value);
}

float canlv_sdc22_dspace_dash_timer_cmd_count0_decode(uint8_t value)
{
    return ((float)value);
}

bool canlv_sdc22_dspace_dash_timer_cmd_count0_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t canlv_sdc22_dspace_dash_timer_cmd_count1_encode(float value)
{
    return (uint8_t)(value);
}

float canlv_sdc22_dspace_dash_timer_cmd_count1_decode(uint8_t value)
{
    return ((float)value);
}

bool canlv_sdc22_dspace_dash_timer_cmd_count1_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}