#include "game.h"

using namespace std;



/*************************************************
 * Notes/Funct: constructor w/ no seed
 * In: argc from command line args
 * Out: none, sets up board and starts game loop
 * Conditions: argv must be correct/valid
 * ***********************************************/
Game::Game(char** argv) {
    srand(time(NULL));

    this->cave_size = stoi(argv[1]);

    std::string debug(argv[2]);

    if(debug == "true") {
        this->debug = true;
    } else {
        this->debug = false;
    }

    game_board = vector<vector<Room>>(cave_size, vector<Room>(cave_size));
    generateSeed();
    makeBoard();
    gameLoop();
}



/*************************************************
 * Notes/Funct: constructor with provided seed
 * In: argc from command line args, seed
 * Out: none, sets up board and starts game loop, uses existing seed
 * Conditions: argv must be correct/valid, seed must be correct size
 * ***********************************************/
Game::Game(char** argv, vector<int> seed) {
    srand(time(NULL));

    this->cave_size = stoi(argv[1]);

    game_board = vector<vector<Room>>(cave_size, vector<Room>(cave_size));
    this->seed = seed;
    makeBoard();
    gameLoop();
}



/*************************************************
 * Notes/Funct: GameLoop, main game function
 * In: member vars seed and game_board must be set
 * Out: none
 * Conditions: stops when something sets done to true
 * ***********************************************/
void Game::gameLoop() {
    do {
        printGameBoard();
        getInput();
        doEncounter();
        getPercepts();
    } while (done == false);
}



/*************************************************
 * Notes/Funct: generateSeed
 * adds zeros and shuffles seed so it is correct length
 * In: seed values set in header
 * Out: member var seed is now init
 * Conditions: cave_size must be set (greater then 4)
 * ***********************************************/
void Game::generateSeed() {
    vector<int>::iterator it;
    it = seed.begin();
    //1 = wum, 2 = gold, 3 = bat, 4 = pit, 5 = rope
    //fills rest of seed w/ zeros
    seed.insert(it, ((cave_size * cave_size) - 7), 0);
    random_shuffle(seed.begin(), seed.end());

}



/*************************************************
 * Notes/Funct:
 * In:
 * Out:
 * Conditions:
 * ***********************************************/
void Game::makeBoard() {
    for(int i = 0; i < cave_size; i++) {
        for(int j = 0; j < cave_size; j++) {
            game_board[i][j].setRoomEvent(seed[(cave_size * i)+j]);
            if(seed[(cave_size * i)+j] == 5) {
                player_coords[0] = j;
                player_coords[1] = i;
            }
        }
    }
}



/*************************************************
 * Notes/Funct:
 * In:
 * Out:
 * Conditions:
 * ***********************************************/
void Game::printGameBoard() {
    for(int i = 0; i < cave_size; i++) {
        cout << RED << "+-----";
    }
    cout << "+";
    cout << endl;
    for(int i = 0; i < cave_size; i++) { //rows
        for(int j = 0; j < cave_size; j++) {    //columns
            cout << "|  " << RESET << game_board[i][j].getEventChar(debug) << RED << "  ";
        }
        cout << "|" << endl;
        for(int j = 0; j < cave_size; j++) {    //second row
            cout << "|  " << YELLOW << checkPlayer(j, i) << RED << "  ";
        }
        cout << "|" << endl;
        for(int i = 0; i < cave_size; i++) {
            cout << "+-----";
        }
        cout << "+" << endl;
    }

    cout << "\n\n" << RESET;
}




/*************************************************
 * Notes/Funct:
 * In:
 * Out:
 * Conditions:
 * ***********************************************/
char Game::checkPlayer(int i, int j) {
    if(player_coords[0] == i && player_coords[1] == j) {
        return '*';
    } else {
        return ' ';
    }
}



/*************************************************
 * Notes/Funct:
 * In:
 * Out:
 * Conditions:
 * ***********************************************/
void Game::getInput() {
    string input;
    int choice1, choice2 = 0;
    cout << "\nEnter W A S D to move, or SPACE to shoot\n";
    do {
        input = "";
        getline(cin, input);
        //cout << "INPUT:" << input << endl;
    } while (translateInput(input) == 0);
    choice1 = translateInput(input);
    if(choice1 == 5) {
        cout << "Please enter W A S D to indicate the direction to shoot\n";
        do {
            input = "";
            getline(cin, input);
        } while (translateInput(input) > 4 && translateInput(input) < 1); 
        choice2 = translateInput(input); 
    }

    doMovement(choice1, choice2);

}



/*************************************************
 * Notes/Funct:
 * In:
 * Out:
 * Conditions:
 * ***********************************************/
int Game::translateInput(string input) {
    if(input.length() > 1) {
        cout << "\nPlease enter only one character! Try again: ";
        return 0; //invalid
    }

    if(input[0] == 'w') {
        return 1;   //up
    } else if(input[0] == 'a')
        return 2; //left 
    else if(input[0] == 's') 
        return 3; //down
    else if(input[0] == 'd')
        return 4; //right
    else if(input[0] == ' ')
        return 5; //space
    else {
        cout << "\nInvalid input! Try again: ";
        return 0; //invalid
    }
}



/*************************************************
 * Notes/Funct:
 * In:
 * Out:
 * Conditions:
 * ***********************************************/
void Game::doMovement(int choice1, int choice2) {
    if(choice1 == 5) {  //arrow
        shootArrow(choice2);
        arrows--;
    } else {
        if (choice1 == 1 && (player_coords[1] - 1) >= 0) {
            player_coords[1] = player_coords[1] - 1;
        } else  if (choice1 == 2 && (player_coords[0] - 1) >= 0) {
            player_coords[0] = player_coords[0] - 1;
        } else  if (choice1 == 3 && (player_coords[1] + 1) < cave_size) {
            player_coords[1] = player_coords[1] + 1;
        } else  if (choice1 == 4 && (player_coords[0] + 1) < cave_size) {
            player_coords[0] = player_coords[0] + 1;
        } else {
            getInput(); //invalid choice, call again
        }
    }
}



/*************************************************
 * Notes/Funct:
 * In:
 * Out:
 * Conditions:
 * ***********************************************/
void Game::doEncounter() {
    int result = game_board[player_coords[1]][player_coords[0]].getEncounter();
    //1 = wumpus, 2 = gold, 3 = bats, 4 = pit, 5 = rope
    if(result == 2) {
        gold = true; //puts in backpack
    } else if(result == 1 || result == 4) {
        done = true;  //player dies
    } else if(result == 3) {
        randomizePlayerCoords();
    } else if(result == 5 && gold == true) {
        cout << YELLOW << "With the gold in your backpack and the rope in your hard, you climb towards the sun, victorious\n\n" << RESET;
        pressSpace();
    }
}



/*************************************************
 * Notes/Funct:
 * In:
 * Out:
 * Conditions:
 * ***********************************************/
void Game::getPercepts() {
    if(player_coords[0] - 1 >= 0) {     //makes sure valid range
        cout << CYAN << game_board[player_coords[1]][(player_coords[0])-1].getPercept() << "\n";
    }
    if(player_coords[0] + 1 < cave_size) {
        cout << game_board[player_coords[1]][(player_coords[0])+1].getPercept() << "\n";
    }
    if(player_coords[1] + 1 < cave_size) {
        cout << game_board[(player_coords[1] + 1)][player_coords[0]].getPercept() << "\n";
    }
    if(player_coords[1] - 1 >= 0) {
        cout << game_board[(player_coords[1] - 1)][player_coords[0]].getPercept() << RESET << "\n";
    }
}




/*************************************************
 * Notes/Funct:
 * In:
 * Out:
 * Conditions:
 * ***********************************************/
void Game::randomizePlayerCoords() {
    player_coords[0] = rand() % cave_size;
    player_coords[1] = rand() % cave_size;

    //get all the flavor for the new location
    doEncounter();
    getPercepts();

}



/*************************************************
 * Notes/Funct:
 * In:
 * Out:
 * Conditions:
 * ***********************************************/
void Game::shootArrow(int direction) {
    if(arrows == 0) {
        cout << RED << "\n\nYou reach to your backpack for another arrow but your hand comes back empty. You must finish this journey defenseless\n\n" << RESET;
    } else if(direction == 1) {
        for(int i = player_coords[1]; i >= 0; i--) {
            cout << "\ni: " << i << endl;
            game_board[i][player_coords[0]].shoot(); 
        }
    } else if(direction == 2) {
        for(int i = player_coords[0]; i >= 0; i--) {
            cout << "\ni: " << i << endl;
            game_board[player_coords[1]][i].shoot();
        }
    } else if(direction == 3) {
        for(int i = player_coords[1]; i < cave_size; i++) {
            cout << "\ni: " << i << endl;
            game_board[i][player_coords[0]].shoot();
        }
    } else {
        for(int i = player_coords[0]; i < cave_size; i++) {
            cout << "\ni: " << i << endl;
            game_board[player_coords[1]][i].shoot();
        }
    }
}



/*************************************************
 * Notes/Funct:
 * In:
 * Out:
 * Conditions:
 * ***********************************************/
vector<int> Game::getSeed() {
    return seed;
}