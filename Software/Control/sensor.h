#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>
#include "config.h"

void configurarSensores() {
  pinMode(triggerFrente, OUTPUT);
  pinMode(echoFrente, INPUT);
  pinMode(triggerIzquierda, OUTPUT);
  pinMode(echoIzquierda, INPUT);

  pinMode(pinBoton, INPUT_PULLUP);

  pinMode(ledRojo, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void encenderSoloLed(int ledEncender) {
  digitalWrite(ledRojo, ledEncender == ledRojo ? HIGH : LOW);
  digitalWrite(ledAmarillo, ledEncender == ledAmarillo ? HIGH : LOW);
  digitalWrite(ledVerde, ledEncender == ledVerde ? HIGH : LOW);
}

int obtenerDistancia(int trigPin, int echoPin, const char* nombreSensor) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duracion = pulseIn(echoPin, HIGH, 20000);
  int distancia = duracion * 0.034 / 2;

  Serial.print("[SENSOR] ");
  Serial.print(nombreSensor);
  Serial.print(" -> Tiempo de Eco: ");
  Serial.print(duracion);
  Serial.print(" us | Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  if (distancia == 0 || distancia > 350) {
    return 400;
  }

  return distancia;
}

#endif