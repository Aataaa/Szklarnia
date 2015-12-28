#include "Noc.h"

using namespace sf;

Noc::Noc()
{


    if(!tekstura1.loadFromFile("sprajty/gracz/n2.png"))
	{
		MessageBox(NULL,"Nie znaleziono tekstur","Blad",NULL);
		return;
	}

	sprajt1.setTexture(tekstura1);
	sprajt1.setTextureRect(IntRect(0,0,537,308));


    if(!tekstura2.loadFromFile("sprajty/gracz/p2.png"))
	{
		MessageBox(NULL,"Nie znaleziono tekstur","Blad",NULL);
		return;
	}

	sprajt2.setTexture(tekstura2);
	sprajt2.setTextureRect(IntRect(0,0,537,308));




	klatka = 0;
	szybkosc = 2.5;
    sprajt1.setPosition(500,720/2);
     sprajt2.setPosition(500,720/2);
    sprajt=sprajt1;
    	zegar.restart();
zegar2.restart();



}


Noc::~Noc(void)
{
muzyka.stopmuzyka();
}

/*
void Noc::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(sprajt);


}
*/
void Noc::aktualizuj()
{



	if(zegar.getElapsedTime() > sf::seconds(0.2f) )
	{

		if(klatka < 3 /*liczba klatek animacji*/)
        {
            klatka++;

        }


		else
        {
            klatka = 0; //zapetlanie animacji

        }

		sprajt.setTextureRect(IntRect(klatka*537,0,537,308));
								//x, y, szerokosc, wysokosc


		zegar.restart();
	}
}

void Noc::podstawowy()
{
	sprajt=sprajt1;


}


void Noc::zmien()
{
	sprajt=sprajt2;


}



void Noc::ruszNoc(sf::RenderWindow &okno, bool m)
{



	bool silnik=false;
zegar2.restart();


muzyka.glosnosc(!m);

while(!silnik)
	{



if(!czcionka.loadFromFile("sprajty/czcionki/Szklarnia.ttf"))
	{
		MessageBox(NULL,"Czcionka nieznaleziona","Blad",NULL);
		return;
	}

	    if(!tlo.loadFromFile("sprajty/obrazy/noc.png"))
	{
		MessageBox(NULL,"Nie znaleziono tekstur","Blad",NULL);
		return;
	}

sprajttlo.setTexture(tlo);
sprajttlo.setScale(1, 1);

Text tekst;



		tekst.setFont(czcionka);
		tekst.setCharacterSize(95);

		tekst.setString("Koniec dnia");
		tekst.setPosition(450, 50);


if(zegar2.getElapsedTime() > sf::seconds(5) )
{
    silnik=true;
}

Event zdarzenie;
while(okno.pollEvent(zdarzenie))
		{
if(zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::O)
			{

				podstawowy();
silnik=true;
			}


			if(zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::P)
			{

				zmien();
			}

		}


aktualizuj();

		okno.clear();
okno.draw(sprajttlo);
okno.draw(tekst);
		okno.draw(sprajt);



		okno.display();

	}
}
