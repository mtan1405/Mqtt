/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PERIPHERALS_H_
#define _PERIPHERALS_H_

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/
#include "fsl_common.h"
#include "fsl_lpuart.h"
#include "fsl_lpuart_freertos.h"
#include "fsl_clock.h"

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/
/* Definitions for BOARD_InitPeripherals functional group */
/* Definition of peripheral ID */
#define LPUART2_PERIPHERAL LPUART2
/* Definition of the backround buffer size */
#define LPUART2_BACKGROUND_BUFFER_SIZE 1
/* LPUART2 interrupt vector ID (number). */
#define LPUART2_IRQN LPUART2_IRQn
/* LPUART2 interrupt vector priority. */
#define LPUART2_IRQ_PRIORITY 0

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/
extern lpuart_rtos_handle_t LPUART2_rtos_handle;
extern lpuart_handle_t LPUART2_lpuart_handle;
extern lpuart_rtos_config_t LPUART2_rtos_config;

/***********************************************************************************************************************
 * Initialization functions
 **********************************************************************************************************************/

void BOARD_InitPeripherals(void);

/***********************************************************************************************************************
 * BOARD_InitBootPeripherals function
 **********************************************************************************************************************/
void BOARD_InitBootPeripherals(void);

#if defined(__cplusplus)
}
#endif

#endif /* _PERIPHERALS_H_ */
