# Control Board Firmware

## Overview

This is the firmware for the EMS-Radar control board. It is based on the ArduinoSoftware of the *LetYourBodyMove* toolkit extending it with SPI-based switching board control and a hexadecimal-encoded electrode command protocol. The original code is available at [https://bitbucket.org/MaxPfeiffer/letyourbodymove/src/master/Toolkit/ArduinoSoftware/](https://bitbucket.org/MaxPfeiffer/letyourbodymove/src/master/Toolkit/ArduinoSoftware/)


### Core Components

- **EMSSystem**: High-level system controller managing multiple EMS channels
- **EMSChannel**: Individual channel abstraction for each stimulation output
- **SwitchingBoard**: Hardware abstraction layer for electrode switching and intensity control

### Communication Protocol

The system accepts commands via Bluetooth or USB in the following format:
- `ACTION` (G): General control commands
- `CHANNEL` (C): Select target channel
- `INTENSITY` (I): Set stimulation intensity
- `TIME` (T): Set stimulation duration
- `OPTION` (O): Additional parameters
- `ELECTRODE` (E): Electrode selection

## Building and Uploading

This project uses [PlatformIO](https://platformio.org/) for build management:

```bash
platformio run --target upload
```

To monitor serial output:
```bash
platformio device monitor
```

## Configuration

Key configuration options in `src/main.cpp`:
- `EMS_BLUETOOTH_ID`: Bluetooth device name (default: "EMS99TD")
- `ACCEPT_USB_COMMANDS`: Enable/disable USB command interface
- `SETUP_BLUETOOTH`: Configure Bluetooth module on first upload

## License

This project is licensed under "The MIT License (MIT) - military use of this product is forbidden - V 0.2". See [LICENSE.md](LICENSE.md) for details.

## Credits

- **Original Development**: Tim Duente, Max Pfeiffer
- **Revisions**: Pedro Lopes, Lukas Schneider
