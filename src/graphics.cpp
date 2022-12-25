#include "graphics.h"


void Graphics::draw_border(WINDOW *win) {
    box(win, 0, 0);
    wrefresh(win);
}
        

void Graphics::init() {

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

void Graphics::clear_yx(int y, int x) {
    mvwprintw(win, y, x, " ");
    wrefresh(win);
}


void Graphics::draw(int y, int x, int ch) {
    mvwprintw(win, y, x, "%c", ch);
    wrefresh(win);
}

void Graphics::draw_universe(Universe uni) {
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

void Graphics::destroy() {
    endwin(); 
    std::cout << "Program finished cleanly" << std::endl;
}

// Class constructor
Graphics::Graphics() {
    init();
}

