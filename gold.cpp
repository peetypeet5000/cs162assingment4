#include "gold.h"


//GOLD CONSTRUCTOR, sets the type to g
Gold::Gold() {
    type = 'G';
}



//GOLD PERCEPT, just returns a string
std::string Gold::percept() {
    return  "You see a glimmer nearby.";
}


//GOLD ENCOUNTER, returns a 2 so game knows what to do, prints some fun text
int Gold::encounter() {
    readAsciiArt(10);
    cout << MAGENTA << "\n\nYou found the gold! You picked it up and placed it in your backpack...\n\n\n" << RESET;
    pressSpace();
    return 2;
}
