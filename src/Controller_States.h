
#include "Controller_Game_Timer.h"
#include "Updater_SerialPrint_IdleState.h"

/*IDLE STATE
 */
void state_Idle()
{
    while (gameState == 0) // while game is paused, wait for the button to be pressed
    {
        rainbow(1, 1);
        serialPrint_Info_idle(session_highscore); // print idle info to serial monitor
        startButton.read();                       // read the start button

        if (startButton.wasReleased()) // if the start button was released, this means user has pressed it, so we reset to the pause menu
        {
            blank(1);
            serialPrint_Info_PrePlay(); // print some game starting info to the serial monitor
            current_Session_Duration(); // start round timer
        }                               // END OF MAIN BUTTON PRESS CHECK
    }                                   // END OF GAME STATE 0 WHILE LOOP //PAUSED STATE
}

/*IDLE STATE
 */
void state_PrePlay()
{
    
}