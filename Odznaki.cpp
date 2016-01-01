#include "Odznaki.h"

#include <Windows.h>

#include <iostream>



using namespace sf;

Odznaki::Odznaki(void)
{
	if(!tekstura1.loadFromFile("sprajty/gracz/kwiatek.jpg"))
	{
		MessageBox(NULL,"Nie znaleziono tekstur","Blad",NULL);
		return;
	}

	sprajt1.setTexture(tekstura1);
	sprajt1.setTextureRect(IntRect(0,0,205,160));






if(!tekstura2.loadFromFile("sprajty/gracz/owoc.jpg"))
	{
		MessageBox(NULL,"Nie znaleziono tekstur","Blad",NULL);
		return;
	}

	sprajt2.setTexture(tekstura2);
	sprajt2.setTextureRect(IntRect(0,0,137,162));





if(!tekstura3.loadFromFile("sprajty/gracz/warzywko.jpg"))
	{
		MessageBox(NULL,"Nie znaleziono tekstur","Blad",NULL);
		return;
	}

	sprajt3.setTexture(tekstura3);
	sprajt3.setTextureRect(IntRect(0,0,131,160));


if(!tekstura4.loadFromFile("sprajty/gracz/odznaka.jpg"))
	{
		MessageBox(NULL,"Nie znaleziono tekstur","Blad",NULL);
		return;
	}

	sprajt4.setTexture(tekstura4);
	sprajt4.setTextureRect(IntRect(0,0,138,97));


	sprajt1.setPosition(700,600);
		sprajt2.setPosition(800,600);

                       sprajt3.setPosition(900,600);

sprajt4.setPosition(1000,600);

}


Odznaki::~Odznaki(void)
{
}


void Odznaki::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(sprajt1);
	target.draw(sprajt2);
	target.draw(sprajt3);
target.draw(sprajt4);
}

