
#include "Uprawa.h"
#include <Windows.h>
#include <math.h>
#include <iostream>


using namespace sf;

Uprawa::Uprawa(void)
{
	if(!tekstura1.loadFromFile("sprajty/gracz/banana.png"))
	{
		MessageBox(NULL,"Nie znaleziono tekstury","Blad",NULL);
		return;
	}

	sprajt1.setTexture(tekstura1);
	sprajt1.setTextureRect(IntRect(0,0,447,439));





if(!tekstura2.loadFromFile("sprajty/gracz/strawberry.png"))
	{
		MessageBox(NULL,"Nie znaleziono tekstury","Blad",NULL);
		return;
	}

	sprajt2.setTexture(tekstura2);
	sprajt2.setTextureRect(IntRect(0,0,447,439));



if(!tekstura3.loadFromFile("sprajty/gracz/roza.png"))
	{
		MessageBox(NULL,"Nie znaleziono tekstury","Blad",NULL);
		return;
	}

	sprajt3.setTexture(tekstura3);
	sprajt3.setTextureRect(IntRect(0,0,134,190));



if(!tekstura4.loadFromFile("sprajty/gracz/carrot.png"))
	{
		MessageBox(NULL,"Nie znaleziono tekstury","Blad",NULL);
		return;
	}

	sprajt4.setTexture(tekstura4);
	sprajt4.setTextureRect(IntRect(0,0,447,439));




if(!tekstura5.loadFromFile("sprajty/gracz/radish.png"))
	{
		MessageBox(NULL,"Nie znaleziono tekstury","Blad",NULL);
		return;
	}

	sprajt5.setTexture(tekstura5);
	sprajt5.setTextureRect(IntRect(0,0,447,439));



if(!tekstura6.loadFromFile("sprajty/gracz/pepper.png"))
	{
		MessageBox(NULL,"Nie znaleziono tekstury","Blad",NULL);
		return;
	}

	sprajt6.setTexture(tekstura6);
	sprajt6.setTextureRect(IntRect(0,0,447,439));

if(!tekstura7.loadFromFile("sprajty/gracz/orange.png"))
	{
		MessageBox(NULL,"Nie znaleziono tekstury","Blad",NULL);
		return;
	}

	sprajt7.setTexture(tekstura7);
	sprajt7.setTextureRect(IntRect(0,0,447,439));


	if(!tekstura8.loadFromFile("sprajty/gracz/squash.png"))
	{
		MessageBox(NULL,"Nie znaleziono tekstury","Blad",NULL);
		return;
	}

	sprajt8.setTexture(tekstura8);
	sprajt8.setTextureRect(IntRect(0,0,447,439));


	if(!tekstura9.loadFromFile("sprajty/gracz/slonecznik.png"))
	{
		MessageBox(NULL,"Nie znaleziono tekstury","Blad",NULL);
		return;
	}

	sprajt9.setTexture(tekstura9);
	sprajt9.setTextureRect(IntRect(0,0,190,190));

	if(!tekstura10.loadFromFile("sprajty/gracz/stokrotka.png"))
	{
		MessageBox(NULL,"Nie znaleziono tekstury","Blad",NULL);
		return;
	}

	sprajt10.setTexture(tekstura10);
	sprajt10.setTextureRect(IntRect(0,0,98,190));

if(!tekstura11.loadFromFile("sprajty/gracz/puste.png"))
	{
		MessageBox(NULL,"Nie znaleziono tekstury","Blad",NULL);
		return;
	}

	sprajt11.setTexture(tekstura11);
	sprajt11.setTextureRect(IntRect(0,0,447,439));



        sprajt1.setPosition(-50,450);
        sprajt1.setScale(0.7, 0.7);
		sprajt2.setPosition(50,450);
		 sprajt2.setScale(0.7, 0.7);
		sprajt3.setPosition(250,550);
		 sprajt3.setScale(0.7, 0.7);
		sprajt4.setPosition(250,450);
		 sprajt4.setScale(0.7, 0.7);
		sprajt5.setPosition(350,450);
		 sprajt5.setScale(0.7, 0.7);
		sprajt6.setPosition(450,450);
		 sprajt6.setScale(0.7, 0.7);
		sprajt7.setPosition(550,450);
		 sprajt7.setScale(0.7, 0.7);
		sprajt8.setPosition(650,450);
		 sprajt8.setScale(0.7, 0.7);
		sprajt9.setPosition(750,450);
		 sprajt9.setScale(0.7, 0.7);
sprajt10.setPosition(800,450);
		 sprajt10.setScale(0.7, 0.7);
sprajtr=sprajt11;
sprajtr1=sprajt11;
sprajtr2=sprajt11;




}


Uprawa::~Uprawa(void)
{
}


void Uprawa::draw(sf::RenderTarget &target, RenderStates states) const
{

states.transform *= getTransform();
	target.draw(sprajt1);
	target.draw(sprajt2);
	target.draw(sprajt3);
	target.draw(sprajt4);
	target.draw(sprajtr);
target.draw(sprajtr1);
target.draw(sprajtr2);
}




void Uprawa::rzodkiew()
{
	sprajtr=sprajt5;


}


void Uprawa::papryka()
{

sprajtr=sprajt6;

}



void Uprawa::pomarancza()
{

sprajtr1=sprajt7;

}



void Uprawa::gruszka()
{

sprajtr1=sprajt8;

}

void Uprawa::slonecznik()
{

sprajtr2=sprajt9;

}

void Uprawa::stokrotka()
{

sprajtr2=sprajt10;

}



