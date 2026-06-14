#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Inicializamos el controlador PCA9685
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Configuración de los pulsos del Servo MG90S
#define SERVOMIN  150 // Pulso mínimo (0 grados)
#define SERVOMAX  600 // Pulso máximo (180 grados)

void setup() {
  Serial.begin(9600);
  Serial.println("--- INICIANDO TEST DE INTEGRACIÓN: 12 MOTORES ---");
  
  pwm.begin();
  pwm.setPWMFreq(60); // Frecuencia estándar para servos analógicos
  delay(100);
}

void loop() {
  // Bucle que recorre los puertos del 0 al 11
  for (uint8_t puerto = 0; puerto <= 11; puerto++) {
    Serial.print("Probando motor en el PIN: ");
    Serial.println(puerto);
    
    // 1. Mueve a 0 grados
    pwm.setPWM(puerto, 0, SERVOMIN);
    delay(400); // Espera 400ms para darle tiempo a llegar
    
    // 2. Mueve al centro (90 grados)
    int pulsoCentro = map(90, 0, 180, SERVOMIN, SERVOMAX);
    pwm.setPWM(puerto, 0, pulsoCentro);
    delay(400);
    
    // 3. Mueve a 180 grados
    pwm.setPWM(puerto, 0, SERVOMAX);
    delay(400);
    
    // 4. Lo devuelve a la posición de reposo (90 grados) antes de pasar al siguiente
    pwm.setPWM(puerto, 0, pulsoCentro);
    delay(800); // Pausa un poco más larga para que notes el cambio de motor
  }
  
  Serial.println("--- CICLO COMPLETADO. REINICIANDO EN 3 SEGUNDOS ---");
  delay(3000); // Pausa de 3 segundos antes de volver a empezar el test
}