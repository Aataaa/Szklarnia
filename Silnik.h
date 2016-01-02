

#pragma once

 #include "Muzyka.h"
#include "Postac.h"
#include "Koniec.h"
#include "Uprawa.h"
#include "Akcje.h"
#include "Noc.h"
#include "szklarnia.h"
#include "Odznaki.h"
#include <Windows.h>
#include <sstream>

class Silnik
: public sf::RectangleShape
{
public:
	Silnik(sf::RenderWindow &ok, bool m);
	~Silnik(void);



	void ruszSilnik (sf::RenderWindow &okno, bool m);

private:
	Postac postac;
	Uprawa uprawa;
	Akcje akcje;
	Muzyka muzyka;
Noc noc;
Odznaki odznaki;
Koniec koniec;
	 Szklarnia szklarnia;



	 Font czcionka;


	sf::Texture tlogry;
	sf::Sprite sprajttlo;
	string nazwa;
       int wzrost;
       int zdrowie;
       int atrybut;
       int klasa;
       int akcja;
       int numer;
       int dzien=0;
       bool koniec_dnia=0;
};
