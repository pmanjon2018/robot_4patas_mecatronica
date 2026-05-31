## Robot Cuadrúpedo Autónomo 🤖

Este repositorio contiene la documentación técnica y el código fuente del proyecto final de **Robot con Patas** para la asignatura de **Mecatrónica**. En este trabajo se ha diseñado, fabricado, programado y validado experimentalmente un robot cuadrúpedo capaz de desplazarse de forma estable, transportar carga útil, realizar el seguimiento continuo de una pared y navegar autónomamente evadiendo obstáculos del entorno.

---

## 📋 Índice
1. [Descripción General](#-descripción-general)
2. [Objetivos Cumplidos](#-objetivos-cumplidos)
3. [Restricciones de Diseño](#-restricciones-de-diseño)
4. [Diseño y Arquitectura del Sistema](#-diseño-y-arquitectura-del-sistema)
5. [Modos de Funcionamiento](#%EF%B8%8F-modos-de-funcionamiento)
6. [Pruebas de Validación y Criterios de Éxito](#-pruebas-de-validación-y-criterios-de-éxito)
7. [Estructura del Repositorio](#%EF%B8%8F-estructura-del-repositorio)
8. [Documentación Adjunta](#-documentación-adjunta)

---

## 🔍 Descripción General

El propósito central de este proyecto ha sido el desarrollo integral de un **robot con patas completamente funcional**, unificando conceptos avanzados de diseño mecánico, electrónica de control, programación embebida en tiempo real, sistemas de alimentación autónoma y verificación empírica. 

La elección de una configuración **cuadrúpeda** responde a un compromiso de ingeniería: proporciona un equilibrio óptimo entre estabilidad estática y dinámica, control de la complejidad mecánica y versatilidad de maniobra en entornos donde los robots con ruedas presentan limitaciones. El resultado es un prototipo robótico autónomo, desvinculado de conexiones umbilicales de alimentación, dotado de una estructura estructural de fabricación propia y una interfaz hombre-máquina (HMI) básica para la gestión segura del encendido y apagado del sistema.

---

## 🎯 Objetivos Cumplidos

A lo largo del desarrollo del proyecto, se lograron satisfacer satisfactoriamente los siguientes objetivos funcionales e hitos de ingeniería:
- [x] **Diseño y construcción:** Estructura física robusta, ligera y balanceada para un robot cuadrúpedo.
- [x] **Integración mecatrónica:** Acoplamiento óptimo de actuadores, sensórica de distancia, electrónica de control y sistemas de potencia.
- [x] **Locomoción guiada:** Implementación de algoritmos de marcha estables para el desplazamiento paralelo respecto a una pared de referencia.
- [x] **Capacidad de carga:** Capacidad probada de transporte de una carga muerta de **250 g** sobre una sección útil especificada de **5 cm x 5 cm**.
- [x] **Navegación inteligente:** Desarrollo de una lógica reactiva y autónoma para la evasión de obstáculos en tiempo real.
- [x] **Validación empírica:** Superación exitosa de pruebas experimentales en escenarios físicos controlados.

---

## ⚙️ Restricciones de Diseño

El prototipo final se consolidó respetando estrictamente el marco de restricciones técnicas y operativas del proyecto:

| Criterio | Restricción / Especificación Técnica |
| :--- | :--- |
| **Dimensiones Máximas** | Envolvente cúbica máxima de 30 cm de alto, 30 cm de ancho y 30 cm de profundidad. |
| **Alimentación** | 100% Autónoma a bordo, implementada mediante el uso de baterías recargables. |
| **Aislamiento Eléctrico** | Ausencia absoluta de cables de alimentación o control externos hacia el entorno durante las pruebas. |
| **Estructura Portante** | Chasis y patas de fabricación propia (justificados técnicamente mediante selección de materiales y esfuerzos). |
| **Componentes Comerciales** | Permitidos exclusivamente para elementos genéricos de sensórica, actuación y placas de control. |
| **Interfaz de Usuario** | Inclusión obligatoria de un mecanismo básico de hardware para el arranque y la parada segura. |

---

## 🛠️ Diseño y Arquitectura del Sistema

Para simplificar las fases de diseño, manufactura y posterior integración mecatrónica, el robot se estructuró modularmente en los siguientes seis subsistemas interactuantes:

### 1. Estructura Mecánica
* **Componentes:** Chasis principal, soportes estructurales y eslabones de las patas.
* **Detalles:** Diseñados a medida y fabricados específicamente para este proyecto, optimizando la relación rigidez-peso y protegiendo los componentes electrónicos internos.

### 2. Sistema de Actuación
* **Componentes:** Servomotores/actuadores de alto torque distribuidos en las extremidades.
* **Detalles:** Responsables de ejecutar los patrones cinemáticos de las patas para la generación de la marcha (gait) y el mantenimiento del equilibrio dinámico.

### 3. Sensórica
* **Componentes:** Sensores de distancia y proximidad (p. ej., ultrasonido, infrarrojo o ToF).
* **Detalles:** Dispuestos para la detección lateral de paredes (control de distancia en paralelo) y detección frontal de obstáculos en la trayectoria.

### 4. Control Embebido
* **Componentes:** Unidad de procesamiento central (microcontrolador o tarjeta de desarrollo embebida).
* **Detalles:** Encargado de la lógica de control en tiempo real, procesamiento de señales de sensores, resolución cinemática y coordinación síncrona de los actuadores.

### 5. Alimentación y Potencia
* **Componentes:** Batería recargable y etapa de regulación/distribución de energía.
* **Detalles:** Garantiza el suministro estable y desacoplado eléctricamente entre la etapa de control (sensible al ruido) y la etapa de potencia (motores).

### 6. Interfaz de Usuario
* **Componentes:** Botones físicos de interacción rápida y elementos visuales/sonoros de estado (p. ej., LEDs de diagnóstico).
* **Detalles:** Permite al operador inicializar las rutinas autónomas o inducir una parada controlada inmediatamente.

> 💡 **Nota de Ingeniería:** Esta división modular facilitó de forma significativa las tareas independientes de prueba, calibración analítica de sensores y aislamiento de errores de software/hardware.

---

## 🕹️ Modos de Funcionamiento

El comportamiento global del robot está regido por una Máquina de Estados Finitos (FSM) programada para priorizar la estabilidad de la marcha y la repetibilidad del movimiento:
