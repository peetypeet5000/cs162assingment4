#include "wumpus.h"



//WUMPUS CONSTRUCTOR -> just sets type to W for printing
Wumpus::Wumpus() {
    type = 'W';
}



//WUMPUS PERCEPT -> just returns a string to be printed
std::string Wumpus::percept() {
    return "You smell a terrible stench.";
}



//WUMPUS ENCOUNTER -> overloads event encounter, prints art and flavor text, returns 1 so game knows to kill player
int Wumpus::encounter() {
    readAsciiArt(8);
    cout << RED << "\n\nYou encounter the wumpus...\n\n";
    pressSpace();
    readAsciiArt(9);
    cout << RED << "\n\nThe Wumpus smells you draw near, slowly tilts his head towards yours, and bears his fangs. As you lock eyes you \n";
    cout << "begin to question what steps lead you here, to this moment, in this place...\n\n" << RESET;
    pressSpace();
    return 1;
}


//WUMPUS GETSHOT -> only child to overload getShot, prints text and returns a 1 so room knows to kill wumpus
int Wumpus::getShot() {
    cout << YELLOW << "\n\nAfter shooting you arrow into the darkness you hear a deep, whining growl followed by a booming thud. With one direct hit\n";
    cout << "the wumpus has fallen. A feeling of determination washes over you and you vow to finish your journey...\n\n";
    return 1;
}