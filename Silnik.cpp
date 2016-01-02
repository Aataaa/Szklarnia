

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


sf::RectangleShape ramkaodzn(sf::Vector2f(300,160));
ramkaodzn.setPosition(700,500);
ramkaodzn.setFillColor(sf::Color::White);
ramkaodzn.setOutlineThickness(10);
ramkaodzn.setOutlineColor(sf::Color(250, 150, 100));
Text tekstodzn;
tekstodzn.setFont(czcionka);
tekstodzn.setString("Odznaki: \n\nkwiat                  owoc               warzywo");
tekstodzn.setCharacterSize(15);
tekstodzn.setPosition(700, 510);
tekstodzn.setColor( sf::Color::Black );





string typ[]={"Roslina", "Owoc", "Kwiat", "Warzywo"};
int ile2=5;
Text tekst2[ile2];
string str2[] = {"Witaj w symulacji szklarni \nPielegnuj 4 lub wiecej roslin:\n warzyw , owocow i kwiatow. \nPowodzenia!",
"Jesli chcesz podlac lub nawiezc rosline, \nkliknij na wybrana rosline, \na potem na podlej lub nawiez. \nMozesz takze zakonczyc dzien. \nPamietaj, ze liczba akcji jest ograniczona!",
"jesli chcesz zasadzic rosline, \nkliknij na przycisk, \nktorego jeszcze nie ma xd",
"dzien:"+naString(dzien)+"\nakcje: "+naString(szklarnia.podaj_ileakcji()),
"Roslina:"+szklarnia.opis(ktora_roslina-1)+" Typ: "+typ[szklarnia.opis6(ktora_roslina-1)]+"\nWoda: "+naString(szklarnia.opis2(ktora_roslina-1))+" Wzrost: "+naString(szklarnia.opis3(ktora_roslina-1))+
"\nZdrowie: "+naString(szklarnia.opis4(ktora_roslina-1))+"Cecha: "+naString(szklarnia.opis5(ktora_roslina-1))

};





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
      switch(szklarnia.podaj_los()){
    case 0: {noc.zmientekst(); noc.ruszNoc(okno, m);break;} //dalej wywala, ale nie wiem czemu
    case 1: {noc.zmientekst2();
        noc.podstawowy();noc.ruszNoc(okno, m);break;}
    case 2: {noc.zmientekst3();
       noc.zmien();noc.ruszNoc(okno, m);break;}
    case 3: {noc.zmientekst4();
       noc.zmien2();noc.ruszNoc(okno, m);break;}
      }
}
if(szklarnia.podaj_odow()==1)odznaki.zmienodow();
if(szklarnia.podaj_odkwi()==1)odznaki.zmienodkwi();
if(szklarnia.podaj_odwarz()==1)odznaki.zmienodwarz();
if(szklarnia.podaj_odznake()==1)odznaki.zmienodznaka();




		Event zdarzenie;
		sf::Vector2f mysz(Mouse::getPosition(okno));

		while(okno.pollEvent(zdarzenie))
		{


if(ramka.getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
		if(licznik_tekstu<ile2-1)
        {

            if(licznik_tekstu==0)   postac.podstawowy();
            if(licznik_tekstu==1)postac.owoce();
           else if(licznik_tekstu==2) postac.szpadel();
           else if(licznik_tekstu==3) postac.podstawowy();

            else postac.warz();
licznik_tekstu++;
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

		case 1:szklarnia.podlewanie_roslin(0); break;
		case 2:szklarnia.podlewanie_roslin(1); break;
		case 3:szklarnia.podlewanie_roslin(2); break;
		case 4:szklarnia.podlewanie_roslin(3); break;
		default: break;

		}
ktora_roslina=0;
			}

if(tekst[1].getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
switch(ktora_roslina)
		{

		case 1:szklarnia.nawozenie_roslin(0); break;
		case 2:szklarnia.nawozenie_roslin(1); break;
		case 3:szklarnia.nawozenie_roslin(2); break;
		case 4:szklarnia.nawozenie_roslin(3); break;
		default: break;

		}
	ktora_roslina=0;
				}

if(tekst[2].getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{

dzien++;
szklarnia.koniec_dnia();
  switch(szklarnia.podaj_los()){
   case 0: {noc.zmientekst(); noc.ruszNoc(okno, m);break;} //dalej wywala, ale nie wiem czemu
    case 1: {noc.zmientekst2();
        noc.podstawowy();noc.ruszNoc(okno, m);break;}
    case 2: {noc.zmientekst3();
       noc.zmien();noc.ruszNoc(okno, m);break;}
    case 3: {noc.zmientekst4();
       noc.zmien2();noc.ruszNoc(okno, m);break;}
       default: break;
      }

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


		}
szklarnia.stan_roslin();
szklarnia.wygrana();
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
				okno.draw(ramkaodzn);
okno.draw(odznaki);
			okno.draw(uprawa);
			okno.draw(akcje);


okno.draw(tekst2[licznik_tekstu]);
okno.draw(tekstodzn);

		okno.display();
	}
	if(szklarnia.podaj_odznake()==1)
    {
        koniec.podstawowy();
        koniec.zmientekst2();
        koniec.ruszKoniec(okno, m);
    }
    if(szklarnia.podaj_zycie()==0)
    {
        koniec.zmien();
        koniec.zmientekst();
        koniec.ruszKoniec(okno, m);
    }
}
