

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
bool czy_zyje[10];

int i0=3;
int i1=4;
int i2=5;
int i3=6;
int i4=7;
int i5=7;
int i6=7;
int i7=7;
int i8=7;
int i9=7;

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
sprajttlo.setScale(1.8, 1.8);


	    if(!dodaj.loadFromFile("sprajty/gracz/plus.png"))
	{
		MessageBox(NULL,"Nie znaleziono tekstury","Blad",NULL);
		return;
	}

sprajtdodaj.setTexture(dodaj);
sprajtdodaj.setTextureRect(IntRect(0,0,577,574));
sprajtdodaj.setScale(0.4, 0.4);
sprajtdodaj.setPosition(1150,500);




int ilewybor=7;
string wybor[]={"","Rzodkiew ", "Papryka ", "Pomarancza ", "Gruszka ", "Slonecznik", "Stokrotka"};
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
	string str[] = {"Podlej","Nawiez", "Noc", "Banan", "Truskawka", "Roza", "Marchewka"};
	for(int i=0;i<ile;i++)
	{
	    int zmienna=i;
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
            tekst[i].setPosition(50+i*200, 300);
        }
		else if(i<7)
        {
            tekst[i].setCharacterSize(18);


            tekst[i].setPosition(50+(i-3)*120, 500);

        }
        else
        {
            tekst[i].setCharacterSize(18);

if(i==9||i==11||i==13)zmienna--;
            tekst[i].setPosition(200+(zmienna-3)*70, 500);

        }

	}

sf::RectangleShape ramka(sf::Vector2f(330, 200));
ramka.setPosition(620,200);
ramka.setFillColor(sf::Color::White);
ramka.setOutlineThickness(10);
ramka.setOutlineColor(sf::Color(250, 150, 100));


sf::RectangleShape ramkaodzn(sf::Vector2f(300,145));
ramkaodzn.setPosition(970, 7);
ramkaodzn.setFillColor(sf::Color::White);
ramkaodzn.setOutlineThickness(10);
ramkaodzn.setOutlineColor(sf::Color(250, 150, 100));


Text tekstodznaki;
tekstodznaki.setFont(czcionka);
tekstodznaki.setString("Odznaki: \nkwiat                  owoc               warzywo");
tekstodznaki.setCharacterSize(15);
tekstodznaki.setPosition(970, 10);
tekstodznaki.setColor( sf::Color::Black );




string typ[]={"Roslina", "Kwiat", "Owoc", "Warzywo"};

int ile2=9;
Text tekst2[ile2];
string str2[] = {    "Witaj w symulacji szklarni \nPielegnuj 4 lub wiecej roslin:\n warzyw , owocow i kwiatow. \nPowodzenia!",
"Jesli bedziesz zle zajmowac sie\ndana roslina, zgnije. \nJesli wszystkie Twoje \nrosliny zgnija, przegrasz.",
"Aby wygrac, musisz zdobyc odznake \nSuper Ogrodnika. Dostaniesz ja, jesli \ndostaniesz odznaki Kwiat, Owoc i \nWarzywo. Kazda z nich mozesz otrzymac \njesli jedno z twoich kwiatow \nowocow i warzyw rosnie wyjatkowo \ndobrze",
"Jesli chcesz podlac lub nawiezc rosline, \nkliknij na wybrana rosline, \na potem na podlej lub nawiez. \nMozesz takze zakonczyc dzien. \nPamietaj, ze liczba akcji jest \nograniczona!",
"Jesli chcesz zasadzic rosline, \nkliknij na przycisk plusa",
"dzien:"+naString(dzien)+"\nakcje: "+naString(szklarnia.podaj_ileakcji()),
"Roslina:"+szklarnia.opis_nazwa(ktora_roslina-1)+" Typ: "+typ[szklarnia.opis_klasa(ktora_roslina-1)]+"\nWoda: "+naString(szklarnia.opis_woda(ktora_roslina-1))+" Wzrost: "+naString(szklarnia.opis_wzrost(ktora_roslina-1))+
"\nZdrowie: "+naString(szklarnia.opis_zdrowie(ktora_roslina-1))+"Cecha: "+naString(szklarnia.opis_cecha(ktora_roslina-1)),
"Masz:"+naString(szklarnia.podaj_elementy())+" roslin",
"Masz do wyboru 2 warzywa, 2 kwiaty i \n2 owoce. Mozesz posadzic 1 roslne \nkazdego rodzaju."

};





for(int j=0;j<ile2;j++)
	{
		tekst2[j].setFont(czcionka);

		tekst2[j].setString(str2[j]);

		tekst2[j].setCharacterSize(15);

            tekst2[j].setPosition(630, 220);

            tekst2[j].setColor( sf::Color::Black );
        }


szklarnia.stan_roslin();
szklarnia.wygrana();


if(szklarnia.podaj_ileakcji()<=0)
{
    dzien++;
    szklarnia.koniec_dnia();
      switch(szklarnia.podaj_los()){
    case 0: {noc.podstawowy(); noc.ruszNoc(okno, m);break;}
    case 1: {noc.zmien(); noc.ruszNoc(okno, m);break;}
    case 2: {noc.zmien2();
       noc.ruszNoc(okno, m);break;}
    case 3: {noc.zmien3();
      noc.ruszNoc(okno, m);break;}
      }
}
if(szklarnia.podaj_odznake_o()==1)odznaki.zmien_odznake_o();
if(szklarnia.podaj_odznake_k()==1)odznaki.zmien_oznake_k();
if(szklarnia.podaj_odznake_w()==1)odznaki.zmien_odznake_w();


for(int n=0; n<10;n++)
{
czy_zyje[n]=0;
  }


for(int n=0; n<szklarnia.podaj_elementy();n++)
{
   if(szklarnia.opis_nazwa(n)=="Banan") czy_zyje[0]=1;
   if(szklarnia.opis_nazwa(n)== "Truskawka") czy_zyje[1]=1;
   if(szklarnia.opis_nazwa(n)=="Roza") czy_zyje[2]=1;
   if(szklarnia.opis_nazwa(n)== "Marchewka") czy_zyje[3]=1;
   if(szklarnia.opis_nazwa(n)=="Rzodkiewka") czy_zyje[4]=1;
   if(szklarnia.opis_nazwa(n)=="Papryka") czy_zyje[5]=1;
   if(szklarnia.opis_nazwa(n)=="Pomarancza") czy_zyje[6]=1;
   if(szklarnia.opis_nazwa(n)=="Gruszka") czy_zyje[7]=1;
   if(szklarnia.opis_nazwa(n)=="Slonecznik") czy_zyje[8]=1;
   if(szklarnia.opis_nazwa(n)=="Stokrotka") czy_zyje[9]=1;
}


if(czy_zyje[0]==0){i0=7; uprawa.umiera(0);}
if(czy_zyje[1]==0){i1=7;uprawa.umiera(1);}
if(czy_zyje[2]==0){i2=7;uprawa.umiera(2);}
if(czy_zyje[3]==0){i3=7;uprawa.umiera(3);}
if(czy_zyje[4]==0 && czy_zyje[5]==0){i4=7; i5=7;uprawa.umiera(4);}
if(czy_zyje[6]==0 &&czy_zyje[7]==0){i6=7; i7=7;uprawa.umiera(5);}
if(czy_zyje[8]==0 &&czy_zyje[9]==0){i6=7; i7=7;uprawa.umiera(6);}






		Event zdarzenie;
		sf::Vector2f mysz(Mouse::getPosition(okno));

		while(okno.pollEvent(zdarzenie))
		{


if(ramka.getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
		if(licznik_tekstu<ile2-2)
        {

            if(licznik_tekstu>=0&&licznik_tekstu<2)   postac.podstawowy();
            if(licznik_tekstu>=2&&licznik_tekstu<4)postac.owoce();
           else if(licznik_tekstu>=5&&licznik_tekstu<7) postac.szpadel();


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
   case 0: {noc.podstawowy(); noc.ruszNoc(okno, m);break;} //dalej wywala, ale nie wiem czemu
    case 1: {noc.zmien();
        noc.ruszNoc(okno, m);break;}
    case 2: {noc.zmien2();
       noc.ruszNoc(okno, m);break;}
    case 3: {noc.zmien3();
      noc.ruszNoc(okno, m);break;}
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

if(tekst[8].getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
ktora_roslina=licznikwarzywo;

			}


if(tekst[9].getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
ktora_roslina=licznikwarzywo;

			}



if(tekst[10].getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
ktora_roslina=licznikowoc;

			}


if(tekst[11].getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
ktora_roslina=licznikowoc;

			}
if(tekst[12].getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
ktora_roslina=licznikkwiat;

			}


if(tekst[13].getGlobalBounds().contains(mysz) &&
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
i4=8;

			}

   if(jakaroslina[2].getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left&&licznikwarzywo==0)
			{
uprawa.papryka();
Rosliny *warzywko= new Warzywa("Papryka",(rand()%2)+3 , (rand()%7)+7);
szklarnia.zasadz_rosline(warzywko);
licznikwarzywo=szklarnia.podaj_elementy();
i5=9;
			}


   if(jakaroslina[3].getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left&&licznikowoc==0)
			{
uprawa.pomarancza();
Rosliny *owocek= new Owoce("Pomarancza",(rand()%5)+8 , (rand()%3)+1);
szklarnia.zasadz_rosline(owocek);
licznikowoc=szklarnia.podaj_elementy();
i6=10;
			}

		   if(jakaroslina[4].getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left&&licznikowoc==0)
			{
uprawa.gruszka();
Rosliny *owocek= new Owoce("Gruszka",(rand()%4)+1 , (rand()%3)+9);
szklarnia.zasadz_rosline(owocek);
licznikowoc=szklarnia.podaj_elementy();
i7=11;
		}

			   if(jakaroslina[5].getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left&&licznikkwiat==0)
			{
uprawa.slonecznik();
Rosliny *kwiatek= new Kwiaty("Slonecznik",(rand()%9)+6 , (rand()%4)+2);
szklarnia.zasadz_rosline(kwiatek);
licznikkwiat=szklarnia.podaj_elementy();
i8=12;
			}



 if(jakaroslina[6].getGlobalBounds().contains(mysz) &&
zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left&&licznikkwiat==0)
			{
uprawa.stokrotka();
Rosliny *kwiatek= new Kwiaty("Stokrotka",(rand()%5)+1 , (rand()%8)+7);
szklarnia.zasadz_rosline(kwiatek);
licznikkwiat=szklarnia.podaj_elementy();
i9=13;
			}






			if(zdarzenie.type == Event::KeyReleased && zdarzenie.key.code == Keyboard::Escape)


            {
               muzyka.stopmuzyka();
                menu = true;
            }


		}

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

for(int i=0; i<3; i++)
    okno.draw(tekst[i]);

okno.draw(tekst[i0]);
           okno.draw(tekst[i1]);
  okno.draw(tekst[i2]);
 okno.draw(tekst[i3]);
  okno.draw(tekst[i4]);
  okno.draw(tekst[i5]);
 okno.draw(tekst[i6]);
   okno.draw(tekst[i7]);
 okno.draw(tekst[i8]);
   okno.draw(tekst[i9]);



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
okno.draw(tekstodznaki);

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
