# Magnetic valve control

## Summary
This project is about controlling a magnetic valve to automate the watering of my garden. The magnetic valve is connected on both sides to some tubing of my Gardena Microdrip system. The valve should control part of the tube system and turn on the watering every evening. I have 3D printed the adapters for connecting the 4.6 mm Gardena Microdrip tube to the magnetic valve and added some gaskets to make it water tight. The magnetic valve is turned on and off by a MOSFET transistor acting as switch. You need a MOSFET, I also tried a common bipolar transistor (BC337) first, but the bipolar transistor is not powerful enough. The valve did not move. The transistor is controlled again by an Arduino Nano. The trigger of the Arduino is scheduled to happen every evening. For keeping the right time even in case of power outage, the Arduino Nano is connected to a real time clock (RTC) module which saves the time. Everything is powered by an old DC power supply (12 V DC, 800 mA) that I had lying around from other electronics.



## Bill of materials

* Arduino Nano
* DS3231 RTC module
* [IRF 520 MOSFET transistor](https://www.vishay.com/docs/91017/91017.pdf) (or similar)
* 1 kOhm resistor
* [1N4001 diode](https://www.onsemi.com/pdf/datasheet/1n4001-d.pdf) (or similar)
* magnetic solenoid valve, 12 V DC 
* DC power supply, 12 V DC, 800 mA (or similar, the current rating can potentially be different)


## Circuit setup

The following picture shows the schematic of the circuit. The resistor R1 limits the current from the Arduino Nano to the transistor Q1 and protects both components. The diode D1 protects the solenoid L1 (the magnetic valve) from the peak of the induced inverse voltage when the solenoid switching off.

<img src="circuit_schematic.png" width=70%>



The following picture shows the illustration of the circuit. Please note that the 12 V power supply is not illustrated and should be connected to the red and black wires. The solenoid can be connected with either polarity.

<img src="circuit_illustration.png" width=70%>


## Links and references

A similar project can be found here: https://bc-robotics.com/tutorials/controlling-a-solenoid-valve-with-arduino/ 