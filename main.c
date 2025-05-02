//Programação do Semáforo com Pedestre

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

// Entradas
// Botão para pedestres - PB0

// Saídas
// Semáforo verde - PB1, Semáforo Amarelo - PB2, Semáforo Vermelho - PB3 
// Pedestre verde - PB4, Pedestre Vermelho - PB5

int main(void){  

    unsigned long tempo = 0;

    DDRB &= ~(1<<0);
    PORTB |= (1<<0);

    DDRB |= (1<<1);
    DDRB |= (1<<2);
    DDRB |= (1<<3);
    DDRB |= (1<<4);
    DDRB |= (1<<5);

    while (1){
        _delay_ms(1);
        tempo++;

        if((!(PINB & (1<<PINB0))) && (tempo<=32000)){
            tempo = 32000;
        }

        if(tempo<=42000){
            PORTB &= ~(1<<2);
            PORTB &= ~(1<<3);
            PORTB |= (1<<1);
            PORTB &= ~(1<<4);
            PORTB |= (1<<5);
        }else if(tempo<=45000){
            PORTB &= ~(1<<1);
            PORTB &= ~(1<<3);
            PORTB |= (1<<2);
        }else if(tempo<=57000){
            PORTB &= ~(1<<1);
            PORTB &= ~(1<<2);
            PORTB |= (1<<3);
            PORTB &= ~(1<<5);
            PORTB |= (1<<4);
        }else if(tempo<=60000){
            PORTB &= ~(1<<4);
            PORTB |= (1<<5);
            _delay_ms(500);
            PORTB &= ~(1<<5);
            _delay_ms(500);
            PORTB |= (1<<5);
            _delay_ms(500);
            PORTB &= ~(1<<5);
            _delay_ms(500);
            PORTB |= (1<<5);
            _delay_ms(500);
            PORTB &= ~(1<<5);
            _delay_ms(500);
            tempo = 0;        
        }

    }
}
