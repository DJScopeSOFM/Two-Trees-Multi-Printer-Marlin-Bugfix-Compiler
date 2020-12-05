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

// #### Ignore the machine name and description in Marlin Auto Build. It is not design to change printer types on the fly.
// #### Once the firmware is compiled, you need to copy the robin_nano35.bin file located in \.pio\build\mks_robin_nano35\ to your SDCard and restart your
// #### printer. The progress bar must go all the way to the end of the screen, if the progress bar hangs anywhere before the end, you need to turn off the
// #### printer, copy the robin_nano35.bin file to SDCard again and restart the printer.

 // {01} What type of printer are you using?

  //#define Bluer
  //#define Bluer_Plus            //<< Still in testing due to TFT43 screen. Please rename robin_nano35.bin to robin_nano43.bin to flash.
  //#define Sapphire_Pro
  #define Sapphire_Plus
  //#define Sapphire_Plus_Rotated_Screen

 // {01a} What type of main board do you have?

  #define mboard Nano_V1           //<< MKS Robin Nano V1.x
  //#define mboard Nano_V2           //<< MKS Robin Nano V2.x
//----------------------------------------------------------------------------------

// {02} Are you using custom stepper drivers?

  //#define stock_drivers
  #define custom_drivers

/** {02a} If they are custom, please fill in the option below.

 * Options: A4988, A5984, DRV8825, LV8729, L6470, L6474, POWERSTEP01,
 *          TB6560, TB6600, TMC2100,
 *          TMC2130, TMC2130_STANDALONE, TMC2160, TMC2160_STANDALONE,
 *          TMC2208, TMC2208_STANDALONE, TMC2209, TMC2209_STANDALONE,
 *          TMC26X,  TMC26X_STANDALONE,  TMC2660, TMC2660_STANDALONE,
 *          TMC5130, TMC5130_STANDALONE, TMC5160, TMC5160_STANDALONE  */

#if ENABLED(custom_drivers)

  #define x_driver    TMC2209_STANDALONE
  #define y_driver    TMC2209_STANDALONE
  #define z1_driver   TMC2209_STANDALONE
  #define z2_driver   TMC2209_STANDALONE                  //Called E1 but used for Z2 stepper
  #define e_driver    TMC2209_STANDALONE

#endif

// {02b} Do you need to invert driver direction?

#define invert_drivers

#if ENABLED(invert_drivers)

  #define invert_x    true
  #define invert_y    true
  #define invert_z1   true
  #define invert_z2   true
  #define invert_e    true

#endif

//----------------------------------------------------------------------------------

// {03} What type of User Interface do you want to use?

  //#define classic_stock_marlin           // This is like the old interface with monotone screens and turn nob controls but with touch buttons
  #define touch_colour_marlin            // This is similar to above but with more touch friendly possitioning of buttons
  //#define modern_touch_mks_interface     // This is a modern full touch interface, but has some limitations in terms of features

  // Quick note about the MKS interface. I've got it runnings and setup as much as I could but because I don't like using it, I will not be looking at
  // further developing/porting function to for it. My goal was to port it over and get it running. Hopefully, MKS will further develope this and give
  // proper sources for Marlin integration, especially, as easy way to customise it and add current Marlin funtions to it.

//----------------------------------------------------------------------------------

// {04} What type of Bed Levelling are you using? If you don't have a probe, just define manual_bed_lvl.

  //#define manual_bed_lvl                 // Like ABL (auto bed levelling) this allows you to manually build a mesh of your bed with the piece of paper technique
  //#define bltouch_3x3                    // Bltouch ABL with a 3x3 grid. This works well for fast probing before each print. Place G29 in you start gcode.
  //#define bltouch_5x5                    // Bltouch ABL with a 5x5 grid. Great for most cases. A bit slower than above.
  //#define bltouch_7x7                    // Bltouch ABL with a 7x7 grid. Slow. If you want this, I suggest Unified Bed Leveling below, but it's up to you.
  //#define three_point                    // Bltouch ABL with a 3 point leveling for perfectly flat beds.
  #define unified_bed_levelling            // Bltouch ABL with a fully comprehensive system. This is best for large print beds with lots of warping.


// {04a}  << If you are using "manual_bed_lvl" then you can skip to {05} >>
//        Probe offset? You may define your probe offset here or in LCD menu under Setting > Configuration > Advanced > Probe Offset.
//        These are calulated by measuring the distance from the tip of the probe while it's deployed/down to the tip of the nozzle.

  #if ANY(bltouch_3x3, bltouch_5x5, bltouch_7x7, unified_bed_levelling, three_point)

    #define probeX 0           // LEFT is -X, RIGHT is +X (Movement of hotend)
    #define probeY -44         // BACK is -Y, FORWARD is +Y (Movement of hotend)
    #define probeZ -2.52        // UP is -Z, and DOWN is +Z (Movement of bed)

  #endif

//----------------------------------------------------------------------------------

// {05} Are you running a stock Bowden or a Direct Drive setup? (This will affect your default Fillament Change and Retract Settings)
//      Fillament Runout settings can be changed in the LCD menu in Setting > Configuration > Advanced > Fillament (Load / Unload)
//      Retract settings can be changed in Setting > Configuration > Retact. This is altimately overwritten by your slicer.

  #define direct_drive    //<< comment out " //#define direct_drive " for Bowden Drive

//----------------------------------------------------------------------------------

// {06} Will you be using a fillament runout sensor?

  #define filament_runout  //<< comment out " //#define filament_runout " to disable

//----------------------------------------------------------------------------------

// {07} MKS Wifi Module?

  //#define MKS_WIFI

//----------------------------------------------------------------------------------

// {08} Customised PID Autotune Settings?

  #define custom_pid_hotend

// {08a} Hotend PID Autotune Settings

  #if ENABLED(custom_pid_hotend)
    #define hotend_Kp      22.20
    #define hotend_Ki       1.08
    #define hotend_Kd     114.00
  #endif
// {08b} Bed PID Autotune Settings

  //#define bang_bang          //<< comment out " //#define custom_pid_bed " to endable PID bed mode

  #if DISABLED(bang_bang)
    #define custom_pid_bed
      #if ENABLED(custom_pid_bed)
        #define bed_Kp      46.6
        #define bed_Ki      5.82
        #define bed_Kd     249.2
      #endif
    #endif

//----------------------------------------------------------------------------------

// {09} Do you want to customise your motion settings?
// LINEAR ADVANCE: releases and increase pressure in the nozzle for decceleration and acceleration moves to maintain an even line thickness with fast movement.
// JERK: controls the speed at which directional changes are made.
// S CURVE: Control acceleration for curved movements

  #define custom_motion
    #if ENABLED(custom_motion)
      #define linear_advance true         // default is set to K0
        #if linear_advance == true
          #define LA_k_value 0.075          // WARNING!!! Beware that if you are using a TMC2208 driver on E, there is a large chance that the driver will shut down mid print.
        #endif
      #define scurve                       // S CURVE works in conjuction with LINEAR ADVANCE with the Experimental S Curve feature.
      #define junction_deviation           // Classic Jerk will be enabled if you disable junction deviation.
        #if ENABLED(junction_deviation)
          #define j_value 0.17
        #else
          #define jerk_x  10.0
          #define jerk_y  10.0
          #define jerk_z  0.3
        #endif
    #endif

// {10} Steps per mm settings

  #define step_x      80
  #define step_y      80
  #define step_z     400
  #define step_e     413

