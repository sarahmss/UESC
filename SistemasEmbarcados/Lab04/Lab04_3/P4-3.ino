/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lab04_3.ino                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:21:55 by smodesto          #+#    #+#             */
/*   Updated: 2025/05/01 20:21:55 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <avr/io.h>
#include <avr/interrupt.h>

#define OUTPUT_PIN      (1 << PB2) // Pin  10 (PB2 == OC1B)
#define INPUT_PIN       (1 << PD2)  // pin 2 (PD2 == INT0)

// F_pwm = F_clk/(2N * (TOP + 1)) ; F_clk = 16 MHz   
  

// TOP == 500000 -> F_pwm == 2 Hz
#define TOP_2Hz         62500     

volatile int cycles = 0;  // 


void setup(void)
{
    Serial.begin(9600);
    cli();
// ================================== Detector de Zero ================================
    // set INPUT_PIN as input
    DDRD &= ~INPUT_PIN;

    // Enable External Interrupts in INT0  == Pin 2
    EIMSK |= (1 << INT0);

    // Bits to set mode in INT0 01 = FALLING 
    EICRA &= ~(1 << ISC00);  // Clear ISC00
    EICRA |=  (1 << ISC01);  // Set ISC01


// ================================== Temporizador ====================================
    // 
    DDRB |= OUTPUT_PIN;
    PORTB &= ~OUTPUT_PIN;

    // TCNTn: Timer/Counter register ()
    TCNT1 = 0;
    OCR1A = 0;
    TCCR1A = 0;
    TCCR1B = 0;
    TIMSK1 = 0;

    // OCRnX: Outupt Compare Register ->  stores the compare value
    OCR1A = TOP_2Hz;

    // COMBnX: Compare Match Output B Mode 
    // COM1B1:0 = 0b10 (non-inverting mode - HIGH at bottom, LOW on Match)
    // OC1B -> store
    TCCR1A &= ~(1 << COM1A1);    
    TCCR1A &= ~(1 << COM1A0);    

    // TCCRnX: Timer/Counter Control Register 


    // WGMn: Waveform Generation Mode bit
    // WGM03:0 = 0b0100 (CTC with OCR1A as TOP)
    TCCR1B &= ~ (1 << WGM13); 
    TCCR1B |= (1 << WGM12);
    TCCR1A &= ~ (1 << WGM11); 
    TCCR1A &= ~ (1 << WGM10); 


    // Set interrupt on compare match
    TIMSK1 |= (1 << OCIE1A);


    // CSn: Clock select
    // CS12:0 = 0b011 (Prescaler == 64 -> F_clck / 64) 
    TCCR1B &= ~(1 << CS12);
    TCCR1B |= (1 << CS11); 
    TCCR1B |= (1 << CS10); 

    sei();
}

ISR (TIMER1_COMPA_vect)
{
    PORTB ^= OUTPUT_PIN;                // Toggle LED state
    Serial.print("Quantidade de ciclos: ");
    Serial.println(cycles);
    cycles = 0;
  }
/*
  @brief: defines the routine for INT0 interrupt (INPUT_PIN)
*/
ISR(INT0_vect) {
    cycles++; 
}

void loop(void){

}