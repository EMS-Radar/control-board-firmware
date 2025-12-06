// #include <Arduino.h>
// #include "SwitchingBoard.h"

// SwitchingBoard* switchingBoard;

// void setup() {
//   switchingBoard = new SwitchingBoard(16);

//   Serial.begin(115200);
//   delay(50);
//   Serial.println("EMS-Radar: setup complete");
// }

// void loop() {
//   Serial.println("Activate all");
//   uint16_t last = 0b1111111111111111;
//   switchingBoard->setSwitchingBoard(last);
//   switchingBoard->enableOutputs(true);
//   delay(5000);

//   // Example 1: Turn on channels 0 and 15
//   Serial.println("Updating pattern 1");
//   // Binary: 1000000000000001
//   uint16_t pattern1 = 0b1000000000000001;
//   switchingBoard->setSwitchingBoard(pattern1);
//   delay(1000);

//   // Example 2: Turn on channels 4, 5, 6, 7
//   Serial.println("Updating pattern 2");
//   // Binary: 0000000011110000
//   uint16_t pattern2 = 0b0000000011110000;
//   switchingBoard->setSwitchingBoard(pattern2);
//   delay(1000);

//   // Example 3: A chasing light effect
//   for (int i = 0; i < 16; i++) {
//     Serial.println(i);
//     switchingBoard->setSwitchingBoard(1 << i); // Set a single bit
//     delay(100);
//   }
// }
