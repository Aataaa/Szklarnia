

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
int ktora_roslina=0;
int licznik_tekstu=0;

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

sf::RectangleShape ramka(sf::Vector2f(320, 200));
ramka.setPosition(700,100);
ramka.setFillColor(sf::Color::White);
ramka.setOutlineThickness(10);
ramka.setOutlineColor(sf::Color(250, 150, 100));



int ile2=4;
Text tekst2[ile2];
string str2[] = {"Witaj w symulacji szklarni \nPielegnuj 4 lub wiecej roslin:\n warzyw , owocow i kwiatow. \nPowodzenia!",
"Jesli chcesz podlac lub nawiezc rosline, \nkliknij na wybrana rosline, \na potem na podlej lub nawiez. \nMozesz takze zakonczyc dzien. \nPamietaj, ze liczba akcji jest ograniczona!",
"jesli chcesz zasadzic rosline, \nkliknij na przycisk, \nktorego jeszcze nie ma xd",
"dzien:"+naString(dzien)+"\nakcje: "+naString(szklarnia.podaj_ileakcji())};
for(int j=0;j<ile2;j++)
	{
		tekst2[j].setFont(czcionka);

		tekst2[j].setString(str2[j]);

		tekst2[j].setCharacterSize(15);

            tekst2[j].setPosition(700, 110);

            tekst2[j].setColor( sf::Color::Black );
        }





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


if(ramka.getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
		if(licznik_tekstu<ile2-1)
        {
            licznik_tekstu++;
            if(licznik_tekstu==0)   postac.podstawowy();
            if(licznik_tekstu==1)postac.owoce();
           else if(licznik_tekstu==2) postac.szpadel();
            else postac.warz();

        }
		else
        {
            licznik_tekstu=0;

        }
			}


if(tekst[0].getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
		switch(ktora_roslina)
		{
		case 0: break;
		case 1:szklarnia.podlewanie_roslin(1); break;
		case 2:szklarnia.podlewanie_roslin(2); break;
		case 3:szklarnia.podlewanie_roslin(3); break;
		case 4:szklarnia.podlewanie_roslin(4); break;
		default: break;

		}
ktora_roslina=0;
			}

if(tekst[1].getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
switch(ktora_roslina)
		{
		case 0: break;
		case 1:szklarnia.nawozenie_roslin(1); break;
		case 2:szklarnia.nawozenie_roslin(2); break;
		case 3:szklarnia.nawozenie_roslin(3); break;
		case 4:szklarnia.nawozenie_roslin(4); break;
		default: break;

		}
	ktora_roslina=0;
				}

if(tekst[2].getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
szklarnia.koniec_dnia();
dzien++;
noc.ruszNoc(okno, m);

			}

if(tekst[3].getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
ktora_roslina=1;
			}

if(tekst[4].getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
ktora_roslina=2;
			}

if(tekst[5].getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
ktora_roslina=3;

			}
if(tekst[6].getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
ktora_roslina=4;

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

			okno.draw(uprawa);
			okno.draw(akcje);

okno.draw(tekst2[licznik_tekstu]);


		okno.display();
	}
}
