Projeto: Controle de LEDs e Buzzer com Raspberry Pi Pico

Descrição Geral

Este projeto permite controlar três LEDs e um buzzer conectado a um microcontrolador Raspberry Pi Pico. O usuário pode enviar comandos através do terminal para:

Ligar ou desligar LEDs individuais.
Ligar todos os LEDs simultaneamente.
Acionar o buzzer em diferentes frequências.
Reiniciar o microcontrolador para habilitar o modo de gravação via USB.

Requisitos de Hardware

Raspberry Pi Pico.
LEDs (verde, azul e vermelho).
Resistores para os LEDs (330 Ω recomendados).
Buzzer.

Protoboard e fios de conexão.

Ligação dos Pinos
LED Verde: GPIO 11
LED Azul: GPIO 12
LED Vermelho: GPIO 13
Buzzer: GPIO 21

Descrição dos Comandos
Abaixo estão os comandos que podem ser enviados pelo terminal e suas respectivas ações:

1 = Liga o LED verde e desliga os outros LEDs.
2 = Liga o LED azul e desliga os outros LEDs.
3 = Liga o LED vermelho e desliga os outros LEDs.
4 = Liga todos os LEDs (verde, azul e vermelho) simultaneamente.
5 = Desliga todos os LEDs.
6 = Aciona o buzzer com uma frequência de 2 kHz por 2 segundos.
7 = Reinicia o microcontrolador e habilita o modo de gravação via USB.

Detalhes das Funções do Código

Configuração Inicial
A função setup() é responsável por inicializar os pinos GPIO dos LEDs e do buzzer, configurando-os como saída.

Controle de LEDs
turn_off_all(): Desliga todos os LEDs.
light_led(uint led_pin): Liga apenas o LED especificado pelo pino, desligando os demais.

Controle do Buzzer
activate_buzzer(): Aciona o buzzer por 2 segundos sem alterar a frequência.
activate_buzzer_with_frequency(int frequency, int duration_ms): Aciona o buzzer com uma frequência especificada (em Hz) por um tempo definido (em milissegundos).

Modo de Gravação via USB

reset_usb_boot(0, 0): Reinicia o microcontrolador e entra no modo de gravação, permitindo que um novo firmware seja carregado.

Como Executar : 
Conecte o hardware de acordo com as especificações dos pinos.
Compile o código utilizando o SDK do Raspberry Pi Pico.
Carregue o binário no microcontrolador.

Abra o terminal (via USB ou UART) e envie os comandos conforme a tabela acima.

Observações
Certifique-se de instalar e configurar corretamente o SDK do Raspberry Pi Pico antes de compilar o projeto.
Utilize resistores adequados para proteger os LEDs.
Para reprogramar o Pico, envie o comando 7 ou conecte o botão BOOTSEL ao reiniciar.

Autor

Projeto desenvolvido para fins educativos utilizando o Raspberry Pi Pico e sua biblioteca pico/stdlib.

