/*
 * SwitchingBoard.cpp
 *
 *  Created on: 08.11.2025
 *  Author: Lukas Schneider
 */

#include "SwitchingBoard.h"
#include <SPI.h>

// --- Define Control Pins ---
// Hardware SPI (SCK on D13, MOSI on D11) is configured by SPI.begin().
// We only need to define our manual control pins.
const int LATCH_PIN = 10; // Connects to LE (Latch Enable)
const int OE_PIN = 3;     // Connects to OE (Output Enable) on a PWM pin

SwitchingBoard::SwitchingBoard(uint8_t numPins) {
    this->numPins = numPins;

    // Set up our manual control pins
    pinMode(LATCH_PIN, OUTPUT);
    pinMode(OE_PIN, OUTPUT);

    // Deselect the chip (latch HIGH)
    digitalWrite(LATCH_PIN, HIGH);
    // Disable outputs (OE HIGH)
    digitalWrite(OE_PIN, HIGH);

    // Initialize the hardware SPI
    SPI.begin();

    // Create our SPISettings object
    // 1MHz speed, MSB first, Mode 0
    spiSettings = SPISettings(1000000, MSBFIRST, SPI_MODE0);
}

uint8_t SwitchingBoard::getPinCount() {
    return this->numPins;
}

/**
 * @brief Controls the switching board using hardware SPI.
 * Assumes up to four 16-bit MAX6969 chips are cascaded.
 * @param mask A 64-bit bitmask of active electrodes.
 */
void SwitchingBoard::setSwitchingBoard(uint64_t mask) {
    // Break the 64-bit mask into four 16-bit words.
    // The MAX6969 is a 16-bit driver. 
    // When cascading, data for the LAST board (bits 63-48) must be sent FIRST.
    uint16_t dataBoard3 = (mask >> 48) & 0xFFFF;
    uint16_t dataBoard2 = (mask >> 32) & 0xFFFF;
    uint16_t dataBoard1 = (mask >> 16) & 0xFFFF;
    uint16_t dataBoard0 = (mask) & 0xFFFF;

    // Begin SPI transaction
    SPI.beginTransaction(spiSettings);

    // Pull the latch pin LOW to select the chip
    digitalWrite(LATCH_PIN, LOW);

    // Send all 64 bits (4 x 16-bit transfers).
    // The SPI.transfer16() function is highly efficient. [3]
    SPI.transfer16(dataBoard3);
    SPI.transfer16(dataBoard2);
    SPI.transfer16(dataBoard1);
    SPI.transfer16(dataBoard0);

    // Pull the latch pin HIGH to commit the data to the outputs
    digitalWrite(LATCH_PIN, HIGH);
    
    // End SPI transaction
    SPI.endTransaction();

    // Debug print from your original template
    debug_println(F("\tSWITCH_BOARD: Set mask (64-bit)"));
}

/**
 * @brief Sets the global intensity of all channels.
 * @param percent Intensity from 0 (off) to 100 (max).
 */
void SwitchingBoard::setIntensity(uint8_t percent) {
    // Constrain the value just in case
    percent = constrain(percent, 0, 100);
    // Map 0-100% to the 255-0 inverted scale for the active-low OE pin
    int pwmValue = map(percent, 0, 100, 255, 0);
    analogWrite(OE_PIN, pwmValue);
}

/**
 * @brief Globally enables or disables all 16 outputs.
 * @param enable Set to true to enable outputs, false to disable.
 */
void SwitchingBoard::enableOutputs(bool enable) {
    // OE is active-low, so HIGH = Disabled, LOW = Enabled 
    if (enable) {
        digitalWrite(OE_PIN, LOW);
    } else {
        digitalWrite(OE_PIN, HIGH);
    }
}
