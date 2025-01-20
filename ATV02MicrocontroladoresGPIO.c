#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include <pico/bootrom.h>


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

// Função para acionar o buzzer em uma frequência específica
void activate_buzzer_with_frequency(int frequency, int duration_ms)
{
    int delay = 1000000 / (2 * frequency); // Meio-período em microsegundos

    for (int i = 0; i < (duration_ms * 1000) / (2 * delay); i++)
    {
        gpio_put(BUZZER, 1);
        sleep_us(delay); // Liga por meio-período
        gpio_put(BUZZER, 0);
        sleep_us(delay); // Desliga por meio-período
    }
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
            gpio_put(LED_GREEN, 1);
            gpio_put(LED_BLUE, 1);
            gpio_put(LED_RED, 1);
            printf("Todos os LED's foram acessos.\n");
            break;
        case '5': // Desligar todos os LEDs
            turn_off_all();
            printf("Todos os LED's foram desligados.\n");
            break;
        case '6': // Acionar o buzzer
        printf("Buzzer ativado (2 kHz por 2 segundos).\n");
            activate_buzzer_with_frequency(2000, 2000);
            
            break;
        case '7': //Sair do modo de execução e habilitar o modo de gravação via software (reboot)
            printf("Modo de gravação via software habilitado.\n");
            reset_usb_boot(0,0);
            break;
        default:
            printf("Comando inválido. Tente novamente.\n");
            break;
        }
    }

    return 0;
}
