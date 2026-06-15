#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pca = Adafruit_PWMServoDriver(0x40);
volatile boolean sistemaPausado = true;

#include "config.h"
#include "sensor.h"
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

configurarSensores();

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

  // --- LÓGICA DE DETECCIÓN Y SEGURIDAD ---
  int distanciaFrente = obtenerDistancia(triggerFrente, echoFrente, "Frente");

  // REGLA 1: Emergencia - Si está a 5 cm o menos de la pared
  if (distanciaFrente <= 6) {
    Serial.println("\n[¡ALERTA!] ¡Pared demasiado cerca! Parada de emergencia.");
    encenderSoloLed(ledRojo); // Mantenemos el rojo encendido
    
    // Hacemos que el robot se ponga firme de forma suave antes de pausar
    standPose(); 
    sistemaPausado = true; // Pausamos el sistema automáticamente
    return; // Salimos del loop para que no intente dar el siguiente paso
  }
  
  // REGLA 2: Aviso - Si está a 15 cm o menos de la pared
  else if (distanciaFrente <= 15) {
    encenderSoloLed(ledRojo); // Encendemos ROJO (Pared detectada)
  } 
  
  // REGLA 3: Camino libre
  else {
    encenderSoloLed(ledVerde); // Encendemos VERDE (Todo despejado)
  }

  // Ejecuta la marcha de gateo fluida
  avanzarPaso();
}