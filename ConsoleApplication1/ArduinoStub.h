#pragma once

//--------------------------------------------------------------------
// Arduino Console Stub
//--------------------------------------------------------------------

#ifndef _ARDUIONOSTUB_H_
#define _ARDUIONOSTUB_H_


#if _MSC_VER 

#pragma once

#define _CRT_SECURE_NO_WARNINGS

#pragma warning(disable : 4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Add CPU hardware definitions

#define __arm__

#define _AVR_IO_H_
#define _SFR_IO8(io_addr) ((io_addr))

#define boolean bool


#define DEC 10
#define HEX 16
#define OCT 8
#define BIN 2
#define BYTE 0

// From "c:\program files\arduino\hardware\cores\arduino\wiring.h"

#define HIGH 0x1
#define LOW  0x0

#define INPUT 0x0
#define OUTPUT 0x1

#define PI 3.14159265
#define HALF_PI 1.57079
#define TWO_PI 6.283185
#define DEG_TO_RAD 0.01745329
#define RAD_TO_DEG 57.2957786

#define SERIAL  0x0
#define DISPLAY 0x1

#define LSBFIRST 0
#define MSBFIRST 1

#define CHANGE 1
#define FALLING 2
#define RISING 3

#define INTERNAL 3
#define DEFAULT 1
#define EXTERNAL 0

/*
* Analog pins
*/
#define  A0  54
#define  A1  55
#define  A2  56
#define  A3  57
#define  A4  58
#define  A5  59
#define  A6  60
#define  A7  61
#define  A8  62
#define  A9  63
#define  A10  64
#define  A11  65
#define  DAC0  66
#define  DAC1  67
#define  CANRX  68
#define  CANTX  69


class CSerial
{
public:
	void begin(long);

	void print(char*);
	void print(int, int);

	void println();
	void println(char*);
	void println(int, int);
	void println(unsigned int, int);
	void println(unsigned long, int);
	int available();
	char read();

	// VSPDE
	void _append(char c);
private:
	char buffer[1024];
	int buflen;
};

extern CSerial Serial;
extern unsigned long millis();
extern void delay(unsigned long);
extern void pinMode(int, int);
extern void digitalWrite(int, int);
extern void analogWrite(int, int);
extern bool digitalRead(int);
extern int analogRead(int);

typedef unsigned int       uint32_t;
typedef volatile       uint32_t WoReg; /**< Write only 32-bit register (volatile unsigned int) */
typedef volatile       uint32_t RwReg; /**< Read-Write 32-bit register (volatile unsigned int) */
typedef volatile       uint32_t RoReg; /**< Read only 32-bit register (volatile const unsigned int) */

typedef struct {
	RwReg      TC_CCR;        /**< \brief (TcChannel Offset: 0x0) Channel Control Register */
	RwReg      TC_CMR;        /**< \brief (TcChannel Offset: 0x4) Channel Mode Register */
	RwReg      TC_SMMR;       /**< \brief (TcChannel Offset: 0x8) Stepper Motor Mode Register */
	RoReg      Reserved1[1];
	RwReg      TC_CV;         /**< \brief (TcChannel Offset: 0x10) Counter Value */
	RwReg      TC_RA;         /**< \brief (TcChannel Offset: 0x14) Register A */
	RwReg      TC_RB;         /**< \brief (TcChannel Offset: 0x18) Register B */
	RwReg      TC_RC;         /**< \brief (TcChannel Offset: 0x1C) Register C */
	RwReg      TC_SR;         /**< \brief (TcChannel Offset: 0x20) Status Register */
	RwReg      TC_IER;        /**< \brief (TcChannel Offset: 0x24) Interrupt Enable Register */
	RwReg      TC_IDR;        /**< \brief (TcChannel Offset: 0x28) Interrupt Disable Register */
	RwReg      TC_IMR;        /**< \brief (TcChannel Offset: 0x2C) Interrupt Mask Register */
	RoReg      Reserved2[4];
} TcChannel;

#define TCCHANNEL_NUMBER 3

typedef struct {
	TcChannel  TC_CHANNEL[TCCHANNEL_NUMBER]; /**< \brief (Tc Offset: 0x0) channel = 0 .. 2 */
	WoReg      TC_BCR;        /**< \brief (Tc Offset: 0xC0) Block Control Register */
	RwReg      TC_BMR;        /**< \brief (Tc Offset: 0xC4) Block Mode Register */
	WoReg      TC_QIER;       /**< \brief (Tc Offset: 0xC8) QDEC Interrupt Enable Register */
	WoReg      TC_QIDR;       /**< \brief (Tc Offset: 0xCC) QDEC Interrupt Disable Register */
	RoReg      TC_QIMR;       /**< \brief (Tc Offset: 0xD0) QDEC Interrupt Mask Register */
	RoReg      TC_QISR;       /**< \brief (Tc Offset: 0xD4) QDEC Interrupt Status Register */
	RwReg      TC_FMR;        /**< \brief (Tc Offset: 0xD8) Fault Mode Register */
	RoReg      Reserved1[2];
	RwReg      TC_WPMR;       /**< \brief (Tc Offset: 0xE4) Write Protect Mode Register */
} Tc;

typedef enum IRQn
{
	/******  Cortex-M3 Processor Exceptions Numbers ******************************/
	NonMaskableInt_IRQn = -14, /**<  2 Non Maskable Interrupt                */
	MemoryManagement_IRQn = -12, /**<  4 Cortex-M3 Memory Management Interrupt */
	BusFault_IRQn = -11, /**<  5 Cortex-M3 Bus Fault Interrupt         */
	UsageFault_IRQn = -10, /**<  6 Cortex-M3 Usage Fault Interrupt       */
	SVCall_IRQn = -5,  /**< 11 Cortex-M3 SV Call Interrupt           */
	DebugMonitor_IRQn = -4,  /**< 12 Cortex-M3 Debug Monitor Interrupt     */
	PendSV_IRQn = -2,  /**< 14 Cortex-M3 Pend SV Interrupt           */
	SysTick_IRQn = -1,  /**< 15 Cortex-M3 System Tick Interrupt       */
						/******  SAM3X8E specific Interrupt Numbers *********************************/

						SUPC_IRQn = 0, /**<  0 SAM3X8E Supply Controller (SUPC) */
						RSTC_IRQn = 1, /**<  1 SAM3X8E Reset Controller (RSTC) */
						RTC_IRQn = 2, /**<  2 SAM3X8E Real Time Clock (RTC) */
						RTT_IRQn = 3, /**<  3 SAM3X8E Real Time Timer (RTT) */
						WDT_IRQn = 4, /**<  4 SAM3X8E Watchdog Timer (WDT) */
						PMC_IRQn = 5, /**<  5 SAM3X8E Power Management Controller (PMC) */
						EFC0_IRQn = 6, /**<  6 SAM3X8E Enhanced Flash Controller 0 (EFC0) */
						EFC1_IRQn = 7, /**<  7 SAM3X8E Enhanced Flash Controller 1 (EFC1) */
						UART_IRQn = 8, /**<  8 SAM3X8E Universal Asynchronous Receiver Transceiver (UART) */
						SMC_IRQn = 9, /**<  9 SAM3X8E Static Memory Controller (SMC) */
						PIOA_IRQn = 11, /**< 11 SAM3X8E Parallel I/O Controller A, (PIOA) */
						PIOB_IRQn = 12, /**< 12 SAM3X8E Parallel I/O Controller B (PIOB) */
						PIOC_IRQn = 13, /**< 13 SAM3X8E Parallel I/O Controller C (PIOC) */
						PIOD_IRQn = 14, /**< 14 SAM3X8E Parallel I/O Controller D (PIOD) */
						USART0_IRQn = 17, /**< 17 SAM3X8E USART 0 (USART0) */
						USART1_IRQn = 18, /**< 18 SAM3X8E USART 1 (USART1) */
						USART2_IRQn = 19, /**< 19 SAM3X8E USART 2 (USART2) */
						USART3_IRQn = 20, /**< 20 SAM3X8E USART 3 (USART3) */
						HSMCI_IRQn = 21, /**< 21 SAM3X8E Multimedia Card Interface (HSMCI) */
						TWI0_IRQn = 22, /**< 22 SAM3X8E Two-Wire Interface 0 (TWI0) */
						TWI1_IRQn = 23, /**< 23 SAM3X8E Two-Wire Interface 1 (TWI1) */
						SPI0_IRQn = 24, /**< 24 SAM3X8E Serial Peripheral Interface (SPI0) */
						SSC_IRQn = 26, /**< 26 SAM3X8E Synchronous Serial Controller (SSC) */
						TC0_IRQn = 27, /**< 27 SAM3X8E Timer Counter 0 (TC0) */
						TC1_IRQn = 28, /**< 28 SAM3X8E Timer Counter 1 (TC1) */
						TC2_IRQn = 29, /**< 29 SAM3X8E Timer Counter 2 (TC2) */
						TC3_IRQn = 30, /**< 30 SAM3X8E Timer Counter 3 (TC3) */
						TC4_IRQn = 31, /**< 31 SAM3X8E Timer Counter 4 (TC4) */
						TC5_IRQn = 32, /**< 32 SAM3X8E Timer Counter 5 (TC5) */
						TC6_IRQn = 33, /**< 33 SAM3X8E Timer Counter 6 (TC6) */
						TC7_IRQn = 34, /**< 34 SAM3X8E Timer Counter 7 (TC7) */
						TC8_IRQn = 35, /**< 35 SAM3X8E Timer Counter 8 (TC8) */
						PWM_IRQn = 36, /**< 36 SAM3X8E Pulse Width Modulation Controller (PWM) */
						ADC_IRQn = 37, /**< 37 SAM3X8E ADC Controller (ADC) */
						DACC_IRQn = 38, /**< 38 SAM3X8E DAC Controller (DACC) */
						DMAC_IRQn = 39, /**< 39 SAM3X8E DMA Controller (DMAC) */
						UOTGHS_IRQn = 40, /**< 40 SAM3X8E USB OTG High Speed (UOTGHS) */
						TRNG_IRQn = 41, /**< 41 SAM3X8E True Random Number Generator (TRNG) */
						EMAC_IRQn = 42, /**< 42 SAM3X8E Ethernet MAC (EMAC) */
						CAN0_IRQn = 43, /**< 43 SAM3X8E CAN Controller 0 (CAN0) */
						CAN1_IRQn = 44, /**< 44 SAM3X8E CAN Controller 1 (CAN1) */

						PERIPH_COUNT_IRQn = 45  /**< Number of peripheral IDs */
} IRQn_Type;

#endif
#endif

