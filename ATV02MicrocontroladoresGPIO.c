#include <stdlib.h>
#include "pico/stdlib.h"
#include "pico/time.h"
#include <stdio.h>
#include <pico/bootrom.h>

// Definição dos pinos
#define LED_GREEN 11
#define LED_BLUE 12
#define LED_RED 13
#define BUZZER 21

// Função para desligar todos os LEDs
void turn_off_all() {
    gpio_put(LED_GREEN, 0);
    gpio_put(LED_BLUE, 0);
    gpio_put(LED_RED, 0);
}

// Função para ligar um LED específico
void light_led(uint led_pin) {
    turn_off_all();
    gpio_put(led_pin, 1);
}

// Função para ligar todos os LEDs (luz branca)
void light_all_leds() {
    gpio_put(LED_GREEN, 1);
    gpio_put(LED_BLUE, 1);
    gpio_put(LED_RED, 1);
}
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


// Configuração inicial dos pinos
void setup() {
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);

    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);

    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);
}

void stop_sound() {
    // Desativa o buzzer (PWM ou GPIO ligado ao buzzer)
    gpio_put(BUZZER, 0);
}
// Função para tocar uma sequência de notas
void play_notes(float* notes, int* durations, int num_notes) {
    for (int i = 0; i < num_notes; i++) {
        float frequency = notes[i];
        int duration_ms = durations[i];

        if (frequency <= 0.0) {
            gpio_put(BUZZER, 0);
            sleep_ms(duration_ms);
        } else {
            int period_us = (int)(1000000.0 / frequency);
            if (period_us <= 0) {
                printf("Frequência inválida: %.2f\n", frequency);
                continue;
            }

            int half_period_us = period_us / 2;
            long total_cycles = (long)duration_ms * 1000 / period_us;

            for (long j = 0; j < total_cycles; j++) {
                gpio_put(BUZZER, 1);
                sleep_us(half_period_us);
                gpio_put(BUZZER, 0);
                sleep_us(half_period_us);
            }
        }

        // Se não for a última nota, faça o sleep como de costume
        if (i != num_notes - 1) {
            sleep_ms(0);
        }
    }

    // Aguardar um tempo extra após a última nota, caso necessário
    sleep_ms(100);
    stop_sound(); 
  
}




// Função para tocar o tema de Asa Branca
void play_asa_branca() {
    // Frequências das notas em Hz e suas durações em milissegundos
    float notes[] = {
        392.00, 440.00, 493.88, 587.33, 587.33, 493.88, 523.25, 523.25,
        392.00, 440.00, 493.88, 587.33, 587.33, 523.25, 493.88, 0.0,
        392.00, 392.00, 440.00, 493.88, 587.33, 0.0, 587.33, 523.25,
        493.88, 392.00, 523.25, 0.0, 523.25, 493.88, 440.00, 440.00,
        493.88, 0.0, 493.88, 440.00, 392.00, 392.00, 0.0, 392.00, 392.00,
        440.00, 493.88, 587.33, 0.0, 587.33, 523.25, 493.88, 392.00,
        523.25, 0.0, 523.25, 493.88, 440.00, 440.00, 493.88, 0.0, 493.88,
        440.00, 392.00, 392.00, 698.46, 587.33, 659.26, 523.25, 587.33,
        493.88, 523.25, 440.00, 493.88, 392.00, 440.00, 392.00, 329.63,
        392.00, 392.00, 698.46, 587.33, 659.26, 523.25, 587.33, 493.88,
        523.25, 440.00, 493.88, 392.00, 440.00, 392.00, 329.63, 392.00,
        392.00, 0.0
    };

    int durations[] = {
        125, 125, 250, 250, 250, 250, 250, 500, 
        125, 125, 250, 250, 250, 250, 500, 125, 
        125, 125, 125, 125, 250, 125, 125, 125, 
        125, 250, 250, 125, 125, 125, 125, 250, 
        125, 125, 125, 125, 500, 125, 125, 125, 
        125, 250, 125, 125, 125, 125, 250, 250, 
        125, 125, 125, 125, 500, 125, 125, 125, 
        125, 500, 125, 125, 125, 125, 250, 250, 
        250, 250, 250, 250, 250, 250, 250, 250, 
        250, 250, 250, 250, 250, 250, 250, 250, 
        250, 500
    };

    int num_notes = sizeof(notes) / sizeof(notes[0]);

    // Toca as notas com as durações correspondentes
    play_notes(notes, durations, num_notes);
   

}



// Função para tocar Für Elise
void play_fur_elise() {
    float notes[] = {
        659.26, 622.25, 659.26, 622.25, 659.26, 493.88, 587.33, 523.25,
        440.00, 0.0, 261.63, 329.63, 440.00, 493.88, 0.0, 329.63,
        415.30, 493.88, 523.25, 0.0, 329.63, 659.26, 622.25, 659.26,
        622.25, 659.26, 493.88, 587.33, 523.25, 440.00, 0.0
    };
    int durations[] = {
        250, 250, 250, 250, 250, 250, 250, 250,
        500, 250, 250, 250, 250, 500, 250, 250,
        250, 250, 500, 250, 250, 250, 250, 250,
        250, 250, 250, 250, 250, 500, 250
    };
    
    play_notes(notes, durations, sizeof(notes) / sizeof(notes[0]));
}


 // Função para tocar o tema de O Poderoso Chefão
void play_godfather_theme() {
    float notes[] = {
        0.0, 0.0, 0.0, 329.63, 440.00, 523.25, 493.88, 440.00, 523.25,
        440.00, 493.88, 440.00, 349.23, 392.00, 329.63, 329.63, 440.00,
        523.25, 493.88, 440.00, 523.25, 440.00, 523.25, 440.00, 329.63,
        311.13, 293.66, 293.66, 349.23, 415.30, 493.88, 293.66, 349.23,
        415.30, 440.00
    };
    int durations[] = {
        400, 400, 400, 200, 200, 200, 200, 200, 200,
        200, 200, 200, 200, 200, 400, 200, 200, 200,
        200, 200, 200, 200, 200, 200, 200, 200, 200,
        200, 200, 200, 200, 200, 400, 200, 200
    };

    play_notes(notes, durations, sizeof(notes) / sizeof(notes[0]));
}



// Função para tocar O Pulo da Gaita
void play_o_pulo_da_gaita() {
    float notes[] = {
        523.25, 392.00, 466.16, 440.00, 392.00, 261.63, 261.63, 392.00,
        392.00, 392.00, 523.25, 392.00, 466.16, 440.00, 392.00, 261.63,
        261.63, 392.00, 392.00, 392.00, 349.23, 329.63, 293.66, 261.63
    };
    int durations[] = {
        400, 200, 400, 200, 100, 200, 100, 100,
        100, 200, 400, 200, 400, 200, 100, 200,
        100, 100, 100, 200, 200, 200, 200, 200
    };

    play_notes(notes, durations, sizeof(notes) / sizeof(notes[0]));
}

// Função para tocar Hedwig's Theme (Harry Potter)
void play_harry_potter_theme() {
    float notes[] = {
        0.0, 293.66, 392.00, 466.16, 440.00, 392.00, 587.33, 523.25,
        440.00, 392.00, 466.16, 440.00, 349.23, 415.30, 293.66, 293.66,
        392.00, 466.16, 440.00, 392.00, 587.33, 698.46, 659.26, 622.25,
        493.88, 622.25, 587.33, 554.37, 277.18, 493.88, 392.00, 466.16,
        587.33, 466.16, 587.33, 466.16, 622.25, 587.33, 554.37, 440.00,
        466.16, 587.33, 554.37, 277.18, 293.66, 587.33, 0.0, 466.16,
        587.33, 466.16, 587.33, 466.16, 698.46, 659.26, 622.25, 493.88,
        622.25, 587.33, 554.37, 277.18, 466.16, 392.00
    };
    int durations[] = {
        500, 1000, 500, 250, 500, 1000, 500, 1500,
        1500, 250, 250, 500, 1000, 500, 1000, 2000,
        500, 250, 500, 1000, 500, 1000, 500, 1000,
        500, 750, 250, 500, 2000, 500, 1000, 500,
        1000, 500, 1000, 500, 1000, 500, 1500, 500,
        500, 1000, 500, 2000, 500, 1000, 500, 1000,
        500, 1000, 500, 1000, 500, 1000, 500, 2000,
        500, 500, 1000, 500
    };

    play_notes(notes, durations, sizeof(notes) / sizeof(notes[0]));
}




int main() {
    stdio_init_all();
    setup();

    while (true) {
        char command;
        printf("Digite o comando: \n");
        printf("1: LED Verde\n");
        printf("2: LED Azul\n");
        printf("3: LED Vermelho\n");
        printf("4: Todos os LEDs\n");
        printf("5: Desligar LEDs\n");
        printf("6: Ativar buzzer (2 kHz por 2 segundos)\n");
        printf("7: Modo de Gravação\n");
        printf("Músicas:\n");
        printf("8: Asa Branca\n");
        printf("9: Für Elise\n");
        printf("0: O Poderoso Chefão\n");
        printf("*: Pulo da Gaita\n");
        printf("#: Tema Harry Potter\n");
        printf("Q: Sair\n");
        printf("Digite o comando desejado: ");
        scanf(" %c", &command);  // Captura o comando inserido pelo usuário

    

        switch (command) {
            case '1':
                light_led(LED_GREEN);
                printf("LED verde ligado.\n");
                break;
            case '2':
                light_led(LED_BLUE);
                 printf("LED azul ligado.\n");
                break;
            case '3':
                light_led(LED_RED);
                printf("LED vermelho ligado.\n");
                break;
            case '4':
                light_all_leds();
                printf("Todos os LEDs ligados.\n");
                break;
            case '5':
                turn_off_all();
                printf("Todos os LEDs desligados.\n");
                break;
           case '6': // Acionar o buzzer
                printf("Buzzer ativado (2 kHz por 2 segundos).\n");
                activate_buzzer_with_frequency(2000, 2000);
                break;
            case '7': //Sair do modo de execução e habilitar o modo de gravação via software (reboot)
                printf("Modo de gravação via software habilitado.\n");
                reset_usb_boot(0,0);
                break;
            case '8':
                play_asa_branca();
                printf("Tocando Asa Branca!\n");
                break;
            case '9':
                play_fur_elise();
                printf("Tocando Fur Elise!\n");
                break;
            case '0':
                play_godfather_theme();
                printf("Tocando O Poderoso Chefão!\n");
                break;
            case '*':
                play_o_pulo_da_gaita();
                printf("Tocando O Pulo da Gaita ( Auto da Compadecida)!\n");
                break;
            case '#':
                play_harry_potter_theme();
                printf("Tocando Tema Harry Potter!\n");
                break;
           case 'Q': // Sair do programa
                printf("Saindo...\n");
                turn_off_all();
                return 0;
            default:
                printf("Comando inválido. Tente novamente.\n");
                break;
        }
        sleep_ms(500);  // Aguarda um pouco antes de pedir o próximo comando
    }

    return 0;  // Retorno do programa
}
