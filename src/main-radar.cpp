#include <Arduino.h>
#include <SPI.h> // Include the official Arduino SPI library

// --- Professional Method: SPI Library ---

// Define the control pins based on your pin selection.
// D11 (MOSI) and D13 (SCK) are used automatically by the SPI library
// and do not need to be defined.
const int LATCH_PIN = 10; // Corresponds to LE (and SPI's SS/CS)
const int OE_PIN = 3;     // Corresponds to OE (Output Enable) on a PWM pin

// Define SPI settings for the MAX6969
// Speed: 1MHz (1000000) is a safe, fast speed for the Nano.
// Bit Order: MSBFIRST is required by the MAX6969.
// Data Mode: SPI_MODE0 is the standard for this type of chip.
SPISettings max6969_SPI_Settings(1000000, MSBFIRST, SPI_MODE0);

void setup() {
  // Set our *manual* control pins as outputs
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(OE_PIN, OUTPUT);

  // Initially, disable the outputs by pulling OE HIGH (active-low)
  digitalWrite(OE_PIN, HIGH);
  // Deselect the chip (LATCH is HIGH)
  digitalWrite(LATCH_PIN, HIGH);

  // Initialize the SPI hardware.
  // This automatically configures D13 (SCK) and D11 (MOSI) as outputs.
  SPI.begin();

  // Initialize Serial for debug output
  Serial.begin(115200);
  delay(50); // short delay to allow host to open the port
  Serial.println("EMS-Radar (SPI Version): setup complete");
}

// Function to update the 16 channels of the MAX6969 using hardware SPI
void updateChannels(uint16_t channelData) {
  
  // Start the SPI transaction with our defined settings
  SPI.beginTransaction(max6969_SPI_Settings);

  // Pull the latch pin LOW to "select" the chip for communication
  digitalWrite(LATCH_PIN, LOW);

  // Send the 16-bit data word.
  // SPI.transfer16() handles sending both bytes for us.
  SPI.transfer16(channelData);

  // Pull the latch pin HIGH. This "deselects" the chip and,
  // on the MAX6969, latches the data from the shift register 
  // to the outputs.
  digitalWrite(LATCH_PIN, HIGH);

  // End the SPI transaction to release the bus
  SPI.endTransaction();
}

void loop() {
  // Enable the outputs (active-low)
  digitalWrite(OE_PIN, LOW);

  Serial.println("Activate all");
  uint16_t last = 0b1111111111111111;
  updateChannels(last);
  delay(5000);

  // Example 1: Turn on channels 0 and 15
  Serial.println("Updating pattern 1");
  // Binary: 1000000000000001
  uint16_t pattern1 = 0b1000000000000001;
  updateChannels(pattern1);
  delay(1000);

  // Example 2: Turn on channels 4, 5, 6, 7
  Serial.println("Updating pattern 2");
  // Binary: 0000000011110000
  uint16_t pattern2 = 0b0000000011110000;
  updateChannels(pattern2);
  delay(1000);

  // Example 3: A chasing light effect
  for (int i = 0; i < 16; i++) {
    Serial.println(i);
    updateChannels(1 << i); // Set a single bit
    delay(100);
  }
}
