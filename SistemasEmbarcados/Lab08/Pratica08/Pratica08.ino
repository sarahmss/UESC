

#include <avr/io.h>
#define INPUT_PIN         (1 << PC0)    // Pin A0 == ADC0
#define INPUT_PIN2        (1 << PC1)    // Pin A1 == ADC1
#define TOP_50us          50            // 50us --- 20khz
#define OUTPUT_PIN_0      (1 << PD6)    // Pin 6

volatile uint16_t ADCValue  = 0;
volatile uint16_t samples = 0;
bool aux = 0;

/************************* Temporizador 0 - CTC (50us = 20Khz) *****************/
void ConfTimer0(void)
{
    DDRD |= OUTPUT_PIN_0;
    PORTD &= ~OUTPUT_PIN_0;

    // TCNTn: Timer/Counter register ()
    TCNT0 = 0;
    OCR0A = 0;
    TCCR0A = 0;
    TCCR0B = 0;
    TIMSK0 = 0;

    // OCRnX: Outupt Compare Register ->  stores the compare value
    OCR0A = TOP_50us; 

    // COMBnX: Compare Match Output B Mode 
    // COM0B0:0 = 0b00 (non-inverting mode - HIGH at bottom, LOW on Match)
    // OC0B -> store
    TCCR0A &= ~(1 << COM0A0);    
    TCCR0A &= ~(1 << COM0A1);    

    // TCCRnX: Timer/Counter Control Register 

    // WGMn: Waveform Generation Mode bit
    // WGM02:0 = 0b010 (CTC with OCR0A as TOP)
    TCCR0B &= ~ (1 << WGM02); 
    TCCR0A |= (1 << WGM01);
    TCCR0A &= ~ (1 << WGM00); 

    // Set interrupt on compare match
    TIMSK0 |= (1 << OCIE0A);

    // CSn: Clock select
    // CS02:0 = 0b010 (Prescaler == 8 -> F_clck / 8) 
    TCCR0B &= ~(1 << CS02);
    TCCR0B |= (1 << CS01); 
    TCCR0B &= ~(1 << CS00); 
}

/*
    @brief: Define a rotina de interrupção para o temporizador que conta 0ms
*/
ISR (TIMER0_COMPA_vect)
{
  PORTD ^= OUTPUT_PIN_0;
}

/************************* Configuração do ADC *****************/

void Conf250kHz(){
    // ADPS2:0 = 0x110: ADC Prescaler Selection (Df = 64) 
    // f_conv = f_clk/Df ; 
    // Set ADC prescalar to 64 → 16 MHz / 64 = 250 kHz
    // 250kHz / 13 ciclos = 19.230 amostras/seg
    ADCSRA |= (1 << ADPS2);
    ADCSRA |= (1 << ADPS1); 
    ADCSRA &= ~(1 << ADPS0); 
}

void ConfAdc(void){
// Definição portas como entrada
  DDRC &= ~INPUT_PIN;
  PORTC |= INPUT_PIN;
  DDRC &= ~INPUT_PIN2;
  PORTC |= INPUT_PIN2;

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

  // Seleciona trigger como "Timer/Counter1 compare match B"
  // ADTS2:0 = 0b011
  ADCSRB &= ~ (1 << ADTS2);
  ADCSRB |= (1 << ADTS1);
  ADCSRB |= (1 << ADTS0);

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

  Conf250kHz();
}


ISR(ADC_vect){
  //  ??
  TIFR1 = (1 << OCF1A);

  // Averigua o fim da conversão (ADSC != 0)
  // while(ADCSRA & (1 << ADSC));

  // Lê valor de 8 bits  
  ADCValue = ADCH; 
  
  if (aux==0){
    // MUX3:0 = (0x000): Define a entrada única ADC0
    ADMUX &= ~(1 << MUX0);
    Serial.print(ADCValue);
    Serial.print(",");
  }
  if (aux==1){
    // MUX3:0 = (0x001): Define a entrada única ADC1
    ADMUX |=  (1 << MUX0);
    Serial.print(ADCValue);
    Serial.print(",");
  }
  aux = !aux;
}

/******************************************************/
void setup() {

  cli();  
  ConfTimer0();
  ConfAdc();
  Serial.begin(500000);
  sei();
}

void loop() {
    
}