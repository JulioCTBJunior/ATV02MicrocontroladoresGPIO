#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"

// Definição dos pinos
#define LED_GREEN 11
#define LED_BLUE 12
#define LED_RED 13
#define BUZZER 21

// Função para desligar todos os LEDs
void turn_off_all()
{
    gpio_put(LED_GREEN, 0);
    gpio_put(LED_BLUE, 0);
    gpio_put(LED_RED, 0);
}

// Função para ligar um LED específico
void light_led(uint led_pin)
{
    turn_off_all();
    gpio_put(led_pin, 1);
}

// Função para acionar o buzzer
void activate_buzzer()
{
    gpio_put(BUZZER, 1);
    sleep_ms(2000); // Aciona por 2 segundos
    gpio_put(BUZZER, 0);
}

// Configuração inicial dos pinos
void setup()
{
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);

    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);

    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);
}

int main()
{
    stdio_init_all();
    setup();

    while (true)
    {
        char command;
        printf("Enter command: ");
        command = getchar(); // Recebe comando via terminal

        switch (command)
        {
        case '1': // Ligar LED verde
            light_led(LED_GREEN);
            printf("LED verde ligado.\n");
            break;
        case '2': // Ligar LED azul
            light_led(LED_BLUE);
            printf("LED azul ligado.\n");
            break;
        case '3': // Ligar LED vermelho
            light_led(LED_RED);
            printf("LED vermelho ligado.\n");
            break;
        case '4': // Ligar os três LEDs
        case '5': // Desligar todos os LEDs
        case '6': // Acionar o buzzer
        default:
            printf("Comando inválido. Tente novamente.\n");
            break;
        }
    }

    return 0;
}
