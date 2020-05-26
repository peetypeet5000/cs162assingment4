#include "rope.h"

Rope::Rope() {
    type = 'R';
}


std::string Rope::percept() {
    return "THE ROPE";
}


int Rope::encounter() {
    std::cout << MAGENTA << "You feel the warm caress of the rope on your back..." << RESET;
    return 5;
}


int Rope::getShot() {
    return 0;
}