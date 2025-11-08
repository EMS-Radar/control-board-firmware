/*
 * SwitchingBoard.cpp
 *
 *  Created on: 08.11.2025
 *  Author: Lukas Schneider
 */

#include "SwitchingBoard.h"

SwitchingBoard::SwitchingBoard(uint8_t numPins) {
    this->numPins = numPins;
}

uint8_t SwitchingBoard::getPinCount() {
    return this->numPins;
}

/**
 * @brief Controls the switching board.
 * This function is a placeholder. You must implement the logic 
 * specific to your hardware (e.g., SPI, I2C, shift registers).
 * @param mask A 64-bit bitmask of active electrodes.
 */
void SwitchingBoard::setSwitchingBoard(uint64_t mask) {
    // --- YOUR HARDWARE LOGIC GOES HERE ---
    
    // Example for SPI / Shift Registers (for 32-bit):
    /*
    uint8_t byte1 = (mask >> 24) & 0xFF; // MSB
    uint8_t byte2 = (mask >> 16) & 0xFF;
    uint8_t byte3 = (mask >> 8) & 0xFF;
    uint8_t byte4 = (mask) & 0xFF;       // LSB
    
    digitalWrite(LATCH_PIN, LOW);
    shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, byte1); 
    shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, byte2); 
    shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, byte3); 
    shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, byte4); 
    digitalWrite(LATCH_PIN, HIGH);
    */
    
    // For now, let's just debug-print the mask
    debug_println(F("\tSWITCH_BOARD: Set mask (64-bit)"));
    // Arduino's print doesn't support 64-bit, so we'd print Hi/Lo parts
    // debug_println((uint32_t)(mask >> 32), BIN); 
    // debug_println((uint32_t)(mask), BIN);
}
