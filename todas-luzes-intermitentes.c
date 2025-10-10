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

    while (1) {
        // todas acesas
        digitalWrite(RED, HIGH);
        digitalWrite(YELLOW, HIGH);
        digitalWrite(GREEN, HIGH);
        printf("Todas as luzes ligadas\n");
        delay(1000);

        // todas apagadas
        digitalWrite(RED, LOW);
        digitalWrite(YELLOW, LOW);
        digitalWrite(GREEN, LOW);
        printf("Todas as luzes desligadas\n");
        delay(1000);
    }

    return 0;
}
