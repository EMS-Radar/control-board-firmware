/*
 * SwitchingBoard.h
 *
 *  Created on: 08.11.2025
 *      Author: Lukas Schneider
 */

#ifndef SWITCHINGBOARD_H_
#define SWITCHINGBOARD_H_

#include <Arduino.h>
#include "Debug.h"

class SwitchingBoard {
public:
	SwitchingBoard(uint8_t numPins);
    void setSwitchingBoard(uint16_t mask);

protected:

private:
    uint8_t numPins;
};

#endif /* SWITCHINGBOARD_H_ */
