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
              bool odznaka_w;

bool odznaka_o;
bool odznaka_k;
int los;
bool *tablica;


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
              bool podaj_odznake_w();
                bool podaj_odznake_o();
                  bool podaj_odznake_k();
            int podaj_ileakcji();
             int podaj_los();
         std::string opis_nazwa(int n);
         int opis_woda(int n);
          int opis_wzrost(int n);
           int opis_zdrowie(int n);
            int opis_cecha(int n);
          int opis_klasa(int n);

         int podaj_elementy();
};

#endif // SZKLARNIA_H_INCLUDED
