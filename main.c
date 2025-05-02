//Programação do Semáforo com Pedestre

#define F_CPU   16000000

#include <util/delay.h>
#include <avr/io.h>

#define VDS_OFF PORTB &= ~(1<<5) //Verde semaforo
#define AS_OFF PORTB &= ~(1<<4)  //Amarelo semaforo
#define VMS_OFF PORTB &= ~(1<<3) //Vermelho semaforo

#define VDS_ON PORTB |= (1<<5) 
#define AS_ON PORTB |= (1<<4)
#define VMS_ON PORTB |= (1<<3)

#define VDP_OFF PORTB &= ~(1<<2) //Verde pedestre
#define VMP_OFF PORTB &= ~(1<<1) //Vermelho pedestre

#define VDP_ON PORTB |= (1<<2)
#define VMP_ON PORTB |= (1<<1)


char bp(void)
{
    return ( (PINB & (1<<0) ? 0 : 1 ) ); // Considerando botão com pull-up interno e pressionado = LOW
}

int main(void)
{
    int tempo = 0;

    // Configuração dos pinos como saída ou entrada
    DDRB |= (1<<1) | (1<<2) | (1<<3) | (1<<4) | (1<<5); // Saídas
    DDRB &= ~(1<<0); // Pino do botão como entrada

    // Habilita pull-up interno para botão
    PORTB |= (1<<0);

    while(1)
    {
        _delay_ms(1);
        tempo++;

        if(tempo >= 60000)
        {
            tempo = 0;
        }

        VDS_OFF; AS_OFF; VMS_OFF;
        VDP_OFF; VMP_OFF;

        if(tempo < 42000)
        {
            if(bp() && tempo < 32000)
            {
                tempo = 32000;
            }
            VDS_ON;
            VMP_ON;

            AS_OFF;
            VMS_OFF;
            VDP_OFF;
        }
        else if (tempo < 47000)
        {
            AS_ON;
            VMP_ON;

            VDS_OFF;
            VMS_OFF;
            VDP_OFF;
        }
        else 
        {
            VMS_ON;
            VDP_ON;

            VDS_OFF;
            AS_OFF;
            VMP_OFF;
        }
    }
}
