#ifndef CONFIG_H
#define CONFIG_H

const int triggerFrente = 2;
const int echoFrente = 3;
const int triggerIzquierda = 4;
const int echoIzquierda = 5;

const int pinBoton = 9;
const int ledRojo = 6;
const int ledAmarillo = 7;
const int ledVerde = 8;

const int DIST_OBSTACULO_FRENTE = 25;
const int PARED_IDEAL_IZQ = 20;
const int MARGEN_PARED = 5;

const int SERVO_MIN = 110;
const int SERVO_MAX = 510;

const int FL[3] = {1, 0, 2};
const int FR[3] = {4, 3, 5};
const int BL[3] = {7, 6, 8};
const int BR[3] = {9, 10, 11};

int center[12] = {
  90, 90, 90,
  90, 90, 90,
  90, 90, 90,
  90, 90, 90
};

int dir[12] = {
  1, -1, 1,
 -1, 1, -1,
 -1, -1, -1,
  1, 1, 1
};

const int HIP_SWING = 20;
const int SHOULDER_LIFT = 15;
const int KNEE_BEND = 35;

const int STEP_DELAY = 200;
const int STEP_SETTLE = 250;

const char* nombres[4] = {
  "FL (Del. Izq)",
  "FR (Del. Der)",
  "BL (Tras. Izq)",
  "BR (Tras. Der)"
};

extern volatile boolean sistemaPausado;

#endif