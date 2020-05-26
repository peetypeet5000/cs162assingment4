#include "bats.h"

Bats::Bats() {
    type = 'B';
}


std::string Bats::percept() {
    return "You hear wings flapping.";
}


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