#include <DHT.h>
#include <SoftwareSerial.h>

#define DHTPIN 2          // Pin de datos del sensor DHT
#define DHTTYPE DHT11     // O DHT22, dependiendo del sensor que tengas
#define BUZZER_PIN 13      // Pin donde está conectado el buzzer

DHT dht(DHTPIN, DHTTYPE); // Inicializa el sensor DHT

// Configuración de SoftwareSerial para HC-05
SoftwareSerial BTSerial(10, 11);  // RX, TX (en este caso, usaremos pines 10 y 11)

// Inicializa la comunicación serial Bluetooth
void setup() {
  Serial.begin(9600);   // Comunicación serial con el monitor serial
  BTSerial.begin(9600); // Comunicación con el módulo HC-05
  dht.begin();
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // Lee la humedad
  float humedad = dht.readHumidity();
  
  // Verifica si la lectura es válida
  if (isnan(humedad)) {
    Serial.println("Error al leer el sensor");
    return;
  }
  
  // Muestra la humedad en el puerto serial
  Serial.print("Humedad: ");
  Serial.print(humedad);
  Serial.println(" %");

  // Si la humedad es mayor que un umbral, enciende el buzzer
  if (humedad > 60) {  // Ajusta este valor según tu necesidad
    digitalWrite(BUZZER_PIN, HIGH);  // Enciende el buzzer
    BTSerial.println("ALERTA: Humedad alta!");  // Envía la señal Bluetooth
  } else {
    digitalWrite(BUZZER_PIN, LOW);   // Apaga el buzzer
  }

  delay(2000); // Espera 2 segundos antes de la siguiente lectura
}