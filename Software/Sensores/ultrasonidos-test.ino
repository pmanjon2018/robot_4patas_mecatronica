const int PIN_TRIG = 3; // Trigger1
const int PIN_ECHO = 2; // Echo1
const int PIN_TRIG = 5; // Trigger2
const int PIN_ECHO = 4; // Echo2

void setup() {
  Serial.begin(9600);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  Serial.println("Iniciando prueba de Ultrasonidos...");
}

void loop() {
  // Limpiamos el pin Trigger
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  
  // Enviamos un pulso de 10 microsegundos
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);
  
  // Leemos el tiempo que tarda en volver el eco
  long duracion = pulseIn(PIN_ECHO, HIGH);
  
  // Calculamos la distancia en centímetros
  int distancia = duracion * 0.034 / 2;
  
  Serial.print("Distancia al obstáculo: ");
  Serial.print(distancia);
  Serial.println(" cm");
  
  delay(500); // Esperamos medio segundo antes de la siguiente lectura
}