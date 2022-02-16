/*
File Name: Inputs_Hardware.h
Description: hardware input control
Version: 1.0.0

Created By: aLooSeal
Initial Creation Date: 22-02-08 

TODO:
//-implement functionality of start button
//-implement functionailty of score trigger zones
//-track score trigger zones state

*/

#include <JC_Button.h> // https://github.com/JChristensen/JC_Button
//#include "Controller_Output_Lights.h"

/**************
 *START BUTTON*
 **************/
////-implement functionality of start button
//define start button pins
#define BUTTON_GND_PIN A0
#define startButton_PIN 9
//define score zone laser sensors pins
#define SCOREZONE_A_SENSOR_1_PIN 3
#define SCOREZONE_A_SENSOR_2_PIN 4
#define SCOREZONE_B_SENSOR_1_PIN 5
#define SCOREZONE_B_SENSOR_2_PIN 6
#define SCOREZONE_C_SENSOR_1_PIN 7
#define SCOREZONE_C_SENSOR_2_PIN 8

//construct score zone laser sensors as 'button object' (JC_Button.h)
Button startButton(startButton_PIN);                   // construct the button
Button scorezone_A_Sensor_1(SCOREZONE_A_SENSOR_1_PIN); // construct the button
Button scorezone_A_Sensor_2(SCOREZONE_A_SENSOR_2_PIN); // construct the button
Button scorezone_B_Sensor_1(SCOREZONE_B_SENSOR_1_PIN); // construct the button
Button scorezone_B_Sensor_2(SCOREZONE_B_SENSOR_2_PIN); // construct the button
Button scorezone_C_Sensor_1(SCOREZONE_C_SENSOR_1_PIN); // construct the button
Button scorezone_C_Sensor_2(SCOREZONE_C_SENSOR_2_PIN); // construct the button

/***********
 *FUNCTIONS*
 ***********/
void Inputs_Hardware_Setup()
{ //setup all hardware inputs
    delay(2000);
    //initialize main menu button objects (JC_Button.h)
    pinMode(BUTTON_GND_PIN, OUTPUT);
    analogWrite(BUTTON_GND_PIN, 0);
    digitalWrite(BUTTON_GND_PIN, LOW);
    startButton.begin(); // initialize the button object
    Serial.println("startButton has been successfully setup");

    delay(1000);

    //initialize score zone laser sensor objects (JC_Button.h)
    scorezone_A_Sensor_1.begin(); // initialize the button object
    Serial.println("scorezone_A_Sensor_1 has been successfully setup");
    Serial.println("\t"); //tab
    scorezone_A_Sensor_2.begin(); // initialize the button object
    Serial.println("scorezone_A_Sensor_2 has been successfully setup");
    Serial.println("\t"); //tab
    scorezone_B_Sensor_1.begin(); // initialize the button object
    Serial.println("scorezone_B_Sensor_1 has been successfully setup");
    Serial.println("\t"); //tab
    scorezone_B_Sensor_2.begin(); // initialize the button object
    Serial.println("scorezone_B_Sensor_2 has been successfully setup");
    Serial.println("\t"); //tab
    scorezone_C_Sensor_1.begin(); // initialize the button object
    Serial.println("scorezone_C_Sensor_1 has been successfully setup");
    Serial.println("\t"); //tab
    scorezone_C_Sensor_2.begin(); // initialize the button object
    Serial.println("scorezone_C_Sensor_2 has been successfully setup");
    Serial.println("\t"); //tab
    delay(1000);
    Serial.println("all score zones initialized");
    Serial.println("\t"); //tab
    Serial.println("\t"); //tab
    delay(150);
    Serial.println("Hardware Inputs setup is complete.");
    Serial.println("\t"); //tab
    
    //alert_Template(alert_Count_OKAY, alert_Speed_OKAY, alert_Wait_OKAY, alert_Red_OKAY, alert_Green_OKAY, alert_Blue_OKAY); //alert| 3 blinks | fast | green
}

////track score trigger zones state
bool scoreZone_A_Triggered() //check if SCORE_ZONE_A has been triggered
{
    scorezone_A_Sensor_1.read();                                                  //read data from sensor 1
    scorezone_A_Sensor_2.read();                                                  //read data from sensor 2
    if (scorezone_A_Sensor_1.wasReleased() || scorezone_A_Sensor_2.wasReleased()) // if sensor 1, OR sensor 2 has been triggered
    {
        return true;
        //Serial.println("SCOREZONE_A has been triggered!");
    }
    else
    {
        return false;
    }
}

////track score trigger zones state
bool scoreZone_B_Triggered() //check if SCORE_ZONE_A has been triggered
{
    scorezone_B_Sensor_1.read();                                                  //read data from sensor 1
    scorezone_B_Sensor_2.read();                                                  //read data from sensor 2
    if (scorezone_B_Sensor_1.wasReleased() || scorezone_B_Sensor_2.wasReleased()) // if sensor 1, OR sensor 2 has been triggered
    {
        return true;
        //Serial.println("SCOREZONE_B has been triggered!");
    }
    else
    {
        return false;
    }
}

////track score trigger zones state
bool scoreZone_C_Triggered() //check if SCORE_ZONE_A has been triggered
{
    scorezone_C_Sensor_1.read();                                                  //read data from sensor 1
    scorezone_C_Sensor_2.read();                                                  //read data from sensor 2
    if (scorezone_C_Sensor_1.wasReleased() || scorezone_C_Sensor_2.wasReleased()) // if sensor 1, OR sensor 2 has been triggered
    {
        return true;
        //Serial.println("SCOREZONE_C has been triggered!");
    }
    else
    {
        return false;
    }
}
