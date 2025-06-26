#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define TRIG_PIN 7      // Pin TRIG del sensor ultrasónico
#define ECHO_PIN 8      // Pin ECHO del sensor ultrasónico
#define MOTOR_ENA 11    // Pin PWM para controlar velocidad del motor
#define MOTOR_IN1 9     // Dirección del motor hacia la izquierda
#define MOTOR_IN2 10    // Dirección del motor hacia la derecha
#define DHTPIN 4        // Pin donde está conectado el DHT22
#define DHTTYPE DHT22   // Tipo de sensor DHT (DHT22)

DHT dht(DHTPIN, DHTTYPE);

float temperatura = 0.0;
float distanciaActual = 0.0;

void setup() {
  Serial.begin(9600);     // Iniciar el monitor serial para detectar la tecla SPACE
  dht.begin();            // Iniciar el sensor DHT22

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(MOTOR_ENA, OUTPUT);
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);

  Serial.println("Motor moviéndose entre 3 cm y 14 cm...");
}

void loop() {
  // Leer temperatura
  temperatura = dht.readTemperature();
  
  // Leer distancia con el sensor ultrasónico
  distanciaActual = medirDistancia();

  // Mostrar temperatura y distancia en el Monitor Serial
  Serial.print("Temp: ");
  Serial.print(temperatura);
  Serial.print(" C | Dist: ");
  Serial.print(distanciaActual);
  Serial.println(" cm");

  // Si la distancia detectada es menor a 3 cm, detenerse y mover a la derecha
  if (distanciaActual <= 5.0) {
    detenerMotor();
    delay(500);  // Pausar 500 ms antes de mover el motor a la derecha
    moverMotorIzquierda();  // Mover el motor hacia la izquierda
  } 

  // Si la distancia detectada es mayor o igual a 14 cm, detenerse y mover a la izquierda
  else if (distanciaActual >= 16.0) {
    detenerMotor();
    delay(500);  // Pausar 500 ms antes de mover el motor a la izquierda
    moverMotorDerecha();  // Mover el motor hacia la derecha

  }

  // Esperar un poco antes de la siguiente medición para evitar movimientos bruscos
  delay(100);
}

// Función para mover el motor hacia la derecha
void moverMotorDerecha() {
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, HIGH);
  analogWrite(MOTOR_ENA, 255);  // Máxima velocidad
  Serial.println("Moviendo motor a la derecha");
}

// Función para mover el motor hacia la izquierda
void moverMotorIzquierda() {
  digitalWrite(MOTOR_IN1, HIGH);
  digitalWrite(MOTOR_IN2, LOW);
  analogWrite(MOTOR_ENA, 255);  // Máxima velocidad
  Serial.println("Moviendo motor a la izquierda");
}

// Función para detener el motor
void detenerMotor() {
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, LOW);
  analogWrite(MOTOR_ENA, 0);  // Detener el motor
}

// Función para medir la distancia usando el sensor ultrasónico
float medirDistancia() {
  long duracion;
  float distancia;
  
  digitalWrite(TRIG_PIN, LOW); 
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  duracion = pulseIn(ECHO_PIN, HIGH);
  distancia = (duracion * 0.0343) / 2; // Calcular la distancia en centímetros
  
  return distancia;
}
