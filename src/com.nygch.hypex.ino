
#include "Controller_Game_Timer.h"

void setup()
{
    Serial.begin(115200);
    Serial.println("Serial Connection Established.");
    Serial.println("\t"); //tab

    timer_Setup();

    neopixel_Setup();

    Inputs_Hardware_Setup(); //setup and initialize all hardare inputs

    Serial.println("all setup complete");
    Serial.println("\t"); //tab

} //END SETUP

void loop()
{

    while (gameState == 0) //while game is paused, wait for the button to be pressed
    {
        rainbow(1, 1);
        Serial.print("waiting to start game || \t");
        Serial.print("Session Highscore: ");
        Serial.println(session_highscore);
        Serial.println("\t"); //tab
        Serial.println("\t"); //tab

        /*START BUTTON CHECK
        - wait for the user to press the start button
        - perform some checks
        - if all is well, prepare to start round
        - display starting info to client
        - start game timer
        */
        // read the button
        startButton.read();
        // if the button was released, this means user has pressed it, so we reset to the pause menu
        if (startButton.wasReleased())
        {
            /*PRINT GAME STARTING INFO 
            this prints all the relevant game over information to the serial console
            - this has delay and trailing dots for purely and solely for asthetic purposes! (can, and most likely will be removed)!
            */
            //// print some game starting info to the serial monitor |started:22.2.13
            blank(100);
            Serial.println("GET READY!!");
            Serial.println("\t"); //tab
            //start 3 second countdown
            //todo: do something with pixels
            delay(1000);
            //todo: do something with pixels
            delay(1000);
            //todo: do something with pixels
            delay(1000);
            //todo: do something with pixels
            //todo: when 3 second countdown is finished turn neopixels WHITE
            delay(250);

            /*START ROUND TIMER
            most of everything is done in here | controller_game_timer
            */
            current_Session_Duration();

        } //END OF MAIN BUTTON PRESS CHECK
    }     //END OF GAME STATE 0 WHILE LOOP //PAUSED STATE
} //END LOOP