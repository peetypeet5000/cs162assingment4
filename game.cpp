#include "game.h"

using namespace std;


Game::Game(int size) {
    this->cave_size = size;

    game_board = vector<vector<Room>>(cave_size, vector<Room>(cave_size));
    generateSeed();
    makeBoard();
}



void Game::generateSeed() {
    vector<int>::iterator it;
    it = seed.begin();
    //1 = wum, 2 = gold, 3 = bat, 4 = pit, 5 = rope
    //fills rest of seed w/ zeros
    seed.insert(it, ((cave_size * cave_size) - 7), 0);
    random_shuffle(seed.begin(), seed.end());

}


void Game::makeBoard() {
    for(int i = 0; i < cave_size; i++) {
        for(int j = 0; j < cave_size; j++) {
            //game_board[i].push_back(Room(seed[(cave_size * i) + j]));
            game_board[i][j].setRoomEvent(seed[(cave_size * i)+j]);
        }
    }
}


void Game::printGameBoard() {
    
}