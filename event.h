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
        std::string virtual percept(); //overloaded by ALL
        char getType();
        int virtual encounter(); //overloaded by ALL
        int virtual getShot(); //overloaded by WUMPUS


};


#endif