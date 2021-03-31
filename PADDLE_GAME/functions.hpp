#ifndef functions_hpp
#define functions_hpp

#include<cstdlib>
#include <iostream>
#include <SDL2/SDL.h>
#include "class.hpp"




Game::Game(){

    

    if(SDL_Init(SDL_INIT_EVERYTHING)!=0){
        std::cout<<"SDL INITIALIZATION ERROR"<<SDL_GetError();
        isRuning=false; 
    }

    window= SDL_CreateWindow("PADDLE GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,WINDOW_WIDTH,WINDOW_HEIGHT,SDL_WINDOW_OPENGL);
    
    if(!window){
        std::cout<<"SDL CREATE WINDOW ERROR"<<SDL_GetError();
        isRuning=false;    }
    
    render = SDL_CreateRenderer(window,-1,0);

    if(!render){
        std::cout<<"SDL RENDER  ERROR"<<SDL_GetError();
        isRuning=false;}
}

Game::~Game(){
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::renderization(){

    SDL_SetRenderDrawColor(render,0,0,0,0);

    SDL_RenderClear(render);

    SDL_SetRenderDrawColor(render,255,255,255,255);
    for(int i = 0; i<WINDOW_HEIGHT; i++){
        SDL_RenderDrawPoint(render,WINDOW_WIDTH/2, i);
    }
    
    SDL_SetRenderDrawColor(render, 255,255,255,255);
    SDL_RenderFillRect(render, &ball);

    SDL_SetRenderDrawColor(render, 255,255,255,255);
    SDL_RenderFillRect(render, &paddle1);

    SDL_SetRenderDrawColor(render, 255,255,255,255);
    SDL_RenderFillRect(render, &paddle2);

    SDL_RenderPresent(render);


}

void Game::update(){
    
    
    

    time_to_wait=  FRAME_TIME_TARGET - (SDL_GetTicks()-last_frame_time);

    if(time_to_wait>0 && time_to_wait<=FRAME_TIME_TARGET){
        SDL_Delay(time_to_wait);
    }

    delta_time = (SDL_GetTicks()- last_frame_time)/10.0F;
    
    system("clear");

    std::cout<<"Delta time: "<<delta_time<<std::endl;
    std::cout<<"last frame time: "<<last_frame_time<<std::endl;
    std::cout<<"paddle one position y: "<<paddle1.y<<std::endl;
    std::cout<<"paddle two position y : "<<paddle2.y<<std::endl;
    std::cout<<"paddle one position x: "<<paddle1.x<<std::endl;
    std::cout<<"paddle two position x : "<<paddle2.x<<std::endl;
    std::cout<<"bal position x : "<<ball.x<<std::endl;
    std::cout<<"ball position y : "<<ball.y<<std::endl;
    last_frame_time = SDL_GetTicks();
}



void Game::process(){

    SDL_PollEvent(&event);
    
    switch (event.type)
    {

    case SDL_QUIT:
            isRuning=false;
        break;
    
    case SDL_KEYDOWN:

        if(paddle1.y<=0) paddle1.y=1;

        if(event.key.keysym.sym==SDLK_DOWN) paddle1.y+=3*delta_time;
            
        
        if(paddle1.y>=WINDOW_HEIGHT) paddle1.y=WINDOW_HEIGHT-paddle1.h; 

        if(event.key.keysym.sym==SDLK_UP) paddle1.y-=3*delta_time;


    case SDL_KEYUP: 
        if(event.key.keysym.sym==SDLK_SPACE){
            ball.x+=1*delta_time*1.12;
        }        
        
        break;
       }
        
    }









#endif //functions_hpp