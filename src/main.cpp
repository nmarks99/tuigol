#include <iostream>
#include <ncurses.h>
#include <cmath>

class Graphics {
    
    private:
        void draw_border(WINDOW *win) {
            box(win, 0, 0);
            wrefresh(win);
        }

    public:
        
        void init() {

            initscr();
            cbreak();
            noecho();
            curs_set(0); // Sets cursor invisible

            int x_max, y_max;
            getmaxyx(stdscr, y_max, x_max);
             
            int bdr_height = std::floor(y_max * 0.8);
            int bdr_width = std::floor(x_max * 0.8);

            WINDOW *win = newwin(
                    bdr_height,
                    bdr_height*2,
                    y_max/2-bdr_height/2,
                    x_max/2-bdr_height
            );

            refresh(); 
    
            draw_border(win);
            mvwprintw(win, 1, 1, "Hi");
            wrefresh(win);

            mvwprintw(win, 10, 10, "o");
            wrefresh(win);

            getch();
        }


        void destroy() {
            endwin(); 
            std::cout << "Program finished cleanly" << std::endl;
        }
        
        // Constructor
        Graphics() {
            init();
        }

};

int main(int argc, char **argv) {
   
    Graphics gr;
    gr.destroy(); 


    // initscr(); // Clear screen and initialize ncurses
    //
    // move(10,10);
    // printw("Game of life!");
    // getch();
    // endwin(); // Destroy ncurses

    return 0;
}
