#include "bats.h"


//BAT CONSTRUCTOR, sets type to b
Bats::Bats() {
    type = 'B';
}

//BAT PERCEPT, just returns a string
std::string Bats::percept() {
    return "You hear wings flapping.";
}


/*************************************************
 * Notes/Funct: bat encounter, prints flavor text/image
 * and return 3 so game knows what to do
 * In: none
 * Out: 3
 * Conditions: need fileio things
 * ***********************************************/
int Bats::encounter() {
    readAsciiArt(6);
    std::cout << MAGENTA << "\n\nYou ran into a swarm of super bats!! They sink their claws into your shirt and throw you into the darkness.";
    std::cout << "\nYou slowly open your eyes to find yourself in an unfamiliar place\n\n\n" << RESET;
    pressSpace();
    return 3;
}


int Bats::getShot() {
    return 0;
}