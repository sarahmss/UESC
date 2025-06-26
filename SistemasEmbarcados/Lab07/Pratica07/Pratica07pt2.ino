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
#define INPUT_PIN0 (1 << PC0)    // Pin A0 == ADC0
#define INPUT_PIN1 (1 << PC1)    // Pin A0 == ADC1

volatile uint8_t currentChannel = 0;  // 0 para A0, 1 para A1
volatile uint16_t valorTensao = 0;
volatile uint16_t valorNTC = 0;

void Conf125kHz(){
 // ADPS2:0 = 0x000: ADC Prescaler Selection (Df = 128) 
  // f_conv = f_clk/Df ; 
  // Set ADC prescalar to 128 → 16 MHz / 128 = 125 kHz
  ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); 
}

void setup() {
  cli();

  DDRC &= ~INPUT_PIN1;
  PORTC |= INPUT_PIN1;

  DDRC &= ~INPUT_PIN0;
  PORTC |= INPUT_PIN0;

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
  // REFS1:0 = (0x11): Tensão de referência == (tensão interna do arduino 1.1V)
  ADMUX |= (1 << REFS0); 
  ADMUX |= (1 << REFS1); 

  // MUX3:0 = (0x000): Define a entrada única ADC0
  ADMUX &= ~(1 << MUX0);
  ADMUX &= ~(1 << MUX1);
  ADMUX &= ~(1 << MUX2);
  ADMUX &= ~(1 << MUX3);

  //ADLAR = (0x1): Left adjust ADC result to allow easy 10 bit reading
  ADMUX |= (1 << ADLAR);

  Conf125kHz();

  Serial.begin(9600);
  sei();
}


ISR(ADC_VECT){
  //  ??
  //TIFR1 = (1 << OCF1A);

  // Averigua o fim da conversão (ADSC != 0)
  //while(ADCSRA & (1 << ADSC));

  // Lê valor do ADC (10 bits)
  uint16_t valor = ADCL | (ADCH << 8);

  if (currentChannel == 0) {
    valorTensao = valor;
    Serial.print("Tensao:");
    Serial.print(valorTensao);
    Serial.print(",");
  } else {
    valorNTC = valor;
    Serial.print("NTC:");
    Serial.print(valorNTC);
    Serial.print("\n");
  }

  samples++;
  if (samples >= 10000) {
    // Parar conversão após 10 mil amostras
    ADCSRA &= ~(1 << ADIE);  // Desabilita interrupção ADC
  }

  // Alterna o canal no ADMUX
  currentChannel = !currentChannel;
  if (currentChannel == 0) {
    ADMUX &= ~(1 << MUX0); // Seleciona ADC0 (A0)
  } else {
    ADMUX |= (1 << MUX0);  // Seleciona ADC1 (A1)
  }

  // Inicia a próxima conversão manualmente
  ADCSRA |= (1 << ADSC);
}


void loop() {

}