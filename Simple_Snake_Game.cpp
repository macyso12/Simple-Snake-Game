//  Simple Snake Game

#include <iostream>
#include <curses.h>
#include <cstdlib>
#include <Carbon/Carbon.h>
//#include <window.h>

// --------------------------------------------------------------------------------------------------
// Variables
using namespace std;
bool gameOver ;
const int width = 20; // map limit
const int height = 20 ; // map limit
int x, y, fruitx, fruity, score ; // variables
int tailx[100], taily[100];
int nTail;
enum eDirection{STOP = 0, LEFT, RIGHT, UP, DOWN}; // track direction of the snake
eDirection dir;
 
// --------------------------------------------------------------------------------------------------
// Setup functions ()
void Setup(){
    gameOver = false ;
    dir = STOP ;
    x = width / 2;
    y = height / 2 ;
    fruitx = rand() % width;
    fruity = rand() % height;
}
// --------------------------------------------------------------------------------------------------
// Draw function ()

void Draw (){
    system ("cls"); // clear the screen/console
    for ( int i = 0; i < width; i++){
        cout << "#" ;
    }
    cout << endl ;
    for ( int i = 0; i < height; i++){
        for ( int j = 0; j < width; j++){
            if (j == 0)
                cout << "#" ;
            if ( i == y && j == x){
                cout << "O";
            }
            else if (i == fruity && j == fruitx){
                cout << "F" ;
            }
            else{
                bool print = false ;
                for (int k = 0; k < nTail; k++){
                    if (tailx[k] == j && taily[k] == i ){
                        cout << "O" ;
                        print = true ;
                    }
                }
                if (!print)
                cout << " " ;
            }

            if (j == width - 1)
                cout << "#" ;
        }
        cout << endl ;
    }
    
    for ( int i = 0; i < width+2; i++){
        cout << "#" ;
    }
    cout << endl ;
    cout << "Score: " << score << endl ;
}
// --------------------------------------------------------------------------------------------------
// Input function (wasd)

Boolean isPressed( unsigned short inKeyCode )
{
    return true ;
}

void Input (){
    if (isPressed('w')==true||isPressed('a')==true||isPressed('s')==true||isPressed('d')==true){
        switch(getch()){
            case 'a':
                dir = LEFT;
                break ;
            case 'd':
                dir = RIGHT;
                break ;
            case 'w':
                dir = UP;
                break ;
            case 's':
                dir = DOWN;
                break ;
            case 'x':
                gameOver = true ;
                break ;
        }
    }
}
// --------------------------------------------------------------------------------------------------
// Logic function ()

void Logic (){
    int prevX = tailx[0];
    int prevY = taily[0];
    int prev2x, prev2y;
    tailx[0] = x ;
    taily[0] = y ;
    for (int i = 1; i < nTail ; i++){
        prev2x = tailx[i];
        prev2y = taily[i];
        tailx[i] = prevX;
        taily[i] = prevY;
        prevX = prev2x;
        prevY = prev2y;
    }
    switch(dir){
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }
    if (x > width || x < 0 || y > height || y < 0)
        gameOver = true ;
    if (x >= width){
        x = 0;
    }
    else if (x < 0){
        x = width - 1 ;
    }
    if (y >= height){
        y = 0;
    }
    else if (y < 0){
        y = height - 1 ;
    }
    for (int i = 0; i < nTail ; i++){
        if (tailx[i] == x && taily[i] == y){
            gameOver = true ;
        }
    }
    if (x == fruitx && y == fruity){
        score += 10 ;
        fruitx = rand()%width ;
        fruity = rand()%height ;
        nTail ++ ;
        
    }
}

// --------------------------------------------------------------------------------------------------
// Main()
int main() {
    Setup();
    while (!gameOver){
        Draw();
        Input();
        Logic();
        sleep (10) ;
    }
    return 0;
}
