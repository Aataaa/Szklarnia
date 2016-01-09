#include "choroba.h"
#include <cstdlib>
#include <ctime>


Choroba::Choroba():Czynniki()
{

}


void Choroba::wplyw_na_rosline(Rosliny* roslina)
 {
     srand( time( NULL ) );
     roslina->zmien_wode((rand() % 3 ) -1);
     roslina->zmien_zdrowie((rand() % 3 ) -3);
    // roslina.zmien_witaminy(-30);
      //roslina.zmien_piekno(-30);
     // roslina.zmien_slodkosc(-30);

 }
