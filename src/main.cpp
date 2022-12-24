#include <iostream>
#include <ncurses.h>
#include <cmath>
#include <vector>
#include <unistd.h>

class Graphics {
    
    private:
        WINDOW *win;

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

            win = newwin(
                    bdr_height,
                    bdr_height*2,
                    y_max/2-bdr_height/2,
                    x_max/2-bdr_height
            );

            refresh(); 
    
            draw_border(win);
            mvwprintw(win, 0, bdr_width/2, " Game of Life ");
            wrefresh(win);

            getch();
        }

        void clear_yx(int y, int x) {

            mvwprintw(win, y, x, " ");
            wrefresh(win);

        }

        void draw(int y, int x) {
           
            mvwprintw(win, y, x, "o");
            wrefresh(win);

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


class Universe {
    
    private:

        std::vector<std::vector<int>> init(int rows, int cols, int value = 0) {
            std::vector<std::vector<int>> vec(
                    rows,
                    std::vector<int> (cols, value)
            ) ;
            return vec;
        }

    public:

        std::vector<std::vector<int>> vec;

        void display() {
            // prints the Matrix to the screen. Useful in debugging
            for(int i = 0; i < vec.size(); i++) {
                for(int j = 0; j < vec[i].size(); j++)
                    std::cout << vec[i][j] <<" ";
                std::cout << std::endl;
            }
        }

        // Class constructor. Calls init to construct the vector<vector<int>>
        Universe(int rows, int cols, int value=0){
            vec = init(rows, cols, value);
        }
    
};


// int get_neighbors(Matrix M, int i, int j) {
    //
    // return 1;
// }

int main(int argc, char **argv) {
    
    Graphics gr;
    while (true) {
        int i = 10;
        for (i; i <= 50; i++) {
            gr.draw(10,i);
            usleep(25000);
            gr.clear_yx(10,i);
        }
    }

    gr.destroy();

    return 0;
}




