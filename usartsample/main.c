/*
 * usartsample.c
 *
 * Created: 2016/03/19 12:25:52
 * Author : hirokazu
 */ 

#include <stdio.h>
#include <avr/io.h>
#include "usart.h"

uint16_t count = 0;

void rxEventListener(uint8_t data) {
    
    if(data == '1') {
        printf("%d\n", count);
    }
}

int main(void) {
    USART_init(TX_COMPLETION_INTERRUPT | RX_COMPLETION_INTERRUPT, 51);
    USART_setRxCompletionInterruptListener(*rxEventListener);
    fdevopen(*USART_sendData, NULL);

    // タイマの初期化
    TCCR1A = 0;
    TCCR1B = (1<<WGM12)|(1<<CS12);    //クロックの分周指定(256分周),CTC動作指定
    TCCR1C = 0;
    TIMSK1 = (1<<OCIE1A);    //A比較一致割り込み許可
    OCR1A  = 1000;        //カウントクロック数(比較一致)

    sei();
    printf("Initialized>>\n");
    while (1) {        
    }
}

ISR(TIMER1_COMPA_vect) {
    if(count == 65535) {
        count = 0;
    }
    count++;    
}