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


    if(!tekstura2.loadFromFile("sprajty/gracz/6a.png"))
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
str2="Wygrana!";
str3="Zmarly wszystkie twoje rosliny!";
str4="Twoje rosliny pieknie urosly, dostajesz odznake super ogrodnika!";
str=str2;
strr=str4;



}


Koniec::~Koniec(void)
{
muzyka.stopmuzyka();
}


void Koniec::podstawowy()
{
	sprajt=sprajt1;

odznaki.zmien_odznake();
}


void Koniec::zmien()
{
	sprajt=sprajt2;


}


void Koniec::zmientekst()
{
	str=str1;
	strr=str3;
}
void Koniec::zmientekst2()
{
	str=str2;
	strr=str4;
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



sf::RectangleShape ramkaodzn(sf::Vector2f(300,160));
ramkaodzn.setPosition(970, 7);
ramkaodzn.setFillColor(sf::Color::White);
ramkaodzn.setOutlineThickness(10);
ramkaodzn.setOutlineColor(sf::Color(250, 150, 100));


Text tekstodzn;
tekstodzn.setFont(czcionka);
tekstodzn.setString("Odznaka super ogrodnika: ");
tekstodzn.setCharacterSize(25);
tekstodzn.setPosition(975, 10);
tekstodzn.setColor( sf::Color::Black );





Text tekst;



		tekst.setFont(czcionka);
		tekst.setCharacterSize(95);

		tekst.setString("Koniec gry");
		tekst.setPosition(480, 50);


Text tekst2[2];




		tekst2[0].setFont(czcionka);
		tekst2[0].setCharacterSize(95);

		tekst2[0].setString(str);
		tekst2[0].setPosition(500, 150);


		tekst2[1].setFont(czcionka);
		tekst2[1].setCharacterSize(45);

		tekst2[1].setString(strr);
		if(strr==str3)
        {
            tekst2[1].setPosition(450, 250);
        }
        else if(strr==str4)
        {
         tekst2[1].setPosition(200, 250);
        }


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

for(int i=0; i<2; i++)
okno.draw(tekst2[i]);
okno.draw(tekst);
okno.draw(sprajt);
okno.draw(ramkaodzn);
okno.draw(tekstodzn);

okno.draw(odznaki);
		okno.display();

	}
}
