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

#include <stdint.h>

# define OUTPUT_PIN_T1 (1 << PB2)      // Pin 10 (PB2 == OC1B)
# define OUTPUT_PIN_T0 (1 << PD5)      // Pin 11 (PD5 == OC0B)
# define OUTPUT_PIN_T2 (1 << PD3)      // Pin 3  (PD3 == OC2B)

# define TOP        57             // (TOP + 1) = f_clk / (N * f_pwm) = 16e6/(8 * 35*10^3)
# define LENGTH     583
# define N0         194
# define N2         388
const uint8_t amostras[583] = { 29, 29, 29, 29, 30, 30, 30, 31, 31, 31, 32, 32, 32, 32, 33, 33, 33, 34, 34, 34, 35, 35, 35, 36, 36, 36, 36, 37, 37, 37, 38, 38, 38, 38, 39, 39, 39, 40, 40, 40, 40, 41, 41, 41, 42, 42, 42, 42, 43, 43, 43, 43, 44, 44, 44, 44, 45, 45, 45, 45, 46, 46, 46, 46, 47, 47, 47, 47, 48, 48, 48, 48, 48, 49, 49, 49, 49, 50, 50, 50, 50, 50, 51, 51, 51, 51, 51, 52, 52, 52, 52, 52, 52, 53, 53, 53, 53, 53, 53, 53, 54, 54, 54, 54, 54, 54, 54, 55, 55, 55, 55, 55, 55, 55, 55, 55, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 55, 55, 55, 55, 55, 55, 55, 55, 55, 54, 54, 54, 54, 54, 54, 54, 53, 53, 53, 53, 53, 53, 53, 52, 52, 52, 52, 52, 52, 51, 51, 51, 51, 51, 50, 50, 50, 50, 50, 49, 49, 49, 49, 48, 48, 48, 48, 48, 47, 47, 47, 47, 46, 46, 46, 46, 45, 45, 45, 45, 44, 44, 44, 44, 43, 43, 43, 43, 42, 42, 42, 42, 41, 41, 41, 40, 40, 40, 40, 39, 39, 39, 38, 38, 38, 38, 37, 37, 37, 36, 36, 36, 36, 35, 35, 35, 34, 34, 34, 33, 33, 33, 32, 32, 32, 32, 31, 31, 31, 30, 30, 30, 29, 29, 29, 29, 28, 28, 28, 27, 27, 27, 26, 26, 26, 25, 25, 25, 25, 24, 24, 24, 23, 23, 23, 22, 22, 22, 21, 21, 21, 21, 20, 20, 20, 19, 19, 19, 19, 18, 18, 18, 17, 17, 17, 17, 16, 16, 16, 15, 15, 15, 15, 14, 14, 14, 14, 13, 13, 13, 13, 12, 12, 12, 12, 11, 11, 11, 11, 10, 10, 10, 10, 9, 9, 9, 9, 9, 8, 8, 8, 8, 7, 7, 7, 7, 7, 6, 6, 6, 6, 6, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 9, 9, 10, 10, 10, 10, 11, 11, 11, 11, 12, 12, 12, 12, 13, 13, 13, 13, 14, 14, 14, 14, 15, 15, 15, 15, 16, 16, 16, 17, 17, 17, 17, 18, 18, 18, 19, 19, 19, 19, 20, 20, 20, 21, 21, 21, 21, 22, 22, 22, 23, 23, 23, 24, 24, 24, 25, 25, 25, 25, 26, 26, 26, 27, 27, 27, 28, 28, 28, 29 };

// ================================= Temporizador 1 - Fast PWM (0°) =================================
// F_pwm = F_clk/(N * (TOP + 1)) ; F_clk = 16 MHz   

void    ConfTimer1(){
    DDRB |= OUTPUT_PIN_T1;
    PORTB &= ~OUTPUT_PIN_T1;

    // TCNTn: Timer/Counter register
    TCNT1 = 0;
    OCR1A = 0;
    OCR1B = 0;
    TCCR1A = 0;
    TCCR1B = 0;

    // TCCRnX: Timer/Counter Control Register 
    // COMBnX: Compare Match Output B Mode 
    // COM1B1:0 = 0b10 (non-inverting mode)
    // OC1B -> store 
    TCCR1A |= (1 << COM1B1);   
    TCCR1A &= ~(1 << COM1B0);    

    // Set interrupt on compare match
    TIMSK1 |= (1 << OCIE1A);

    // WGMn: Waveform Generation Mode bit
    // WGM13:0 = 0b1111 (Fast PWM with OCR1A as TOP)
    TCCR1B |= (1 << WGM13);
    TCCR1B |= (1 << WGM12);
    TCCR1A |= (1 << WGM11); 
    TCCR1A |= (1 << WGM10);

    // CSn: Clock select
    // CS12:0 = 0b010 (Prescaler == 8 -> F_clck / 8) 
    TCCR1B &= ~(1 << CS12);
    TCCR1B |= (1 << CS11); 
    TCCR1B &= ~(1 << CS10);

    // OCRnX: Outupt Compare Register -> stores the compare value
    OCR1A = TOP;
    OCR1B = amostras[0];
}

/*
    @brief: Define a rotina de interrupção para o temporizador que conta 1ms
*/
ISR (TIMER1_COMPA_vect)
{
    static int n0 = N0 + 1;
    static int n1 = 1;
    static int n2 = N2 + 1;

    OCR0B = amostras[n0];
    n0 = n0 < LENGTH - 1 ? (n0 + 1) : 0;

    OCR2B = amostras[n2];
    n2 = n2 < LENGTH - 1 ? (n2 + 1) : 0;
    
    OCR1B = amostras[n1];
    n1 = n1 < LENGTH - 1 ? (n1 + 1) : 0;

}

// ================================= Temporizador 0 - Fast PWM (120°)   =================================

void    ConfTimer0(){
    DDRD |= OUTPUT_PIN_T0;
    PORTD &= ~OUTPUT_PIN_T0;

    // TCNTn: Timer/Counter register
    TCNT0 = 0;
    OCR0A = 0;
    OCR0B = 0;
    TCCR0A = 0;
    TCCR0B = 0;

    // TCCRnX: Timer/Counter Control Register 
    // COMBnX: Compare Match Output B Mode 
    // COM1B1:0 = 0b10 (non-inverting mode)
    // OC1B -> store 
    TCCR0A |= (1 << COM0B1);   
    TCCR0A &= ~(1 << COM0B0);    

    // Set interrupt on compare match
    //TIMSK0 |= (1 << OCIE0A);

    // WGMn: Waveform Generation Mode bit
    // WGM13:0 = 0b111 (Fast PWM with OCR1A as TOP)
    TCCR0B |= (1 << WGM02);
    TCCR0A |= (1 << WGM01); 
    TCCR0A |= (1 << WGM00);

    // CSn: Clock select
    // CS12:0 = 0b010 (Prescaler == 8 -> F_clck / 8) 
    TCCR0B &= ~(1 << CS02) ;
    TCCR0B |= (1 << CS01); 
    TCCR0B &= ~(1 << CS00);

    // OCRnX: Outupt Compare Register -> stores the compare value
    OCR0A = TOP;
    OCR0B = amostras[N0];
}

// ================================= Temporizador 2 - Fast PWM (240°) =================================
void    ConfTimer2(){
    DDRD |= OUTPUT_PIN_T2;
    PORTD &= ~OUTPUT_PIN_T2;

    // TCNTn: Timer/Counter register
    TCNT2 = 0;
    OCR2A = 0;
    OCR2B = 0;
    TCCR2A = 0;
    TCCR2B = 0;

    // TCCRnX: Timer/Counter Control Register 
    // COMBnX: Compare Match Output B Mode 
    // COM1B1:0 = 0b10 (non-inverting mode)
    // OC1B -> store 
    TCCR2A |= (1 << COM2B1);   
    TCCR2A &= ~(1 << COM2B0);    

    // Set interrupt on compare match
    //TIMSK2 |= (1 << OCIE2A);

    // WGMn: Waveform Generation Mode bit
    // WGM23:0 = 0b111 (Fast PWM with OCR1A as TOP)
    TCCR2B |= (1 << WGM22);
    TCCR2A |= (1 << WGM21); 
    TCCR2A |= (1 << WGM20);

    // CSn: Clock select
    // CS22:0 = 0b010 (Prescaler == 8 -> F_clck / 8) 
    TCCR2B &= ~(1 << CS22) ;
    TCCR2B |= (1 << CS21); 
    TCCR2B &= ~(1 << CS20);

    // OCRnX: Outupt Compare Register -> stores the compare value
    OCR2A = TOP;
    OCR2B = amostras[N2];
}



void setup(void){
    cli();
    //Serial.begin(9600);
    ConfTimer2();
    ConfTimer1();
    ConfTimer0();
    sei();
}

void loop(void){
    
}

