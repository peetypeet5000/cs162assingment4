#ifndef GOLD
#define GOLD

#include <string>
#include "event.h"
#include "file_io.h"


class Gold : public Event {
    private:
        


        
    public:
        Gold();
        ~Gold() { };
        std::string percept();
        int encounter();
        int getShot();

};


#endif