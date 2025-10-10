#include <wiringPi.h>
#include <stdio.h>

// Definições dos pinos (BCM → wiringPiSetupGpio)
#define RED     17
#define YELLOW  27
#define GREEN   22

int main(void) {
    if (wiringPiSetupGpio() == -1) {
        printf("Erro ao iniciar wiringPi\n");
        return 1;
    }

    pinMode(RED, OUTPUT);
    pinMode(YELLOW, OUTPUT);
    pinMode(GREEN, OUTPUT);

    // mantém todas ligadas
    digitalWrite(RED, HIGH);
    digitalWrite(YELLOW, HIGH);
    digitalWrite(GREEN, HIGH);
    printf("Todas as luzes ficam sempre ligadas\n");

    while (1) {
        delay(1000); // apenas segura o programa rodando
    }

    return 0;
}
