/*
player has X amount of time to score as much points as they can
there are 3 score zones, user has to get the bag into the correct zone,
score zones change at a random time based on difficulty. higher difficulty, faster zone change.
getting the bag in the correct score zone grants 10 points. getting the bag in any other score zone grants 1 point

users distance/motion will also be monitored. 
when game says green light, player can move forward at will.
but if player is still moving after game says red light, player will automatically lose.
if player makes it to withing <24 inches oof the game, player can move at will until game is over.


*/

#include "Controller_Game_Settings.h"
#include "Controller_Game_Updater.h"
#include "Controller_Input_Hardware.h"

unsigned long upTime; //track current uptime
unsigned long currentMillis;
unsigned long previousMillis = 0;
unsigned long elapsed_TimeDuration;
unsigned long elapsed_ZoneChangeDuration;

//buttons
int button_PauseGame_State;

//  CUSTOM FUCNTIONS
//main game loop | check for start button press here
void gameTick()
{
  //keep track of current time
  currentMillis = millis();

  //TODO
  //1. print instructions for saving settings
  //2. button check for button_saveSettingsButton here
  //3. apply selected settings from client to game logic if button_saveSettingsButton is pressed

  //print instructions to start new game
  Serial.println("press S to start timer");
  //if start button has been pressed
  //if (newData == true) {
  //  //start game clock
  //  TimeDuration();
  //}
}

void timer_Setup()
{
  gameDuration = currentlySelected_gameDuration;
  zoneChangeDuration = currentlySelected_zoneChangeTime;
  gameDifficulty = currentlySelected_gameDifficulty;
} //end of setup

//print to serial current MCU upTime
void displayUpTime()
{
  upTime = millis(); //update newest time
  Serial.print("uptime: ");
  Serial.println(upTime / 1000);
}

//print to serial time left in the round
void serialPrintElapsedTime()
{
  //time left this round
  Serial.print("Time elapsed this round: ");
  Serial.println(gameDuration - elapsed_TimeDuration);
}

//prints all stats at once to serial console
void printShit_serial()
{
  //print data . print as fast as possible
  //time left this round
  Serial.print("Time elapsed this round: ");
  Serial.println(gameDuration - elapsed_TimeDuration);
  //current score zone
  Serial.print("current score zone is: "); //print tet to screen
  Serial.println(currentScoreZone);        //print tet to screen
  //zone change in
  Serial.print("zone change in: ");                                //print tet to screen
  Serial.println(zoneChangeDuration - elapsed_ZoneChangeDuration); //print value to the screen
}

//picks a random zone when called. modifies currentScoreZone value
int Randomize_Zone()
{
  currentScoreZone = random(3);
  return currentScoreZone;
}

//keeps track of time until next zone change
void ZoneChangeDuration()
{
  //record the time game was started
  unsigned long startTime = millis();
  //create a timer based on current game settings
  unsigned long timer = 1000ul * zoneChangeDuration;
  // Repeatedly check if time is up using a while loop
  // While loop will continue until zoneChangeDuration time is up
  while ((millis() - startTime) < timer)
  {
    // Calculate time elapsed in seconds
    elapsed_ZoneChangeDuration = int((millis() - startTime) / 1000);
    //check when it is time to change score zone
    if (elapsed_ZoneChangeDuration <= 0)
    {
      //pick random score zone
      Randomize_Zone();
    }
    printShit_serial();
    delay(1000);
  }
}

//generate random zone change duration based on chosen difficulty
int Randomize_ZoneChangeDuration()
{
  int minValue;
  int maxValue;
  switch (gameDifficulty)
  {
  case 0: //training
    minValue = difficulty_training[0];
    maxValue = difficulty_training[1];
    //generate random zoneChangeDuration based on selected difficulty
    zoneChangeDuration = random(minValue, maxValue);
    //apply new randomly generated zoneChangeDuration based on selected difficulty, to the game clock
    ZoneChangeDuration();
    break;
  case 1: //rookie
    minValue = difficulty_rookie[0];
    maxValue = difficulty_rookie[1];
    //generate random zoneChangeDuration based on selected difficulty
    zoneChangeDuration = random(minValue, maxValue);
    //apply new randomly generated zoneChangeDuration based on selected difficulty, to the game clock
    ZoneChangeDuration();
    break;
  case 2: //easy
    minValue = difficulty_easy[0];
    maxValue = difficulty_easy[1];
    //generate random zoneChangeDuration based on selected difficulty
    zoneChangeDuration = random(minValue, maxValue);
    //apply new randomly generated zoneChangeDuration based on selected difficulty, to the game clock
    ZoneChangeDuration();
    break;
  case 3: //medium
    minValue = difficulty_medium[0];
    maxValue = difficulty_medium[1];
    //generate random zoneChangeDuration based on selected difficulty
    zoneChangeDuration = random(minValue, maxValue);
    //apply new randomly generated zoneChangeDuration based on selected difficulty, to the game clock
    ZoneChangeDuration();
    break;
  case 4: //hard
    minValue = difficulty_hard[0];
    maxValue = difficulty_hard[1];
    zoneChangeDuration = random(minValue, maxValue);
    //apply new randomly generated zoneChangeDuration based on selected difficulty, to the game clock
    ZoneChangeDuration();
    break;
  case 5: //pro
    minValue = difficulty_pro[0];
    maxValue = difficulty_pro[1];
    //generate random zoneChangeDuration based on selected difficulty
    zoneChangeDuration = random(minValue, maxValue);
    //apply new randomly generated zoneChangeDuration based on selected difficulty, to the game clock
    ZoneChangeDuration();
    break;
  case 6: //expert
    minValue = difficulty_expert[0];
    maxValue = difficulty_expert[1];
    //generate random zoneChangeDuration based on selected difficulty
    zoneChangeDuration = random(minValue, maxValue);
    //apply new randomly generated zoneChangeDuration based on selected difficulty, to the game clock
    ZoneChangeDuration();
    break;
  case 7: //unbeatable
    minValue = difficulty_unbeatable[0];
    maxValue = difficulty_unbeatable[1];
    //generate random zoneChangeDuration based on selected difficulty
    zoneChangeDuration = random(minValue, maxValue);
    //apply new randomly generated zoneChangeDuration based on selected difficulty, to the game clock
    ZoneChangeDuration();
    break;
  default:
    // if nothing else matches, do the default
    //TO DO
    //1. set zone change duration to 10 minutes
    //2. apply STANDBY zone light pattern using neopixels
    //
    break;
  }
}

// keeps track of time until round is over
void current_Session_Duration()
{

  /* Repeatedly check if time is up using a while loop
   While loop will continue until gameDuration time is up 
   TODO
   - set the game state to play mode (1)
   - calculate the amount of time elapsed in seconds
   - change current valid score zone randomly
   - game over when timer reaches to 0
   - check for user pressing start button
   */

  unsigned long startTime = millis();          //record the time game was started
  unsigned long timer = 1000ul * gameDuration; //create a timer based on current game settings
  while ((millis() - startTime) < timer)
  {
    //set game state to play mode (1)
    gameState = 1;

    
    // Calculate time left in round. divide by 1000 to get 'seconds' value
    elapsed_TimeDuration = int((millis() - startTime) / 1000);
    // change score zones randomly  | this will run until round is over
    //Randomize_ZoneChangeDuration();
    ///////////////////add core game logic here/////////////////

    update_Pixels_With_Current_Duration(elapsed_TimeDuration,0, gameDuration, 0, NUM_LEDS);
    
    ////display current score, and amount of time left on serial console |started :22.2.13
    // prints the elapsed time to the serial console
    serialPrintElapsedTime();
    // prints the currnet score to the serial console
    Serial.print("Current score: ");
    Serial.print(current_score);
    Serial.print("\t");
    // prints the session highscore to the serial console
    Serial.print("Session Highscore: ");
    Serial.println(session_highscore);
    Serial.println("\t");
    Serial.println("\t"); //update pixels
    ////finished: 22.2.13

    ////check for the score zone being triggered by an object: 22.2.13
    //if score zone A has been triggered, do this
    if (scoreZone_A_Triggered() == true)
    {
      // print confirmation of score zone being triggered to serial console
      //TODO: make this so it can easily be turned on/off
      Serial.println("SCOREZONE_A has been triggered!");
      //if score zone is triggered, add some new points to the current score
      current_score = current_score + SCOREZONE_A_WEIGHT;
    } ////finished: 22.2.13

    /*START BUTTON CHECK
    ////check if button was pressed, if it was reset state to 0 |started: 22.2.12
    */
    // read the current button state
    startButton.read();
    // if the button was released, this means user has pressed it, so we reset to the pause menu
    if (startButton.wasReleased())
    {

      /*PRINT GAME OVER INFO 
      this prints all the relevant game over information to the serial console
      - this has delay and trailing dots for purely and solely for asthetic purposes! (can, and most likely will be removed)!
      */
      //// print some game over info to the serial monitor |started:22.2.13
      Serial.println("Game Over! ");
      Serial.print("RESETTING NOW \t");
      //start 3 second countdown
      delay(1000);
      //todo: do something with pixels
      Serial.print(".");
      delay(1000);
      //todo: do something with pixels
      Serial.print(".");
      delay(1000);
      //todo: do something with pixels
      Serial.println(".");
      ////finished: 22.2.13

      //check if current score is higher than session_highscore
      if (current_score > session_highscore)
      {
        //if it is, update highscore with current score
        session_highscore = current_score;
      }

      current_score = 0; //reset current score back to 0
      gameState = 0;     //set game state back to not playing
    }                    //END OF START BUTTON CHECK
                         ////finished: 22.2.13

  } //} //END OF "GAME STATE 1" WHILE LOOP //PLAYING STATE

  /*GAME OVER  //// started:22.2.13
      -this prints all the relevant game over information to the serial console
      - this also sets the new highscore if relevant
      - this has delay and trailing dots for purely and solely for asthetic purposes! (can, and most likely will be removed)!
  */
  //when game clock reaches zero, set game state to idle(0)
  gameState = 0;
  if (gameState == 0) // if the game is over
  {
    //// print some game over info to the serial monitor
    Serial.println("Game Over! ");
    Serial.print("RESETTING NOW \t");
    delay(1000);
    //todo: do something with pixels
    Serial.print(".");
    delay(1000);
    //todo: do something with pixels
    Serial.print(".");
    delay(1000);
    //todo: do something with pixels
    Serial.println(".");
    ////finished: 22.2.13


    /*SET NEW HIGHSCORE //// started:22.2.13
    - this checks if the current score is greater than the current highscore and updates the highscore accordingly
    */
    //check if current score is higher than session_highscore
    if (current_score > session_highscore)
    {
      //if it is, update highscore with current score
      session_highscore = current_score;
    }
    //reset current score back to 0
    current_score = 0;
    ////finished: 22.2.13
  }
}
