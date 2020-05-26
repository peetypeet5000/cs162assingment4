#include "pit.h"



//PIT CONSTRUCTOR, just sets type to P for printing
Pit::Pit() {
    type = 'P';
}



//PIT PERCEPT, just returns a string
std::string Pit::percept() {
    return "You feel a breeze.";
}



//PIT ENCOUNTER, prints fun image and text, returns a 4 so game knows what to do
int Pit::encounter() {
    readAsciiArt(5);
    std::cout << MAGENTA << "\n\nAs you step into the coming room, you place your shoe on a patch of damp leaves. Your foot flies\n";
    std::cout << "out from under you and you find youself catapulted into the unforgiving void below. As the light narrows to\n";
    std::cout << "just a pinhead, you question whether or not you will ever feel solid ground again.\n\n\n" << RESET;
    pressSpace();
    readAsciiArt(9);
    pressSpace();
    return 4;
}

