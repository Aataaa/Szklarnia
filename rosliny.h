#ifndef ROSLINY_H_INCLUDED
#define ROSLINY_H_INCLUDED
#include <string>


class Rosliny
{
      private:

            std::string nazwa;
            int wzrost;
             int nawodnienie;
            int zdrowie;
             bool zyje;
protected:

            int klasa;

      public:

            Rosliny(std::string nazwa, int wzrost);
            ~Rosliny();

            virtual void nawoz() =0;
            virtual void podlej() =0;
            virtual int podaj_klase();
            virtual int podaj_ceche()=0;

            int podaj_zdrowie();
            int podaj_wode() ;
            std::string podaj_nazwe() ;
            int podaj_wzrost();
            bool czy_zyje() ;
            void zmien_wode(int wod);
            void zmien_zdrowie(int zdr) ;
            void zmien_wzrost(int wzr) ;
            void gnije();

};

#endif // ROSLINY_H_INCLUDED
