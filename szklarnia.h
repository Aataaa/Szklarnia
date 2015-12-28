#ifndef SZKLARNIA_H_INCLUDED
#define SZKLARNIA_H_INCLUDED
#include "kwiaty.h"
#include "czynniki.h"
#include "owoce.h"
#include "warzywa.h"
#include "rosliny.h"
#include "czynniki.h"
#include "cieplo.h"
#include "szkodniki.h"
#include "choroba.h"
#include <list>

class Szklarnia
{
       private:
              int ile_akcji;
              bool zycie;
              bool odznaka;
              int licznik;
              bool odwarz;

bool odow;
bool odkwi;
int los;

              std::list <Rosliny*> roslinki;
      public:
             Szklarnia();
             ~Szklarnia();
            void zasadz_rosline(Rosliny* roslinka);
                   void usun_rosline(Rosliny* roslinka);
            void koniec_dnia();
            void stan_roslin();
            void podlewanie_roslin(int numer);
            void nawozenie_roslin(int numer);
            void wygrana();
            bool podaj_zycie();
            bool podaj_odznake();
            int podaj_ileakcji();
             int podaj_los();
         std::string opis(int n);
         int opis6(int n);
          int opis2(int n);
           int opis3(int n);
            int opis4(int n);
          int opis5(int n);
         int podaj_elementy();
};

#endif // SZKLARNIA_H_INCLUDED
