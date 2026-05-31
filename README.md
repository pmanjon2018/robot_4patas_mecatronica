| Robot cuadrúpedo autónomo |

-Repositorio del proyecto final de Robot con Patas de Mecatrónica. En este trabajo se ha diseñado, fabricado y programado un robot cuadrúpedo capaz de desplazarse de forma estable, transportar carga, seguir una pared y realizar navegación autónoma con evasión de obstáculos.
-El objetivo del proyecto ha sido desarrollar un robot con patas completamente funcional, integrando diseño mecánico, electrónica, control de movimiento, programación embebida, prototipado y validación experimental. Hemos optado por una configuración cuadrúpeda por su equilibrio entre estabilidad, complejidad mecánica y capacidad de maniobra.
-El resultado final es un robot autónomo, alimentado por baterías recargables, con estructura de fabricación propia y una interfaz básica de usuario para iniciar y detener el sistema.

| Objetivos cumplidos |

-Durante el desarrollo del proyecto se han cubierto los siguientes objetivos funcionales:

  -Diseño y construcción de un robot cuadrúpedo estable y funcional.
  -Integración de actuadores, sensores, electrónica de control y alimentación autónoma.
  -Implementación de locomoción para desplazamiento paralelo a una pared.
  -Transporte de una carga de 250 g sobre una superficie útil de 5 cm x 5 cm.
  -Desarrollo de una estrategia de evasión de obstáculos.
  -Validación del funcionamiento del robot mediante pruebas experimentales.
| Prueba 1: desplazamiento con carga | 

-El sistema debe ser capaz de moverse en paralelo a una pared plana durante al menos 1 metro, pudiendo estar la pared situada a cualquiera de los lados del robot. Además, la prueba debe realizarse transportando una carga de 250 gramos colocada sobre un área de 5 cm x 5 cm de la estructura, y completarse en menos de 1 minuto.

| Prueba 2: evasión y autonomía |

-El robot debe comenzar desde el centro de un cuadrado, desplazarse de forma autónoma, evitar obstáculos presentes en el entorno y alcanzar las paredes. Esta prueba debe completarse en un tiempo inferior a 2 minutos.

| Restricciones de diseño |

-El desarrollo del prototipo se ha ajustado a las restricciones impuestas por la práctica:

  -Dimensiones máximas de 30 cm de alto, 30 cm de ancho y 30 cm de profundidad.
  -Alimentación mediante baterías recargables.
  -Ausencia de cables de alimentación durante las pruebas.
  -Estructura de fabricación propia, con justificación técnica.
  -Uso permitido de componentes comerciales para sensores, actuadores y electrónica.
  -Inclusión de una interfaz básica de usuario para arranque y parada.
  
| Diseño del sistema |

-El robot se ha dividido en varios subsistemas para simplificar el diseño, la fabricación y la integración final:

  -Estructura mecánica: chasis principal, soportes y patas fabricadas específicamente para el proyecto.
  -Sistema de actuación: conjunto de actuadores responsables del movimiento de las patas y de la generación de la marcha.
  -Sensórica: sensores dedicados a la detección de pared, medida de distancia y evasión de obstáculos.
  -Control embebido: lógica de control encargada de coordinar sensores y actuadores en tiempo real.
  -Alimentación: batería recargable y sistema de distribución de energía.
  -Interfaz de usuario: mecanismo simple de arranque y parada, complementado con elementos visuales de estado.
  
-Esta organización ha permitido separar la parte mecánica, electrónica y software, facilitando las tareas de prueba, calibración y corrección de errores.

| Funcionamiento general |

-El robot dispone de distintos modos de funcionamiento orientados a las pruebas de la asignatura:

  -Inicialización: encendido del sistema, comprobación básica y puesta en posición inicial.
  -Modo desplazamiento: ejecución de la marcha necesaria para avanzar en paralelo a una pared manteniendo estabilidad y carga útil.
  -Modo autónomo: navegación desde la zona central del área de pruebas, detección de obstáculos y corrección de trayectoria.
  -Parada segura: detención del robot mediante la interfaz de usuario.
  
-El comportamiento general se ha planteado para priorizar estabilidad, repetibilidad.

| Validación realizada |

-Se han realizado pruebas de locomoción, estabilidad estructural, capacidad de carga, respuesta de los sensores, seguimiento de pared, evasión de obstáculos y funcionamiento autónomo dentro del espacio establecido.
-Además del prototipo funcional, hemos hecho un manual de usuario y mantenimiento, así como un informe de autoevaluación del equipo. Este repositorio sirve como apoyo documental y soporte de documentación técnica del proyecto.
