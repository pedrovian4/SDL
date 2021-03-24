#include <SDL2/SDL.h>//inclusão da biblioteca //lib inclusion 
#include<iostream>// C++ biblioteca padrão de inclusão


SDL_Window *window=NULL; // Variavel janela para criar a janela com uso da estrutura SDL_Window//Window variable to creation of window through SDL_Window Struct
SDL_Renderer *renderer= NULL; //variavel do da struct de renderização// Struct Renderization variable 



class FirstWindow{
    public:
        FirstWindow(); // construtor para inicialização//constructior to initialization
        //~FirstWindow(); //Desconstrutor para finalização do programa// Desconstructor  to end the program 
        void Renderer(); //função para a renderização da janela//Renderization of the window fuction
        bool GetRunning(){return isRunning;}
        

    private: 
        bool isRunning=true;
};


FirstWindow::FirstWindow(){
    if(SDL_Init(SDL_INIT_VIDEO)!=0){
        std::cout<<"VIDEO SDL ERROR: "<<SDL_GetError();
        isRunning=false;
    }else{
        // SDL_CreateWindow os parametrso são: Titulo da janela, posição X e Y no plano, tamanho altura e largura, e uma SDL_Flag
        //  SDL_CreateWindow the parameters are: Title to the window, the positions at plane, size of the window with width and height and SDL_Flag
        window= SDL_CreateWindow("My First Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_RESIZABLE);
        
        
        //It Will return the window value if  was sucessed created otherwise will return NULL which means failure 
        //Ira retornar valor da window se for bem sucessedida a criação da janela, caso contrário irá retornar NULL que será falha na criação  


        //Check if was correctly created 
        //Checar se foi criada corretamente

        if(!window){
            std::cout<<"WINDOW Creation ERROR"<<SDL_GetError();
                isRunning=false;
        }
    }

}


void FirstWindow::Renderer(){


    //SDL_CreateRenderer tem esse padrão por enquanto após explicarei melhor 
    //SDL_CreateWindow for now this is the deafult after  will be better explained 
   
    renderer=SDL_CreateRenderer(window, -1,0);

    //Check error same as the others 
    //Checar os erros mesmo padrão dos antigos 
    if(!renderer){
        std::cout<<"SDL Renderization ERROR"<<SDL_GetError();

        isRunning=false;
    }



    // this is how you use to show colors on your screen 
    //Assim você mostra cores na sua tela
    SDL_SetRenderDrawColor(renderer, 255,0,0,0);

    //After SDL_RenderDrawColr or whatever operation you need after clean the buffer
    //Depois da função é preciso fazer a limpeza do Buffer para as cores aparecerem 

    SDL_RenderClear(renderer);   


    //Apresentar  a janela 
    //Show the window
    SDL_RenderPresent(renderer);



}


int main (int argc, const char* argv[]){

    FirstWindow *Window_Obj= new FirstWindow();// calling the constructor the first OBJ // chamando construtor para o primeiro objeto 



    if(Window_Obj->GetRunning()==true){
        Window_Obj->Renderer(); 
        SDL_Delay(5000);
    }




    //Fechar SDL
    //Close SDl
    
    SDL_Quit();
    return 0;
}