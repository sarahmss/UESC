/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pratica07.ino                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:28:12 by smodesto          #+#    #+#             */
/*   Updated: 2025/06/25 16:28:12 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <avr/io.h>
#define INPUT_PIN (1 << PC0)    // Pin A0 == ADC0

volatile uint16_t ADCValue  = 0;
volatile uint16_t samples = 0;

void Conf2MHz(){
 // ADPS2:0 = 0x101: ADC Prescaler Selection (Df = 8) 
  // f_conv = f_clk/Df ; 
  // Set ADC prescalar to 8 → 16 MHz / 8 = 2 MHz
  ADCSRA &= ~(1 << ADPS2);
  ADCSRA &= ~(1 << ADPS1); 
  ADCSRA |= (1 << ADPS0); 
}

void Conf125kHz(){
 // ADPS2:0 = 0x000: ADC Prescaler Selection (Df = 128) 
  // f_conv = f_clk/Df ; 
  // Set ADC prescalar to 128 → 16 MHz / 128 = 125 kHz
  ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); 
}

void Conf500kHz(){
 // ADPS2:0 = 0x101: ADC Prescaler Selection (Df = 32) 
  // f_conv = f_clk/Df ; 
  // Set ADC prescalar to 32 → 16 MHz / 32 = 500 kHz
  ADCSRA |= (1 << ADPS2);
  ADCSRA &= ~(1 << ADPS1); 
  ADCSRA |= (1 << ADPS0); 
}

void setup() {
  cli();

  DDRC &= ~INPUT_PIN;
  PORTC |= INPUT_PIN;

  // ADCSRA: Registrador de Controle e status
  // ADEN: Enable ADC bit
  ADCSRA |= (1 << ADEN); 

  // ADC conversion complete Interrupt is activated 
  // ADIE: Enable ADC interrupt bit 
  ADCSRA |= (1 << ADIE); 

  // Auto Trigger Enable (modo contínuo)
  // ADATE: ADC Auto Trigger Enable
  ADCSRA |= (1 << ADATE);

  // Start A2D Conversions 
  ADCSRA |= (1 << ADSC); 

  // Seleciona trigger como "Free Running Mode"
  ADCSRB &= ~(1 << ADTS2);
  ADCSRB &= ~(1 << ADTS1);
  ADCSRB &= ~(1 << ADTS0);

  // ADMUXn: Registrador de seleção e multiplexação
  // REFS1:0 = (0x01): Tensão de referência == AVCC (tensão interna do arduino)
  ADMUX |= (1 << REFS0); 
  ADMUX &= ~(1 << REFS1); 

  //ADLAR = (0x1): Left adjust ADC result to allow easy 10 bit reading
  ADMUX |= (1 << ADLAR);

  // MUX3:0 = (0x000): Define a entrada única ADC0
  ADMUX &= ~(1 << MUX0);
  ADMUX &= ~(1 << MUX1);
  ADMUX &= ~(1 << MUX2);
  ADMUX &= ~(1 << MUX3);

  Conf125kHz();
//   Conf500kHz();
//   Conf2MHz();


  Serial.begin(9600);
  sei();
}


ISR(ADC_VECT){
  TIFR1 = (1 << OCF1A);

  // Lê valor de 10 bits  
  ADCValue = ADC; 

  // Lê valor de 8 bits  
  //   ADCValue = ADCH; 

  if (samples < 5000){
    Serial.print(ADCValue);
    Serial.print("|");
    Serial.print(ADCValue * 1024 / 5);
    Serial.print(",");
  }
  else {
    ADCSRA &= ~(1 << ADIE); // Desabilita a conversao AD
  }
  samples++;
}


void loop() {

}