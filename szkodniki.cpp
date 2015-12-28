#include "szkodniki.h"
#include <cstdlib>
#include <ctime>

Szkodniki::Szkodniki():Czynniki()
{

}

Szkodniki::~Szkodniki()
{

}
void Szkodniki::wplyw_na_rosline(Rosliny* roslina)
 {
    srand( time( NULL ) );
     roslina->zmien_zdrowie((rand() % 3 ) - 2);
     roslina->zmien_wzrost((rand() % 3 ) -4);

     // roslina.zmien_piekno(-30);
     // roslina.zmien_kolor(-30);

 }
