
#include "Controller_Output_Lights.h"

////update pixels with amount of time left | started: 22.2.15
void update_Pixels_With_Current_Duration(unsigned long time,unsigned long fromLow,unsigned long FromHigh,unsigned long ToLow,unsigned long ToHigh)
{

    // map current game duration to amount of neopixels in a single score zone (22) for display pourposes
    unsigned long elapsed_TimeDuration_mapped = map(time, 0, gameDuration, 0, NUM_LEDS);
    // set strip position and color //display elapsed time to pixels
    strip.setPixelColor(elapsed_TimeDuration_mapped, strip.Color(0, 200, 250));
    // update strip with new values
    strip.show();

} ////finished: 22.2.15

