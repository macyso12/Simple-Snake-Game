// Macy So
// Snake_Game_Advanced


#include <iostream>
#include <ncurses.h>
#include <curses.h>
#include <cstdlib>

using namespace std;

//variables (Global Variables)
bool gameOver;
const int width = 20, height = 20;
int x, y, FruitX, FruitY, score;
enum eDirection {STOP = 0, LEFT, RIGHT, Up, DOWN};
eDirection dir;

void Setup(){
    
    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);
    
    gameOver = false;
    dir = STOP;
    x = width/2;
    y = height/2;
    FruitX = (rand()%width)+1;
    FruitY = (rand()%height)+1;
    score = 0;
}

void Draw(){
    
    clear();
    for(int i = 0; i < width+2; i++){
        mvprintw(0, i, "+");
    }
    
    for(int i = 0; i < height+2; i++){
        for (int j = 0; i < width+2; j++){
            if ( i == 0 || i == 21){
                mvprintw(i, j, "+");
            }
            else if (j == 0|| j == 21){
                mvprintw(i, j, "+");
            }
            else if (i == y && j == x){
                mvprintw(i, j, "O");
            }
            else if (i == FruitY && j == FruitX){
                mvprintw(i, j, "@");
            }
        }
    }
    mvprintw(23,0,"Score %d", score);
    
    refresh();
    getchar();
}

void Input(){
    
}

void Logic(){
    
}

int main() {

    Setup();
    Draw();
    /*while (!gameOver){
        Draw();
        Input();
        Logic();
    }*/
    return 0;
}
