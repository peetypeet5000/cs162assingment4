#ifndef BATS
#define BATS

#include <string>
#include "event.h"


class Bats : public Event {
    private:
        
    public:
        Bats();
        ~Bats() { };
        std::string percept();


};


#endif