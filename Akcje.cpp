
#include "Akcje.h"
#include <Windows.h>
#include <math.h>
#include <iostream>



using namespace sf;

Akcje::Akcje(void)
{
	if(!tekstura1.loadFromFile("sprajty/gracz/9.png"))
	{
		MessageBox(NULL,"Nie znaleziono tekstur","Blad",NULL);
		return;
	}

	sprajt1.setTexture(tekstura1);
	sprajt1.setTextureRect(IntRect(0,0,607,694));






if(!tekstura2.loadFromFile("sprajty/gracz/10.png"))
	{
		MessageBox(NULL,"Nie znaleziono tekstur","Blad",NULL);
		return;
	}

	sprajt2.setTexture(tekstura2);
	sprajt2.setTextureRect(IntRect(0,0,607,694));





if(!tekstura3.loadFromFile("sprajty/gracz/7.png"))
	{
		MessageBox(NULL,"Nie znaleziono tekstur","Blad",NULL);
		return;
	}

	sprajt3.setTexture(tekstura3);
	sprajt3.setTextureRect(IntRect(0,0,607,694));





	sprajt1.setPosition(-200,-200);
		sprajt2.setPosition(50,-200);

                       sprajt3.setPosition(300,-200);



}


Akcje::~Akcje(void)
{
}


void Akcje::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(sprajt1);
	target.draw(sprajt2);
	target.draw(sprajt3);

}


