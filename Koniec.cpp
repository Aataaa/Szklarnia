#include "Koniec.h"



using namespace sf;

Koniec::Koniec()
{


    if(!tekstura1.loadFromFile("sprajty/gracz/8.png"))
	{
		MessageBox(NULL,"Nie znaleziono tekstur","Blad",NULL);
		return;
	}

	sprajt1.setTexture(tekstura1);
	sprajt1.setTextureRect(IntRect(0,0,607,694));


    if(!tekstura2.loadFromFile("sprajty/gracz/6.png"))
	{
		MessageBox(NULL,"Nie znaleziono tekstur","Blad",NULL);
		return;
	}

	sprajt2.setTexture(tekstura2);
	sprajt2.setTextureRect(IntRect(0,0,607,694));


    sprajt1.setPosition(300,100);
     sprajt2.setPosition(300,200);

    sprajt=sprajt1;



str1="Przegrana";
str2="Wygrana";
str=str2;

}


Koniec::~Koniec(void)
{
muzyka.stopmuzyka();
}


void Koniec::podstawowy()
{
	sprajt=sprajt1;


}


void Koniec::zmien()
{
	sprajt=sprajt2;


}


void Koniec::zmientekst()
{
	str=str1;
}
void Koniec::zmientekst2()
{
	str=str2;
}


void Koniec::ruszKoniec(sf::RenderWindow &okno, bool m)
{



	bool silnik=false;



muzyka.glosnosc(!m);

while(!silnik)
	{



if(!czcionka.loadFromFile("sprajty/czcionki/Szklarnia.ttf"))
	{
		MessageBox(NULL,"Czcionka nieznaleziona","Blad",NULL);
		return;
	}

	    if(!tlo.loadFromFile("sprajty/obrazy/images.jpg"))
	{
		MessageBox(NULL,"Nie znaleziono tekstur","Blad",NULL);
		return;
	}

sprajttlo.setTexture(tlo);
sprajttlo.setScale(5, 5);

Text tekst;



		tekst.setFont(czcionka);
		tekst.setCharacterSize(95);

		tekst.setString("Koniec gry");
		tekst.setPosition(450, 50);


Text tekst2;




		tekst2.setFont(czcionka);
		tekst2.setCharacterSize(95);

		tekst2.setString(str);
		tekst2.setPosition(460, 200);



		Event zdarzenie;
		sf::Vector2f mysz(Mouse::getPosition(okno));

		while(okno.pollEvent(zdarzenie))
		{
if(zdarzenie.type == Event::KeyReleased && zdarzenie.key.code == Keyboard::Escape)


            {
               muzyka.stopmuzyka();
                silnik = true;
            }
		}

okno.clear();
okno.draw(sprajttlo);
okno.draw(tekst);
okno.draw(tekst2);
okno.draw(sprajt);



		okno.display();

	}
}
