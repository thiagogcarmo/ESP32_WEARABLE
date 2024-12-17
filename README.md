This program run in a tin esp32, using the bluetooth funcionalit to control music, by pairing with the device playing music.
focused on wearable projects. can be changed to control other features, just like using BLE.
Until this moment i have two projects.

**Wi-Fi Status Display on LED Matrix**
**Este projeto exibe informações de status da conexão Wi-Fi em uma matriz de LED usando o ESP32. Ele combina conectividade Wi-Fi e um painel de LEDs para fornecer atualizações em tempo real, como redes disponíveis, status de conexão e endereço IP obtido.**

**Funcionalidades**
Conexão automática a redes Wi-Fi configuradas.
Exibição do progresso da conexão ("Connecting to [SSID]...").
Mensagem de sucesso ao conectar, incluindo o nome da rede e o endereço IP.
Reconexão automática em caso de desconexão.
Atualização contínua do status do Wi-Fi na matriz de LED.
Tecnologias Utilizadas
ESP32: Para conectar às redes Wi-Fi e controlar a matriz de LED.
**Bibliotecas:**
WiFi.h: Gerenciamento de conexão Wi-Fi.
Max72xxPanel: Controle de uma matriz de LEDs com módulos baseados no MAX7219.
Adafruit_GFX: Suporte para fontes e gráficos no painel.
**Hardware Necessário**
ESP32.
Módulos de matriz de LED baseados no MAX7219 (quantidade configurável).
Fonte de alimentação para o ESP32 e a matriz de LED.
Como Usar
**Configurar Redes Wi-Fi:**
Insira os nomes das redes (ssid) e senhas (password) no código.
Conectar a Matriz de LED:
**Configure o número d**e módulos e ajuste a rotação física de cada módulo no código.
Carregar o Código:![main_0_](https://github.com/user-attachments/assets/7fb67350-e3b7-44a3-9d98-626d538d2586)

Faça o upload do programa para o ESP32 usando a IDE Arduino.
**Monitorar o Status:**
Acompanhe as mensagens de conexão diretamente na matriz de LED.
**Exemplo de Exibição**
"Connecting to Network1..."
"Connected to Network1"
"IP: 192.168.0.101"
"Wi-Fi: Network1"
![main_6_](https://github.com/user-attachments/assets/a5ffaa1c-f298-49f6-abc4-dde226aa5a38)
