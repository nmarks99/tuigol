#include "tuigol.h"
#pragma once

class Universe {
    
    private:

        std::vector<std::vector<int>> init(int rows, int cols);
        
        int get_neighbors(int rownow, int colnow);

    public:

        std::vector<std::vector<int>> vec;

        void display();

        void next_gen();

        Universe(int rows, int cols, bool randomize=false);
    
};

