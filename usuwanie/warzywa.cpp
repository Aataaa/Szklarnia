#include "warzywa.h"
#include <cstdlib>
#include <ctime>

using namespace std;


Warzywa::Warzywa(string nazwa,int wzrost, int witaminy) : Rosliny(nazwa, wzrost){
    this->witaminy=witaminy;
    klasa=3;
    nawodnienie=35;
}

Warzywa::~Warzywa() {}



void Warzywa::podlej() {srand( time( NULL ) );
Rosliny::zmien_wode((rand() % 5 ) + 6 ); Rosliny::zmien_wzrost((rand() % 5 ) + 1);}
void Warzywa::nawoz() {
Rosliny::zmien_zdrowie((rand() % 5 ) + 5); zmien_witaminy((rand() % 5 ) + 3);}
int Warzywa::podaj_ceche() {return witaminy;}
void Warzywa::zmien_witaminy(int wit) {witaminy = witaminy+wit;}
int Warzywa::podaj_klase() {return klasa;}

