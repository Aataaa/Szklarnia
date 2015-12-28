#ifndef CHOROBA_H
#define CHOROBA_H
#include "czynniki.h"


class Choroba: public Czynniki
{
    public:
        Choroba();

        void wplyw_na_rosline(Rosliny* roslina);
    protected:
    private:
};

#endif // CHOROBA_H
