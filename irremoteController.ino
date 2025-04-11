const int PIR_SENSOR_PIN = 32;  // Pin where your PIR sensor is connected
const int LED_PIN = 13;        // Pin for an LED (optional, for visual indication)

void setup() {
  pinMode(PIR_SENSOR_PIN, INPUT);  // Set PIR sensor pin as input
  pinMode(LED_PIN, OUTPUT);        // Set LED pin as output
  Serial.begin(9600);              // Start serial communication at 9600 baud
  Serial.println("Motion Detector is ready.");
}

void loop() {
  int motionDetected = digitalRead(PIR_SENSOR_PIN);  // Read PIR sensor value

  if (motionDetected == HIGH) {  // If motion is detected
    Serial.println("Motion detected!");
    digitalWrite(LED_PIN, HIGH);  // Turn on LED
    delay(1000);                  // Delay to avoid continuous detection
  } else {
    digitalWrite(LED_PIN, LOW);   // Turn off LED
  }

  delay(100);  // Short delay for stability
}
