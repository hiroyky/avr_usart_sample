/*
 * usartsample.c
 *
 * Created: 2016/03/19 12:25:52
 * Author : hirokazu
 */ 

#include <stdio.h>
#include <avr/io.h>
#include "usart.h"


void txEventListener() {
}

void rxEventListener(uint8_t data) {    
    printf("echo back: %d \n", data);
}

int main(void) {
    USART_init(TX_COMPLETION_INTERRUPT | RX_COMPLETION_INTERRUPT, 51);
    USART_setRxCompletionInterruptListener(*rxEventListener);
    fdevopen(*USART_sendData, NULL);
    sei();
    printf("Initialized>>\n");
    while (1) {
    }
}

