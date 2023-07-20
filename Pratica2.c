/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/



/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

#include "stm32f4xx.h"        //inclusão das definições do microcontrolador
#include <stdio.h>            //necessário para usar as funções printf e scanf
#include "Utility.h"
#include <math.h>

#define AMPLITUDE 1.5
#define FREQUENCIA 350
#define VLR_MEDIO 2
#define NUM_SAMPLES 200
#define SAMPLING_RATE 1.0

void ledOne(void);
void apagaLedOne(void);

void ligaBuzzer(void);
void desligaBuzzer(void);

void ledTwo(void);
void apagaLedTwo(void);



#include <math.h>

void generateWaveform(uint8_t *samples) {
  float timeStep = 1.0 / SAMPLING_RATE;
  float angularFrequency = 2.0 * M_PI * FREQUENCIA;

  for (int i = 0; i < NUM_SAMPLES; i++) {
    float t = i * timeStep;
    float sample = AMPLITUDE * sinf(angularFrequency * t) + VLR_MEDIO;

    // Converter para inteiro e ajustar para o intervalo de 0 a 4095
    samples[i] = (uint8_t)(sample + 0.5);
    samples[i] = samples[i] < 0 ? 0 : samples[i];             // Limitar o valor mínimo a 0
    samples[i] = samples[i] > 4095 ? 4095 : samples[i];       // Limitar o valor máximo a 4095
  }
}

void q1();
void q2();
void q3();
void q5();

int main(void)
{
	q2();
}

void q1(){
	Utility_Init();
		RCC->AHB1ENR |= 1; //habilita o clock do GPIOA
		RCC->APB2ENR |= 1 << 8; //habilita o clock do GPIOA
		GPIOA->MODER |= 0b11 << 8; //inicialização do pino PA4 no modo analógico
		RCC->APB1ENR |= 1 << 29; //habilita o clock da interface digital do DAC
		DAC->CR |= 1; //habilita o canal 1 do DAC

		while(1)
		{
			for(int asc = 0; asc < 4096; asc++){
				DAC->DHR12R1 = asc;
				Delay_ms(1);
			}
			for(int asc = 4095; asc >= 0; asc--){
				DAC->DHR12R1 = asc;
				Delay_ms(1);
			}
		}
}

void q2(){
	Utility_Init();
	//array com amostras do sinal
	uint8_t waveform[NUM_SAMPLES];
	generateWaveform(waveform);

	RCC->AHB1ENR |= 1; //habilita o clock do GPIOA
	GPIOA->MODER |= 0b11 << 10; //inicialização do pino PA4 no modo analógico
	RCC->APB1ENR |= 1 << 29; //habilita o clock da interface digital do DAC
	DAC->CR |= 1; //habilita o canal 1 do DAC
	uint8_t contador =0; //indexador do array de amostras do sinal
	while(1)
	{
		DAC->DHR12R1 = waveform[contador]; //escreve no DAC1
		++contador; //atualiza o indexador
		if(contador == 200) contador = 0; //verifica se chegou ao final do array
		Delay_us(200); //aguarda para a próxima amostra
	}
}




//QUESTÃO 5

void ledOne(void){
	Utility_Init();
	//habilita o clock do GPIOA
	RCC->AHB1ENR |=1;
	//fazer o pino PA6 ser uma saída
	GPIOA-> MODER |= 0b01 << 12;

	GPIOA->ODR |= 1<<6;
	GPIOA->ODR &= ~(1<<6);
	//Delay_ms(250);

	}

void apagaLedOne(void){
	Utility_Init();
	//habilita o clock do GPIOA
	RCC->AHB1ENR |=1;
	//fazer o pino PA6 ser uma saída
	GPIOA-> MODER |= 0b01 << 12;

	GPIOA->ODR |= 1<<6;
	//Delay_ms(250);

	}

void ledTwo(void){
	Utility_Init();
	//habilita o clock do GPIOA
	RCC->AHB1ENR |=1;
	//fazer o pino PA6 ser uma saída
	GPIOA -> MODER |= 0b01 << 14;

	GPIOA->ODR |= 1<<7;
	GPIOA->ODR &= ~(1<<7);
	//Delay_ms(250);

	}

void apagaLedTwo(void){
	Utility_Init();
	//habilita o clock do GPIOA
	RCC->AHB1ENR |=1;
	//fazer o pino PA6 ser uma saída
	GPIOA -> MODER |= 0b01 << 14;

	GPIOA->ODR |= 1<<7;
	//Delay_ms(250);

	}

void ligaBuzzer(void){
	Utility_Init(); // Inicia a Biblioteca Utility
	//HABILITA O CLOCK DO GPIOA
	RCC->AHB1ENR |= 0b0011;

	//HABILITA O CLOCK DO GPIOE
	RCC->AHB1ENR |= 0b10000;

	//HABILITA O CLOCK DO GPIOD
	RCC->AHB1ENR |= 0b1000;

	// Fazer o Pino PA6 ser uma Saída
	//GPIOA-> MODER |= 0b01 << 12;
	//GPIOA-> MODER |= 0b01 << 14;

	// Fazer o Pino PE4 ser uma Saída
	GPIOE-> MODER |= 0b01 << 8;

	// Fazer o Pino PD3 ser uma Saída
	GPIOD-> MODER |= 0b01 << 6;


	GPIOD->ODR |= 1<<3;
	Delay_ms(500);
	GPIOD->ODR &= ~(1<<3);
	Delay_ms(500);
}

void desligaBuzzer(void){
	Utility_Init(); // Inicia a Biblioteca Utility
	//HABILITA O CLOCK DO GPIOA
	RCC->AHB1ENR |= 0b0011;

	//HABILITA O CLOCK DO GPIOE
	RCC->AHB1ENR |= 0b10000;

	//HABILITA O CLOCK DO GPIOD
	RCC->AHB1ENR |= 0b1000;

	// Fazer o Pino PA6 ser uma Saída
	//GPIOA-> MODER |= 0b01 << 12;
	//GPIOA-> MODER |= 0b01 << 14;

	// Fazer o Pino PE4 ser uma Saída
	GPIOE-> MODER |= 0b01 << 8;

	// Fazer o Pino PD3 ser uma Saída
	GPIOD-> MODER |= 0b01 << 6;


	GPIOD->ODR &= ~(1<<3);
	Delay_ms(50);
}

void q5(){
	Configure_Clock();			//configura o sistema de clock
	USART1_Init();				//inicializa a USART1
	Delay_Start();				//inicializa funções de Delay

	RCC-> APB2ENR |= RCC_APB2ENR_ADC1EN;

	ADC->CCR |= 0b01 << 16;		//prescaler /4
	ADC1->SQR1 &= ~(0xF << 20);	//conversão de apenas um canal
	ADC1->SQR3 |= 16;           // Selecao canal a ser convertido (IN_16)
	ADC1->SMPR1 |= (7 << 18);   // Tempo de amostragem igual a 480 ciclos de ADC
	ADC->CCR |= ADC_CCR_TSVREFE; //Liga sensor de temperatura
	ADC1->CR2 |= ADC_CR2_ADON;   // Liga o conversor AD

	uint32_t *p = (uint32_t *) 0x1FFF7A2C; //Cria ponteiro para uma posicao
	uint32_t Word = p[0];                  //Ler o valor contido na memoria
	uint16_t TS_CAL1 = (Word & 0x0000FFFF); //Ler o valor de TS_CAL1
	uint16_t TS_CAL2 = (Word & 0xFFFF0000) >> 16; //Ler o valor de TS_CAL2

	while(1){
		uint32_t leitura = 0;
		for(int cont=0; cont<50; ++cont){
			ADC1-> CR2 |= ADC_CR2_SWSTART;
			while(!(ADC1-> SR & ADC_SR_EOC));
			leitura += ADC1->DR;
		}
		uint8_t temperatura = ((80*((leitura/50) - TS_CAL1))/(TS_CAL2-TS_CAL1)) + 30;
		printf("Temperatura = %d \n", temperatura);

		Delay_ms(500);

		 if (temperatura <= 45){
			 apagaLedOne();
			 printf("\nA temperatura está dentro da faixa de segura de operação \n");
		 }
		 else if  (temperatura <= 55){
			 ledOne();
			 desligaBuzzer();
			 apagaLedTwo();
			 printf("\nA temperarura está dentro da faixa de atenção \n");

		 }
		 else{
			 ligaBuzzer();
			 ledOne();
			 ledTwo();
			 printf("\nA temperatura está dentro da faixa de superaquecimento \n");
		 }
	}
}

//void q3(){
//	Configure_Clock();	//configura o sistema de clock
//	Delay_Start();		//inicializa funções de Delay
//
//	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;	//habilita o clock do GPIOA
//	GPIOA->MODER |= 0b11 << 8;				//inicialização do pino PA4 no modo analógico
//
//	RCC->APB1ENR |= RCC_APB1ENR_DACEN;	//habilita o clock da interface digital do DAC
//	DAC->CR |= DAC_CR_EN1;				//habilita o canal 1 do DAC
//
//	while(1)
//	{
//		for(uint32_t contador=0; contador<sizeof(sounddata_data); ++contador)
//		{
//			DAC->DHR8R1 = sounddata_data[contador];	//escreve no DAC1
//			Delay_us(120);					//aguarda a próxima amostra
//		}
//	}
//}
//------------------------AD/DA------------------------
//#include "stm32f4xx.h"
//#include "stdio.h"
//#include "Utility.h"
//int main(void)
//{
//	Utility_Init();
//	USART1_Init();
//
//	//configuração de conversor
//	RCC->AHB1ENR |= 1; //habilita o clock do GPIOA
//	GPIOA->MODER |= 0b11; //pino PA0 como entrada analógica
//	GPIOA->MODER |= 0B01 << 12;
//	GPIOA->MODER |= 0B01 << 14;
//	RCC->APB2ENR |= 1 << 8; //liga o clock da interface digital do ADC1
//	ADC->CCR |= 0b01 << 16; //prescaler /4 (fADC=21MHz)
//	ADC1->SQR1 &= ~(0xF << 20); //conversão de apenas um canal
//	ADC1->SQR3 &= ~(0x1F); //seleção do canal a ser convertido (IN_0)
//	ADC1->CR2 |= 1; //liga o conversor AD
//
//	uint16_t leitura = 0 //faz a leitura do valor convertido
//	while(1){
//
//		ADC1->CR2 |= ADC_CR2_SWSTART; //inicia a conversão
//		while(!(ADC1->SR & ADC_SR_EOC)); //aguarda o fim da conversão
//		uint16_t leitura = 0 //faz a leitura do valor convertido
//		if(leitura > 3000){
//			leitura = leitura-2048;
//			GPIOA -> ODR |= (1<<7);
//			GPIOA -> ODR |= (1 << 6);
//			Delay_us(leitura);
//			GPIOA -> ODR &= ~(1<<6);
//			Delay_us(4095-leitura);
//		}else if(leitura < 2000){
//			GPIOA -> ODR |= (1<<6);
//			GPIOA -> ODR |= (1 << 7);
//			Delay_us(leitura);
//			GPIOA -> ODR &= ~(1<<7);
//			Delay_us(2048-leitura);
//		}else{
//			GPIOA -> ODR |= (1<<7);
//			GPIOA -> ODR |= (1<<6);
//		}
//		Delay_ms(100);
//	}
//}




//-------------------------GPIO-------------------------

//void doisDoTres(void);
//void vinteSeteDoDois(void);
//void piscaAlternado(void);
//void apagaDezVez(void);
//void bipAlarme(void);
//void botao(void);



//void atraso(uint32_t tempo)
//{
//	while(tempo) --tempo;
//}


//void vinteSeteDoDois(void)
//{
//	//Habilita funÃ§Ãµes auxiliares
//		Utility_Init();
//		// Habilita o clock do GPIOA
//		// RCC -> Reset Control Clock
//		RCC->AHB1ENR |= 0B1001;
//		// Fazer o pino PA6 ser uma saida
//		GPIOA->MODER |= 0B01 << 12;
//		GPIOA->MODER |= 0B01 << 14;
//
//		//FAZER PINO PD15 SER UMA SAIDA
//		GPIOD->MODER |= 0B01 << 30;
//		int aceso = 1;
//		while(1){
//			GPIOD->ODR |= 1 << 15; //set nivel logico alto
//			GPIOA->ODR |= 1 << 6; //set nivel logico alto
//			GPIOA->ODR |= 1 << 7; //set nivel logico alto
//			Delay_ms(1000);
//			GPIOD->ODR &= ~(1 << 15); //set nivel logico baixo
//			GPIOA->ODR &= ~(1 << 6); //set nivel 1ogico baixo
//			GPIOA->ODR |= 1 << 7; //set nivel logico alto
//			Delay_ms(1000);
//			GPIOD->ODR &= ~(1 << 15); //set nivel logico baixo
//			GPIOA->ODR |= 1 << 6; //set nivel logico alto
//			GPIOA->ODR &= ~(1 << 7); //set nivel 1ogico baixo
//			Delay_ms(1000);
//
//	//		if(aceso){
//	//			int j = 1000;
//	//			for(int i=0; i<=1000; i++){
//	//					GPIOA->ODR |= 1 << 6; //set nivel logico alto
//	//					GPIOA->ODR |= 1 << 7; //set nivel logico alto
//	//					Delay_us(i);
//	//					GPIOA->ODR &= ~(1 << 6); //set nivel 1ogico baixo
//	//					GPIOA->ODR &= ~(1 << 7); //set nivel logico baixo
//	//					Delay_us(j--);
//	//			}
//	//			aceso = 0;
//	//		}else{
//	//			int j = 0;
//	//			for(int i=1000; i>=0; i--){
//	//					GPIOA->ODR |= 1 << 6; //set nivel logico alto
//	//					GPIOA->ODR |= 1 << 7; //set nivel logico alto
//	//					Delay_us(i);
//	//					GPIOA->ODR &= ~(1 << 6); //set nivel 1ogico baixo
//	//					GPIOA->ODR &= ~(1 << 7); //set nivel logico baixo
//	//					Delay_us(j++);
//	//			}
//	//			aceso = 1;
//	//		}
//		}
//}
//
//void doisDoTres(void)
//{
//	//Habilita funÃ§Ãµes auxiliares
//		Utility_Init();
//		// Habilita o clock do GPIOA
//		// RCC -> Reset Control Clock
//		RCC->AHB1ENR |= 0B1001;
//		// Fazer o pino PA6 ser uma saida
//		GPIOA->MODER |= 0B01 << 12;
//		GPIOA->MODER |= 0B01 << 14;
//
//		//FAZER PINO PD15 SER UMA SAIDA
//		GPIOD->MODER |= 0B01;
//		GPIOD->MODER |= 0B01 << 4;
//		while(1){
//			GPIOD->ODR |= 1; //set nivel logico alto
//			GPIOD->ODR &= ~(1 << 2); //set nivel logico alto
//			GPIOA->ODR |= 1 << 6; //set nivel logico alto
//			GPIOA->ODR |= 1 << 7; //set nivel logico alto
//			Delay_ms(1000);
//			GPIOD->ODR &= ~(1); //set nivel logico alto
//			GPIOD->ODR |= 1 << 2; //set nivel logico alto
//			GPIOA->ODR |= 1 << 6; //set nivel logico alto
//			GPIOA->ODR |= 1 << 7; //set nivel logico alto
//			Delay_ms(1000);
//			GPIOD->ODR &= ~(1 << 15); //set nivel logico baixo
//			GPIOD->ODR &= ~(1 << 2); //set nivel logico alto
//			GPIOA->ODR &= ~(1 << 6); //set nivel 1ogico baixo
//			GPIOA->ODR |= 1 << 7; //set nivel logico alto
//			Delay_ms(1000);
//			GPIOD->ODR &= ~(1 << 15); //set nivel logico baixo
//			GPIOD->ODR &= ~(1 << 2); //set nivel logico alto
//			GPIOA->ODR |= 1 << 6; //set nivel logico alto
//			GPIOA->ODR &= ~(1 << 7); //set nivel 1ogico baixo
//			Delay_ms(1000);
//		}
//}
//
//void piscaAlternado(void)
//{
//	//	02/03/2023
//	//FAZER PINO PD15 SER UMA SAIDA
//			Utility_Init();
//			RCC->AHB1ENR |= 0B1000;
//			GPIOD->MODER |= 0B01;
//			GPIOD->MODER |= 0B01 << 4;
//			while(1){
//				GPIOD->ODR |= 1; //set nivel logico alto
//				GPIOD->ODR |= 1 << 2; //set nivel logico alto
//				Delay_ms(250);
//				GPIOD->ODR &= ~(1); //set nivel logico baixo
//				GPIOD->ODR &= ~(1 << 2); //set nivel logico baixo
//				Delay_ms(250);
//				GPIOD->ODR |= 1; //set nivel logico alto
//				GPIOD->ODR &= ~(1 << 2); //set nivel logico baixo
//				Delay_ms(250);
//				GPIOD->ODR &= ~(1); //set nivel logico baixo
//				GPIOD->ODR &= ~(1 << 2); //set nivel logico baixo
//				Delay_ms(250);
//			}
//}
//
//void apagaDezVez(void)
//{
//	//	02/03/2023
//	Utility_Init();
//	RCC->AHB1ENR |= 0B1000;
//	GPIOD->MODER |= 0B01;
//	GPIOD->MODER |= 0B01 << 4;
//	while(1){
//		GPIOD->ODR |= 1 | 1<<2; //set nivel logico alto
//		Delay_ms(50);
//		GPIOD->ODR &= ~(1 | 1 << 2); //set nivel logico baixo
//		Delay_ms(50);
//	}
//
//}
//
//void bipAlarme(void)
//{
//	//	02/03/2023
//	Utility_Init();
//	RCC->AHB1ENR |= 0B1000;
//	GPIOD->MODER |= 0B01;
//	while(1){
//		GPIOD->ODR |= 1; //set nivel logico alto
//		Delay_ms(75);
//		GPIOD->ODR &= ~1; //set nivel logico baixo
//		Delay_ms(75);
//		GPIOD->ODR |= 1; //set nivel logico alto
//		Delay_ms(75);
//		GPIOD->ODR &= ~1; //set nivel logico baixo
//		Delay_ms(75);
//		GPIOD->ODR |= 1; //set nivel logico alto
//		Delay_ms(75);
//		GPIOD->ODR &= ~1; //set nivel logico baixo
//		Delay_ms(75);
//		GPIOD->ODR |= 1; //set nivel logico alto
//		Delay_ms(75);
//		GPIOD->ODR &= ~1; //set nivel logico baixo
//		Delay_ms(2000);
//	}
//
//}
//
//void botao(void){
//	// 09/03/2023
//	Utility_Init();
//
//	//liga clock
//	RCC->AHB1ENR |= 1<<4;
//	RCC->AHB1ENR |= 1;
//
//	//configura o pino PE4 como entrada
//	GPIOE -> MODER &= ~(0b11 << 8);
//	GPIOE -> PUPDR |= 0b01 << 8;
//
//	GPIOE -> MODER &= ~(0b11 << 6);
//	GPIOE -> PUPDR |= 0b01 << 6;
//
//	GPIOA -> MODER |= (0b01 << 12);
//	GPIOA -> MODER |= (0b01 << 12);
//
//	GPIOA -> MODER |= (0b01 << 14);
//	GPIOA -> MODER |= (0b01 << 14);
//
//	while(1){
//
//		// verifica se recebeu nivel logico alto
//		if (!(GPIOE -> IDR || (1<<3) | (1<<4))){
//			GPIOA -> ODR |= (1 << 7);
//			GPIOA -> ODR |= (1 << 6);
//		}
//
//		// verifica se recebeu nivel logico baixo
//		else{
//			GPIOA -> ODR &= ~(1 << 7);
//			GPIOA -> ODR &= ~(1 << 6);
//		}
//	}
//}
