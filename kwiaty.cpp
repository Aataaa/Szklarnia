#include "kwiaty.h"
#include <cstdlib>
#include <ctime>

using namespace std;
Kwiaty::Kwiaty(string nazwa, int wzrost, int piekno) : Rosliny(nazwa, wzrost)
{
    this->piekno=piekno;
    klasa=1;
    nawodnienie=20;
}

Kwiaty::~Kwiaty() {}

void Kwiaty::podlej() { srand( time( NULL ) ); Rosliny::zmien_wode((rand() % 3 ) + 3); Rosliny::zmien_zdrowie((rand() % 3 ) + 10); }
void Kwiaty::nawoz() {Rosliny::zmien_wzrost((rand() % 3 ) + 1); zmien_piekno((rand() % 3 ) + 150); }
int Kwiaty::podaj_klase() {return klasa;}
int Kwiaty::podaj_ceche() {return piekno;}
void Kwiaty::zmien_piekno(int pie) {piekno = piekno+pie;}



