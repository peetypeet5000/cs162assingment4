#include "event.h"


//EVENT CONSTRUCTOR, sets type to blank so they dont
//make a mark on the printed game board
Event::Event() {
    type = ' ';
}



//GETTYPe -- getter for type var, used to print debug mode symbols
char Event::getType() {
    return type;
}



//getSHOT -- return zero so game knows wumpus is not here
//inherited by all but wummpus as only wumpus can get shot
int Event::getShot() {
    return 0; //indicates this it NOT the wumpus
}