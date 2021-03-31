#include "functions.hpp"
#include "class.hpp"

int main (int arc, char*argv[]){
    Game * game = new Game();

    while (game->GetisRunning())
    {
        
        game->renderization();
        game->process();
        game->update();
    }
    
    
    return 0;
}