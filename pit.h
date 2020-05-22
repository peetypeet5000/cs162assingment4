#ifndef PIT
#define PIT

#include <string>
#include "event.h"


class Pit : public Event {
    private:
        


        
    public:
        Pit();
        ~Pit() { };
        std::string percept();


};


#endif