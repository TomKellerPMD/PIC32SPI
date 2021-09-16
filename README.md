# PIC32SPI
C-Motion port to Curiosity PIC32 MZ EF for SPI inferface.
Using MPLAB X IDE v5.00
Note this is not "rev 2" of the Curiosity board.

This will only setup the SPI interface and create an Axis Handle.
Once you have the Axis Handle initialized you can send any C-Motion command.
Typcially starts with an initialization like SetupAxis1().
And can start moves ProfileMove().
