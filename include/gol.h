#include <iostream>
#include <ncurses.h>
#include <cmath>
#include <vector>
#include <unistd.h>
#include <assert.h> 
#include <time.h>

#define GAME_SIZE 0.8 // percentage of terminal window to take up with game
#define ALIVE_CHAR 'o' // character representing living cells
#define DEAD_CHAR ' ' // character representing dead cells
#define REFRESH_RATE 20 // rate at which to refresh the game
#define USEC 1000000 

class Universe {
    
    private:

        std::vector<std::vector<int>> init(int rows, int cols);

    public:

        std::vector<std::vector<int>> vec;

        void display();

        int get_neighbors(int rownow, int colnow);

        void next_gen();

        // Class constructor. Calls init to construct the vector<vector<int>>
        Universe(int rows, int cols, bool randomize=false);
    
};

