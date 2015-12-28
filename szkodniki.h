#ifndef SZKODNIKI_H
#define SZKODNIKI_H
#include "czynniki.h"



class Szkodniki: public Czynniki
{
    public:
        Szkodniki();
        virtual ~Szkodniki();
        void wplyw_na_rosline(Rosliny* roslina);
    protected:
    private:
};

#endif // SZKODNIKI_H
