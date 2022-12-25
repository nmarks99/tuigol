#include "gol.h"

// Class constructor. Calls init to construct the vector<vector<int>>
Universe::Universe(int rows, int cols, bool randomize /*=false*/){
    vec = init(rows, cols);

    if (randomize) {
        srand(time(NULL));
        int val;
        for(int i = 0; i < vec.size(); i++) {
            for(int j = 0; j < vec[i].size(); j++) {
                val = rand() % 2;
                vec[i][j] = val;
            }
        }
    }
}

std::vector<std::vector<int>> Universe::init(int rows, int cols) {
    std::vector<std::vector<int>> vec(
            rows,
            std::vector<int> (cols, 0)
    );
    return vec;
}
        

// std::vector<std::vector<int>> Universe::vec;

void Universe::display() {
    // prints the Matrix to the screen. Useful in debugging
    for(int i = 0; i < vec.size(); i++) {
        for(int j = 0; j < vec[i].size(); j++)
            std::cout << vec[i][j] <<" ";
        std::cout << std::endl;
    }
}

int Universe::get_neighbors(int rownow, int colnow) {

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

void Universe::next_gen() {
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


    

