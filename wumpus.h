#ifndef WUM
#define WUM

#include <string>
#include "event.h"


class Wumpus : public Event {
    private:
        


        
    public:
        Wumpus();
        ~Wumpus() { };
        std::string percept();


};


#endif