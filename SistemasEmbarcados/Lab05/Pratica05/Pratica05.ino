/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pratica05.ino                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 09:14:50 by smodesto          #+#    #+#             */
/*   Updated: 2025/05/21 09:14:50 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Pratica05.h"

/******************************************************************************/

#define OUTPUT_PIN_0      (1 << PD5) // Pin 5 (PD5 == OC0B)
#define OUTPUT_PIN_1      (1 << PB2) // Pin 10 (PB2 == OC1B)
#define TOP_1ms           1000       // 1ms --- 1000Hz
#define F_CLK             16000000


static unsigned int duracao[] = {15, 5, 15, 7, 30, 15, 30, 30, 30, 30, 30, 30, 15, 30, 15, 30, 15, 30, 30, 15, 30, 22, 15, 15,
30, 15, 30, 30, 15, 15, 30, 15, 30, 15, 30, 15, 30, 15, 30, 30, 15, 30, 22, 15, 15, 30, 15, 30, 30, 15, 15, 30, 30, 15,
15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 30, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 30, 15, 15, 15, 15, 15, 15,
15, 15, 15, 15, 15, 15, 15, 15, 30, 15, 30, 15, 30, 15}; //em milissegundos.

static unsigned int nota[] = {E2, silen, E2, silen, E2, C2, E2, G2, silen, G, silen, C2, silen, G, silen, E, silen, A, B, AS, A, G,
E2, G2, A2, F2, G2, E2, C2, D2, B, silen, C2, silen, G, silen, E, silen, A, B, AS, A, G, E2, G2, A2, F2, G2, E2, C2, D2, B,
silen, G2, F2S, F2, D2S, silen, E2, silen, G2, A, C2, silen, A, C2, D2, silen, G2, F2S, F2, D2S, silen, E2, silen, C3, silen,
C3, C3, silen, G2, F2S, F2, D2S, silen, E2, silen, GS, A, C2, silen, A, C2, D2, silen, D2S, silen, D2, silen, C2};

#define LENGTH (sizeof(duracao) / sizeof(duracao[0])) - 1

void PrintOut(uint8_t period, uint8_t times, uint8_t n, int nota){
    Serial.print("Periodo = ");
    Serial.print(period);
    Serial.print(" | time = ");
    Serial.print(times);
    Serial.print(" | n = ");
    Serial.print(n);
    Serial.print(" | Nota = ");
    Serial.println(nota);
}

/*************************************** Temporizador 1 - CTC (1ms) ********************************/

void ConfTimer1(void)
{
    DDRB |= OUTPUT_PIN_1;
    PORTB &= ~OUTPUT_PIN_1;

    // TCNTn: Timer/Counter register ()
    TCNT1 = 0;
    OCR1A = 0;
    TCCR1A = 0;
    TCCR1B = 0;
    TIMSK1 = 0;

    // OCRnX: Outupt Compare Register ->  stores the compare value
    OCR1A = TOP_1ms; 

    // COMBnX: Compare Match Output B Mode 
    // COM1B1:0 = 0b10 (non-inverting mode - HIGH at bottom, LOW on Match)
    // OC1B -> store
    TCCR1A &= ~(1 << COM1A1);    
    TCCR1A &= ~(1 << COM1A0);    

    // TCCRnX: Timer/Counter Control Register 

    // WGMn: Waveform Generation Mode bit
    // WGM13:0 = 0b0100 (CTC with OCR0A as TOP)
    TCCR1B &= ~ (1 << WGM13); 
    TCCR1B |= (1 << WGM12);
    TCCR1A &= ~ (1 << WGM11); 
    TCCR1A &= ~ (1 << WGM10); 


    // Set interrupt on compare match
    TIMSK1 |= (1 << OCIE1A);

    // CSn: Clock select
    // CS12:0 = 0b010 (Prescaler == 8 -> F_clck / 8) 
    TCCR1B &= ~(1 << CS12);
    TCCR1B |= (1 << CS11); 
    TCCR1B &= ~(1 << CS10); 
}

/*
    @brief: Define a rotina de interrupção para o temporizador que conta 1ms
*/
ISR (TIMER1_COMPA_vect)
{
    static uint8_t  n = -1;  
    static uint8_t  times = 0;  
    static uint8_t  period = 0;  

    PORTB ^= OUTPUT_PIN_1;
    
    if (times == period){
      n = n < LENGTH ? (n + 1) : 0;
      
      period = duracao[n];
      ConfTimer0(nota[n]);

      times = 0;
    }  
    times++;
    PrintOut(period, times, n, nota[n]);
}

// ========================================================= Temporizador 0 - PWM (f_var) ================================================
// F_pwm = F_clk/(N * (TOP + 1)) ; F_clk = 16 MHz   

void    ConfTimer0(int f_pwm){
    DDRD |= OUTPUT_PIN_0;
    PORTD &= ~OUTPUT_PIN_0;

    // TCNTn: Timer/Counter register ()
    TCNT0 = 0;
    OCR0A = 0;
    OCR0B = 0;
    TCCR0A = 0;
    TCCR0B = 0;

    int top = F_CLK / (8 * f_pwm);
    int duty_cycle = top / 2;
    // OCRnX: Outupt Compare Register ->  stores the compare value
    OCR0A = top;
    OCR0B = duty_cycle;


    // TCCRnX: Timer/Counter Control Register 

    // COMBnX: Compare Match Output B Mode 
    // COM0B1:0 = 0b10 (non-inverting mode - HIGH at bottom, LOW on Match)
    // OC0B -> store
    TCCR0A |= (1 << COM0B1);   
    TCCR0A &= ~(1 << COM0B0);    
    // WGMn: Waveform Generation Mode bit
    // WGM02:0 = 0b111 (Fast PWM with OCR0A as TOP)
    TCCR0B |= (1 << WGM02);
    TCCR0A &= ~ (1 << WGM01); 
    TCCR0A |= (1 << WGM00);

    // CSn: Clock select
    // CS02:0 = 0b010 (Prescaler == 8 -> F_clck / 8) 
    TCCR0B &= ~(1 << CS00);
    TCCR0B |= (1 << CS01); 
    TCCR0B &= ~(1 << CS02) ;
}

void setup(void){
  cli();
  ConfTimer1();
  Serial.begin(9600);
  sei();
}

void loop(void){

}