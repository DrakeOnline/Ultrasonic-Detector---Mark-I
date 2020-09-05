#define echo_pin 7
#define trig_pin 8
#define light_pin 13

long duration;
long distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(echo_pin, INPUT);
  pinMode(trig_pin, OUTPUT);
  pinMode(light_pin, OUTPUT);
}

void loop() {
  // Turn ultrasonic sensor off
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);

  // Turn ultrasonic sensor on
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);

  // Turn ultrasonic sensor off
  digitalWrite(trig_pin, LOW);

  // Recieve input from ultrasonic sensor
  duration = pulseIn(echo_pin, HIGH);
  // Calculate distance
  distance = duration/58.2;

  // Print distance to Arduino IDE console
  Serial.println(distance);

  // If distance is within 10 units, turn the sensor on
  if(distance < 10) { digitalWrite(light_pin, HIGH); } 
  else              { digitalWrite(light_pin, LOW); }

  delay(50);
}
