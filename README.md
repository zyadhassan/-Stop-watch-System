# Stop-watch-System
StopWatch Project on AVR ( ATmega32) as Practicng on I/O Ports, Timers and Interrupts 
# Hardware 
Working on :<br />
AVR Processor ( Atmega32 Microcontroller) <br />
7 Segments ( six of them for minutes , seconds and hours )<br />
7447 Decoder <br />
Push Buttons <br />

# Connections 
Connecting the six 7-segments in the project using the multiplexed technique.<br />
We can connect more than one 7-segment display by using the Multiplexing method. In this method, at a time one 7-segment display is driven by the Microcontroller and the rest are OFF. It keeps switching the displays using transistors. Due to the persistence of vision, it appears as a normal display.<br />

# Features 
Stop Watch counting should start once the power is connected to the MCU.<br />
Configure External Interrupt INT0 with falling edge. Connecting a push button with the
internal pull-up resistor. If a falling edge detected the Stop Watch time should be
reset.<br />
Configure External Interrupt INT1 with raising edge. Connecting a push button with the
external pull-down resistor. If a raising edge detected the Stop Watch time should be
paused.<br />
Configure External Interrupt INT2 with falling edge. Connecting a push button with the
internal pull-up resistor. If a falling edge detected the Stop Watch time should be
resumed.<br />
# Snaps 
![9-23-2022 (06-17-52)](https://user-images.githubusercontent.com/85132939/191891352-7779b192-1d7d-4267-bc39-f7f45b36f533.gif)
