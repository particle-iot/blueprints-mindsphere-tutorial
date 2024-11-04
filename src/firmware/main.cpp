/* 
 * Particle Blueprint - Siemens MindSphere Tutorial
 * https://github.com/particle-iot/blueprint-hello-world
 */

// Include Particle Device OS APIs
#include "Particle.h"

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(AUTOMATIC);

// Show system, cloud connectivity, and application logs over USB
// View logs with CLI using 'particle serial monitor --follow'
SerialLogHandler logHandler(LOG_LEVEL_INFO);

// setup() runs once, when the device is first turned on
void setup() {
  Log.info("Setup has finished!");
}

//This loop generate temperature data that goes up and down in steps between 12 and 30 degrees
//it starts at 12 and goes up to 30 in increments of 0.1 every 10 seconds. when it hits 30 it goes back down to 12
void loop() {
  static float temperature = 12.0;
  static bool goingUp = true;

  //print the temperature to the console
  Log.info("Temperature: %.2f", temperature);

  //increment or decrement the temperature
  if (goingUp) {
    temperature += 0.1;
  } else {
    temperature -= 0.1;
  }

  //if the temperature is 30, start going down
  if (temperature >= 30.0) {
    goingUp = false;
  }

  //if the temperature is 12, start going up
  if (temperature <= 12.0) {
    goingUp = true;
  }

  //publish to the cloud as JSON
  Particle.publish("temperature", String::format("{ \"temperature\": %.2f }", temperature) );

  //block for 10 seconds
  delay( 10 * 1000 );
}
