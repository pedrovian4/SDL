#ifndef class_hpp
#define class_hpp

#include <SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>




#define WINDOW_HEIGHT 500
#define WINDOW_WIDTH 800
#define FPS 30 
#define FRAME_TIME_TARGET (1000/FPS)

#define BALL_WIDTH 15
#define BALL_HEIGTH 15


class Game 
{
    private:
        bool isRuning=true;
        SDL_Window *window;
        SDL_Renderer *render;
        SDL_Event event;
        SDL_Rect ball{ball.x=WINDOW_WIDTH/2-7, ball.y=WINDOW_HEIGHT/2,BALL_WIDTH, BALL_WIDTH};
        SDL_Rect paddle1{paddle1.x=0, paddle1.y=WINDOW_HEIGHT/2, 15,50};
        SDL_Rect paddle2{paddle2.x=WINDOW_WIDTH-15, paddle2.y=WINDOW_HEIGHT/2, 15,50};
        int last_frame_time=0;
        float delta_time; 
        int time_to_wait;
        int directionsXY[1];
        
    public:
        Game();
        ~Game();
        void process(); 
        void update (); 
        void renderization ();
        bool GetisRunning(){return isRuning;}

};



#endif //class_hpp