#include <ncurses.h>


int main(int argc, char **argv) {
   
    
    initscr(); // Clear screen and initialize ncurses
    
    move(10,10);
    printw("Game of life!");
    getch(); 
    endwin(); // Destroy ncurses

    return 0;
}
