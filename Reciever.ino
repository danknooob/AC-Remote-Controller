#include <IRremote.h>

const int IR_RECEIVE_PIN = 32;  // Pin where your IR receiver is connected

IRrecv irReceiver(IR_RECEIVE_PIN);  // Create an IRrecv object
decode_results results;  // To store the results of the received IR signal

void setup() {
  Serial.begin(9600);        // Start serial communication at 9600 baud rate
  irReceiver.enableIRIn();   // Start the IR receiver
  Serial.println("IR Receiver is ready.");
}

void loop() {
  if (irReceiver.decode(&results)) {  // If an IR signal is received
    Serial.print("Received IR Code: ");
    Serial.println(results.value, HEX);  // Print the received code in hexadecimal

    irReceiver.resume();  // Prepare the IR receiver for the next code
  }
}
