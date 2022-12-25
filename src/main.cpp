#include "gol.h"
#include "graphics.h"


int main(int argc, char **argv) {
   
    // initialize graphics 
    Graphics gr; 

    int rows = gr.bdr_height;
    Universe uni(rows,rows,true);

    gr.draw_universe(uni);
    getch();

    int iterations = 200;
    int k = 0;
    while (k < iterations) {
        
        gr.draw_universe(uni);
        usleep(1000000/REFRESH_RATE);
        uni.next_gen();

        k++;

    }

    getch();
    gr.destroy();



    return 0;
}




