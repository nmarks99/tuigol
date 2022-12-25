#include "gol.h"

// Class constructor. Calls init to construct the vector<vector<int>>
Universe::Universe(int rows, int cols, bool randomize /*=false*/){
    /*
    Universe class constructor. If randomize is true, every cell
    in the 2D vector representing the universe will be randomly
    assigned as either 0 (living) or 1 (dead).
    */
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
    /*
    Initializes the vector<vector<int>> representing the 
    Conway's Game of Life universe/game board as a 2D vector
    of zeros with the specified number of rows and columns.
    */
    std::vector<std::vector<int>> vec(
            rows,
            std::vector<int> (cols, 0)
    );
    return vec;
}
        

// std::vector<std::vector<int>> Universe::vec;

void Universe::display() {
    /*
    Prints the vector<vector<int>> representing the game
    board to stdout. This is just useful for debugging 
    and won't show if ncurses graphics have already been 
    initialized.
    */
    for(int i = 0; i < vec.size(); i++) {
        for(int j = 0; j < vec[i].size(); j++)
            std::cout << vec[i][j] <<" ";
        std::cout << std::endl;
    }
}

int Universe::get_neighbors(int rownow, int colnow) {
    /*
    Determines the number of living neighbors to a cell 
    at the given the row and column.
    */
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
    /*
    Determines the universe (game board) at the next
    generation according to the rules of the game
    */
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


    

