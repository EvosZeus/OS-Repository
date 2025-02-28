// Definición de pines
const int ledPin = 13;    // LED en pin 13
const int motorPin = 12;  // Motor en pin 12
const int sensorPin = A0; // LM35 en A0

// Función para leer temperatura
float readTemperature() {
    int sensorValue = analogRead(sensorPin);
    return ((sensorValue * (5.0 / 1023.0))) * 100.0;
}

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(motorPin, OUTPUT);
    Serial.begin(9600);
    Serial.println("### Temperature Monitor ###");
}

void loop() {
    float temp = readTemperature();
    
    Serial.print("Temp Value: ");
    Serial.print(temp);
    Serial.println(" °C");

    // Lógica de activación del LED y motor
    if (temp < 5) {
        digitalWrite(ledPin, HIGH);
        delay(500);
        digitalWrite(ledPin, LOW);
        delay(500);
        digitalWrite(motorPin, LOW);
    } 
    else if (temp >= 5 && temp <= 25) {  // Incluye 5°C
        digitalWrite(ledPin, LOW);
        digitalWrite(motorPin, LOW);
    } 
    else { // temp > 25
        digitalWrite(ledPin, HIGH);
        digitalWrite(motorPin, HIGH);
    }

    delay(2000);
}