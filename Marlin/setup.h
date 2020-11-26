/**
 *
████████╗██╗    ██╗ ██████╗     ████████╗██████╗ ███████╗███████╗███████╗    ███╗   ███╗ █████╗ ██████╗ ██╗     ██╗███╗   ██╗
╚══██╔══╝██║    ██║██╔═══██╗    ╚══██╔══╝██╔══██╗██╔════╝██╔════╝██╔════╝    ████╗ ████║██╔══██╗██╔══██╗██║     ██║████╗  ██║
   ██║   ██║ █╗ ██║██║   ██║       ██║   ██████╔╝█████╗  █████╗  ███████╗    ██╔████╔██║███████║██████╔╝██║     ██║██╔██╗ ██║
   ██║   ██║███╗██║██║   ██║       ██║   ██╔══██╗██╔══╝  ██╔══╝  ╚════██║    ██║╚██╔╝██║██╔══██║██╔══██╗██║     ██║██║╚██╗██║
   ██║   ╚███╔███╔╝╚██████╔╝       ██║   ██║  ██║███████╗███████╗███████║    ██║ ╚═╝ ██║██║  ██║██║  ██║███████╗██║██║ ╚████║
   ╚═╝    ╚══╝╚══╝  ╚═════╝        ╚═╝   ╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝    ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚═╝╚═╝  ╚═══╝
 *
 *
In this file you need to chose the cofiguration that you want for the firmware.
Please pick only from the options and make sure that it is written as #defined <option> and nothing else.

  Remove the // before define to select the option. Please have only one option activated at once.

       eg.     //#define Sapphire_Bluer    << Not selected
                 #define Sapphire_Bluer    << Selected


Keep a copy of this setup file so that if future upgrades to the firmware become available, you don't need to update any of the firmware files.
But if the time comes that I need expand or modify the setup.h file, I will let you know in advance so that you can update your setup file.

<<<<<<<< PLEASE READ THIS CAREFULLY! >>>>>>>>

This firmware has a couple of changes from standard to make it less hassle to maintain and customise. So please bare these notes in mind!
  1) The BLTouch/3D Touch 2pin trigger cable is plugged into the PW_DET header on the main board. NOT THE Z MIN/MAX ENDSTOP! << IMPORTANT
  2) Junction Deviation is on and set to J0.13 by default. You may change this in the LCD in Setting > Configuration > Advanced > Junction Deviation
  3) Linear Advance is on but is set to K0.00 by default. Setting > Configuration > Advanced > Fillament > Linear Advance
      3a) Please note that Linear Advance is not compatible with the TMC2208 and is set to K0 on purpurse. If you change to a custom driver for the
          extruder. This will be set to K0.25 by default.
  4) Thing to do on you first run:
      4a) Do a PID Autotune. Go to Setting > Configuration > Advanced > Temperature
            Select PID Autotune E1 and choose 10C above the nominal highest temperature you are planning on printing on the hotend. Then, once finished;
            Select PID Autotune BED and choose 10C above the nominal highest temperature you will be using on the bed.
            Store the settings! (M500)
      4b) Generate a bed mesh. Go to Settings > Motion > Bed Levelling (menu name is different depending on the type chosen below)
          Best practice is the put :M420 S1" after "G28" in you start gcode if you're not planing to run G29 in your start gcode.
      4c) If you haven't calibrated your printer, please follow this link and do the step by step guide: https://teachingtechyt.github.io/calibration.html
  5) Store settings after any changes you make in the LCD menus. Setting > Configuration > Store Settings (or run M500 in terminal).

Enjoy!

       DJScope (Igor Rebenko) you can find me on the Two Trees Facebook Group if you need any queries answered.

    PS. If you run into any weird behaviour by the printer, like weird homing and such. First restart the printer.
    If still happening, initialise EEPROM, restore defaults, and store settings.
    Last resort is to reflash the firmware file.
    Usually a simple restart fixes all issues                                                                         */

/**
███████╗████████╗ █████╗ ██████╗ ████████╗
██╔════╝╚══██╔══╝██╔══██╗██╔══██╗╚══██╔══╝
███████╗   ██║   ███████║██████╔╝   ██║
╚════██║   ██║   ██╔══██║██╔══██╗   ██║
███████║   ██║   ██║  ██║██║  ██║   ██║
╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝
*/

 // {01} What type of printer are you using?

  //#define Bluer
  //#define Bluer_Plus
  //#define Sapphire_Pro
  //#define Sapphire_Plus
  #define Sapphire_Plus_Rotated_Screen

//----------------------------------------------------------------------------------

// {02} Are you using custom stepper drivers?

  //#define stock_drivers
  #define custom_drivers

// {02a} If they are custom, please fill in the option below.

#if ENABLED(custom_drivers)

  #define x_driver    TMC2208_STANDALONE
  #define y_driver    TMC2208_STANDALONE
  #define z1_driver   A4988
  #define z2_driver   A4988                  //Called E1 but used for Z2 stepper
  #define e_driver    TMC2209_STANDALONE

#endif

//----------------------------------------------------------------------------------

// {03} What type of User Interface do you want to use?

  //#define classic_stock_marlin           // This is like the old interface with monotone screens and turn nob controls but with touch buttons
  //#define touch_colour_marlin            // This is similar to above but with more touch friendly possitioning of buttons
  #define modern_touch_mks_interface     // This is a modern full touch interface, but has some limitations in terms of features

  // Quick note about the MKS interface. I've got it runnings and setup as much as I could but because I don't like using it, I will not be looking at
  // further developing/porting function to for it. My goal was to port it over and get it running. Hopefully, MKS will further develope this and give
  // proper sources for Marlin integration, especially, as easy way to customise it and add current Marlin funtions to it.

//----------------------------------------------------------------------------------

// {04} What type of Bed Levelling are you using? If you don't have a probe, just define manual_bed_lvl.

  //#define manual_bed_lvl                 // Like ABL (auto bed levelling) this allows you to manually build a mesh of your bed with the piece of paper technique
  //#define bltouch_3x3                    // Bltouch ABL with a 3x3 grid. This works well for fast probing before each print. Place G29 in you start gcode.
  //#define bltouch_5x5                    // Bltouch ABL with a 5x5 grid. Great for most cases. A bit slower than above.
  //#define bltouch_7x7                    // Bltouch ABL with a 7x7 grid. Slow. If you want this, I suggest Unified Bed Leveling below, but it's up to you.
  #define three_point                    // Bltouch ABL with a 3 point leveling for perfectly flat beds.
  //#define unified_bed_levelling            // Bltouch ABL with a fully comprehensive system. This is best for large print beds with lots of warping.


// {04a}  << If you are using "manual_bed_lvl" then you can skip to {05} >>
//        Probe offset? You may define your probe offset here or in LCD menu under Setting > Configuration > Advanced > Probe Offset.
//        These are calulated by measuring the distance from the tip of the probe while it's deployed/down to the tip of the nozzle.

  #if ANY(bltouch_3x3, bltouch_5x5, bltouch_7x7, unified_bed_levelling, three_point)

    #define probeX 0           // LEFT is -X, RIGHT is +X (Movement of hotend)
    #define probeY -44         // BACK is -Y, FORWARD is +Y (Movement of hotend)
    #define probeZ -2.8        // UP is -Z, and DOWN is +Z (Movement of bed)

  #endif

// {05} Are you running a stock Bowden or a Direct Drive setup? (This will affect your default Fillament Change and Retract Settings)
//      Fillament Retract settings can be changed in the LCD menu in Setting > Configuration > Advanced > Fillament (Load / Unload)
//      Retract are a firmaware setting and can be overwritten using your preferred slicer.

  #define direct_drive    //<< comment out " //#define direct_drive " for Bowden Drive

// {06} Will you be using a fillament runout sensor?

  #define filament_runout  //<< comment out " //#define filament_runout " to disable

// {07} MKS Wifi Module?

  //#define MKS_WIFI

