#include "tuigol.h"
#pragma once

class Universe {
    
    private:

        std::vector<std::vector<int>> init(int rows, int cols);

    public:

        std::vector<std::vector<int>> vec;

        void display();

        int get_neighbors(int rownow, int colnow);

        void next_gen();

        Universe(int rows, int cols, bool randomize=false);
    
};

