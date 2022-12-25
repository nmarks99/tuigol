#include "tuigol.h"
#include "gol.h"

#pragma once

class Graphics {
    
    private:
        WINDOW *win;

        void draw_border(WINDOW *win);

    public:
        
        int bdr_height;
        int bdr_width;

        void init();

        void clear_yx(int y, int x);

        void draw(int y, int x, int ch);

        void draw_universe(Universe uni);

        void destroy();
        
        // Class constructor
        Graphics();

};
