// serial print

/*STATES:
    idle
    pre-playing
    playing
    post-playing
    game-over WIN
    game-over LOSE
    */

/*IDLE
    //todo
    current uptime
    ////highscore info
    */

    //prints idle info to the serial console
    uint8_t serialPrint_Info_idle(int _session_highscore){ 
        Serial.print("Press Start Button to play! || \t");
        Serial.print("Session Highscore: ");
        Serial.println(_session_highscore);
        Serial.println("\t"); //tab
        Serial.println("\t"); //tab
    } ////aLooSeal - 22.2.15
    

/*PRE-PLAYING
    //todo
    ////pre play info
    */

    /*PRINT GAME STARTING INFO 
            this prints all the relevant game over information to the serial console
            - this has delay and trailing dots for purely and solely for asthetic purposes! (can, and most likely will be removed)!
            */
    void serialPrint_Info_PrePlay(){ 
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
    } ////aLooSeal - 22.2.15
    

/*PLAYING
    current time left in the round
    *current score info
    */

/*POST-PLAYING
    -post play info
        
    */

/*GAME-OVER WIN
    -game over info
    -new highscore info
    -highscore info
    */

/*GAME-OVER LOSE
    -game over info
    -try again info
    -highscore info
    */

/*RESET
    -resseting info
    */


