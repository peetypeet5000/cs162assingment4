#ifndef EVENT
#define EVENT


#include <string>
#include <iostream>





class Event {
    protected:
        char type;
    public:
        Event() ;
        virtual ~Event() { };   //No dynamic mem, but must be virtual b/c children
        std::string virtual percept() = 0; //overloaded by ALL
        char getType();
        int virtual encounter() = 0; //overloaded by ALL
        int virtual getShot(); //overloaded by WUMPUS


};


#endif