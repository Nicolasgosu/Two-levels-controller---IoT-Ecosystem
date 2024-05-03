#include <Wire.h>

#define SLAVE_ADDRESS 9

void setup() {
  Wire.begin(SLAVE_ADDRESS);  // Inicia la comunicación I2C como esclavo
  Wire.onReceive(receiveEvent); // Configura la función para manejar la recepción de datos
  Serial.begin(9600);          // Inicia la comunicación serial para debug
}

void loop() {
  delay(100);  // Espera un poco para no saturar la comunicación
}

void receiveEvent(int bytes) {
  while (Wire.available()) {     // Mientras haya datos disponibles
    char c = Wire.read();         // Lee el dato recibido
    Serial.print(c);              // Muestra el dato recibido en el puerto serial
  }
}
