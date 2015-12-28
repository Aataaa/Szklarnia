#include <cstdlib>
#include <iostream>
#include <cstring>
#include "szklarnia.h"
#include "rosliny.h"
#include "kwiaty.h"
using namespace std;

 void komunikat(){
    cout << endl << endl<< "Koniec gry!" << endl << endl;
}


 void lista_dzialan(){
    cout << "Mozliwe dzialania: \n1. Podlej\n2. Nawiez\n3. Koniec dnia "<< endl ;
}

int main(int argc, char *argv[])
{
       cout<<"Instrukcja:"<<endl;
       cout<<"Zadbaj o swoj ogrod. Pielegnuj 9 lub wiecej roslin: warzyw , owocow i kwiatow. \nPowodzenia!"<<endl<<endl<<endl;
  //     system ("PAUSE");
   //    system ("cls");
       Szklarnia gra;
       char odp;
       string nazwa;
       int wzrost;
       int zdrowie;
       int atrybut;
       int klasa;
       int akcja;
       int numer;
       int dzien=0;
       bool koniec_dnia=0;
       int n; //losowanie czynnikow

        do {

            dzien++;
            cout<<"dzien: "<<dzien<<endl;;
            cout<<"Czy chcesz zasadzic rosline? (t/n)"<<endl;
            cin>>odp;
                if(odp=='t' || odp=='T'){
                    cout<<"Podaj typ (1-Kwiat, 2-Owoc, 3-Warzywo)"<<endl;
                    cin>>klasa;
                    cout<<"Podaj nazwe: "<<endl;
                    cin>>nazwa;
                    cout<<"Podaj wzrost : "<<endl;
                    cin>>wzrost;
                    cout<<"Podaj atrybut: "<<endl;
                    cin>>atrybut;
                    if(klasa==1){
                         Rosliny* kwiatek= new Kwiaty(nazwa, wzrost, atrybut);
                        gra.zasadz_rosline(kwiatek);}

                    else if(klasa==3){ Rosliny* warzywko= new Warzywa(nazwa, wzrost, atrybut);
                        gra.zasadz_rosline(warzywko);}
                    else if(klasa==2) {Rosliny* owocek= new Owoce(nazwa, wzrost, atrybut);
                        gra.zasadz_rosline(owocek);}
                    }

    cout<<endl;

    cout<<"Rosliny:"<<endl;

for(int n=0; n<gra.podaj_elementy(); n++){

  cout<<gra.opis(n)<<", typ: ";
  if(gra.opis6(n)==1) cout<<"Kwiat, ";
  else if(gra.opis6(n)==3) cout<<"Warzywo, ";
  else if(gra.opis6(n)==2) cout<<"Owoc, ";
  cout<<"Wzrost: "<<gra.opis3(n)<<" ";
   cout<<"Cecha: "<<gra.opis5(n)<<" ";
   cout<<"Nawodnienie: "<<gra.opis2(n)<<" ";
   cout<<"Zdrowie: "<<gra.opis4(n)<<" ";
    cout <<endl;
}


    lista_dzialan();
    cout<<endl;

      do{
            koniec_dnia=0;
          cout<<"Twoje akcje: "<<gra.podaj_ileakcji()<<endl;
          cout<<"podaj co chcesz zrobic (1, 2, 3)"<<endl;
          cin>>akcja;
              switch(akcja){
                case 1:  {
                    cout<<"ktora roslina?"<<endl;
                    cin>>numer;
                    gra.podlewanie_roslin(numer-1);
                    break;
                }
                case 2: {
                    cout<<"ktora roslina?"<<endl;
                    cin>>numer;
                    gra.nawozenie_roslin(numer-1);
                    break;
                }
                case 3: {
                     koniec_dnia=1;
                     break;
                }
                default: cout << "Podano niewlasciwy znak. " << endl;
            }
        }
      while(gra.podaj_ileakcji()>0&& koniec_dnia==0);

      gra.koniec_dnia();

      if(gra.podaj_los()==0)
        cout<<"Nic sie nie stalo"<<endl;
       else if(gra.podaj_los()==1)
        cout<<"Cieplo. Dodaje wzrost i zdrowie. Odejmuje wode. "<<endl;
         else if(gra.podaj_los()==2)
        cout<<"Szkodniki. Odejmuja zdrowie i wzrost. "<<endl;
        else  if(gra.podaj_los()==3)
        cout<<"Choroby. Odejmuja zdrowie i wode. "<<endl;
else          cout<<"nhfhjj. "<<endl;
      gra.wygrana();
      gra.stan_roslin();

cout<<"czy zyja?"<<gra.podaj_zycie()<<endl;

      system("PAUSE");
      system("cls");
    }
    while(gra.podaj_odznake()==0 && gra.podaj_zycie()==1);
    komunikat();




       system("PAUSE");
       return EXIT_SUCCESS;
}
