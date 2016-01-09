#include "szklarnia.h"
#include <cstdlib>
#include <ctime>

Szklarnia::Szklarnia(){
    ile_akcji=3;
    zycie=1;
    licznik=0;


    odznaka=0;
    odznaka_w=0;
    odznaka_o=0;
    odznaka_k=0;
los=0;

    roslinki.push_back(new Owoce("Banan", 3, 4));
    roslinki.push_back(new Owoce("Truskawka", 8, 6));
    roslinki.push_back(new Kwiaty("Roza", 5,5));
    roslinki.push_back(new Warzywa("Marchewka", 7, 8));





}
Szklarnia::~Szklarnia(){

 std::list<Rosliny*>::iterator iter;
    for( iter=roslinki.begin(); iter != roslinki.end(); ++iter)
      iter=roslinki.erase(iter);


}

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

Czynniki *czynniki;
    switch(los){
        case 0: {break;}

       case 1:{      czynniki=new Szkodniki;


            break;
        }
        case 2:{
            czynniki=new Cieplo;


            break;
        }
        case 3:{
              czynniki=new Choroba;

            break;

        }
        default: break;
    }
    if(los!=0)
       {
           for( iter=roslinki.begin(); iter != roslinki.end(); ++iter){
                czynniki->wplyw_na_rosline(*iter);
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

                if((*iter)->podaj_ceche()>100 ) {odznaka_k=1;}
        }

         if ((*iter)->podaj_klase()==2){
                if((*iter)->podaj_ceche()>=70 ) {odznaka_o=1;}
        }

        if ((*iter)->podaj_klase()==3){
               if((*iter)->podaj_ceche()>=50 ) {odznaka_w=1; }
        }
        }
if (odznaka_w==1&&odznaka_o==1&&odznaka_k==1) odznaka=1;

}
void Szklarnia::stan_roslin(){

    std::list<Rosliny*>::iterator iter;
    for( iter=roslinki.begin(); iter != roslinki.end(); ++iter){
        if((*iter)->podaj_wode()<=0) {

            usun_rosline(*iter);
        }

        if((*iter)->podaj_wzrost()<=0){

 usun_rosline(*iter);
        }

        if((*iter)->podaj_zdrowie()<=0){

 usun_rosline(*iter);
        }

        if((*iter)->podaj_wode()>100){

 usun_rosline(*iter);
        }
    }

    if (roslinki.size()==0) zycie=0;


}

bool Szklarnia::podaj_zycie()
{
    return zycie;
}

bool Szklarnia::podaj_odznake()
{
    return odznaka;
}

bool Szklarnia::podaj_odznake_w()
{
    return odznaka_w;
}


bool Szklarnia::podaj_odznake_o()
{
    return odznaka_o;
}

bool Szklarnia::podaj_odznake_k()
{
    return odznaka_k;
}


int Szklarnia::podaj_ileakcji()
{
    return ile_akcji;
}
int Szklarnia::podaj_los()
{
    return los;
}



std::string Szklarnia::opis_nazwa(int n)
{
    std::string nic="";
if(n==-1)return nic;
 std::list<Rosliny*>::iterator iter = roslinki.begin();
        if(n>0) {
            advance(iter, n);
        }
       return (*iter)->podaj_nazwe();


}
int Szklarnia::opis_woda(int n)
{
if(n==-1)return 0;
 std::list<Rosliny*>::iterator iter = roslinki.begin();
        if(n>0) {
            advance(iter, n);
        }
       return (*iter)->podaj_wode();


}
int Szklarnia::opis_wzrost(int n)
{
if(n==-1)return 0;
 std::list<Rosliny*>::iterator iter = roslinki.begin();
        if(n>0) {
            advance(iter, n);
        }
       return (*iter)->podaj_wzrost();


}
int Szklarnia::opis_zdrowie(int n)
{
if(n==-1)return 0;
 std::list<Rosliny*>::iterator iter = roslinki.begin();
        if(n>0) {
            advance(iter, n);
        }
       return (*iter)->podaj_zdrowie();


}
int Szklarnia::opis_cecha(int n)
{
if(n==-1)return 0;
 std::list<Rosliny*>::iterator iter = roslinki.begin();
        if(n>0) {
            advance(iter, n);
        }
       return (*iter)->podaj_ceche();


}

int Szklarnia::opis_klasa(int n)
{
if(n==-1)return 0;
 std::list<Rosliny*>::iterator iter = roslinki.begin();
        if(n>0) {
            advance(iter, n);
        }
       return (*iter)->podaj_klase();


}




