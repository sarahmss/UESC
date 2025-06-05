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

#define OUTPUT_PIN_0      (1 << PD5) // Pin 5 (PD5 == OC0B)
#define OUTPUT_PIN_1      (1 << PB2) // Pin 10 (PB2 == OC1B)
#define INPUT_PIN         (1 << PD2) // Pin 2 (PD2 == INT0)

// F_pwm = F_clk/(2N * (TOP + 1)) ; F_clk = 16 MHz   
  

// TOP == 500000 -> F_ctc = 2 Hz
#define TOP_2Hz         62500    

// TOP == 100 -> F_pwm == 20 kHz
#define TOP_1MHz       200     
#define DUTY_CYCLE_50   100

volatile int cycles = 0;  // 

// ========================================================= Temporizador 1 - CTC ================================================


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
}

ISR (TIMER1_COMPA_vect)
{
    PORTB ^= OUTPUT_PIN_1;                // Toggle LED state
}

// ================================================= Detector de Zero ======================================================

void ConfZeroDetector(void)
{
    // set INPUT_PIN as input
    DDRD &= ~INPUT_PIN;

    // Enable External Interrupts in INT0  == Pin 2
    EIMSK |= (1 << INT0);

    // Bits to set mode in INT0 01 = FALLING 
    EICRA &= ~(1 << ISC00);  // Clear ISC00
    EICRA |=  (1 << ISC01);  // Set ISC01
}

/*
  @brief: defines the routine for INT0 interrupt (INPUT_PIN)
*/
ISR(INT0_vect) {
    cycles++; 
}


// ========================================================= Temporizador 0 - CTC ================================================


void ConfTimer0(void){

    // 
    DDRD |= OUTPUT_PIN_0;
    PORTD &= ~OUTPUT_PIN_0;

    // TCNTn: Timer/Counter register ()
    TCNT0 = 0;
    OCR0A = 0;
    OCR0B = 0;
    TCCR0A = 0;
    TCCR0B = 0;

    // OCRnX: Outupt Compare Register ->  stores the compare value
    OCR0A = TOP_1MHz;
    OCR0B = DUTY_CYCLE_50;


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
    TCCR0B &= ~(1 << CS02);

}

void setup(void)
{
    Serial.begin(9600);
    cli();

    ConfZeroDetector();
    ConfTimer1();
    ConfTimer0();
    sei();
}

void loop(void){

}