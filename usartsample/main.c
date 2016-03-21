/*
 * usartsample.c
 *
 * Created: 2016/03/19 12:25:52
 * Author : hirokazu
 */ 

#include <stdio.h>
#include <avr/io.h>
#include "usart.h"


int main(void) {
    USART_init(NOMAL, 51);
    fdevopen(*USART_sendData, NULL);
    printf("Enter>>\n");
    while (1) {
        uint8_t val = USART_recieveData();
        printf("%d\n", val);
    }
}

