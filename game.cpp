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

    //sets cave size
    this->cave_size = stoi(argv[1]);

    std::string debug(argv[2]);

    if(debug == "true") {   //sets debug momde
        this->debug = true;
    } else {
        this->debug = false;
    }

    //fills vector with roomm objects
    game_board = vector<vector<Room>>(cave_size, vector<Room>(cave_size));
    //all init things
    generateSeed();
    makeBoard();
    gameLoop(); //starts actual game
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


    std::string debug(argv[2]);

    if(debug == "true") {
        this->debug = true;
    } else {
        this->debug = false;
    }

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
        getPercepts();
        printGameBoard();
        getInput();
        doEncounter();
        //funcitons in game call done whenever
        //they want the game to stop
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
 * Notes/Funct: uses seed to set all the rooms to have
 * an event in them
 * In: seed, game_board member var
 * Out: game_board is now working
 * Conditions: need seed of correct length, need game
 * baord to be declared/init before
 * ***********************************************/
void Game::makeBoard() {
    for(int i = 0; i < cave_size; i++) {
        for(int j = 0; j < cave_size; j++) {
            game_board[i][j].setRoomEvent(seed[(cave_size * i)+j]);
            if(seed[(cave_size * i)+j] == 5) {
                //sets player starting coords to where rope is
                player_coords[0] = j;
                player_coords[1] = i;
            }
        }
    }
}



/*************************************************
 * Notes/Funct: prints the grid, using getEventChar to print
 * the debug mode symbols
 * In: game_board member funct, debug mode
 * Out: prints to termial
 * Conditions: need init game board
 * NOTE: When printing, it does rows -> col, so coords are actually
 * y, x which is really confusing
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
            //DOES CHECK PLAYER (j, i) B/C X AND Y ARE SWAPPED
            cout << "|  " << YELLOW << checkPlayer(j, i) << RED << "  ";
        }
        cout << "|" << endl;
        for(int i = 0; i < cave_size; i++) {
            cout << "+-----";
        }
        cout << "+" << endl;
    }

    cout << "\n\n" << RESET;
    if(gold == true) {  //lets user know they picked up the gold
        cout << YELLOW << "You have the gold!\n\n" << RESET;
    }
}




/*************************************************
 * Notes/Funct: check if coords passed match player coords,
 * In: player coords member var, passed coords i, j
 * Out: * if match, ' ' if not
 * Conditions: player coords init
 * ***********************************************/
char Game::checkPlayer(int i, int j) {
    if(player_coords[0] == i && player_coords[1] == j) {
        return '*'; //indicates player coords match
    } else {
        return ' ';
    }
}



/*************************************************
 * Notes/Funct: gets the direction & arrow direction
 * from the player, calls movment funct inside
 * In: none
 * Out: does movment function, modifies member var
 * Conditions: NOT PORTABLE -- USES STTY RAW/COOKED
 * ***********************************************/
void Game::getInput() {
    string input;
    int choice1, choice2 = 0;
    cout << "\nEnter W A S D to move, or SPACE to shoot\n";
    do {
        input = "";
        //sets terminal to RAW mode, allows immediate input
        system("stty raw"); 
        input = getchar();
        //sets it back to normal so stuff works
        system("stty cooked");
    } while (translateInput(input) == 0);
    choice1 = translateInput(input);
    if(choice1 == 5) {
        cout << "Please enter W A S D to indicate the direction to shoot\n";
        do {
            input = "";
            system("stty raw"); 
            input = getchar();
            system("stty cooked");
        } while (translateInput(input) > 4 && translateInput(input) < 1); 
        choice2 = translateInput(input); 
    }

    doMovement(choice1, choice2);   //actually moves the player
    cout << "\n\n\n\n";

}



/*************************************************
 * Notes/Funct: changes W A S D into 1 2 3 4 and
 * SPACE to 5 for easier inpuit
 * In: char WASD SPACE
 * Out: int 1-5
 * Conditions: returns 0 if none matching
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
 * Notes/Funct: changes the player coords depending on
 * their direction, shoots arrow if selected (and depletes arrows)
 * In: choice 1 (1-5), choice 2 (1-4)
 * Out: changes player_coords
 * Conditions: checks if in bounds, calls again if not
 * NOTE: coords are stored as x, y, but if you wanted to use this
 * in the game_board, use as y, x
 * ***********************************************/
void Game::doMovement(int choice1, int choice2) {
    if(choice1 == 5) {  //arrow
        shootArrow(choice2);
        arrows--;
    } else {
        if (choice1 == 1 && (player_coords[1] - 1) >= 0) {
            player_coords[1] = player_coords[1] - 1;    //up
        } else  if (choice1 == 2 && (player_coords[0] - 1) >= 0) {
            player_coords[0] = player_coords[0] - 1;    //left
        } else  if (choice1 == 3 && (player_coords[1] + 1) < cave_size) {
            player_coords[1] = player_coords[1] + 1;    //down
        } else  if (choice1 == 4 && (player_coords[0] + 1) < cave_size) {
            player_coords[0] = player_coords[0] + 1;    //right
        } else {
            getInput(); //invalid choice, call again
        }
    }
}



/*************************************************
 * Notes/Funct: Sets variables/calls poly function for
 * each type of encounter depending on where
 * player is located
 * In: player coords member var, game board
 * Out: cout, sets member vars
 * Conditions: game board must be filled with events
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
        readAsciiArt(11);
        cout << YELLOW << "With the gold in your backpack and the rope in your hard, you climb towards the sun, victorious\n\n" << RESET;
        pressSpace();
        done = true;    //player won
    }
}



/*************************************************
 * Notes/Funct: Calls each rooms percept function for
 * 4 closest rooms
 * In: game_board and player_coords member vars
 * Out: couts percepts in cyan
 * Conditions: cords must be in range, does not check
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
 * Notes/Funct: Moves player to random room and calls
 * percepts/events for new location
 * In: player_coords member var
 * Out: modified player coords
 * Conditions: none
 * ***********************************************/
void Game::randomizePlayerCoords() {
    player_coords[0] = rand() % cave_size;  //rand from 0 - size
    player_coords[1] = rand() % cave_size;

    //get all the flavor for the new location
    doEncounter();
    getPercepts();

}



/*************************************************
 * Notes/Funct: takes direction and checks if room in that
 * direciton is WUMPUS using room.shoot()
 * In: direction (1-4), coords and board member var 
 * Out: modifies wumpus room if hit
 * Conditions: coords and board must be init
 * ***********************************************/
void Game::shootArrow(int direction) {
    int counter = 0, dead = 0;
    if(arrows <= 0) {
        //if no more arrows, does not allow shooting
        cout << RED << "\n\nYou reach to your backpack for another arrow but your hand comes back empty. You must finish this journey defenseless" << RESET;
    } else if(direction == 1) { //up
        for(int i = player_coords[1]; i >= 0; i--) {
            //calls room.shoot for all in line straight up
            //note the use of the x cord bc of the swap thing
            dead = dead + game_board[i][player_coords[0]].shoot();
            if(counter++ == 3) {    //stops arrow after 3 rooms
                break;
            }
        }
    } else if(direction == 2) { //left
        for(int i = player_coords[0]; i >= 0; i--) {
            dead = dead + game_board[player_coords[1]][i].shoot();
            if(counter++ == 3) {    //stops arrow after 3 rooms
                break;
            }
        }
    } else if(direction == 3) { //down
        for(int i = player_coords[1]; i < cave_size; i++) {
            dead = dead + game_board[i][player_coords[0]].shoot();
            if(counter++ == 3) {    //stops arrow after 3 rooms
                break;
            }
        }
    } else {    //right 
        for(int i = player_coords[0]; i < cave_size; i++) {
            dead = dead + game_board[player_coords[1]][i].shoot();
            if(counter++ == 3) {    //stops arrow after 3 rooms
                break;
            }
        }
    }
    if(dead == 0 && arrows > 0) {
        moveWumpus();
    }
}



/*************************************************
 * Notes/Funct: Has a 75% chance of moving the wumpus room
 * In: none
 * Out: maybe modified game_board
 * Conditions: none
 * ***********************************************/
void Game::moveWumpus() {
    int rand_num = rand() % 4; //0-4
    if(rand_num < 2) {
        //search for current wump
        for(int i = 0; i < cave_size; i++) { 
            for(int j = 0; j < cave_size; j++) {   
                if(game_board[i][j].getEventChar(debug) == 'W') {
                    game_board[i][j].setRoomEvent(0); //removes wump
                }
            }
        }
        
        //makes a new wump
        int i = rand() % cave_size;  //rand from 0 - size
        int j = rand() % cave_size;
        game_board[i][j].setRoomEvent(1);
    }

}
/*************************************************
 * Notes/Funct: returns the seed vector
 * In: none
 * Out: seed member var
 * Conditions: none
 * ***********************************************/
vector<int> Game::getSeed() {
    return seed;
}