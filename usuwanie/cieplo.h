#ifndef CIEPLO_H
#define CIEPLO_H
#include "czynniki.h"


class Cieplo: public Czynniki
{
    public:
        Cieplo();
        virtual ~Cieplo();
        void wplyw_na_rosline(Rosliny* roslina);
    protected:
    private:
};

#endif // CIEPLO_H
