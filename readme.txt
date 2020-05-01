
This example is for a TDoA Blink running on the DWM1001C platform.

BUILDING AND RUNNING THE CODE 

This project is created using the Segger Embedded Studio IDE. The Segger IDE includes a full license to develop, debug and run applications targeting nRF52832 ARM MCU, which is the MCU used onto the Decawave’s DWM1001 hardware platform. 

INSTALLING OF THE SEGGER IDE 

Download and install the Segger Embedded Studio IDE from the following web site: https://www.segger.com/products/development-tools/embedded-studio/ 

LOADING OF THE PROJECT TO THE IDE 

Unpack the source code to the “dwm1001_tdoa_tag” folder. In the Segger IDE, choose File->Open Solution and select the project tdoa_tag.emProject, located in the examples\tdoa_tag\ folder. 

CONNECTING, BUILDING AND RUNNING OF THE APPLICATION 

Connect the board to the PC. You may require to install J-Link drivers, which could be found on the Segger web site: 
https://www.segger.com/downloads/jlink/#J-LinkSoftwareAndDocumentationPack 
Install J-Link Software and Documentation pack, which includes drivers and J-Flash Lite tool needed for reprogramming new FW binary into tag. 
To check if the target board is working select Target->Connect J-Link from the menu. To start the TDOA Tag application select Build->Build and Run from menu. 

If it is the first time to start your app you will be asked for a licence. License is free for Nordic MCU’S