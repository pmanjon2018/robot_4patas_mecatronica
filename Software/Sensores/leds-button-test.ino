// --- CONFIGURACIÓN DE PINES ---
const int PIN_BOTON = 9;
const int LED_ROJO = 6;
const int LED_VERDE = 7;

void setup() {
  Serial.begin(9600);
  // Configuramos el botón con resistencia interna
  pinMode(PIN_BOTON, INPUT_PULLUP); 
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  Serial.println("Prueba de Interfaz lista. Presiona el botón.");
}

void loop() {
  // Al usar INPUT_PULLUP, LOW significa que el botón está presionado
  if (digitalRead(PIN_BOTON) == LOW) {
    Serial.println("¡Botón presionado!");
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_ROJO, LOW);
    delay(200); // Pequeño delay para evitar el rebote del botón
  } else {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_ROJO, HIGH);
  }
}