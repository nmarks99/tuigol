// #include <iostream>
// #include <ncurses.h>
// #include <cmath>
// #include <vector>
// #include <unistd.h>
// #include <assert.h>
// #include <time.h>
#include "gol.h"

#define GAME_SIZE 0.8 // percentage of terminal window to take up with game
#define ALIVE_CHAR 'o' // character representing living cells
#define DEAD_CHAR ' ' // character representing dead cells
#define REFRESH_RATE 20 // rate at which to refresh the game
#define USEC 1000000 

class Graphics {
    
    private:
        WINDOW *win;

        void draw_border(WINDOW *win) {
            box(win, 0, 0);
            wrefresh(win);
        }

    public:
        
        int bdr_height;
        int bdr_width;

        void init() {

            initscr(); // initialize ncurses screen
            cbreak(); // CTRL+C will terminal program
            noecho(); // do not display user input
            curs_set(0); // Sets cursor invisible

            int x_max, y_max;
            getmaxyx(stdscr, y_max, x_max);
             
            bdr_height = std::floor(y_max * GAME_SIZE);
            bdr_width = bdr_height * 2;
            win = newwin(
                    bdr_height+2,
                    bdr_width+2,
                    y_max/2-bdr_height/2,
                    x_max/2-bdr_height
            );

            refresh(); 
    
            draw_border(win);
            mvwprintw(win, 0, bdr_width/2 - 6, " Game of Life ");
            wrefresh(win);

            getch();
        }

        void clear_yx(int y, int x) {
            mvwprintw(win, y, x, " ");
            wrefresh(win);
        }


        void draw(int y, int x, int ch) {
            mvwprintw(win, y, x, "%c", ch);
            wrefresh(win);
        }

        void draw_universe(Universe uni) {
            int i, j;
            auto myvec = uni.vec;
            for(i = 0; i < myvec.size(); i++) {
                for(j = 0; j < myvec[i].size(); j++)
                    if (myvec[i][j] == 0) {
                        draw(i+1, (2*j)+1, DEAD_CHAR);
                    }
                    else if (myvec[i][j] == 1) {
                        draw(i+1, (2*j)+1, ALIVE_CHAR);
                    }
            }
        }


        void destroy() {
            endwin(); 
            std::cout << "Program finished cleanly" << std::endl;
        }
        
        // Class constructor
        Graphics() {
            init();

        }

};



int main(int argc, char **argv) {
   
    // initialize graphics 
    Graphics gr; 

    int rows = gr.bdr_height;
    Universe uni(rows,rows,true);

    gr.draw_universe(uni);
    getch();

    int iterations = 200;
    int k = 0;
    while (k < iterations) {
        
        gr.draw_universe(uni);
        usleep(1000000/REFRESH_RATE);
        uni.next_gen();

        k++;

    }

    getch();
    gr.destroy();



    return 0;
}




