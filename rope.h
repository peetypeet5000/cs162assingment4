#ifndef ROEP
#define ROEP

#include <string>
#include "event.h"
#include "file_io.h"


class Rope : public Event {
    private:
        


        
    public:
        Rope();
        ~Rope() { };
        std::string percept();
        int encounter();


};


#endif