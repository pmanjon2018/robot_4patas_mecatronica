#ifndef STEPS_H
#define STEPS_H

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "config.h"

extern Adafruit_PWMServoDriver pca;
void comprobarBotonPausa();

// --- VARIABLES DEL MOTOR DE FLUIDEZ ---
float anguloActual[12];
float anguloObjetivo[12];
float velocidad[12];
unsigned long ultimoUpdate = 0;
const int FRECUENCIA_UPDATE = 20; // 50Hz

const int BL_SHOULDER_FIX = -3;
const int BL_KNEE_FIX = -4;
const int FL_KNEE_FIX = -8;

uint16_t anguloAPulse(int ang) {
ang = constrain(ang, 0, 180);
return map(ang, 0, 180, SERVO_MIN, SERVO_MAX);
}

void iniciarInterpolador() {
for(int i = 0; i < 12; i++) {
anguloActual[i] = center[i];
anguloObjetivo[i] = center[i];
}
}

void setTarget(int channel, int offset) {
anguloObjetivo[channel] = center[channel] + (dir[channel] * offset);
}

void setLegTarget(const int leg[3], int hipOffset, int shoulderOffset, int kneeOffset) {
setTarget(leg[0], hipOffset);
setTarget(leg[1], shoulderOffset);
setTarget(leg[2], kneeOffset);
}

void esperarMovimientoFluido(int tiempoTotal) {
int pasos = tiempoTotal / FRECUENCIA_UPDATE;
for(int i = 0; i < 12; i++) {
velocidad[i] = (anguloObjetivo[i] - anguloActual[i]) / pasos;
}

unsigned long tiempoInicio = millis();

while (millis() - tiempoInicio < tiempoTotal) {
comprobarBotonPausa();
if (sistemaPausado) return;

if (millis() - ultimoUpdate >= FRECUENCIA_UPDATE) {
ultimoUpdate = millis();

for(int i = 0; i < 12; i++) {
if (abs(anguloObjetivo[i] - anguloActual[i]) > abs(velocidad[i])) {
anguloActual[i] += velocidad[i];
} else {
anguloActual[i] = anguloObjetivo[i];
}
pca.setPWM(i, 0, anguloAPulse((int)anguloActual[i]));
}
}
}
}

void standPose() {
int shoulderDown = 30;
int kneeSupport = 30;

setLegTarget(FL, 0, shoulderDown, kneeSupport + FL_KNEE_FIX);
setLegTarget(FR, 0, shoulderDown, kneeSupport);
setLegTarget(BL, 0, shoulderDown + BL_SHOULDER_FIX, kneeSupport + BL_KNEE_FIX);
setLegTarget(BR, 0, shoulderDown, kneeSupport);

esperarMovimientoFluido(1000);
}

// =========================================================
// MARCHA CONTINUA FLUIDA CON LA NUEVA CALIBRACIÓN
// =========================================================
void avanzarPaso() {
if (sistemaPausado) return;

// 1. LAS BASES (La postura perfecta que acabas de lograr)
int baseShoulder = 30;
int baseKnee = 30;

// 2. EL LEVANTAMIENTO (Para que no arrastre la pata)
int liftShoulder = 60; // Más positivo = levanta más el codo hacia el techo
int liftKnee = 15; // Estira un pelín la rodilla para alcanzar más lejos

// Dividimos la zancada en 4 posiciones para las caderas
int H3 = HIP_SWING; // Punta delantera
int H2 = HIP_SWING / 3; // Apoyo medio-delantero
int H1 = -HIP_SWING / 3; // Apoyo medio-trasero
int H0 = -HIP_SWING; // Punta trasera

// --- FASE 1: AVANZA FR (Las otras 3 deslizan hacia atrás) ---
setLegTarget(FR, H0, liftShoulder, liftKnee); // Levanta
esperarMovimientoFluido(STEP_DELAY);

setLegTarget(FR, H3, liftShoulder, liftKnee); // FR tira adelante en el aire
setLegTarget(BL, H0, baseShoulder, baseKnee); // Empuja
setLegTarget(FL, H1, baseShoulder, baseKnee); // Empuja
setLegTarget(BR, H2, baseShoulder, baseKnee); // Empuja
esperarMovimientoFluido(STEP_SETTLE);

setLegTarget(FR, H3, baseShoulder, baseKnee); // Apoya
esperarMovimientoFluido(STEP_DELAY);
if (sistemaPausado) return;

// --- FASE 2: AVANZA BL (Las otras 3 deslizan hacia atrás) ---
setLegTarget(BL, H0, liftShoulder, liftKnee);
esperarMovimientoFluido(STEP_DELAY);

setLegTarget(BL, H3, liftShoulder, liftKnee);
setLegTarget(FL, H0, baseShoulder, baseKnee);
setLegTarget(BR, H1, baseShoulder, baseKnee);
setLegTarget(FR, H2, baseShoulder, baseKnee);
esperarMovimientoFluido(STEP_SETTLE);

setLegTarget(BL, H3, baseShoulder, baseKnee);
esperarMovimientoFluido(STEP_DELAY);
if (sistemaPausado) return;

// --- FASE 3: AVANZA FL (Las otras 3 deslizan hacia atrás) ---
setLegTarget(FL, H0, liftShoulder, liftKnee);
esperarMovimientoFluido(STEP_DELAY);

setLegTarget(FL, H3, liftShoulder, liftKnee);
setLegTarget(BR, H0, baseShoulder, baseKnee);
setLegTarget(FR, H1, baseShoulder, baseKnee);
setLegTarget(BL, H2, baseShoulder, baseKnee);
esperarMovimientoFluido(STEP_SETTLE);

setLegTarget(FL, H3, baseShoulder, baseKnee);
esperarMovimientoFluido(STEP_DELAY);
if (sistemaPausado) return;

// --- FASE 4: AVANZA BR (Las otras 3 deslizan hacia atrás) ---
setLegTarget(BR, H0, liftShoulder, liftKnee);
esperarMovimientoFluido(STEP_DELAY);

setLegTarget(BR, H3, liftShoulder, liftKnee);
setLegTarget(FR, H0, baseShoulder, baseKnee);
setLegTarget(BL, H1, baseShoulder, baseKnee);
setLegTarget(FL, H2, baseShoulder, baseKnee);
esperarMovimientoFluido(STEP_SETTLE);

setLegTarget(BR, H3, baseShoulder, baseKnee);
esperarMovimientoFluido(STEP_DELAY);
}

#endif