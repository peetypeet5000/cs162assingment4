#include "rope.h"



//ROPE CONSTRUCTOR -> just sets type to R for printing
Rope::Rope() {
    type = 'R';
}



//ROPE PERCEPT returns nothing b/c youre supposed to remember where it is
std::string Rope::percept() {
    return "";
}



//ROPE ENCOUNTER -> prints a flavor text and returns 5 so game knows what to do
int Rope::encounter() {
    std::cout << MAGENTA << "\nYou feel the warm caress of the rope on your back...\n\n" << RESET;
    return 5;
}

