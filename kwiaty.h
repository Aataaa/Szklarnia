#ifndef KWIATY_H_INCLUDED
#define KWIATY_H_INCLUDED
#include "rosliny.h"
using namespace std;
class Kwiaty : public Rosliny
{
    private:
            int piekno;

      public:
            Kwiaty(string nazwa, int wzrost, int piekno) ;
            ~Kwiaty() ;
            void podlej();
            void nawoz() ;
            int podaj_ceche();
            int podaj_klase();
            void zmien_piekno(int pie) ;
};

#endif // KWIATY_H_INCLUDED
