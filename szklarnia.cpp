#include "szklarnia.h"
#include <cstdlib>
#include <ctime>

Szklarnia::Szklarnia(){
    ile_akcji=3;
    zycie=1;
    licznik=0;
    odznaka=0;
    odwarz=0;
    odow=0;
    odkwi=0;
los=0;

    roslinki.push_back(new Owoce("Banan", 8, 4));
    roslinki.push_back(new Owoce("Truskawka", 8, 6));
    roslinki.push_back(new Kwiaty("Roza", 5,5));
    roslinki.push_back(new Warzywa("Marchewka", 7, 800));

}
Szklarnia::~Szklarnia(){}

void Szklarnia::zasadz_rosline(Rosliny* roslinka)
{
    roslinki.push_back(roslinka);
}




void Szklarnia::usun_rosline(Rosliny* roslinka)
{
    std::list<Rosliny*>::iterator iter;
    for( iter=roslinki.begin(); iter != roslinki.end(); ++iter)
    if (*iter == roslinka)
    iter=roslinki.erase(iter);
}

int Szklarnia::podaj_elementy()
{
    return roslinki.size();
}

std::string Szklarnia::opis(int n)
{
    std::string nic="";
if(n==-1)return nic;
 std::list<Rosliny*>::iterator iter = roslinki.begin();
        if(n>0) {
            advance(iter, n);
        }
       return (*iter)->podaj_nazwe();


}
int Szklarnia::opis2(int n)
{
if(n==-1)return 0;
 std::list<Rosliny*>::iterator iter = roslinki.begin();
        if(n>0) {
            advance(iter, n);
        }
       return (*iter)->podaj_wode();


}
int Szklarnia::opis3(int n)
{
if(n==-1)return 0;
 std::list<Rosliny*>::iterator iter = roslinki.begin();
        if(n>0) {
            advance(iter, n);
        }
       return (*iter)->podaj_wzrost();


}
int Szklarnia::opis4(int n)
{
if(n==-1)return 0;
 std::list<Rosliny*>::iterator iter = roslinki.begin();
        if(n>0) {
            advance(iter, n);
        }
       return (*iter)->podaj_zdrowie();


}
int Szklarnia::opis5(int n)
{
if(n==-1)return 0;
 std::list<Rosliny*>::iterator iter = roslinki.begin();
        if(n>0) {
            advance(iter, n);
        }
       return (*iter)->podaj_ceche();


}

int Szklarnia::opis6(int n)
{
if(n==-1)return 0;
 std::list<Rosliny*>::iterator iter = roslinki.begin();
        if(n>0) {
            advance(iter, n);
        }
       return (*iter)->podaj_klase();


}





void Szklarnia::podlewanie_roslin(int numer){
     std::list<Rosliny*>::iterator iter = roslinki.begin();
       if(numer>0) {
           advance(iter, numer);
        }
        (*iter)->podlej();
        ile_akcji--;

}

void Szklarnia::nawozenie_roslin(int numer){
std::list<Rosliny*>::iterator iter = roslinki.begin();
        if(numer>0) {
            advance(iter, numer);
        }
        (*iter)->nawoz();
        ile_akcji--;
}

void Szklarnia::koniec_dnia(){
    ile_akcji=3;
    std::list<Rosliny*>::iterator iter;
   for( iter=roslinki.begin(); iter != roslinki.end(); ++iter){
        (*iter)->zmien_wode(-5);
        (*iter)->zmien_zdrowie(-5);
        (*iter)->zmien_wzrost(10);
    }
srand(time(0));
los=(rand()%4);

Czynniki *czynniczki;
    switch(los){
        case 0: {break;}

       case 1:{      czynniczki=new Szkodniki;


            break;
        }
        case 2:{
            czynniczki=new Cieplo;


            break;
        }
        case 3:{
              czynniczki=new Choroba;

            break;

        }
        default: break;
    }
    if(los!=0)
       {
           for( iter=roslinki.begin(); iter != roslinki.end(); ++iter){
                czynniczki->wplyw_na_rosline(*iter);
            }
       }
}


void Szklarnia::wygrana()
{

std::list<Rosliny*>::iterator iter;
    for( iter=roslinki.begin(); iter != roslinki.end(); ++iter)
        {

 if((*iter)->podaj_klase()==1)
 {

                if((*iter)->podaj_ceche()>200 ) {odkwi=1;}
        }

         if ((*iter)->podaj_klase()==2){
                if((*iter)->podaj_ceche()>=300 ) {odow=1;}
        }

        if ((*iter)->podaj_klase()==3){
               if((*iter)->podaj_ceche()>=500 ) {odwarz=1; }
        }
        }
if (odwarz==1&&odow==1&&odkwi==1) odznaka=1;

}
void Szklarnia::stan_roslin(){
    std::list<Rosliny*>::iterator iter;
    for( iter=roslinki.begin(); iter != roslinki.end(); ++iter){
        if((*iter)->podaj_wode()<=0) {
            (*iter)->gnije();
            //usun_rosline(*iter);
        }

        if((*iter)->podaj_wzrost()<=0){
            (*iter)->gnije();
           // usun_rosline((*iter));
        }

        if((*iter)->podaj_zdrowie()<=0){
            (*iter)->gnije();
           // usun_rosline((*iter));
        }

        if((*iter)->podaj_wode()>100){
            (*iter)->gnije();
           // usun_rosline((*iter));
        }
    }
   for( iter=roslinki.begin(); iter != roslinki.end(); ++iter){
       if((*iter)->czy_zyje()==0) {licznik++;}
       if (licznik==roslinki.size()) zycie=0;
    }
   // licznik=0;
}

bool Szklarnia::podaj_zycie()
{
    return zycie;
}

bool Szklarnia::podaj_odznake()
{
    return odznaka;
}

bool Szklarnia::podaj_odkwi()
{
    return odkwi;
}


bool Szklarnia::podaj_odow()
{
    return odow;
}

bool Szklarnia::podaj_odwarz()
{
    return odwarz;
}


int Szklarnia::podaj_ileakcji()
{
    return ile_akcji;
}
int Szklarnia::podaj_los()
{
    return los;
}
