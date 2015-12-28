#ifndef WARZYWA_H_INCLUDED
#define WARZYWA_H_INCLUDED
#include "rosliny.h"

class Warzywa : public Rosliny
{
    private:
        int witaminy;
        int klasa;
    public:
        Warzywa(std::string nazwa, int wzrost, int witaminy);
        ~Warzywa() ;
        void podlej() ;
        void nawoz() ;

        int podaj_ceche();
         int podaj_klase() ;
        void zmien_witaminy(int wit) ;
};

#endif // WARZYWA_H_INCLUDED
