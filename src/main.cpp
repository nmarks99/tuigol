#include "gol.h"
#include "graphics.h"

#define USEC 1000000  // microseconds in a second
#define ITERATIONS 100


int main(int argc, char **argv) {
   
    // initialize graphics 
    Graphics gr; 
    
    // Define the game window and draw it
    int rows = gr.bdr_height;
    Universe uni(rows,rows,true); 
    gr.draw_universe(uni);
    getch(); // Wait for user to press a key to start the game
    

    // Main loop:
    // Draw universe, get next generation according to rules, repeat
    int k = 0;
    while (k < ITERATIONS) {
        gr.draw_universe(uni);
        usleep(1000000/REFRESH_RATE);
        uni.next_gen();
        k++;
    }
    
    // Wait for user to press a key, then kill the program
    getch();
    gr.destroy();

    return 0;
}




