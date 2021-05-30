/*
 * Exercise1.c
 *
 * Created: 4/10/2014 9:23:41 PM
 * Author: Mohamed Tarek
 */ 

#include "uart.h"
UART_ConfigType UART_config =
{pooling,Asynchronous_operation,One_bit,Rising_edge,Disabled,eight_bit,Double_speed

};
int main(void)
{
	uint8 Str[20];
	uint8 data;
	//UART_init();
	 UART_init2(&UART_config);
    while(1)
    { 
		data = UART_recieveByte(); //Receive Byte from Terminal1
		UART_sendByte(data); //Resend the received byte to Terminal2
//		UART_receiveString(Str); //Receive String from Terminal
//	    UART_sendString(Str); //Resend the string to Terminal2
    }
}
