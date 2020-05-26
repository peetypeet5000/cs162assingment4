#ifndef BATS
#define BATS

#include <string>
#include <iostream>
#include "event.h"
#include "file_io.h"


class Bats : public Event {
    private:
        
    public:
        Bats();
        ~Bats() { };
        std::string percept();
        int encounter();
        int getShot();


};


#endif