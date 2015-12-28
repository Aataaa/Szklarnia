

#include "Gra.h"

RenderWindow okno(VideoMode(1280,720),"Szklarnia",sf::Style::Fullscreen);

Gra::Gra(void)
{
	status =KONIEC;

	if(!czcionka.loadFromFile("sprajty/czcionki/FLOWER.ttf"))
	{
		MessageBox(NULL,"Czcionka nieznaleziona","Blad",NULL);
		return;
	}

	status = MENU;
muzyka.ladujmuzyke(true);
	muzyka.puscmuzyke();
}


Gra::~Gra(void)
{
    muzyka.stopmuzyka();
    	fstream plik("dzwieki.cfg",ios::out | ios::trunc);
	plik<<sciszanie;
	plik.close();
}


void Gra::rozgrywka()
{
	while(status != KONIEC)
	{
		switch (status)
		{
		case MENU:
			menu();
			break;
		case GRA:
			wejscie();
			break;
		}
	}
}


void Gra::menu()
{
	Text tytul("Szklarnia",czcionka,100);
	tytul.setStyle(Text::Bold);
tytul.setColor(Color::Black);
	tytul.setPosition(1280/2-tytul.getGlobalBounds().width/2,20);


if(!tlo.loadFromFile("sprajty/obrazy/s.jpg"))
	{
		MessageBox(NULL,"Nie znaleziono tekstury","Blad",NULL);
		return;
	}



sprajt.setTexture(tlo);
sprajt.setScale(2.2, 1.8);

	const int ile = 2;

	Text tekst[ile];

	string str[] = {"Graj","Wyjscie"};
	for(int i=0;i<ile;i++)
	{
		tekst[i].setFont(czcionka);
		tekst[i].setCharacterSize(95);

		tekst[i].setString(str[i]);
		tekst[i].setPosition(1280/2-tekst[i].getGlobalBounds().width/2,250+i*120);
	}

		bool m;
	//opcje
	fstream plik("dzwieki.cfg");
	if(plik.is_open())
		plik >> m;
	else
		m=true;
	plik.close();

	Text opcje;
	string dzwieki="Muzyka";
	if(m==true)
			opcje.setString(dzwieki+" Wlaczona");
	else
		opcje.setString(dzwieki+" Wylaczona");

	opcje.setFont(czcionka);
	opcje.setCharacterSize(20);
	opcje.setPosition(10,10);
	muzyka.glosnosc(!m);

	while(status == MENU)
	{
		Vector2f mysz(Mouse::getPosition(okno));
		Event zdarzenie;

		while(okno.pollEvent(zdarzenie))
		{
			//Wciśnięcie ESC lub przycisk X
			if(zdarzenie.type == Event::Closed || zdarzenie.type == Event::KeyPressed &&
				zdarzenie.key.code == Keyboard::Escape)
				status = KONIEC;

			//kliknięcie MENU
			else if(tekst[0].getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
				muzyka.stopmuzyka();

				status = GRA;
			}

			//kliknięcie EXIT
			else if(tekst[1].getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
				status = KONIEC;

			}

			//wyciszenie/wlaczenie muzyki
			else if(opcje.getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
				if(m)
				{
					m=false;
					opcje.setString(dzwieki+" Wlaczona");
				}
				else
				{
					m=true;
					opcje.setString(dzwieki+" Wylaczona");
				}
				muzyka.glosnosc(!m);

			}
		}
		for(int i=0;i<ile;i++)
			if(tekst[i].getGlobalBounds().contains(mysz))
			{

				tekst[i].setColor(Color::White);
			}
			else tekst[i].setColor(Color::Black);

		if(opcje.getGlobalBounds().contains(mysz))
		{
			opcje.setColor(Color::White);
		}
		else
			opcje.setColor(Color::Black);

		okno.clear();
 okno.draw(sprajt);
		okno.draw(tytul);
		for(int i=0;i<ile;i++)
			okno.draw(tekst[i]);

		okno.draw(opcje);

		okno.display();
	}
	sciszanie = m;
}


void Gra::wejscie()
{
	Silnik silnik(okno, sciszanie);

	status = MENU;
}
