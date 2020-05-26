#include "wumpus.h"

Wumpus::Wumpus() {
    type = 'W';
}


std::string Wumpus::percept() {
    return "You smell a terrible stench.";
}


int Wumpus::encounter() {
    cout << "You encounter the wumpus...";
    readAsciiArt(3);
    pressSpace();
    return 1;
}



int Wumpus::getShot() {
    cout << YELLOW << "After shooting you arrow into the darkness to hear a low growl followed by a booming thud. With one direct hit\n";
    cout << "the wumpus has fallen. A feeling of determination washes over you and you vow to finish your journey...\n\n";
    return 1;
}