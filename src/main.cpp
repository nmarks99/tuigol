#include <iostream>
#include <ncurses.h>
#include <cmath>
#include <vector>
#include <unistd.h>
#include <assert.h> 

// percentage of terminal height/width to use for the game
#define GAME_SIZE 0.6
#define ALIVE_CHAR 'o'
#define DEAD_CHAR ' '

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

        int get_neighbors(int rownow, int colnow) {

            int rowup = rownow - 1;
            int rowdown = rownow + 1;
            
            int nln = 0; // number of living neighbors
            
            // Check current row
            int cell = vec[rownow][colnow-1];
            if (cell == 1){
                nln +=1;
            }
            cell = vec[rownow][colnow+1];
            if (cell == 1){
                nln += 1;
            }

            // check row above
            for (int i = colnow-1; i < colnow+2; i++) {

                cell = vec[rowup][i];
                if (cell == 1){
                    nln += 1;
                }
            }

            // check row below
            for (int i = colnow-1; i < colnow+2; i++) {
                cell = vec[rowdown][i];
                if (cell == 1){
                    nln += 1;
                }
            }

            return nln;

        }

        void next_gen() {
            int N = vec.size();
            
            for (int i=1; i < N-1; i++) {
                for (int j=1; j < N-1; j++) {

                    int nln = 0;
                    int cell = vec[i][j];
                    nln = get_neighbors(i,j);

                    // If cell is alive
                    if (cell == 1) {
                        if (nln == 0 || nln == 1 || nln >= 4) {
                            vec[i][j] = 0; // cell dies
                        }
                        else if (nln == 2 || nln ==3) {
                            vec[i][j] = 1; // cell lives
                        }
                    }

                    // If cell is dead
                    if (cell == 0) {
                        if (nln == 3) {
                            vec[i][j] = 1; // cell lives
                        }
                    }

                }
            }
        }


        // Class constructor. Calls init to construct the vector<vector<int>>
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
    
    Graphics gr;
    // int rows = gr.bdr_height;
    Universe uni(4,4,0);
    
    uni.vec[1][2] = 1; 
    uni.vec[1][0] = 1;
    uni.vec[1][1] = 1;
    uni.vec[0][1] = 1;
    uni.vec[0][0] = 1;
    uni.vec[2][0] = 1;
    
    gr.draw_universe(uni);
    int nln = uni.get_neighbors(1,1);
    uni.next_gen(); 
    getch();
    gr.draw_universe(uni);


     
    getch();
    gr.destroy();



    return 0;
}




