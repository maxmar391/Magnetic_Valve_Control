// Date and time functions using a DS3231 RTC connected via I2C and Wire lib
#include "RTClib.h"

RTC_DS3231 rtc;

const int ValvePin = 3; // Define the output pins for controlling the magnetic valves
const int ValvePin2 = 9;

const int WaterTime = 5000; // Watering time in ms


//---------------------------
void setup() {
  Serial.begin(57600); // start serial monitor

  pinMode(ValvePin, OUTPUT); // Initialize output pin for valve
  digitalWrite(ValvePin, LOW); // ensure output pin for valve is off
  pinMode(ValvePin2, OUTPUT); // Initialize output pin for valve
  digitalWrite(ValvePin2, LOW); // ensure output pin for valve is off

  // wait for serial port to connect. Needed for native USB
  #ifndef ESP8266
    while (!Serial); 
  #endif

  //check for RTC
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  }

}


//---------------------------
void loop() {

  DateTime now = rtc.now(); // define time variable and read the current time and date
  Serial.print("Time = ");
  Serial.print(now.hour(), DEC);
  Serial.print(":");
  Serial.print(now.minute(), DEC);
  Serial.print(":");
  Serial.println(now.second(), DEC);

  if (now.hour() == 20 && now.minute() == 00) { 
    Serial.println("Watering time!");

    digitalWrite(ValvePin, HIGH); // activate the valve
    digitalWrite(ValvePin2, HIGH); 
    Serial.println("Valve switched ON");
    delay(WaterTime); // valve active time = watering time 

    digitalWrite(ValvePin, LOW); // deactive the valve
    digitalWrite(ValvePin2, LOW);
    Serial.println("Valve switched OFF");

    delay(60000); // wait for 60 s to ensure that the valve is not activated again because the if condition is still true
  }

  delay(20000); // determines frequency of time and date reading
}
