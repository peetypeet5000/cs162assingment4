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
        int arrows = 3;
        vector<int> seed = {1, 2, 3, 4, 3, 4, 5};
        vector<vector<Room>> game_board;
        bool debug = true, done = false, gold = false;
        vector<int> player_coords = {0, 0}; //stored as (x,y), but game board reads as (y, x)



        
    public:
        Game(char**);
        Game(char**, vector<int>);
        void generateSeed();
        void gameLoop();
        void makeBoard();
        void getInput();
        int translateInput(string);
        char checkPlayer(int, int);
        void printGameBoard();
        void doMovement(int, int);
        void doEncounter();
        void getPercepts();
        void randomizePlayerCoords();
        void shootArrow(int);
        vector<int> getSeed();


};


#endif