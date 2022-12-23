#include <ncurses.h>
#include <iostream>
#include "include/helpers.hpp" 

int main(int argc, char **argv) {
   
    int a = 1;
    int b = 2;

    int c = add(a,b);
    
    std::cout << c << std::endl;


    // initscr(); // Clear screen and initialize ncurses
    //
    // move(10,10);
    // printw("Game of life!");
    // getch();
    // endwin(); // Destroy ncurses

    return 0;
}
