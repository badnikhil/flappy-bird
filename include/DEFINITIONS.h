#ifndef DEFINITIONS_H
#define DEFINITIONS_H



#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024

#define SPLASH_SCREEN_SHOW_TIME 0.0
#define SPLASH_SCREEN_BG_FILEPATH "assets/sprites/background-day.png"

#define MAIN_MENU_BG_FILEPATH "assets/res/sky.png"
#define GAME_BG_FILEPATH "assets/res/sky.png"
#define GAME_OVER_BG_FILEPATH "assets/res/sky.png"
#define GAME_TITLE_FILEPATH "assets/res/title.png"
#define PLAY_BUTTON_FILEPATH "assets/res/PlayButton.png"

#define PIPE_UP_FILEPATH "assets/res/PipeUp.png"
#define PIPE_DOWN_FILEPATH "assets/res/PipeDown.png"

#define PIPE_MOVEMENT_SPEED 200.0f
#define PIPE_SPAWN_FREQUENCY 2.0f

#define LAND_FILE_PATH "assets/res/land.png"
#define BIRD_FRAME_1_FILE_PATH "assets/res/bird-01.png"
#define BIRD_FRAME_2_FILE_PATH "assets/res/bird-02.png"
#define BIRD_FRAME_3_FILE_PATH "assets/res/bird-03.png"
#define BIRD_FRAME_4_FILE_PATH "assets/res/bird-04.png"

#define BIRD_ANIMATION_DURATION 0.4f

#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALLING 2
#define BIRD_STATE_FLYING 3
#define GRAVITY 350.f
#define FLYING_SPEED 350.0f 
#define FLYING_DURATION 0.25f

#define ROTATION_SPEED 100.0f

enum GameStates{
    eReady,
    ePlaying,
    eGameOver
};


 
#endif