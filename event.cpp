#include "event.h"

Event::Event() {
    type = ' ';
}

std::string Event::percept() {
    return "";
}


char Event::getType() {
    return type;
}


int Event::encounter() {
    return 0;
}


int Event::getShot() {
    return 0; //indicates this it NOT the wumpus
}