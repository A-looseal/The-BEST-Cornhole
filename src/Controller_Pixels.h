#include <FastLED_NeoPixel.h> //github.com/dmadison/FastLED_NeoPixel

// Which pin on the Arduino is connected to the LEDs?
#define DATA_PIN 2

// How many LEDs are attached to the Arduino?
#define NUM_LEDS 22

// LED brightness, 0 (min) to 255 (max)
#define BRIGHTNESS 150

unsigned int alert_Count_OKAY = 3;
unsigned int alert_Speed_OKAY = 5;
unsigned int alert_Wait_OKAY = 25;
unsigned int alert_Red_OKAY = 0;
unsigned int alert_Green_OKAY = 250;
unsigned int alert_Blue_OKAY = 10;

/* Declare the NeoPixel strip object:
 *     * Argument 1 = Number of LEDs in the LED strip
 *     * Argument 2 = Arduino pin number
 *     * Argument 3 = LED strip color order
 *
 * The FastLED_NeoPixel version uses template arguments instead of function
 * arguments. Note the use of '<>' brackets!
 *
 * You can switch between libraries by commenting out one of these two objects.
 * In this example they should behave identically.
 */
// Adafruit_NeoPixel strip(NUM_LEDS, DATA_PIN, NEO_GRB);  // <- Adafruit NeoPixel version
FastLED_NeoPixel<NUM_LEDS, DATA_PIN, NEO_GRB> strip; // <- FastLED NeoPixel version

/**************
 *CONTROLLERS*
 **************/

/*
Blanks the LEDs and waits for a short time.
example: colorWipe(strip.Color(255, 255, 255), 25);  // white
*/
void blank(unsigned long wait)
{
	strip.clear();
	strip.show();
	delay(wait);
} // blank end

void colorWipe(uint32_t color, unsigned long wait)
{ 
	for (unsigned int i = 0; i < strip.numPixels(); i++)
	{
		strip.setPixelColor(i, color);
		strip.show();
		delay(wait);
	}
} // colorWipe end

/*
 * Simple rainbow animation, iterating through all 8-bit hues. LED color changes
 * based on position in the strip. Takes two arguments:
 *
 *     1. the amount of time to wait between frames
 *     2. the number of rainbows to loop through
 */
void rainbow(unsigned long wait, unsigned int numLoops)
{
	for (unsigned int count = 0; count < numLoops; count++)
	{
		// iterate through all 8-bit hues, using 16-bit values for granularity
		for (unsigned long firstPixelHue = 0; firstPixelHue < 65536; firstPixelHue += 256)
		{
			for (unsigned int i = 0; i < strip.numPixels(); i++)
			{
				unsigned long pixelHue = firstPixelHue + (i * 65536UL / strip.numPixels()); // vary LED hue based on position
				strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));			// assign color, using gamma curve for a more natural look
			}
			strip.show();
			delay(wait);
		}
	}
} // rainbow end

// c = amount of times to blink LED's | s = how fast to blink the leds | w = amount of time to wait between blinks | r = amount of red | g = amount of green | b = amount of blue
void alert_Template(unsigned int c, unsigned int s, unsigned long w, unsigned int r, unsigned int g, unsigned int b)
{
	for (unsigned int i = 0; i < c; i++)
	{
		colorWipe(strip.Color(r, g, b), s);
		blank(w);
	}
}

void neopixel_Setup()
{ // setup all neopixel LED's
	delay(2000);
	strip.begin(); // initialize strip (required!)
	strip.setBrightness(BRIGHTNESS);
	Serial.println("Neopixel setup complete");
	Serial.println("\t"); // tab

	alert_Template(alert_Count_OKAY, alert_Speed_OKAY, alert_Wait_OKAY, alert_Red_OKAY, alert_Green_OKAY, alert_Blue_OKAY); // alert| 3 blinks | fast | green
} // setup end

/**********
 *UPDATERS*
 **********/

//update pixels with amount of time left | started: 22.2.15
void update_Pixels_With_Current_Duration(unsigned long time,unsigned long fromLow,unsigned long FromHigh,unsigned long ToLow,unsigned long ToHigh)
{

    // map current game duration to amount of neopixels in a single score zone (22) for display pourposes
    unsigned long elapsed_TimeDuration_mapped = map(time, fromLow, FromHigh, ToLow, ToHigh);
    // set strip position and color //display elapsed time to pixels
    strip.setPixelColor(elapsed_TimeDuration_mapped, strip.Color(0, 200, 250));
    // update strip with new values
    strip.show();

} ////finished: 22.2.15
