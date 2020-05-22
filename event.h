#ifndef EVENT
#define EVENT

#include <string>


class Event {
    protected:

    public:
        Event() ;
        virtual ~Event() { };
        std::string virtual percept();


};


#endif