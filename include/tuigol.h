#include <iostream>
#include <ncurses.h>
#include <cmath>
#include <vector>
#include <unistd.h>
#include <assert.h>
#include <time.h>

#pragma once

#define GAME_SIZE 0.8 // percentage of terminal window to take up with game
#define ALIVE_CHAR 'o' // character representing living cells
#define DEAD_CHAR ' ' // character representing dead cells
#define REFRESH_RATE 20 // rate at which to refresh the game
#define USEC 1000000 
