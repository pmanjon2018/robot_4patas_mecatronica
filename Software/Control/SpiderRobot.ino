#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pca = Adafruit_PWMServoDriver(0x40);
volatile boolean sistemaPausado = true;

#include "config.h"
// #include "sensor.h" // Descomenta esto si tienes la pestaña sensor.h en tu IDE
#include "steps.h"

unsigned long ultimoTiempoBoton = 0;

void comprobarBotonPausa() {
  // Leemos si el botón ha sido pulsado
  if (digitalRead(pinBoton) == LOW) {
    // Si han pasado más de 300ms desde el último toque (evita dobles lecturas)
    if (millis() - ultimoTiempoBoton > 300) {
      sistemaPausado = !sistemaPausado; // Cambiamos el estado al instante
      ultimoTiempoBoton = millis(); // Guardamos el momento del toque
      if (sistemaPausado) {
        Serial.println("\n========= SISTEMA PAUSADO =========");
        // TRUCO: Despausamos temporalmente a nivel interno para que el robot
        // pueda usar la interpolación de ponerse firme, y luego lo volvemos a pausar.
        sistemaPausado = false;
        standPose();
        sistemaPausado = true;
      } else {
        Serial.println("\n========= SISTEMA INICIADO =========");
      }
    }
  }
}

void setup() {
Serial.begin(115200);
Wire.begin();

pca.begin();
pca.setPWMFreq(50); // Mantenemos 50Hz, la frecuencia perfecta para MG90S

// ========================================================
// ¡AQUÍ ESTÁ EL SECRETO DE LA FLUIDEZ!
// Cargamos los ángulos iniciales en la memoria antes de mover
// ========================================================
iniciarInterpolador();

// configurarSensores(); // Descomenta esto si usas tus ultrasonidos

pinMode(pinBoton, INPUT_PULLUP);

Serial.println("=============================================");
Serial.println(" ESPERANDO PULSACION DEL BOTON PARA INICIAR ");
Serial.println("=============================================");

// Se pone de pie de forma súper suave usando la nueva función
sistemaPausado = false;
standPose();
sistemaPausado = true;
}

void loop() {
comprobarBotonPausa();

// Si está pausado, no hace nada, solo espera al botón
if (sistemaPausado) {
delay(100);
return;
}

// encenderSoloLed(ledVerde); // Descomenta esto si usas el LED

// Ejecuta la marcha de gateo fluida
avanzarPaso();
}