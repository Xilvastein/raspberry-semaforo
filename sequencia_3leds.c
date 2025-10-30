#include <wiringPi.h>  // Biblioteca para controle dos pinos GPIO do Raspberry Pi
#include <stdio.h>      // Biblioteca padrão para funções de entrada e saída (ex: printf)
#include <unistd.h>     // Biblioteca opcional para funções de sistema (como sleep)

// =============================
// Definições dos pinos (modo BCM → wiringPiSetupGpio)
// =============================
#define RED     17      // LED vermelho no GPIO 17 (pino físico 11)
#define YELLOW  27      // LED amarelo no GPIO 27 (pino físico 13)
#define GREEN   22      // LED verde no GPIO 22 (pino físico 15)

// =============================
// Função 1: Sequência normal (verde → amarelo → vermelho)
// =============================
void sequenciaNormal() {
    digitalWrite(GREEN, HIGH);  // Liga o LED verde
    delay(1000);                // Espera 1 segundo
    digitalWrite(GREEN, LOW);   // Desliga o LED verde

    digitalWrite(YELLOW, HIGH); // Liga o LED amarelo
    delay(1000);
    digitalWrite(YELLOW, LOW);  // Desliga o LED amarelo

    digitalWrite(RED, HIGH);    // Liga o LED vermelho
    delay(1000);
    digitalWrite(RED, LOW);     // Desliga o LED vermelho
}

// =============================
// Função 2: Sequência reversa (vermelho → amarelo → verde)
// =============================
void sequenciaReversa() {
    digitalWrite(RED, HIGH);
    delay(1000);
    digitalWrite(RED, LOW);

    digitalWrite(YELLOW, HIGH);
    delay(1000);
    digitalWrite(YELLOW, LOW);

    digitalWrite(GREEN, HIGH);
    delay(1000);
    digitalWrite(GREEN, LOW);
}

// =============================
// Função 3: Piscar todos juntos 5 vezes
// =============================
void piscaTodos() {
    for (int i = 0; i < 5; i++) {  // repete o loop 5 vezes
        digitalWrite(RED, HIGH);
        digitalWrite(YELLOW, HIGH);
        digitalWrite(GREEN, HIGH);
        delay(300);                 // Espera 0,3 segundos

        digitalWrite(RED, LOW);
        digitalWrite(YELLOW, LOW);
        digitalWrite(GREEN, LOW);
        delay(300);                 // Espera 0,3 segundos antes de repetir
    }
}

// =============================
// Função principal
// =============================
int main(void) {
    // Inicializa a biblioteca WiringPi em modo BCM
    if (wiringPiSetupGpio() == -1) {
        printf("Erro ao iniciar WiringPi!\n");
        return 1;  // Encerra o programa se ocorrer falha
    }

    // Configura cada LED como saída
    pinMode(RED, OUTPUT);
    pinMode(YELLOW, OUTPUT);
    pinMode(GREEN, OUTPUT);

    printf("Iniciando sequência de LEDs (modo BCM)...\n");

    // Loop infinito de execução
    while (1) {
        sequenciaNormal();  // Executa a sequência verde → amarelo → vermelho
        sequenciaReversa(); // Executa vermelho → amarelo → verde
        piscaTodos();       // Pisca todos juntos 5 vezes
    }

    return 0;
}
