## <<<<<<<< PLEASE READ THIS CAREFULLY! >>>>>>>>

This firmware has a couple of changes from standard to make it less hassle to maintain and customise. So please bare these notes in mind!
  1) Edit one file only located in "\Marlin\setup.h". Only have one option active at a time, unless its a field, eg. custom drivers or probe offset.
  2) The BLTouch/3D Touch 2pin trigger cable is plugged into the PW_DET header on the main board. 
        __NOT THE Z MIN/MAX ENDSTOP! << IMPORTANT__
  3) Junction Deviation is on and set to J0.13 by default. You may change this in the LCD in Setting > Configuration > Advanced > Junction Deviation
  4) Linear Advance is on but is set to K0.00 by default. Setting > Configuration > Advanced > Fillament > Linear Advance
      3a) Please note that Linear Advance is not compatible with the TMC2208 and is set to K0 on purpurse. If you change to a custom driver for the
          extruder. This will be set to K0.25 by default.
  5) Thing to do on you first run:
      5a) Do a PID Autotune. Go to Setting > Configuration > Advanced > Temperature
            Select PID Autotune E1 and choose 10C above the nominal highest temperature you are planning on printing on the hotend. Then, once finished;
            Select PID Autotune BED and choose 10C above the nominal highest temperature you will be using on the bed.
            Store the settings! (M500)
      5b) Generate a bed mesh. Go to Settings > Motion > Bed Levelling (menu name is different depending on the type chosen below)
          Best practice is the put :M420 S1" after "G28" in you start gcode if you're not planing to run G29 in your start gcode.
      5c) If you haven't calibrated your printer, please follow this link and do the step by step guide: https://teachingtechyt.github.io/calibration.html
  6) Store settings after any changes you make in the LCD menus. Setting > Configuration > Store Settings (or run M500 in terminal).

Enjoy!

    DJScope (Igor Rebenko) you can find me on the Two Trees Facebook Group if you need any queries answered.

    PS. If you run into any weird behaviour by the printer, like weird homing and such. First restart the printer.
    If still happening, initialise EEPROM, restore defaults, and store settings.
    Last resort is to reflash the firmware file.
    Usually a simple restart fixes all issues




# Marlin 3D Printer Firmware

![GitHub](https://img.shields.io/github/license/marlinfirmware/marlin.svg)
![GitHub contributors](https://img.shields.io/github/contributors/marlinfirmware/marlin.svg)
![GitHub Release Date](https://img.shields.io/github/release-date/marlinfirmware/marlin.svg)
[![Build Status](https://github.com/MarlinFirmware/Marlin/workflows/CI/badge.svg?branch=bugfix-2.0.x)](https://github.com/MarlinFirmware/Marlin/actions)

<img align="right" width=175 src="buildroot/share/pixmaps/logo/marlin-250.png" />

Additional documentation can be found at the [Marlin Home Page](https://marlinfw.org/).
Please test this firmware and let us know if it misbehaves in any way. Volunteers are standing by!

## Marlin 2.0 Bugfix Branch

__Not for production use. Use with caution!__

Marlin 2.0 takes this popular RepRap firmware to the next level by adding support for much faster 32-bit and ARM-based boards while improving support for 8-bit AVR boards. Read about Marlin's decision to use a "Hardware Abstraction Layer" below.

This branch is for patches to the latest 2.0.x release version. Periodically this branch will form the basis for the next minor 2.0.x release.

Download earlier versions of Marlin on the [Releases page](https://github.com/MarlinFirmware/Marlin/releases).

## Building Marlin 2.0

To build Marlin 2.0 you'll need [Arduino IDE 1.8.8 or newer](https://www.arduino.cc/en/main/software) or [PlatformIO](https://docs.platformio.org/en/latest/ide.html#platformio-ide). We've posted detailed instructions on [Building Marlin with Arduino](https://marlinfw.org/docs/basics/install_arduino.html) and [Building Marlin with PlatformIO for ReArm](https://marlinfw.org/docs/basics/install_rearm.html) (which applies well to other 32-bit boards).

## Credits

The current Marlin dev team consists of:

 - Scott Lahteine [[@thinkyhead](https://github.com/thinkyhead)] - USA &nbsp; [Donate](https://www.thinkyhead.com/donate-to-marlin) / Flattr: [![Flattr Scott](https://api.flattr.com/button/flattr-badge-small.png)](https://flattr.com/submit/auto?user_id=thinkyhead&url=https://github.com/MarlinFirmware/Marlin&title=Marlin&language=&tags=github&category=software)
 - Roxanne Neufeld [[@Roxy-3D](https://github.com/Roxy-3D)] - USA
 - Chris Pepper [[@p3p](https://github.com/p3p)] - UK
 - Bob Kuhn [[@Bob-the-Kuhn](https://github.com/Bob-the-Kuhn)] - USA
 - João Brazio [[@jbrazio](https://github.com/jbrazio)] - Portugal
 - Erik van der Zalm [[@ErikZalm](https://github.com/ErikZalm)] - Netherlands &nbsp; [![Flattr Erik](https://api.flattr.com/button/flattr-badge-large.png)](https://flattr.com/submit/auto?user_id=ErikZalm&url=https://github.com/MarlinFirmware/Marlin&title=Marlin&language=&tags=github&category=software)

## License

Marlin is published under the [GPL license](/LICENSE) because we believe in open development. The GPL comes with both rights and obligations. Whether you use Marlin firmware as the driver for your open or closed-source product, you must keep Marlin open, and you must provide your compatible Marlin source code to end users upon request. The most straightforward way to comply with the Marlin license is to make a fork of Marlin on Github, perform your modifications, and direct users to your modified fork.

While we can't prevent the use of this code in products (3D printers, CNC, etc.) that are closed source or crippled by a patent, we would prefer that you choose another firmware or, better yet, make your own.
