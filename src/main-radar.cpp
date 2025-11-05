// #include <Arduino.h>

// // --- Foundational Method: shiftOut() Example ---

// // Define the digital pins connected to the MAX6969
// // const int LATCH_PIN = 10; // Corresponds to LE
// // const int DATA_PIN = 11;  // Corresponds to DIN
// // const int CLOCK_PIN = 13; // Corresponds to CLK
// // const int OE_PIN = 9;     // Corresponds to OE (Output Enable)

// const int LATCH_PIN = 10; // Corresponds to LE
// const int DATA_PIN = 11;  // Corresponds to DIN
// const int CLOCK_PIN = 12; // MOVED from 13 (conflicted with LED)
// const int OE_PIN = 3;     // MOVED from 9 (conflicted with AltSoftSerial)

// void setup() {
//   // Set all control pins as outputs
//   pinMode(LATCH_PIN, OUTPUT);
//   pinMode(DATA_PIN, OUTPUT);
//   pinMode(CLOCK_PIN, OUTPUT);
//   pinMode(OE_PIN, OUTPUT);

//   // Initially, disable the outputs by pulling OE HIGH (active-low)
//   digitalWrite(OE_PIN, HIGH);
//   // Ensure the latch is not active
//   digitalWrite(LATCH_PIN, HIGH);

//   // Initialize Serial for debug output so the Serial Monitor can show messages.
//   // Use 115200 which is a common baud for Nanos; match this in the Serial Monitor.
//   Serial.begin(115200);
//   delay(50); // short delay to allow host to open the port
//   Serial.println("EMS-Radar: setup complete");
// }

// // Function to update the 16 channels of the MAX6969
// void updateChannels(uint16_t channelData) {
//   // A 16-bit value is composed of two 8-bit bytes.
//   // Extract the high byte (bits 15-8) and low byte (bits 7-0).
//   byte highByte = (channelData >> 8);
//   byte lowByte = (channelData & 0xFF);

//   // Pull the latch pin LOW to prepare for data transmission
//   digitalWrite(LATCH_PIN, LOW);

//   // Send the 16 bits of data, MSB first as required by the MAX6969.
//   // The high byte (OUT15-OUT8) must be sent first.
//   shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, highByte);
//   shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, lowByte);

//   // Pull the latch pin HIGH to transfer the data from the shift
//   // register to the output latch, updating all channels simultaneously.
//   digitalWrite(LATCH_PIN, HIGH);
// }

// void loop() {
//   // Enable the outputs (active-low)
//   digitalWrite(OE_PIN, LOW);

//   Serial.println("Activate all");
//   uint16_t last = 0b1111111111111111;
//   updateChannels(last);
//   delay(5000);

//   // Example 1: Turn on channels 0 and 15
//   Serial.println("Updating pattern 1");
//   // Binary: 1000000000000001
//   uint16_t pattern1 = 0b1000000000000001;
//   updateChannels(pattern1);
//   delay(1000);

//   // Example 2: Turn on channels 4, 5, 6, 7
//   Serial.println("Updating pattern 2");
//   // Binary: 0000000011110000
//   uint16_t pattern2 = 0b0000000011110000;
//   updateChannels(pattern2);
//   delay(1000);

//   // Example 3: A chasing light effect
//   for (int i = 0; i < 16; i++) {
//     Serial.println(i);
//     updateChannels(1 << i); // Set a single bit
//     delay(100);
//   }
// }
