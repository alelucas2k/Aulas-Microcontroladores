/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

// CABEÇALHOS DAS FUNÇÕES
void q1(void);
void q2(void);
void q3(void);
void q4(void);
void q5(void);
void q6(int value);
void q7(void);
void q9(void);
void q10(void);
void q11(void);
void q12(void);
void q13(void);
void q14(void);
void q17(void);
void q18(void);
void q19(void);

void q21(void);
void q22(void);
void q23(void);
void q24(void);
void q25(void);
void q26(void);
void q27(void);

int main(void)
{
	Utility_Init();
	q19();

}

void q1(void){
	RCC -> AHB1ENR |= 0b01;

	GPIOA -> MODER |= 0B01<<12;

	// Criando laço para manter sistema rodando
	while(1){
		GPIOA -> ODR &= ~(1 << 6);
		Delay_ms(250);
		GPIOA -> ODR |= (1 << 6);
		Delay_ms(250);
	}
}

void q2(void){
	RCC -> AHB1ENR |= 0b01;

	GPIOA -> MODER |= 0B01<<12;

	// Criando laço para manter sistema rodando
	while(1){
		GPIOA -> ODR &= ~(1 << 6);
		Delay_ms(100);
		GPIOA -> ODR |= (1 << 6);
		Delay_ms(1900);
	}
}


void q3(void){
	RCC -> AHB1ENR |= 0b01;

	GPIOA -> MODER |= 0B01<<12;

	// Criando laço para manter sistema rodando
	while(1){
		GPIOA -> ODR &= ~(1 << 6);
		Delay_ms(50);
		GPIOA -> ODR |= (1 << 6);
		Delay_ms(1750/2);

		for(int i = 0;i<2;i++){
			GPIOA -> ODR &= ~(1 << 6);
			Delay_ms(50);
			GPIOA -> ODR |= (1 << 6);
			Delay_ms(50);
		}
		Delay_ms(1750/2);
	}
}

void q4(void){
	RCC -> AHB1ENR |= 0b01;

	GPIOA -> MODER |= 0B01<<12;
	int i = 0;
	// Criando laço para manter sistema rodando
	while(1){
		GPIOA -> ODR &= ~(1 << 6);
		Delay_ms(50);
		GPIOA -> ODR |= (1 << 6);
		Delay_ms(950/i);
		i++;
	}
}

void q5(void){
		Utility_Init(); //habilita as funÃ§Ãµes especiais

		RCC -> AHB1ENR |= 0B10000;

		GPIOE -> MODER |= 0B01;

		while(1)
		{
			for(int i = 0; i<4; i++){
				GPIOE -> ODR |= 1;
				Delay_ms(50);
				GPIOE -> ODR &= ~(1);
				Delay_ms(50);
			}
			Delay_ms(450);
		}
}

void q6 (int value){
	RCC -> AHB1ENR |= 0b01;

	GPIOA -> MODER |= 0B01<<12;
	while(1){
		GPIOA -> ODR &= ~(1 << 6);
		Delay_us(value);
		GPIOA -> ODR |= (1 << 6);
		Delay_us(10000-value);
	}
}

void q7 (void){
	RCC -> AHB1ENR |= 0b01;

	GPIOA -> MODER |= 0B01<<12;
	int flagForte = 0;
	while(1){
		int j = 1000;
		if(flagForte){
			for(int i = 0; i <= 1000; i++){
				GPIOA -> ODR &= ~(1 << 6);
				Delay_us(i);
				GPIOA -> ODR |= (1 << 6);
				Delay_us(j--);
			}
			flagForte = 0;
		}else{
			j = 0;
			for(int i = 1000; i >= 0; i--){
				GPIOA -> ODR &= ~(1 << 6);
				Delay_us(i);
				GPIOA -> ODR |= (1 << 6);
				Delay_us(j++);
			}
			flagForte = 1;
		}
	}
}

void q9(void){
	RCC -> AHB1ENR |= 0b01;

	GPIOA -> MODER |= 0b01<<12;
	GPIOA -> MODER |= 0b01<<14;

	while(1)
	{

		for(int i = 0; i < 4; i++){
			GPIOA -> ODR |= 1<<6;
			GPIOA -> ODR |= 1<<7;
			Delay_ms(1000);
			GPIOA -> ODR &= ~(1<<6);
			GPIOA -> ODR |= 1<<7;
			Delay_ms(1000);
			GPIOA -> ODR |= 1<<6;
			GPIOA -> ODR &= ~(1<<7);
			Delay_ms(1000);
			GPIOA -> ODR &= ~(1<<6);
			GPIOA -> ODR &= ~(1<<7);
			Delay_ms(1000);
		}

	}
}

void q10 (void){
	RCC -> AHB1ENR |= 0b01;

	GPIOA -> MODER |= 0B01<<12;
	GPIOA -> MODER |= 0B01<<14;
	int flagForte = 0;
	while(1){
		int j = 1000;
		if(flagForte){
			for(int i = 0; i <= 1000; i++){
				GPIOA -> ODR &= ~(1 << 6);
				GPIOA -> ODR |= (1 << 7);
				Delay_us(i);
				GPIOA -> ODR |= (1 << 6);
				GPIOA -> ODR &= ~(1 << 7);
				Delay_us(j--);
			}
			flagForte = 0;
		}else{
			j = 0;
			for(int i = 1000; i >= 0; i--){
				GPIOA -> ODR &= ~(1 << 6);
				GPIOA -> ODR |= (1 << 7);
				Delay_us(i);
				GPIOA -> ODR |= (1 << 6);
				GPIOA -> ODR &= ~(1 << 7);
				Delay_us(j++);
			}
			flagForte = 1;
		}
	}
}

void q11(void){
	RCC -> AHB1ENR |= 0b1000;

	GPIOD -> MODER |= 0b0101010101010101;
	// Criando laço para manter sistema rodando
	while(1){
		for(int i = 0; i<256; i++){
			GPIOD -> ODR |= i;
			Delay_ms(50);
			GPIOD -> ODR &= ~(i);
//			Delay_ms(100);
		}
	}
}

void q12(void){
	RCC -> AHB1ENR |= 0b1000;

	GPIOD -> MODER |= 0b0101010101010101;
	// Criando laço para manter sistema rodando
	int flag = 1;
	while(1){
		if(flag){
			for(int i = 0; i<7; i++){
				GPIOD -> ODR |= 1<<i;
				Delay_ms(100);
				GPIOD -> ODR &= ~(1<<i);
//				Delay_ms(500);
			}
			flag = 0;
		}else{
			for(int i = 7; i>=1; i--){
				GPIOD -> ODR |= (1 << i);
				Delay_ms(100);
				GPIOD -> ODR &= ~(1 << i);
//				Delay_ms(500);
			}
			flag = 1;
		}
	}
}

void q13(void){
	RCC -> AHB1ENR |= 0b1000;

	GPIOD -> MODER |= 0b010101010101;
	// Criando laço para manter sistema rodando
	while(1){

		// PRIMEIRA PARTE LIGA VERMELHO
		GPIOD -> ODR |= (1<<2);
		GPIOD -> ODR &= ~(1 << 1);
		GPIOD -> ODR &= ~(1);

		// SEGUNDA PARTE LIGA VERDE
		GPIOD -> ODR |= (1<<3);
		GPIOD -> ODR &= ~(1 << 4);
		GPIOD -> ODR &= ~(1 << 5);

		Delay_ms(2000);

		// PRIMEIRA PARTE LIGA VERMELHO
		GPIOD -> ODR |= (1<<2);
		GPIOD -> ODR &= ~(1 << 1);
		GPIOD -> ODR &= ~(1);

		// SEGUNDA PARTE LIGA AMARELO
		GPIOD -> ODR |= (1<<4);
		GPIOD -> ODR &= ~(1 << 3);
		GPIOD -> ODR &= ~(1 << 5);

		Delay_ms(2000);

		// PRIMEIRA PARTE LIGA VERDE
		GPIOD -> ODR |= (1);
		GPIOD -> ODR &= ~(1 << 2);
		GPIOD -> ODR &= ~(1 << 1);

		// SEGUNDA PARTE LIGA VERMELHO
		GPIOD -> ODR |= (1<<5);
		GPIOD -> ODR &= ~(1 << 3);
		GPIOD -> ODR &= ~(1 << 4);

		Delay_ms(2000);


		// ------------------------------------------ INVERTEU TUDO AGORAA	------------------------------------------

		// PRIMEIRA PARTE LIGA AMARELO
		GPIOD -> ODR |= (1<<1);
		GPIOD -> ODR &= ~(1 << 2);
		GPIOD -> ODR &= ~(1);

		// SEGUNDA PARTE LIGA VEMELHO
		GPIOD -> ODR |= (1<<5);
		GPIOD -> ODR &= ~(1 << 3);
		GPIOD -> ODR &= ~(1 << 4);

		Delay_ms(2000);
	}
}

void q14(void){
	Utility_Init();

	RCC -> AHB1ENR |= 0b1000;
	GPIOD -> MODER |= 0b01010101010101;

	const uint8_t mask[16]={
		0b00111111, //0
		0b00000110, //1
		0b01011011, //2
		0b01001111, //3
		0b01100110, //4
		0b01101101, //5
		0b01111101, //6
		0b00000111, //7
		0b01111111, //8
		0b01101111, //9
		0b01110111, //A
		0b01111100, //B
		0b00111001, //C
		0b01011110, //D
		0b01111001, //E
		0b01110001  //F
	};

	int flagCres = 1;
	while(1){
		if(flagCres){
			for(int i = 0; i<15; i++){
				GPIOD -> ODR |= mask[i];
				Delay_ms(800);
				GPIOD -> ODR &= ~(mask[i]);
			}
			flagCres = 0;
		}else{
			for(int i = 15; i>0; i--){
				GPIOD -> ODR |= mask[i];
				Delay_ms(800);
				GPIOD -> ODR &= ~(mask[i]);
			}
			flagCres = 1;
		}
	}

}


void q17(void){
	Utility_Init();

	RCC -> AHB1ENR |= 0b11000;
	GPIOD -> MODER |= 0b01;
	int indo = 1;

	while(1){
		if (indo){
			for(int i = 500; i < 2500; i+=50){

				Delay_ms(20); //evita debounce
				GPIOD -> ODR |= 1;
				Delay_us(i);
				GPIOD -> ODR &= ~(1);
			}
			indo = 0;
		}
		else{
			for(int i = 2600; i > 400; i-=50){

				Delay_ms(20);
				GPIOD -> ODR |= 1;
				Delay_us(i);
				GPIOD -> ODR &= ~(1);
			}
			indo = 1;
		}
	}
}

void q18(void){
	RCC -> AHB1ENR |= 0b1000;

	GPIOD -> MODER |= 0b010000000101;
	int sentido = 0;
	int flagForte = 0;
	while(1){
		if(sentido){
			GPIOD -> ODR &= ~(1);
			GPIOD -> ODR |= (1<<1);
			for(int k = 0; k<2; k++){
				int j = 1000;
				if(flagForte){
					j = 0;
					for(int i = 1000; i >= 0; i--){
						Delay_ms(2);
						GPIOD -> ODR |= (1 << 5);
						Delay_us(i);
						GPIOD -> ODR &= ~(1 << 5);
						Delay_us(j++);
					}
					flagForte = 0;
				}else{
					for(int i = 0; i <= 1000; i++){
						Delay_ms(2);
						GPIOD -> ODR |= (1 << 5);
						Delay_us(i);
						GPIOD -> ODR &= ~(1 << 5);
						Delay_us(j--);
					}
					flagForte = 1;
				}
			}
			sentido = 0;
		}else{
			GPIOD -> ODR |= (1);
			GPIOD -> ODR &= ~(1<<1);
			for(int k = 0; k<2; k++){
				int j = 1000;
				if(flagForte){
					j = 0;
					for(int i = 1000; i >= 0; i--){
						Delay_ms(2);
						GPIOD -> ODR |= (1 << 5);
						Delay_us(i);
						GPIOD -> ODR &= ~(1 << 5);
						Delay_us(j++);
					}
					flagForte = 0;
				}else{
					for(int i = 0; i <= 1000; i++){
						Delay_ms(2);
						GPIOD -> ODR |= (1 << 5);
						Delay_us(i);
						GPIOD -> ODR &= ~(1 << 5);
						Delay_us(j--);
					}
					flagForte = 1;
				}
			}
			sentido = 1;
		}
	}
}

void q19(void){
	Utility_Init();
	RCC->AHB1ENR |= 1000;
	GPIOD->MODER |= 0b01;
	GPIOD -> OTYPER |= 1;

	while(1){

	GPIOD->ODR |= 1;
	Delay_ms(500);
	GPIOD->ODR &= ~(1);
	Delay_ms(500);

	}
}

void q26(void){
	Utility_Init();

	RCC -> AHB1ENR |= 0b11000;

	GPIOE->MODER &= ~(0b11 << 8);
	GPIOE->PUPDR |= (0b01 << 8);
	GPIOE->MODER &= ~(0b11 << 6);
	GPIOE->PUPDR |= (0b01 << 6);
	GPIOD -> MODER |= 0b01;
	int controle = 600;

	while(1){
		if (!(GPIOE->IDR & (1 << 4)) && (controle < 2500)){
				Delay_ms(20);
				GPIOD -> ODR |= 1;
				Delay_us(controle+=50);
				GPIOD -> ODR &= ~(1);
		}
		if(!(GPIOE->IDR & (1 << 3)) && (controle > 300)){

				Delay_ms(20);
				GPIOD -> ODR |= 1;
				Delay_us(controle-=50);
				GPIOD -> ODR &= ~(1);
		}
	}
}

void q21(void)
{
	Utility_Init();

    // Habilitar o clock para as portas E e A
    RCC->AHB1ENR |= (1 << 4);
    RCC->AHB1ENR |= 1;

    // Configurar os pinos PE4 como entrada e os pinos PA6 e PA7 como saída
    GPIOE->MODER &= ~(0b11 << 8);
    GPIOE->PUPDR |= (0b01 << 8);
    GPIOA->MODER |= (0b01 << 12);

    // Loop infinito
    while (1) {
        // Verificar se o botão K0 foi pressionado
        if (!(GPIOE->IDR & (1 << 4)) == 0) {
        	GPIOA -> ODR |= (1 << 6);
        }
        else{
        	GPIOA -> ODR &= ~(1 << 6);
        }
    }
}

void q22(void)
{
	Utility_Init();

    // Habilitar o clock para as portas E e A
    RCC->AHB1ENR |= (1 << 4);
    RCC->AHB1ENR |= 1;

    // Configurar os pinos PE4 como entrada e os pinos PA6 e PA7 como saída
    GPIOE->MODER &= ~(0b11 << 8);
    GPIOE->PUPDR |= (0b01 << 8);
    GPIOE->MODER &= ~(0b11 << 6);
	GPIOE->PUPDR |= (0b01 << 6);
    GPIOA->MODER |= (0b01 << 12) | (0b01 << 14);

    // Loop infinito
    while (1) {
        // Verificar se o botão K0 foi pressionado
        if (!(GPIOE->IDR & (1 << 4)) == 0) {
        	GPIOA -> ODR |= (1 << 6);
        }
        else{
        	GPIOA -> ODR &= ~(1 << 6);
        }

        // Verificar se o botão K1 foi pressionado
		if (!(GPIOE->IDR & (1 << 3)) == 0) {
			GPIOA -> ODR |= (1 << 7);
		}
		else{
			GPIOA -> ODR &= ~(1 << 7);
		}
    }
}

void q23(void)
{
	Utility_Init();

    // Habilitar o clock para as portas E e A
    RCC->AHB1ENR |= (1 << 4);
    RCC->AHB1ENR |= 1;

    // Configurar os pinos PE4 como entrada e os pinos PA6 e PA7 como saída
    GPIOE->MODER &= ~(0b11 << 8);
    GPIOE->PUPDR |= (0b01 << 8);
    GPIOA->MODER |= (0b01 << 12);
    GPIOA->MODER &= ~(0b11 << 14);

    // Loop infinito
    while (1) {
        // Verificar se o botão K0 foi pressionado
        if ((GPIOE->IDR & (1 << 4)) == 0) {
            // Esperar um curto intervalo para evitar debounce
            Delay_ms(50);
            // Verificar novamente se o botão K0 continua pressionado
            if ((GPIOE->IDR & (1 << 4)) == 0) {
                // Inverter o estado do LED D2
                GPIOA->ODR ^= (1 << 6);
                // Esperar até que o botão K0 seja liberado
                while ((GPIOE->IDR & (1 << 4)) == 0) {
                    Delay_ms(50);
                }
            }
        }
    }
}

void q24(void)
{
	Utility_Init();

    // Habilitar o clock para as portas E e A
    RCC->AHB1ENR |= (1 << 4);
    RCC->AHB1ENR |= 1;

    // Configurar os pinos PE4 como entrada e os pinos PA6 e PA7 como saída
    GPIOE->MODER &= ~(0b11 << 8);
    GPIOE->PUPDR |= (0b01 << 8);
    GPIOE->MODER &= ~(0b11 << 6);
	GPIOE->PUPDR |= (0b01 << 6);
    GPIOA->MODER |= (0b01 << 12) | (0b01 << 14);

    // Loop infinito
    while (1) {
        // Verificar se o botão K0 foi pressionado
    	if (!(GPIOE->IDR & (1 << 3)) == 0){
    		Delay_us(50);
    		if ((!(GPIOE->IDR & (1 << 3)) == 0) || (!(GPIOE->IDR & (1 << 4)) == 0)) {
    						GPIOA -> ODR |= (1 << 6);
    						GPIOA -> ODR |= (1 << 7);
		}else{
			GPIOA -> ODR &= ~(1 << 7);
			GPIOA -> ODR &= ~(1 << 6);
		}
    }
   }
}

void q25(void){

	Utility_Init();

	//habilita o clock do GPIOA
	RCC->AHB1ENR |= 1;
	 //habilita o clock do GPIOE
	RCC->AHB1ENR |= 1<<4;

	//configurando PA6 como saída
	GPIOA->MODER |= (0b01 << 12);
	//configurando PA7 como saída
	GPIOA->MODER |= (0b01 << 14);

	//Configurando o pino PE3 como entrada
	GPIOE->MODER &= ~(0b11 << 6);
	GPIOE->PUPDR |= (0b01 << 6);

	//Configurando o pino PE4 como entrada
	GPIOE->MODER &= ~(0b11 << 8);
	GPIOE->PUPDR |= (0b01 << 8);

	while(1){
			(GPIOA->ODR |= (1 << 6));
				(GPIOA->ODR |= (1 << 7));

			if(!(GPIOE->IDR & (1 << 4)) && !!(GPIOE->IDR & (1 << 3))){
				uint32_t cont = 0;
				while(!(GPIOE->IDR & (1 << 4))){
					Delay_ms(100);
					if(!(GPIOE->IDR & (1 << 3))){
						if(cont<=1000){
							(GPIOA->ODR &= ~(1 << 6));
							(GPIOA->ODR &= ~(1 << 7));
						}

					}else{
						(GPIOA->ODR |= (1 << 6));
						(GPIOA->ODR |= (1 << 7));
					}
					cont += 100;
				}
			}
		}
	}

	void q27(void){
		Utility_Init();

		RCC -> AHB1ENR |= 0b11001;
		GPIOD -> MODER |= 0b01010101010101;

		//Configurando o pino PA0 como entrada
		GPIOA->MODER &= ~(0b11 << 0);
		GPIOA->PUPDR |= (0b10 << 0);

		//Configurando o pino PE3 como entrada
		GPIOE->MODER &= ~(0b11 << 6);
		GPIOE->PUPDR |= (0b01 << 6);

		//Configurando o pino PE4 como entrada
		GPIOE->MODER &= ~(0b11 << 8);
		GPIOE->PUPDR |= (0b01 << 8);

		const uint8_t mask[16]={
			0b00111111, //0
			0b00000110, //1
			0b01011011, //2
		};

		while(1){
			if(!(GPIOA->IDR & (1 << 0))) GPIOD -> ODR &= ~(mask[0]);
			else  GPIOD -> ODR |= mask[0];

			if(!(GPIOE->IDR & (1 << 4))) GPIOD -> ODR |= mask[1];
			else GPIOD -> ODR &= ~(mask[1]);

			if(!(GPIOE->IDR & (1 << 3))) GPIOD -> ODR |= mask[2];
			else GPIOD -> ODR &= ~(mask[2]);
		}

	}
