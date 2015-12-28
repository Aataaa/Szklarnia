

#include "Silnik.h"
using namespace sf;

Silnik::Silnik(sf::RenderWindow &ok, bool m)
{
	ruszSilnik(ok,m);


}


Silnik::~Silnik(void)
{
muzyka.stopmuzyka();
}

string naString(float liczba)
{
	stringstream ss;
	ss<<liczba;

	return ss.str();
}



void Silnik::ruszSilnik(sf::RenderWindow &okno, bool m)
{


	bool menu = false;



muzyka.ladujmuzyke(false);

muzyka.puscmuzyke();
muzyka.glosnosc(!m);

	while(!menu&&szklarnia.podaj_odznake()==0 && szklarnia.podaj_zycie()==1)
	{



if(!czcionka.loadFromFile("sprajty/czcionki/Pascal.ttf"))
	{
		MessageBox(NULL,"Czcionka nieznaleziona","Blad",NULL);
		return;
	}

	    if(!tlogry.loadFromFile("sprajty/obrazy/tlo3.jpg"))
	{
		MessageBox(NULL,"Nie znaleziono tekstur","Blad",NULL);
		return;
	}

sprajttlo.setTexture(tlogry);
sprajttlo.setScale(1.6, 1.8);

 int ile=7;
  Text tekst[ile];
	string str[] = {"Podlej","Nawiez", "Noc", "Banan", "Truskawka", "Kwiat", "Marchewka"};
	for(int i=0;i<ile;i++)
	{
		tekst[i].setFont(czcionka);

		tekst[i].setString(str[i]);

		if(i<3)
        {
            tekst[i].setCharacterSize(45);
            tekst[i].setPosition(50+i*250, 310);
        }
		else
        {
            tekst[i].setCharacterSize(35);
            tekst[i].setPosition(50+(i-3)*150, 420);
        }

	}

sf::RectangleShape ramka(sf::Vector2f(300, 200));
ramka.setPosition(700,100);
ramka.setFillColor(sf::Color::White);
ramka.setOutlineThickness(10);
ramka.setOutlineColor(sf::Color(250, 150, 100));




Text tekst2;
tekst2.setFont(czcionka);
tekst2.setString( "Witaj w symulacji szklarni/r/n  dzien:"+naString(dzien)+"/r/n akcje: "+naString(szklarnia.podaj_ileakcji()) );
tekst2.setCharacterSize(15);
tekst2.setPosition(710, 110);
tekst2.setColor( sf::Color::Black );



if(szklarnia.podaj_ileakcji()<=0)
{
    dzien++;
    szklarnia.koniec_dnia();
    noc.ruszNoc(okno, m);
}




		Event zdarzenie;
		sf::Vector2f mysz(Mouse::getPosition(okno));

		while(okno.pollEvent(zdarzenie))
		{

if(tekst[0].getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
szklarnia.podlewanie_roslin(1);
			}

if(tekst[1].getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
szklarnia.nawozenie_roslin(1);
			}

if(tekst[2].getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
szklarnia.koniec_dnia();
dzien++;
noc.ruszNoc(okno, m);

			}

			if(zdarzenie.type == Event::KeyReleased && zdarzenie.key.code == Keyboard::Escape)


            {
               muzyka.stopmuzyka();
                menu = true;
            }


			if(zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::W)
			{

				postac.szpadel();
			}


			if(zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::Q)
			{

				postac.owoce();
			}



if(zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::R)
			{

				postac.warz();
			}






if(zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::G)
			{

				postac.podstawowy();

			}



		}

for(int i=0;i<ile;i++)
			if(tekst[i].getGlobalBounds().contains(mysz))
			{

				tekst[i].setColor(Color::White);
			}
			else tekst[i].setColor(Color::Black);





		okno.clear();
okno.draw(sprajttlo);

		okno.draw(postac);
			postac.aktualizuj();
			for(int i=0;i<ile;i++)
			okno.draw(tekst[i]);
			okno.draw(ramka);
okno.draw(tekst2);

			okno.draw(uprawa);
			okno.draw(akcje);



		okno.display();
	}
}
