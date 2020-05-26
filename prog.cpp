/******************************************************
** Program: Wupus
** Author: Peter LaMontagne
** Date: 5/25/20
** Description: Plays the game "Hunt the Wumpus"  
** Input: Requires bft.txt to read from
** Output: none
******************************************************/


#include <iostream>
#include <string>
#include "game.h"
#include "util.h"
#include "file_io.h"


vector<int> playWithSeed(vector<int> seed, char** argv) {
    Game game(argv, seed);
    seed = game.getSeed();
    return seed;
}


vector<int> playNoSeed(vector<int> seed, char** argv) {
    Game game(argv);
    seed = game.getSeed();
    return seed;
}



int main(int argc, char** argv) {
    bool good = checkArgs(argc, argv);
    bool done = false;
    int input;
    vector<int> seed;

    if(good == true) {
        //prints first-time image
        readAsciiArt(7);
        pressSpace();

        //play game at least once
        seed = playNoSeed(seed, argv);


        do {
            do{

                cout << "Do you want to play again?\n[0] - No\n[1] - Yes, different bord\n[2] - Yes, same bord\n\n";
    
                input = getInt();
            } while(checkRange(input, 2, 0) == false);

            if(input == 1) {
                seed = playNoSeed(seed, argv);
            } else if(input == 2) {
                seed = playWithSeed(seed, argv);
            } else {
                done = true;
            }
        } while (done == false);

    }
    return 0;
}
