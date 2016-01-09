

#pragma once


#include <fstream>
#include <SFML\Graphics.hpp>
#include <Windows.h>
#include <string>
#include "Silnik.h"

using namespace std;
using namespace sf;

class Gra
{
public:
	Gra(void);
	~Gra(void);
;
	void rozgrywka();

protected:
	enum StatusGry {MENU,GRA,KONIEC_GRY,KONIEC};
	StatusGry status;

private:
	Font czcionka;
Muzyka muzyka;
	bool sciszanie;


	sf::Texture tlo;
	sf::Sprite sprajt;
	void menu();
	void wejscie();
};

