#include "Odznaki.h"

#include <Windows.h>

#include <iostream>



using namespace sf;

Odznaki::Odznaki(void)
{
	if(!tekstura1.loadFromFile("sprajty/gracz/kwiatek.png"))
	{
		MessageBox(NULL,"Nie znaleziono tekstur","Blad",NULL);
		return;
	}

	sprajt1.setTexture(tekstura1);
	sprajt1.setTextureRect(IntRect(0,0,205,160));






if(!tekstura2.loadFromFile("sprajty/gracz/owoc.png"))
	{
		MessageBox(NULL,"Nie znaleziono tekstur","Blad",NULL);
		return;
	}

	sprajt2.setTexture(tekstura2);
	sprajt2.setTextureRect(IntRect(0,0,137,162));





if(!tekstura3.loadFromFile("sprajty/gracz/warzywko.png"))
	{
		MessageBox(NULL,"Nie znaleziono tekstur","Blad",NULL);
		return;
	}

	sprajt3.setTexture(tekstura3);
	sprajt3.setTextureRect(IntRect(0,0,131,160));


if(!tekstura4.loadFromFile("sprajty/gracz/odznaka.png"))
	{
		MessageBox(NULL,"Nie znaleziono tekstur","Blad",NULL);
		return;
	}

	sprajt4.setTexture(tekstura4);
	sprajt4.setTextureRect(IntRect(0,0,138,97));


if(!tekstura5.loadFromFile("sprajty/gracz/puste.png"))
	{
		MessageBox(NULL,"Nie znaleziono tekstur","Blad",NULL);
		return;
	}

	sprajt5.setTexture(tekstura5);
	sprajt5.setTextureRect(IntRect(0,0,138,97));


	sprajt1.setPosition(950,21);
		sprajt2.setPosition(1040,21);
        sprajt3.setPosition(1150,21);

sprajt4.setPosition(1070,40);
sprajt5.setPosition(710,530);

sprajto1=sprajt5;
sprajto2=sprajt5;
sprajto3=sprajt5;
sprajto4=sprajt5;

}


Odznaki::~Odznaki(void)
{
}


void Odznaki::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(sprajto1);
	target.draw(sprajto2);
	target.draw(sprajto3);
target.draw(sprajto4);
}

void Odznaki::zmien_oznake_k()
{
    sprajto1=sprajt1;

}


void Odznaki::zmien_odznake_o()
{
    sprajto2=sprajt2;

}



void Odznaki::zmien_odznake_w()
{
    sprajto3=sprajt3;

}




void Odznaki::zmien_odznake()
{
   sprajto4=sprajt4;
}
