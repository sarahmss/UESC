/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pratica08.ino                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 21:54:07 by smodesto          #+#    #+#             */
/*   Updated: 2025/07/02 21:54:07 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define fclock 16000000 //clock do microcontrolador;
#define BAUD 500000
#define BRR ((fclock/(16UL*BAUD))-1)
#define NL 0xA //Nova linha


#define INPUT_PIN (1 << PC0)    // Pin A0 == ADC0

volatile uint16_t ADCValue  = 0;
volatile uint16_t samples = 0;

/************************************* ADC (20k amostras/s) *********************************************/
void ConfADC(void){
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

    // ADPS2:0 = 0x011: ADC Prescaler Selection (Df = 8) 
    // f_conv = f_clk/Df ; 
    // Set ADC prescalar to 128 → 160 kHz / 8 = 20 kHz
    // ADCSRA &= ~(1 << ADPS2);
    // ADCSRA |= (1 << ADPS1); 
    // ADCSRA |= (1 << ADPS0); 


    // ADPS2:0 = 0x110: ADC Prescaler Selection (Df = 64) 
    // f_conv = f_clk/Df ; 
    // Set ADC prescalar to 64 → 16 MHz / 64 = 250 kHz
    // 250kHz / 13 ciclos = 19.230 amostras/seg
    ADCSRA |= (1 << ADPS2);
    ADCSRA |= (1 << ADPS1); 
    ADCSRA &= ~(1 << ADPS0); 
}

ISR(ADC_VECT){
  TIFR1 = (1 << OCF1A);

  // Lê valor de 10 bits  
  ADCValue = ADC; 

  // Lê valor de 8 bits  
  //   ADCValue = ADCH; 

  Serial.println(ADCValue);

}

/************************************* USART (BRR = 500k)*********************************************/

ISR (USART_RX_vect)
{
    ReceivedChar = UDR0;                       // Read data from the RX buffer
    UDR0 = ReceivedChar;                       // Write the data to the TX buffer
}


void ConfUSART(void){
    // disable TX, RX to set baud rate
    UCSR0B = 0x00;
    // clean flag TXC, select veloc. normal e desab.
    UCSR0A = 0x00; 
    
    /* Set baud rate */
    // UBRRnL and UBRRnH – USART Baud Rate Registers
    UBRR0H = (uint8_t) (BRR >> 8);  // MSB
    UBRR0L = (uint8_t) (BRR);       // LSB

    /* configura USART 500000 baud rate, 8 bits O tamanho das palavras e
    sem paridade, 1 bit stop*/
    
    // UCSRnB – USART Control and Status Register n B
    // RXC0: ??
    // TXENn: Transmitter Enable n
    // RXENn: Receiver Enable n
    UCSR0B = (1<<RXC0) | (1<<TXEN0) | (1<<RXEN0);

    // Enable reciever interrupt
    UCSR0B |= (1 << RXCIE0);   

    // UCSRnC – USART Control and Status Register n C
    // – UCSZn1:0: Character Size 0x011 = 8bits
    UCSR0C = (1<<UCSZ01) | (1<<UCSZ00); // Set frame: 8data, 1 stp

}

void setup(void){
    cli();
    ConfADC();
    ConfUSART();    
    
    Serial.begin(9600);
    sei();
}

void loop(void){

}