#ifndef WUM
#define WUM

#include <string>
#include "event.h"
#include "file_io.h"


class Wumpus : public Event {
    private:
        


        
    public:
        Wumpus();
        ~Wumpus() { };
        std::string percept();
        int encounter();
        int getShot();


};


#endif