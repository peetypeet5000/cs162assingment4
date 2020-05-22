#ifndef GOLD
#define GOLD

#include <string>
#include "event.h"


class Gold : public Event {
    private:
        


        
    public:
        Gold();
        ~Gold() { };
        std::string percept();


};


#endif