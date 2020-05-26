#include "pit.h"

Pit::Pit() {
    type = 'P';
}


std::string Pit::percept() {
    return "You feel a breeze.";
}


int Pit::encounter() {
    readAsciiArt(5);
    std::cout << MAGENTA << "\n\nAs you step into the coming room, you place your shoe on a patch of damp leaves. Your foot flies\n";
    std::cout << "out from under you and you find youself catapulted into the unforgiving void below. As the light narrows to\n";
    std::cout << "just a pinhead, you question whether or not you will ever feel solid ground again.\n\n\n" << RESET;
    pressSpace();
    return 4;
}



int Pit::getShot() {
    return 0;
}