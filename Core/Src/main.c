/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "can.h"
#include "dma.h"
#include "iwdg.h"
#include "spi.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "canlv_sdc22.h"
#include "utils.h"
#include "ws2812_spi.h"
#include <stdbool.h>

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
volatile bool newvalue = false;
volatile uint16_t adcval[4] = {0};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void handle_sync_signal(uint8_t state, uint8_t *newcolor);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
    newvalue = true;
}

#include <string.h>
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_CAN1_Init();
  MX_IWDG_Init();
  MX_ADC1_Init();
  MX_SPI1_Init();
  /* USER CODE BEGIN 2 */
    if (HAL_ADC_Start_DMA(&hadc1, (uint32_t *)adcval, 4) != HAL_OK)
    {
        Error_Handler();
    }
    ws2812_spi_set_all(0);
    ws2812_spi_send(&hspi1);
    if (HAL_CAN_Start(&hcan1) != HAL_OK)
    {
        Error_Handler();
    }
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
    uint32_t last_time = 0;
    uint8_t blink = 0;
    while (1)
    {
        HAL_IWDG_Refresh(&hiwdg);

        if (newvalue && HAL_GetTick() - last_time >= 20)
        {
            last_time = HAL_GetTick();

            static uint32_t mailbox;
            uint8_t data[8] = {0};

            CAN_TxHeaderTypeDef header = {0};
            if (utils_get_board_id() == BOARD_01)
            {
                header.StdId = CANLV_SDC22_SENSORBOARD_ADC_12_15_FRAME_ID;
                header.DLC = CANLV_SDC22_SENSORBOARD_ADC_12_15_LENGTH;

                // struct canlv_sdc22_sensorboard_adc_0_3_t status;

                // status.brake_strain_gauge1 = canlv_sdc22_sensorboard_adc_0_3_brake_strain_gauge1_encode(adcval[0]);
                // status.brake_strain_gauge2 = canlv_sdc22_sensorboard_adc_0_3_brake_strain_gauge2_encode(adcval[1]);
                // status.throttle1 = canlv_sdc22_sensorboard_adc_0_3_throttle1_encode(adcval[2]);
                // status.throttle2 = canlv_sdc22_sensorboard_adc_0_3_throttle2_encode(adcval[3]);

                // canlv_sdc22_sensorboard_adc_0_3_pack(data, &status, CANLV_SDC22_SENSORBOARD_ADC_0_3_LENGTH);
            }
            else if (utils_get_board_id() == BOARD_11)
            {
                header.StdId = CANLV_SDC22_SENSORBOARD_ADC_16_19_FRAME_ID;
                header.DLC = CANLV_SDC22_SENSORBOARD_ADC_16_19_LENGTH;

                // struct canlv_sdc22_sensorboard_adc_4_7_t status;

                // status.brake_press_front = canlv_sdc22_sensorboard_adc_4_7_brake_press_front_encode(adcval[0]);
                // status.steering_angle = canlv_sdc22_sensorboard_adc_4_7_steering_angle_encode(adcval[1]);
                // status.adc4 = canlv_sdc22_sensorboard_adc_4_7_adc4_encode(adcval[2]);
                // status.adc5 = canlv_sdc22_sensorboard_adc_4_7_adc5_encode(adcval[3]);

                // canlv_sdc22_sensorboard_adc_4_7_pack(data, &status, CANLV_SDC22_SENSORBOARD_ADC_4_7_LENGTH);
            }

            // little -> big endian

            data[0] = adcval[0] >> 8;
            data[1] = adcval[0] & 0x00FF;
            data[2] = adcval[1] >> 8;
            data[3] = adcval[1] & 0x00FF;
            data[4] = adcval[2] >> 8;
            data[5] = adcval[2] & 0x00FF;
            data[6] = adcval[3] >> 8;
            data[7] = adcval[3] & 0x00FF;

            // memcpy(data, adcval, 8);

            if (HAL_CAN_AddTxMessage(&hcan1, &header, (uint8_t *)data, &mailbox) == HAL_OK)
            {
                ws2812_spi_set_led(0, WS2812_COLOR(0, !blink ? 0xFF : 0, 0));
                blink++;
                if (blink == 2)
                {
                    blink = 0;
                }
            }
            else
            {
                HAL_CAN_ResetError(&hcan1);
                ws2812_spi_set_led(0, WS2812_COLOR(0xFF, 0, 0));
            }
            ws2812_spi_send(&hspi1);
            newvalue = false;
        }

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 40;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */
    __disable_irq();
    while (1)
    {
    }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
    /* User can add his own implementation to report the file name and line number,
       ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
