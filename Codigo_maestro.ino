#include <Wire.h>

#define LED_PIN 13 // Pin del LED

void setup() {
  Wire.begin(); // Inicia la comunicación I2C como maestro
  pinMode(LED_PIN, OUTPUT); // Configura el pin del LED como salida
  Serial.begin(9600); // Inicia la comunicación serial a 9600 baudios
}

void loop() {
  float temperatura;

  // Solicita datos al esclavo
  Wire.requestFrom(8, sizeof(temperatura));
  
  // Espera a que los datos estén disponibles
  while (Wire.available() < sizeof(temperatura));
  
  // Lee los datos del esclavo
  Wire.readBytes((byte*)&temperatura, sizeof(temperatura));
  
  // Imprime la temperatura recibida por la consola serial
  
  Serial.println(temperatura);
  
  
  // Realiza alguna acción basada en los datos recibidos
  if (temperatura > 25.0) {
    digitalWrite(LED_PIN, HIGH); // Enciende el LED si la temperatura es mayor a 25°C
  } else {
    digitalWrite(LED_PIN, LOW); // Apaga el LED si la temperatura es menor o igual a 25°C
  }

  delay(1000); // Espera 1 segundo antes de solicitar nuevamente los datos
}
