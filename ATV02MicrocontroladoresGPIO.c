#include <stdio.h>
#include "pico/stdlib.h"

// Definições dos GPIOs utilizados
#define LED_VERDE 11
#define LED_AZUL 12
#define LED_VERMELHO 13
#define BUZZER 21

// Prototipação das funções
void ligar_led_verde();
void ligar_led_azul();
void ligar_led_vermelho();
void ligar_todos_leds();
void desligar_todos_leds();
void acionar_buzzer();
void entrar_modo_gravacao();

int main() {
    // Inicialização do UART e dos GPIOs
    stdio_init_all();
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);
    gpio_init(LED_AZUL);
    gpio_set_dir(LED_AZUL, GPIO_OUT);
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);


    while (1) {
        // Loop infinito para manter o programa rodando (se necessário)
    ligar_led_verde();
    ligar_led_azul();
    ligar_led_vermelho();
    ligar_todos_leds();
    desligar_todos_leds();
    acionar_buzzer();
    entrar_modo_gravacao();

    }

    return 0;
}
