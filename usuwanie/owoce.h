#ifndef OWOCE_H_INCLUDED
#define OWOCE_H_INCLUDED
#include "rosliny.h"

class Owoce : public Rosliny
{
    private:
        int slodkosc;
        int klasa;
    public:
        Owoce(std::string nazwa, int wzrost, int slodkosc);
        ~Owoce();
        void podlej() ;
        void nawoz() ;

        int podaj_klase() ;
        int podaj_ceche();
        void zmien_slodkosc(int slo) ;
};

#endif // OWOCE_H_INCLUDED
