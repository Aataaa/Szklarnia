#include "cieplo.h"
#include <cstdlib>
#include <ctime>


Cieplo::Cieplo()
{
    //ctor
}

Cieplo::~Cieplo()
{
    //dtor
}
void Cieplo::wplyw_na_rosline(Rosliny* roslina)
 {
     srand( time( NULL ) );
     roslina->zmien_wode((rand() % 3 ) - 5);
     roslina->zmien_zdrowie((rand() % 3 ) + 3);
     roslina->zmien_wzrost((rand() % 3 ) + 3);
      // roslina.zmien_slodkosc(30);
      //   roslina.zmien_witaminy(30);
 }
