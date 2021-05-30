 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: uart.h
 *
 * Description: Header file for the UART AVR driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#ifndef UART_H_
#define UART_H_

#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"
 typedef enum
{
	pooling,interrupt
}Usart_mode;
// to determine use pooling or interrupt
typedef enum
{
Buad_rate ,control_statue
}Register_select; // to select register UCSRC or UBRRH
typedef enum
{
	One_bit,Two_bit
}Stop_bit_select;
typedef enum
{
	Failing_edge,Rising_edge
}Clock_polarity;

typedef enum
{
	Disabled,Reserved,Even_parity,Odd_pairty
}Parity_mode;
typedef enum{
	five_bit,six_bit,seven_bit,eight_bit,nine_bit,Reserved_bit
} Charatersize;
typedef enum{
	Asynchronous_operation,synchronous_operation
}Mode_select;
typedef enum {
	high,low
}Rate_register;// to select UBRRH or UBRRL
typedef enum{
	normal_speed ,Double_speed
}Usart_speed;
typedef struct{
	Usart_mode mode;
	Mode_select select;
	Stop_bit_select stop;
	Clock_polarity clock;
	Parity_mode Parity;
	Charatersize size;
	Usart_speed speed;

}UART_ConfigType;
extern   UART_ConfigType UART_config;


/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/* UART Driver Baud Rate */
#define USART_BAUDRATE 9600

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void UART_init(void);
void UART_init2(UART_ConfigType * config_ptr);
void UART_sendByte(const uint8 data);

uint8 UART_recieveByte(void);

void UART_sendString(const uint8 *Str);

void UART_receiveString(uint8 *Str); // Receive until #

#endif /* UART_H_ */
