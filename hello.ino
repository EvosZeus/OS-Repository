int const LED=13;
void setup() {
  // put your setup code here, to run once:
pinMode(LED, OUTPUT);
Serial.begin(9600);
digitalWrite(LED,LOW);
Serial.print("hello");

}

void loop() {
  // put your main code here, to run repeatedly:

}