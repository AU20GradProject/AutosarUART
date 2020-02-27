/*
 * CDD_UART_Internal.h
 */

#ifndef UART_CDD_UART_INTERNAL_H_
#define UART_CDD_UART_INTERNAL_H_

/* UART register address type */
typedef VAR( volatile uint32_t* const, TYPEDEF )  UART_RegAddType;

#define MODULES_NUMBER 8u /* maximum UART Modules number in the kit */
/*Register memory map in TivaC*/
#define UART0_BASE_ADDRESS 0x4000C000
#define UART1_BASE_ADDRESS 0x4000D000
#define UART2_BASE_ADDRESS 0x4000E000
#define UART3_BASE_ADDRESS 0x4000F000
#define UART4_BASE_ADDRESS 0x40010000
#define UART5_BASE_ADDRESS 0x40011000
#define UART6_BASE_ADDRESS 0x40012000
#define UART7_BASE_ADDRESS 0x40013000

/*
VAR( static const uint32_t, static ) ModulesBaseAddressLut[MODULES_NUMBER] =
{
        UART0_BASE_ADDRESS,
        UART1_BASE_ADDRESS,
        UART2_BASE_ADDRESS,
        UART3_BASE_ADDRESS,
        UART4_BASE_ADDRESS,
        UART5_BASE_ADDRESS,
        UART6_BASE_ADDRESS,
        UART7_BASE_ADDRESS
};
*/
/* Macro to get the register address by the channel id and register offset*/
#define UART_REG_ADDRESS(CHANNEL_ID,REG_OFFSET)\
        (ModulesBaseAddressLut[CHANNEL_ID] + REG_OFFSET)

/* UART Register Addresses */
#define UARTDR_REG(MODULE_ID) *((UART_RegAddType)UART_REG_ADDRESS(MODULE_ID,0x000))
#define UARTRSR_REG(MODULE_ID) *((UART_RegAddType)UART_REG_ADDRESS(MODULE_ID,0x004))
#define UARTFR_REG(MODULE_ID) *((UART_RegAddType)UART_REG_ADDRESS(MODULE_ID,0x018))
#define UARTIBRD_REG(MODULE_ID) *((UART_RegAddType)UART_REG_ADDRESS(MODULE_ID,0x024))
#define UARTFBRD_REG(MODULE_ID) *((UART_RegAddType)UART_REG_ADDRESS(MODULE_ID,0x028))
#define UARTLCRH_REG(MODULE_ID) *((UART_RegAddType)UART_REG_ADDRESS(MODULE_ID,0x02C))
#define UARTCTL_REG(MODULE_ID) *((UART_RegAddType)UART_REG_ADDRESS(MODULE_ID,0x030))
#define UARTIFLS_REG(MODULE_ID) *((UART_RegAddType)UART_REG_ADDRESS(MODULE_ID,0x034))
#define UARTCC_REG(MODULE_ID) *((UART_RegAddType)UART_REG_ADDRESS(MODULE_ID,0xFC8))
/* UART Interrupt. */
#define UARTIM_REG(MODULE_ID) *((UART_RegAddType)UART_REG_ADDRESS(MODULE_ID,0x038))
#define UARTRIS_REG(MODULE_ID) *((UART_RegAddType)UART_REG_ADDRESS(MODULE_ID,0x03C))
#define UARTMIS_REG(MODULE_ID) *((UART_RegAddType)UART_REG_ADDRESS(MODULE_ID,0x040))
#define UARTICR_REG(MODULE_ID) *((UART_RegAddType)UART_REG_ADDRESS(MODULE_ID,0x044))

/* VAR(static uint8_t, static )UART_GroupState[UART_GROUPS_NUMBER] = {0}; */

#define TXFIFOFULL(MODULE_ID) (UARTFR_REG(MODULE_ID) & 0x0020) /* if Transmitter FIFO is not full this will equal 0x00, Transmitter can transmit*/
#define RXFIFOEMPTY(MODULE_ID) (UARTFR_REG(MODULE_ID) & 0x0010) /* if Receiver FIFO is not empty this will equal 0, Receiver has data received*/

#endif /* UART_CDD_UART_INTERNAL_H_ */
