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

 if(!tekstura3.loadFromFile("sprajty/gracz/11.png"))
	{
		MessageBox(NULL,"Nie znaleziono tekstur","Blad",NULL);
		return;
	}

	sprajt3.setTexture(tekstura3);
	sprajt3.setTextureRect(IntRect(0,0,607,694));


	klatka = 0;
	szybkosc = 2.5;
    sprajt1.setPosition(500,720/2);
     sprajt2.setPosition(500,720/2);
     sprajt3.setPosition(500,720/2);
    sprajt=sprajt1;
    	zegar.restart();
zegar2.restart();

str="";
str1="Nic sie nie stalo";
str2="Noc byla bardzo ciepla";
str3="Szkodniki";
str4="Choroba";

}


Noc::~Noc(void)
{
muzyka.stopmuzyka();
}


void Noc::aktualizuj()
{



	if(zegar.getElapsedTime() > sf::seconds(0.2f) )
	{

		if(klatka < 3 )
        {
            klatka++;

        }


		else
        {
            klatka = 0;

        }

		sprajt.setTextureRect(IntRect(klatka*537,0,537,308));



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


void Noc::zmien2()
{
	sprajt=sprajt3;


}

void Noc::zmientekst()
{
	str=str1;
}
void Noc::zmientekst2()
{
	str=str2;
}
void Noc::zmientekst3()
{
	str=str3;
}
void Noc::zmientekst4()
{
	str=str4;
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


Text tekst2;




		tekst2.setFont(czcionka);
		tekst2.setCharacterSize(95);

		tekst2.setString(str);
		tekst2.setPosition(450, 200);



if(zegar2.getElapsedTime() > sf::seconds(5) )
{
    silnik=true;
}

Event zdarzenie;
while(okno.pollEvent(zdarzenie))
		{
if(zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::W)
			{

			silnik=true;
			}

		}


aktualizuj();
okno.clear();
okno.draw(sprajttlo);
okno.draw(tekst);
okno.draw(tekst2);
okno.draw(sprajt);



		okno.display();

	}
}
