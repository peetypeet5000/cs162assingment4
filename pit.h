#ifndef PIT
#define PIT

#include <string>
#include "event.h"
#include "file_io.h"


class Pit : public Event {
    private:
        


        
    public:
        Pit();
        ~Pit() { };
        std::string percept();
        int encounter();
        int getShot();


};


#endif