/*
 * SwitchingBoard.h
 *
 *  Created on: 08.11.2025
 *  Author: Lukas Schneider
 */

#ifndef SWITCHINGBOARD_H_
#define SWITCHINGBOARD_H_

#include <Arduino.h>
#include <SPI.h>
#include "Debug.h"

class SwitchingBoard {
public:
    SwitchingBoard(uint8_t numPins);
    void setSwitchingBoard(uint64_t mask);
    uint8_t getPinCount();
    void setIntensity(uint8_t percent);
    void enableOutputs(bool enable);

protected:

private:
    uint8_t numPins;
    SPISettings spiSettings;
};

#endif /* SWITCHINGBOARD_H_ */
