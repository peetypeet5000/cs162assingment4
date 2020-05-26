#include "gold.h"

Gold::Gold() {
    type = 'G';
}


std::string Gold::percept() {
    return  "You see a glimmer nearby.";
}



int Gold::encounter() {
    cout << MAGENTA << "You found the gold! You picked it up and placed it in your backpack...\n" << RESET;
    return 2;
}


int Gold::getShot() {
    return 0;
}