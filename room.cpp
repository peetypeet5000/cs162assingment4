#include "room.h"



Room::Room(int event_type) {
    setRoomEvent(event_type);

}


void Room::setRoomEvent(int event) {
    std::cout << " Deleting room event: " <<  &room_event << std::endl;
    if (room_event != NULL) {
        delete room_event;
    }

    switch (event) {
        case 1:
            std::cout << "Calling Wumpus Room Event\n";
            room_event = new Wumpus;
            break;
        case 2:
            std::cout << "Calling Gold Room Event\n";
            room_event = new Gold;
            break;
        case 3:
            std::cout << "Calling Bats Room Event\n";
            room_event = new Bats;
            break;
        case 4:
            std::cout << "Calling Pit Room Event\n";
            room_event = new Pit;
            break;
        case 5:
            std::cout << "Calling Rope Room Event\n";
            room_event = new Rope;
            break;
        default:
            std::cout << "Calling Defualt Room Event\n";
            room_event = new Event;
            break;
    }
}