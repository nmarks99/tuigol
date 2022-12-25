#include "tuigol.h"
#include "gol.h"

#pragma once

class Graphics {
    
    private:
        WINDOW *win;

        void draw_border(WINDOW *win);

        void draw(int y, int x, int ch);
        
        void clear_yx(int y, int x);
        
        void init();

    public:
        
        int bdr_height;
        int bdr_width;

        void draw_universe(Universe uni);

        void destroy();
        
        Graphics();

};
