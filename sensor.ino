float temp;        
int sensorValue;   

void setup() {    
  pinMode(13, OUTPUT);    
  pinMode(12, OUTPUT);    
  Serial.begin(9600); // Baud rate: Baudios    
  Serial.println("### Temperature monitor ###");    
}    

void loop() {    
  sensorValue = analogRead(A0);    
  Serial.print("Sensor value: ");    
  Serial.println(sensorValue);    
  delay(2000); // miliseconds    

  temp = (sensorValue * (500.0 / 1023.0)) - 50.0;    

  Serial.print("Temp value: ");    
  Serial.println(temp);    
  delay(2000);    

  if (temp < 5) {    
    digitalWrite(13, HIGH);    
    delay(500);    
    digitalWrite(13, LOW);    
    delay(500);    
    digitalWrite(12, LOW);    
  }     
  else if (temp >= 6 && temp <= 25) {    
    digitalWrite(13, LOW);    
    digitalWrite(12, LOW);    
  }     
  else {    
    digitalWrite(13, HIGH);    
    digitalWrite(12, HIGH);    
  }    

  delay(1000);    
}