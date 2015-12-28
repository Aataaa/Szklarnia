
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



if(!tekstura3.loadFromFile("sprajty/gracz/sprout.png"))
	{
		MessageBox(NULL,"Nie znaleziono tekstury","Blad",NULL);
		return;
	}

	sprajt3.setTexture(tekstura3);
	sprajt3.setTextureRect(IntRect(0,0,447,439));



if(!tekstura4.loadFromFile("sprajty/gracz/carrot.png"))
	{
		MessageBox(NULL,"Nie znaleziono tekstury","Blad",NULL);
		return;
	}

	sprajt4.setTexture(tekstura4);
	sprajt4.setTextureRect(IntRect(0,0,447,439));





	sprajt1.setPosition(-100,300);
		sprajt2.setPosition(50,300);
		sprajt3.setPosition(200,300);
		sprajt4.setPosition(400,300);



                      sprajt=sprajt5;

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
	target.draw(sprajt5);

}




void Uprawa::ktoraros()
{
	sprajt=sprajt6;


}


void Uprawa::owoce()
{



}



void Uprawa::warz()
{



}
