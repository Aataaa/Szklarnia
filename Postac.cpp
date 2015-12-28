
#include "Postac.h"
#include <Windows.h>
#include <math.h>
#include <iostream>



using namespace sf;

Postac::Postac(void)
{
	if(!tekstura1.loadFromFile("sprajty/gracz/3a.png"))
	{
		MessageBox(NULL,"Nie znaleziono tekstury","Blad",NULL);
		return;
	}

	sprajt1.setTexture(tekstura1);
	sprajt1.setTextureRect(IntRect(524,0,992,694));





if(!tekstura3.loadFromFile("sprajty/gracz/2a.png"))
	{
		MessageBox(NULL,"Nie znaleziono tekstury","Blad",NULL);
		return;
	}

	sprajt3.setTexture(tekstura3);
	sprajt3.setTextureRect(IntRect(524,0,992,694));



if(!tekstura2.loadFromFile("sprajty/gracz/4d.png"))
	{
		MessageBox(NULL,"Nie znaleziono tekstury","Blad",NULL);
		return;
	}

	sprajt2.setTexture(tekstura2);
	sprajt2.setTextureRect(IntRect(524,0,992,694));




if(!tekstura4.loadFromFile("sprajty/gracz/1a.png"))
	{
		MessageBox(NULL,"Nie znaleziono tekstury","Blad",NULL);
		return;
	}

	sprajt4.setTexture(tekstura4);
	sprajt4.setTextureRect(IntRect(524,0,992,694));




	status = NIC;

	klatka = 0;
	szybkosc= 3.5;

	sprajt1.setPosition(800,0);
		sprajt2.setPosition(800,0);
                      sprajt3.setPosition(800,0);
                       sprajt4.setPosition(800,0);
                      sprajt=sprajt1;
	zegar.restart();
}


Postac::~Postac(void)
{
}


void Postac::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(sprajt);

}


void Postac::aktualizuj()
{



	if(zegar.getElapsedTime() > sf::seconds(2.0f) )
	{

		if(klatka < 1 /*liczba klatek animacji*/)
        {
            klatka++;

        }


		else
        {
            klatka = 0; //zapetlanie animacji

        }

		sprajt.setTextureRect(IntRect(klatka*524,0,496,694));
								//x, y, szerokosc, wysokosc


		zegar.restart();
	}
}

void Postac::podstawowy()
{
	status = NIC;

	sprajt=sprajt1;
}



void Postac::szpadel()
{
    status = SZPADEL;
	sprajt=sprajt2;


}


void Postac::owoce()
{
    status =OWOCE;
	sprajt=sprajt3;


}



void Postac::warz()
{


status = WARZYWA;
	sprajt=sprajt4;


}
