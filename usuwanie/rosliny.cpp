#include "rosliny.h"

Rosliny::Rosliny(std::string nazwa, int wzrost)
{
    this->nazwa=nazwa;
    this->wzrost=wzrost;

    zdrowie = 30;
    nawodnienie = 30;
    klasa=0;
}

Rosliny::~Rosliny() {}

int Rosliny::podaj_zdrowie() {return zdrowie;}
int Rosliny::podaj_wode() {return nawodnienie;}
std::string Rosliny::podaj_nazwe() {return nazwa;}
int Rosliny::podaj_wzrost(){return wzrost;}
int Rosliny::podaj_klase() {return klasa;}

void Rosliny::zmien_wode(int wod) {nawodnienie = nawodnienie+wod;}
void Rosliny::zmien_zdrowie(int zdr) {zdrowie = zdrowie+zdr;}
void Rosliny::zmien_wzrost(int wzr) {wzrost = wzrost+wzr;}


