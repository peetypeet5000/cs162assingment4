#ifndef GAME
#define GAME

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "file_io.h"
#include "util.h"
#include "event.h"
#include "wumpus.h"
#include "gold.h"
#include "room.h"

class Game {
    private:
        int cave_size = 0;  //NOT the squared value
        vector<int> seed = {1, 2, 3, 4, 3, 4, 5};
        vector<vector<Room>> game_board;



        
    public:
        Game(int);
        void generateSeed();
        void makeBoard();
        void printGameBoard();


};


#endif