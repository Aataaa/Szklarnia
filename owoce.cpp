#include "owoce.h"
#include <cstdlib>
#include <ctime>

using namespace std;


Owoce::Owoce(string nazwa, int wzrost, int slodkosc) : Rosliny(nazwa, wzrost)
{
    this->slodkosc=slodkosc;
    klasa=2;
}

Owoce:: ~Owoce() {}

void Owoce::podlej() {srand( time( NULL ) );Rosliny::zmien_wode((rand() % 7 ) + 2); Rosliny::zmien_zdrowie((rand() % 7 ) + 1); }
void Owoce::nawoz() {srand( time( NULL ) );Rosliny::zmien_zdrowie((rand() % 7 ) + 8); zmien_slodkosc((rand() % 7 ) + 4);}
int Owoce::podaj_ceche() {return slodkosc;}
void Owoce::zmien_slodkosc(int slo) {slodkosc = slodkosc+slo;}
int Owoce::podaj_klase() {return klasa;}
