
#include "src/Controller_States.h"

void setup()
{
    Serial.begin(115200);
    Serial.println("Serial Connection Established.");
    Serial.println("\t"); // tab

    timer_Setup();           // setup and initialize all clock functionality
    neopixel_Setup();        // setup and initialize neopixels
    Inputs_Hardware_Setup(); // setup and initialize all hardare inputs

    Serial.println("all setup complete");
    Serial.println("\t"); // tab

} // END SETUP

void loop()
{
    state_Idle();
} // END LOOP