#ifndef EVENT
#define EVENT


#include <string>
#include <iostream>





class Event {
    protected:
        char type;
    public:
        Event() ;
        virtual ~Event() { };
        std::string virtual percept();
        char getType();
        int virtual encounter();
        int virtual getShot();


};


#endif