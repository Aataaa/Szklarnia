#ifndef CZYNNNIKI_H
#define CZYNNNIKI_H
#include "rosliny.h"


class Czynniki
{
    public:
        Czynniki();

        virtual void wplyw_na_rosline(Rosliny* roslina)=0;
    protected:
    private:
};

#endif // CZYNNNIKI_H
