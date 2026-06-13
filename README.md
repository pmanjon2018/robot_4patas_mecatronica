# Robot Cuadrúpedo Autónomo 🤖

Este repositorio contiene la documentación técnica y el código fuente del proyecto final de **Robot con Patas** para la asignatura de **Mecatrónica**. En este trabajo se ha diseñado, fabricado, programado y validado experimentalmente un robot cuadrúpedo capaz de desplazarse de forma estable, transportar carga útil, realizar el seguimiento continuo de una pared y navegar autónomamente evadiendo obstáculos del entorno.

---

## 📋 Índice
1. [Descripción General](#-descripción-general)
2. [Objetivos Cumplidos](#-objetivos-cumplidos)
3. [Restricciones de Diseño](#-restricciones-de-diseño)
4. [Diseño y Arquitectura del Sistema](#-diseño-y-arquitectura-del-sistema)
5. [Problemas Encontrados y Soluciones Adoptadas](#-problemas-encontrados-y-soluciones-adoptadas)
6. [Modos de Funcionamiento](#-modos-de-funcionamiento)
7. [Pruebas de Validación y Criterios de Éxito](#-pruebas-de-validación-y-criterios-de-éxito)
8. [Estructura del Repositorio](#%EF%B8%8F-estructura-del-repositorio)
9. [Documentación Adjunta](#-documentación-adjunta)

---

## 🔍 Descripción General

El propósito central de este proyecto ha sido el desarrollo integral de un **robot con patas completamente funcional**, unificando conceptos avanzados de diseño mecánico, electrónica de control, programación embebida en tiempo real, sistemas de alimentación autónoma y verificación empírica.

La elección de una configuración **cuadrúpeda** responde a un compromiso de ingeniería: proporciona un equilibrio óptimo entre estabilidad estática y dinámica, control de la complejidad mecánica y versatilidad de maniobra en entornos donde los robots con ruedas presentan limitaciones. El resultado es un prototipo robótico autónomo, desvinculado de conexiones umbilicales de alimentación, dotado de una estructura de fabricación propia y una interfaz hombre-máquina (HMI) básica para la gestión segura del encendido y apagado del sistema.

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
| **Alimentación** | 100% autónoma a bordo, implementada mediante el uso de baterías recargables. |
| **Aislamiento Eléctrico** | Ausencia absoluta de cables de alimentación o control externos hacia el entorno durante las pruebas. |
| **Estructura Portante** | Chasis y patas de fabricación propia, justificados técnicamente mediante selección de materiales y análisis funcional. |
| **Componentes Comerciales** | Permitidos exclusivamente para elementos genéricos de sensórica, actuación y placas de control. |
| **Interfaz de Usuario** | Inclusión obligatoria de un mecanismo básico de hardware para el arranque y la parada segura. |

---

## 🛠️ Diseño y Arquitectura del Sistema

El diseño mecánico de partida se basó en un modelo open source publicado en Thingiverse, concretamente el proyecto **“Spider robot (quad robot, quadruped)”**, un robot cuadrúpedo impreso en 3D y alimentado mediante Arduino [web:1]. A partir de esta referencia, se adaptaron distintos componentes con **Blender** para ajustarlos a los requisitos geométricos, estructurales y funcionales del proyecto [web:1].

Para simplificar las fases de diseño, manufactura y posterior integración mecatrónica, el robot se estructuró modularmente en los siguientes seis subsistemas interactuantes:

### 1. Estructura Mecánica
- **Componentes:** Chasis principal, soportes estructurales y eslabones de las patas.
- **Detalles:** Diseñados a medida y fabricados específicamente para este proyecto, optimizando la relación rigidez-peso y protegiendo los componentes electrónicos internos.

### 2. Sistema de Actuación
- **Componentes:** Servomotores o actuadores de alto torque distribuidos en las extremidades.
- **Detalles:** Responsables de ejecutar los patrones cinemáticos de las patas para la generación de la marcha (*gait*) y el mantenimiento del equilibrio dinámico.

### 3. Sensórica
- **Componentes:** Sensores de distancia y proximidad, como ultrasonido, infrarrojo o ToF.
- **Detalles:** Dispuestos para la detección lateral de paredes, el control de distancia en paralelo y la detección frontal de obstáculos en la trayectoria.

### 4. Control Embebido
- **Componentes:** Unidad de procesamiento central basada en microcontrolador o tarjeta de desarrollo embebida.
- **Detalles:** Encargada de la lógica de control en tiempo real, procesamiento de señales de sensores, coordinación de actuadores y gestión del comportamiento autónomo.

### 5. Alimentación y Potencia
- **Componentes:** Sistema de baterías recargables con pilas de 3.7V para la distribución de energía.
- **Detalles:** Garantiza el suministro estable del sistema, separando en la medida de lo posible la electrónica de control de la etapa de potencia de los motores.

### 6. Interfaz de Usuario
- **Componentes:** Botones físicos de interacción rápida y elementos visuales o sonoros de estado, como LEDs de diagnóstico.
- **Detalles:** Permite al operador inicializar las rutinas autónomas o inducir una parada controlada de forma inmediata.

> 💡 **Nota de ingeniería:** Esta división modular facilitó significativamente las tareas independientes de prueba, calibración de sensores, mantenimiento mecánico y aislamiento de errores de software y hardware.

---

## 🔧 Problemas Encontrados y Soluciones Adoptadas

Durante el desarrollo e integración del robot surgieron diversas incidencias mecánicas, electrónicas y de fabricación. La resolución de estos problemas fue fundamental para lograr una plataforma funcional y suficientemente robusta para las pruebas finales.

### 1. Problemas con las pilas recargables
Inicialmente se adquirieron pilas recargables que no incluían un cargador compatible, lo que impidió su uso inmediato en la fase de alimentación autónoma del sistema. Como solución, fue necesario comprar nuevas unidades y reorganizar temporalmente la estrategia de alimentación para continuar con el desarrollo.

### 2. Sensor de ultrasonidos averiado
Uno de los sensores de ultrasonidos dejó de funcionar correctamente durante la fase de integración, afectando a la fiabilidad de la detección de distancias. Para resolver esta incidencia, se sustituyó el sensor defectuoso y se recalibraron las lecturas del sistema.

### 3. Limitaciones en la impresión 3D
En una de las iteraciones de fabricación, algunas piezas impresas resultaron más pequeñas de lo esperado, lo que provocó problemas de acoplamiento y montaje. La solución consistió en revisar las dimensiones del diseño, modificar las medidas del modelo y volver a imprimir las piezas corregidas.

### 4. Mejora del giro en las articulaciones
Durante las pruebas se observó que ciertas articulaciones no giraban con la suavidad deseada, afectando a la calidad de la marcha. Para mejorar este comportamiento, se llevó a cabo una limpieza de los motores y un engrase de las zonas mecánicas con mayor fricción.

### 5. Motores averiados
Algunos motores se deterioraron o dejaron de responder correctamente tras varias sesiones de prueba. Fue necesario identificar las unidades dañadas, sustituirlas y volver a verificar el comportamiento de las patas afectadas.

### 6. Riesgo eléctrico por pilas defectuosas
En una fase del montaje, unas pilas defectuosas provocaron una situación de riesgo que estuvo cerca de dañar el Arduino. A partir de este incidente, se revisó completamente la alimentación del sistema, comprobando tensiones, conexiones y el estado real de las baterías antes de realizar nuevas pruebas.

### 7. Propuesta de mejora futura
Como mejora de diseño para futuras versiones, se plantea rediseñar el compartimento de alimentación para que las pilas sean más fáciles de extraer y sustituir. Esta modificación simplificaría el mantenimiento, la recarga y la seguridad general del sistema.

> 💡 **Lección de ingeniería:** Las incidencias encontradas pusieron de manifiesto la importancia de validar por separado la fabricación mecánica, la fiabilidad de la sensórica, el estado de los actuadores y la seguridad eléctrica antes de realizar ensayos completos del robot.

---

## 🕹️ Modos de Funcionamiento

El comportamiento global del robot está regido por una **Máquina de Estados Finitos (FSM)** programada para priorizar la estabilidad de la marcha, la seguridad del sistema y la repetibilidad del movimiento.

### Estados principales del sistema

- **Estado de reposo / espera:** El robot permanece detenido hasta recibir la orden de inicio mediante la interfaz física.
- **Estado de avance:** El robot ejecuta la marcha programada para desplazarse de forma controlada.
- **Estado de seguimiento de pared:** El sistema utiliza la sensórica lateral para mantener una distancia aproximadamente constante respecto a una pared de referencia.
- **Estado de detección de obstáculo:** Cuando se detecta un obstáculo en la trayectoria, se interrumpe el comportamiento de avance normal.
- **Estado de evasión:** El robot ejecuta una maniobra correctiva para esquivar el obstáculo y recuperar una trayectoria válida.
- **Estado de parada segura:** Ante una orden del usuario o una condición crítica, el sistema detiene progresivamente los actuadores para evitar movimientos bruscos o daños mecánicos.

### Lógica general de operación

La FSM se diseñó con una filosofía reactiva, permitiendo cambiar entre estados en función de las lecturas de los sensores y de las condiciones del entorno. Este enfoque facilita una implementación clara, depurable y adecuada para sistemas embebidos con recursos limitados.

---

## ✅ Pruebas de Validación y Criterios de Éxito

Con el fin de verificar el cumplimiento de los objetivos del proyecto, se realizaron diferentes pruebas experimentales sobre el prototipo final.

### 1. Prueba de desplazamiento estable
Se comprobó la capacidad del robot para avanzar de forma continua sin pérdidas significativas de equilibrio ni bloqueos mecánicos en las articulaciones.

### 2. Prueba de seguimiento de pared
Se validó el funcionamiento del sistema de sensórica lateral y del algoritmo de control asociado, verificando que el robot fuese capaz de desplazarse manteniendo una referencia lateral razonablemente constante.

### 3. Prueba de evasión de obstáculos
Se evaluó la respuesta del robot ante la presencia de obstáculos en su trayectoria, comprobando que detectaba el objeto y ejecutaba una maniobra correctiva sin intervención externa.

### 4. Prueba de carga útil
Se verificó que el robot era capaz de transportar una masa de **250 g** distribuida sobre una superficie útil de **5 cm x 5 cm**, manteniendo un comportamiento aceptable durante el desplazamiento.

### 5. Prueba de autonomía funcional
Se comprobó que el sistema era capaz de operar alimentado exclusivamente por baterías, sin depender de cables externos durante la ejecución de las pruebas.

### Criterios de éxito
Se consideró que la validación del sistema era satisfactoria cuando el robot:
- Se desplazaba de forma estable.
- Mantenía el seguimiento de pared.
- Detectaba y evitaba obstáculos.
- Soportaba la carga útil especificada.
- Funcionaba de forma autónoma con alimentación embarcada.

---

## 🗂️ Estructura del Repositorio

La organización del repositorio se ha planteado para separar claramente el código, la documentación y los recursos de diseño:

```bash
.
├── README.md
├── docs/
│   ├── memoria.pdf
│   ├── esquemas/
│   └── pruebas/
├── firmware/
│   ├── main.ino
│   ├── sensores/
│   ├── actuadores/
│   └── control/
├── hardware/
│   ├── diseno_3d/
│   ├── esquemas_electricos/
│   └── lista_componentes/
└── media/
    ├── imagenes/
    └── videos/
```

> **Nota:** La estructura exacta puede adaptarse en función de la evolución del proyecto y del material finalmente incorporado al repositorio.

---

## 📎 Documentación Adjunta

Este repositorio puede incluir la siguiente documentación complementaria para reforzar la trazabilidad técnica del proyecto:

- Memoria técnica completa del sistema.
- Planos, modelos y modificaciones de las piezas impresas en 3D.
- Esquemas eléctricos y de alimentación.
- Código fuente del control embebido.
- Fotografías del montaje final.
- Evidencias experimentales en vídeo o capturas de las pruebas realizadas.

---

## 👨‍🔧 Autor

Proyecto desarrollado como trabajo final para la asignatura de **Mecatrónica**, orientado al diseño, construcción, integración y validación de un **robot cuadrúpedo autónomo**.
