#include "room.h"



Room::Room(int event_type) {
    setRoomEvent(event_type);

}


Room::~Room() {
    //std::cout << " Room event destructor: " <<  &room_event << std::endl;
    delete room_event;
}


void Room::setRoomEvent(int event) {
    if (room_event != NULL) {
        //std::cout << " Deleting room event: " <<  &room_event << std::endl;
        delete room_event;
    }

    switch (event) {
        case 1:
            //std::cout << "Calling Wumpus Room Event\n";
            room_event = new Wumpus;
            break;
        case 2:
            //std::cout << "Calling Gold Room Event\n";
            room_event = new Gold;
            break;
        case 3:
            //std::cout << "Calling Bats Room Event\n";
            room_event = new Bats;
            break;
        case 4:
            //std::cout << "Calling Pit Room Event\n";
            room_event = new Pit;
            break;
        case 5:
            //std::cout << "Calling Rope Room Event\n";
            room_event = new Rope;
            break;
        default:
            //std::cout << "Calling Defualt Room Event\n";
            room_event = new Event;
            break;
    }
}



char Room::getEventChar(bool debug) {
    if(debug == false) {
        return ' ';
    } else {
        return room_event->getType();
    }
    return 'E';
}



std::string Room::getPercept() {
    return room_event->percept();
}



int Room::getEncounter() {
    return room_event->encounter();
    //return 0 if nothing, 1 if wum, 2 if gold, 3 if bats, 4 if pit, 5 if event
}


int Room::shoot() {
    int output = room_event->getShot();
    if(output == 1) {
        setRoomEvent(0);      //if wump killed, remove from board
    }

    return output;
}