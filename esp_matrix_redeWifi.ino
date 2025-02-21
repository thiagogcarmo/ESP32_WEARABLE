
#############################################################################################################
# Esse modulo de programa visa manter buscar sempre a disponibilidade de internet para o modulo esp32,
# permitindo cadastrar diversas redes que estiverem ao alcançe do dispositivo.
# A rotina, que pode ter implementada usando 'interrupts' ou o modulo nativo theadhs para processamento em 
# parelelo, para não atrapalhar a função principal (verificar essa possibilidade).
# A rotina é verificar o status da rede, de tempo em tempo (esse tempo está na linha 104), e, em caso de 
# falha de internet, tentar conectar na proxima rede disponível.
#
##############################################################################################################


#include <WiFi.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

// Configuração da matriz de LEDs
const int pinCS = 5;               // Pino CS da matriz
const int numberOfDisplays = 8;     // Número de módulos conectados
const int width = 8;                // Largura de cada módulo (normalmente 8 pixels)
const int height = 8;               // Altura de cada módulo (normalmente 8 pixels)

// Inicializa a matriz
Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfDisplays, 1);

// Configuração das redes Wi-Fi
const char* ssid[] = {"Network1", "Network2", "Rede 1", "Zamix"};
const char* password[] = {"password1", "password2", "maris2318", "maris2318"};
const int num_networks = 4;

int currentNetwork = -1; // Rede atual conectada (-1 indica nenhuma rede)

// Configura a rotação dos módulos
void setupRotations() {
  for (int i = 0; i < numberOfDisplays; i++) {
    matrix.setRotation(i, 1); // Ajuste conforme a orientação física dos módulos
  }
}

// Função para exibir mensagens na matriz
void displayMessage(String text, int delayTime = 50) {
  matrix.fillScreen(LOW);  // Limpa a matriz
  int textWidth = text.length() * 6; // Largura do texto em pixels
  for (int x = 0; x < textWidth + width; x++) {
    matrix.fillScreen(LOW);
    matrix.setCursor(width - x, 0);
    matrix.print(text);
    matrix.write();
    delay(delayTime);  // Controla a velocidade do scroll
  }
}

// Função para conectar ao Wi-Fi
void connectToWiFi() {
  for (int i = 0; i < num_networks; i++) {
    String connectingMsg = "Connecting to " + String(ssid[i]) + "...";
    displayMessage(connectingMsg);

    WiFi.begin(ssid[i], password[i]);

    // Tenta conectar por até 10 segundos
    int attempt = 0;
    while (WiFi.status() != WL_CONNECTED && attempt < 10) {
      delay(1000);
      attempt++;
    }

    if (WiFi.status() == WL_CONNECTED) {
      currentNetwork = i; // Salva o índice da rede conectada
      String connectedMsg = "Connected to " + String(ssid[i]);
      displayMessage(connectedMsg);
      displayMessage("IP: " + WiFi.localIP().toString());
      return;
    }
  }

  displayMessage("No networks found");
  currentNetwork = -1; // Indica falha na conexão
}

void setup() {
  Serial.begin(9600);

  // Configura a matriz de LEDs
  setupRotations(); // Define a rotação correta de cada módulo
  matrix.setIntensity(3);  // Ajusta o brilho
  matrix.fillScreen(LOW);
  matrix.write();

  displayMessage("Starting ESP32...");
  delay(2000);

  connectToWiFi();
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    displayMessage("Disconnected. Reconnecting...");
    connectToWiFi();
  } else if (currentNetwork >= 0) {
    String statusMsg = "Wi-Fi: " + String(ssid[currentNetwork]);
    displayMessage(statusMsg, 100); // Mensagem fixa ou com scrolling lento
  }
  delay(5000); // Aguarda 5 segundos antes de verificar novamente
}
