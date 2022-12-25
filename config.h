/*
                                                                              

████████╗██╗   ██╗██╗ ██████╗  ██████╗ ██╗     
╚══██╔══╝██║   ██║██║██╔════╝ ██╔═══██╗██║     
   ██║   ██║   ██║██║██║  ███╗██║   ██║██║     
   ██║   ██║   ██║██║██║   ██║██║   ██║██║     
   ██║   ╚██████╔╝██║╚██████╔╝╚██████╔╝███████╗
   ╚═╝    ╚═════╝ ╚═╝ ╚═════╝  ╚═════╝ ╚══════╝

Conway's Game of Life in your Terminal!

This configuration file defines various parmeters for the program 
which you can change as desired.

*/

#define ITERATIONS 100      // Number of iterations to run before stopping
#define GAME_SIZE 0.8       // percentage of terminal window height to use 
#define ALIVE_CHAR 'o'      // character representing living cells
#define DEAD_CHAR ' '       // character representing dead cells
#define REFRESH_RATE 30     // Frequency (Hz) at which to refresh the game
#define DRAW_BORDER true    // Draws a border around the game board (universe)
