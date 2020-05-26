#ifndef ROOM
#define ROOM

#include <iostream>
#include "event.h"
#include "wumpus.h"
#include "rope.h"
#include "bats.h"
#include "pit.h"
#include "gold.h"


class Room {
    private:
        Event* room_event = NULL;


        
    public:
        Room() { };
        ~Room();
        Room(int);
        Room(const Room&);
        Room& operator=(const Room&);
        void setRoomEvent(int);
        char getEventChar(bool) const;
        std::string getPercept();
        int getEncounter();
        int shoot();


};


#endif