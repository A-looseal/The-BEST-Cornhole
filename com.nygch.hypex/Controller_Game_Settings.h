
#define SCOREZONE_A_WEIGHT 1
#define SCOREZONE_B_WEIGHT 1
#define SCOREZONE_C_WEIGHT 1

int currentlySelected_gameDifficulty = 0;
long currentlySelected_gameDuration = 30;   //30 second game length
long currentlySelected_zoneChangeTime = 3;

//game settings
int current_score;
int session_highscore;
int gameDifficulty;
long gameDuration;
long timeLeft;
long zoneChangeDuration;
int gameState;      //track game state
int scoreZones[] = {1, 2, 3};
int currentScoreZone;
//dificulties
int difficulty_training[]     {2, 10};
int difficulty_rookie[]       {5, 5};
int difficulty_easy[]         {4, 5};
int difficulty_medium[]       {3, 5};
int difficulty_hard[]         {2, 5};
int difficulty_pro[]          {2, 4};
int difficulty_expert[]       {2, 3};
int difficulty_unbeatable[]   {1, 3};