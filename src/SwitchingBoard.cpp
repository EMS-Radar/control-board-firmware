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

/**
 * @brief Controls the 16-electrode switching board.
 * This function is a placeholder. You must implement the logic 
 * specific to your hardware (e.g., SPI, I2C, shift registers).
 * @param mask A 16-bit bitmask of active electrodes.
 */
void SwitchingBoard::setSwitchingBoard(uint16_t mask) {
    // --- YOUR HARDWARE LOGIC GOES HERE ---
    
    // Example for SPI / Shift Registers:
    /*
    digitalWrite(LATCH_PIN, LOW);
    // Send the high byte (electrodes 1-8)
    shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, (mask >> 8) & 0xFF); 
    // Send the low byte (electrodes 9-16)
    shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, mask & 0xFF);        
    digitalWrite(LATCH_PIN, HIGH);
    */
    
    // For now, let's just debug-print the mask
    debug_println(F("\tSWITCH_BOARD: Set mask to "));
    // debug_println(mask, BIN);
}
