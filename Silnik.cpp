

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

bool czydodaj=0;
int licznikowoc=0;
int licznikwarzywo=0;
int licznikkwiat=0;
	bool menu = false;
int ktora_roslina=0;
int licznik_tekstu=0;
int i1=7;
int i2=7;
int i3=7;
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


	    if(!dodaj.loadFromFile("sprajty/gracz/48.png"))
	{
		MessageBox(NULL,"Nie znaleziono tekstury","Blad",NULL);
		return;
	}

sprajtdodaj.setTexture(dodaj);
sprajtdodaj.setTextureRect(IntRect(0,0,577,574));
sprajtdodaj.setScale(0.4, 0.4);
sprajtdodaj.setPosition(950,500);




int ilewybor=7;
string wybor[]={" ","Rzodkiew ", "Papryka ", "Pomarancza ", "Gruszka ", "Slonecznik", "Stokrotka"};
Text jakaroslina[ilewybor];
	for(int n=0;n<ilewybor;n++)
	{
		jakaroslina[n].setFont(czcionka);

		jakaroslina[n].setString(wybor[n]);


            jakaroslina[n].setCharacterSize(15);
            if(n<4)
           {
                jakaroslina[n].setPosition(630+(n-1)*100, 340);
           }
            else
            {
              jakaroslina[n].setPosition(630+(n-4)*100, 370);
            }

	}


 int ile=14;
  Text tekst[ile];
	string str[] = {"Podlej","Nawiez", "Noc", "Banan", "Truskawka", "Kwiat", "Marchewka"};
	for(int i=0;i<ile;i++)
	{
		tekst[i].setFont(czcionka);
        if(i<=6)
        {
            tekst[i].setString(str[i]);

        }

		else
        tekst[i].setString(wybor[i-7]);


        if(i<3)
        {
            tekst[i].setCharacterSize(40);
            tekst[i].setPosition(50+i*200, 350);
        }
		else
        {
            tekst[i].setCharacterSize(20);
            tekst[i].setPosition(50+(i-3)*110, 520);
        }


	}

sf::RectangleShape ramka(sf::Vector2f(320, 200));
ramka.setPosition(620,200);
ramka.setFillColor(sf::Color::White);
ramka.setOutlineThickness(10);
ramka.setOutlineColor(sf::Color(250, 150, 100));


sf::RectangleShape ramkaodzn(sf::Vector2f(300,160));
ramkaodzn.setPosition(970, 7);
ramkaodzn.setFillColor(sf::Color::White);
ramkaodzn.setOutlineThickness(10);
ramkaodzn.setOutlineColor(sf::Color(250, 150, 100));


Text tekstodzn;
tekstodzn.setFont(czcionka);
tekstodzn.setString("Odznaki: \n\nkwiat                  owoc               warzywo");
tekstodzn.setCharacterSize(15);
tekstodzn.setPosition(970, 10);
tekstodzn.setColor( sf::Color::Black );




string typ[]={"Roslina", "Owoc", "Kwiat", "Warzywo"};

int ile2=7;
Text tekst2[ile2];
string str2[] = {    "Witaj w symulacji szklarni \nPielegnuj 4 lub wiecej roslin:\n warzyw , owocow i kwiatow. \nPowodzenia!",
"Jesli chcesz podlac lub nawiezc rosline, \nkliknij na wybrana rosline, \na potem na podlej lub nawiez. \nMozesz takze zakonczyc dzien. \nPamietaj, ze liczba akcji jest ograniczona!",
"jesli chcesz zasadzic rosline, \nkliknij na przycisk plusa",
"dzien:"+naString(dzien)+"\nakcje: "+naString(szklarnia.podaj_ileakcji()),
"Roslina:"+szklarnia.opis(ktora_roslina-1)+" Typ: "+typ[szklarnia.opis6(ktora_roslina-1)]+"\nWoda: "+naString(szklarnia.opis2(ktora_roslina-1))+" Wzrost: "+naString(szklarnia.opis3(ktora_roslina-1))+
"\nZdrowie: "+naString(szklarnia.opis4(ktora_roslina-1))+"Cecha: "+naString(szklarnia.opis5(ktora_roslina-1)),
"Masz:"+naString(szklarnia.podaj_elementy())+" roslin",
"Masz do wyboru 2 warzywa, 2 kwiaty i \n2 owoce. Mozesz posadzic 1 roslne kazdego rodzaju."

};





for(int j=0;j<ile2;j++)
	{
		tekst2[j].setFont(czcionka);

		tekst2[j].setString(str2[j]);

		tekst2[j].setCharacterSize(15);

            tekst2[j].setPosition(630, 220);

            tekst2[j].setColor( sf::Color::Black );
        }





if(szklarnia.podaj_ileakcji()<=0)
{
    dzien++;
    szklarnia.koniec_dnia();
      switch(szklarnia.podaj_los()){
    case 0: {noc.zmientekst(); noc.ruszNoc(okno, m);break;}
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




		Event zdarzenie;
		sf::Vector2f mysz(Mouse::getPosition(okno));

		while(okno.pollEvent(zdarzenie))
		{


if(ramka.getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
		if(licznik_tekstu<ile2-2)
        {

            if(licznik_tekstu==0)   postac.podstawowy();
            if(licznik_tekstu==2)postac.owoce();
           else if(licznik_tekstu==4) postac.szpadel();
           else if(licznik_tekstu==6) postac.podstawowy();

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
		case 5:szklarnia.podlewanie_roslin(4); break;
		case 6:szklarnia.podlewanie_roslin(5); break;
		case 7:szklarnia.podlewanie_roslin(6); break;
		/*
		case 8:szklarnia.podlewanie_roslin(7); break;
		case 9:szklarnia.podlewanie_roslin(8); break;
		case 10:szklarnia.podlewanie_roslin(9); break;
		*/
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
		case 5:szklarnia.nawozenie_roslin(4); break;
		case 6:szklarnia.nawozenie_roslin(5); break;
		case 7:szklarnia.nawozenie_roslin(6); break;
		/*
		case 8:szklarnia.nawozenie_roslin(7); break;
		case 9:szklarnia.nawozenie_roslin(8); break;
		case 10:szklarnia.nawozenie_roslin(9); break;
		*/
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

if(tekst[7].getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
ktora_roslina=licznikwarzywo;

			}


if(tekst[8].getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
ktora_roslina=licznikwarzywo;

			}



if(tekst[9].getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
ktora_roslina=licznikowoc;

			}


if(tekst[10].getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
ktora_roslina=licznikowoc;

			}
if(tekst[11].getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
ktora_roslina=licznikkwiat;

			}


if(tekst[12].getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
ktora_roslina=licznikkwiat;

			}





if(sprajtdodaj.getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
		czydodaj=!czydodaj;
		licznik_tekstu=ile2-1;
			}



    if(jakaroslina[1].getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left&&licznikwarzywo==0)
			{
uprawa.rzodkiew();
Rosliny *warzywko= new Warzywa("Rzodkiewka",(rand()%5)+4 , (rand()%2)+5);
szklarnia.zasadz_rosline(warzywko);
licznikwarzywo=szklarnia.podaj_elementy();
i1=8;

			}

   if(jakaroslina[2].getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left&&licznikwarzywo==0)
			{
uprawa.papryka();
Rosliny *warzywko= new Warzywa("Papryka",(rand()%2)+3 , (rand()%7)+7);
szklarnia.zasadz_rosline(warzywko);
licznikwarzywo=szklarnia.podaj_elementy();
i1=9;
			}


   if(jakaroslina[3].getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left&&licznikowoc==0)
			{
uprawa.pomarancza();
Rosliny *owocek= new Owoce("Pomarancza",(rand()%5)+8 , (rand()%3)+1);
szklarnia.zasadz_rosline(owocek);
licznikowoc=szklarnia.podaj_elementy();
i2=10;
			}

		   if(jakaroslina[4].getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left&&licznikowoc==0)
			{
uprawa.gruszka();
Rosliny *owocek= new Owoce("Gruszka",(rand()%4)+1 , (rand()%3)+9);
szklarnia.zasadz_rosline(owocek);
licznikowoc=szklarnia.podaj_elementy();
i2=11;
		}

			   if(jakaroslina[5].getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left&&licznikkwiat==0)
			{
uprawa.slonecznik();
Rosliny *kwiatek= new Kwiaty("Slonecznik",(rand()%9)+6 , (rand()%4)+2);
szklarnia.zasadz_rosline(kwiatek);
licznikkwiat=szklarnia.podaj_elementy();
i3=12;
			}



 if(jakaroslina[6].getGlobalBounds().contains(mysz) &&
zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left&&licznikkwiat==0)
			{
uprawa.stokrotka();
Rosliny *kwiatek= new Kwiaty("Stokrotka",(rand()%5)+1 , (rand()%8)+7);
szklarnia.zasadz_rosline(kwiatek);
licznikkwiat=szklarnia.podaj_elementy();
i3=13;
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

for(int n=0;n<ilewybor;n++)
			if(jakaroslina[n].getGlobalBounds().contains(mysz))
			{

				jakaroslina[n].setColor(Color::Magenta);
			}
			else jakaroslina[n].setColor(Color::Black);




		okno.clear();
okno.draw(sprajttlo);

		okno.draw(postac);
			postac.aktualizuj();
			okno.draw(akcje);
				okno.draw(uprawa);
			for(int i=0;i<ile-6;i++)
            {

            okno.draw(tekst[i]);
            }
 okno.draw(tekst[i1]);
  okno.draw(tekst[i2]);
 okno.draw(tekst[i3]);

			okno.draw(ramka);
				okno.draw(ramkaodzn);
okno.draw(odznaki);

			okno.draw(sprajtdodaj);

if(czydodaj==1)
{
    for(int n=0;n<ilewybor;n++)
        	okno.draw(jakaroslina[n]);
}



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
