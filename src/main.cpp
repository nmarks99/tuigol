#include <iostream>
#include <ncurses.h>
#include <cmath>
#include <vector>
#include <unistd.h>
#include <assert.h> 


class Universe {
    
    private:

        std::vector<std::vector<int>> init(int rows, int cols, int value=0) {
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
        // 111 = 'o'
        Universe(int rows, int cols, int value=1){
            vec = init(rows, cols, value);
        }
    
};

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
             
            bdr_height = std::floor(y_max * 0.3);
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
                        draw(i+1, (2*j)+1, 'd');
                    }
                    else if (myvec[i][j] == 1) {
                        draw(i+1, (2*j)+1, 'a');
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





// int get_neighbors(Matrix M, int i, int j) {
    //
    // return 1;
// }
//


int main(int argc, char **argv) {
    
    Graphics gr;
    int rows = gr.bdr_height;
    Universe uni(rows,rows);
    // auto myvec = uni.vec;
    gr.draw_universe(uni);

    getch();
    gr.destroy();



    return 0;
}




