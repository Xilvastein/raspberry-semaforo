#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definições dos pinos (usando BCM → precisa do wiringPiSetupGpio)
#define RED     17   // GPIO 17
#define YELLOW  27   // GPIO 27
#define GREEN   22   // GPIO 22

int main(void) {
    // inicializa a wiringPi no modo GPIO (BCM)
    if (wiringPiSetupGpio() == -1) {
        printf("Erro ao iniciar wiringPi\n");
        return 1;
    }

    // configura os pinos como saída
    pinMode(RED, OUTPUT);
    pinMode(YELLOW, OUTPUT);
    pinMode(GREEN, OUTPUT);

    // inicializa gerador de números aleatórios
    srand(time(NULL));

    while (1) {
        // Verde acende
        digitalWrite(GREEN, HIGH);
        printf("Semáforo aberto (verde)\n");

        // tempo aleatório entre 5 e 12 segundos
        int tempo_verde = (rand() % (12 - 5 + 1)) + 5;
        printf("Vai ficar verde por %d segundos\n", tempo_verde);
        delay(tempo_verde * 1000);  // delay em ms
        digitalWrite(GREEN, LOW);

        // Amarelo
        digitalWrite(YELLOW, HIGH);
        delay(2000);  // 2 segundos
        digitalWrite(YELLOW, LOW);

        // Vermelho
        digitalWrite(RED, HIGH);
        printf("Pedestre atravessando (vermelho)\n");

        // tempo aleatório entre 5 e 10 segundos
        int tempo_vermelho = (rand() % (10 - 5 + 1)) + 5;
        delay(tempo_vermelho * 1000);
        digitalWrite(RED, LOW);
    }

    return 0;
}
