#include "room.h"



/*************************************************
 * Notes/Funct: Room constructor, sets room event according to int passed
 * In: int event_type (1-5)
 * Out: calls setRoomEvent
 * Conditions: if not 1-5, default EVENT used
 * ***********************************************/
Room::Room(int event_type) {
    setRoomEvent(event_type);

}



/*************************************************
 * Notes/Funct: room destructor
 * In: none
 * Out: none
 * Conditions: deletes the room_event dynamic object
 * ***********************************************/
Room::~Room() {
    //std::cout << " Room event destructor: " <<  &room_event << std::endl;
    delete room_event;
    room_event = NULL;
}



/*************************************************
 * Notes/Funct: room  copy constuctor
 * In: Old room object
 * Out: Inits new room object
 * Conditions: 
 * ***********************************************/
Room::Room(const Room& old) {
    int type = 0;
    //return 0 if nothing, 1 if wum, 2 if gold, 3 if bats, 4 if pit, 5 if event
    if(old.getEventChar(true) =='W') {
        type = 1;
    } else if(old.getEventChar(true) == 'G') {
        type = 2;
    } else if(old.getEventChar(true) == 'B') {
        type = 3;
    } else if(old.getEventChar(true) == 'P') {
        type = 4;
    } else {
        type = 5;
    }
    setRoomEvent(type); //this is the only data member, now the same as copied
}



/*************************************************
 * Notes/Funct: room  assignment operator
 * In: Old room object
 * Out: Returns referance to new room obj
 * Conditions: If room_event already exists, it will be deleted
 * ***********************************************/
Room& Room::operator=(const Room& old) {
    int type = 0;
    if(this != &old) {
        //deletes existinig
        if (room_event != NULL) {
            delete room_event;
            room_event = NULL;
        }

        //copies old room event
        if(old.getEventChar(true) =='W') {
            type = 1;
        } else if(old.getEventChar(true) == 'G') {
            type = 2;
        } else if(old.getEventChar(true) == 'B') {
            type = 3;
        } else if(old.getEventChar(true) == 'P') {
            type = 4;
        } else {
            type = 5;
        }
        setRoomEvent(type); //this is the only data member, now the same as copied
    }

    return *this;
}




/*************************************************
 * Notes/Funct: SetRoomEvent fills room_event with 1 of six objects
 * for use polymorphically
 * In: int (1-5) or will use EVENT
 * Out: room_event filled
 * Conditions: will delete existing event if called again
 * ***********************************************/
void Room::setRoomEvent(int event) {
    if (room_event != NULL) {
        delete room_event;
        room_event = NULL;
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
            //makes nothing, as event is abstract
            break;
    }
}



/*************************************************
 * Notes/Funct: returns the event letter (P for pit, etc)
 * unless debug mode is false
 * In: debug mode bool
 * Out: character of P B W R B or ' '
 * Conditions: room_event must be filled already
 * ***********************************************/
char Room::getEventChar(bool debug) const {
    if(room_event != NULL) {
        if(debug == false) {
            return ' ';
        } else {
            return room_event->getType();
        }
    }
    return ' ';
}



//ROOM GetPercept -> Just calls the percept function on the room_event for use
//polymorphically, returns it
std::string Room::getPercept() {
    if(room_event != NULL) {
        return room_event->percept();
    } else {
        return "";
    }
}



//ROOM GetEncounter -> Same as above but for encounter
int Room::getEncounter() {
    int output = 0;
    if(room_event != NULL) {
        output = room_event->encounter();
        //return 0 if nothing, 1 if wum, 2 if gold, 3 if bats, 4 if pit, 5 if event
    } 

    if(output == 2) {
        setRoomEvent(0);    //deletes gold after acquired
    }

    return output;
}



/*************************************************
 * Notes/Funct: calls getShot for room_event, if event
 * is a wumpus, set it to be an EVENT (wumpus dies)
 * In: none
 * Out: returns int output, may change room_event
 * Conditions: none
 * ***********************************************/
int Room::shoot() {
    int output = 0;
    if(room_event != NULL) {
        output = room_event->getShot();
        if(output == 1) {
            setRoomEvent(0);      //if wump killed, remove from board
        }
    }

    return output;
}