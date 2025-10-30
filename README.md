# 🚦 Projeto Semáforo com Raspberry Pi

Este projeto foi desenvolvido como parte de um trabalho prático na faculdade, utilizando o **Raspberry Pi** e a biblioteca **wiringPi** para simular o funcionamento de um semáforo.  
O código foi escrito em **linguagem C** e executado diretamente no ambiente Linux do Raspberry Pi.

---

## 🧠 Objetivo do Projeto

Demonstrar o uso das portas **GPIO** do Raspberry Pi para controlar **LEDs** que simulam as luzes de um semáforo (vermelho, amarelo e verde), aplicando lógica de programação e controle de tempo.

O projeto também inclui versões alternativas do código:
- Um modo com **luzes intermitentes** (pisca-pisca);
- Um modo com **todas as luzes acesas**;
- Um modo com **tempo aleatório** e **simulação de botão de pedestre (sem o botão físico)**.

---

## ⚙️ Componentes Utilizados

- Raspberry Pi (qualquer modelo com GPIO)
- 3 LEDs (vermelho, amarelo e verde)
- 3 resistores (220Ω ou 330Ω)
- Jumpers
- Protoboard

---

## 💻 Como Executar o Código

### 1. Copie o código para o Raspberry Pi

Salve o arquivo como `semaforo.c` (ou o nome desejado).

### 2. Compile o programa

```bash
gcc semaforo.c -o semaforo -lwiringPi
```
### 3. Execute o programa

Se o Raspberry Pi pedir permissão para acessar os pinos GPIO, use:

```bash
sudo ./semaforo
Em alguns casos (dependendo da configuração do sistema), também pode funcionar com:
./semaforo
```
