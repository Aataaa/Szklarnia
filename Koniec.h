#pragma once






#include <Windows.h>
#include <SFML\Graphics.hpp>
#include <vector>
#include <string>
 #include "Muzyka.h"
 #include "Odznaki.h"


class Koniec

{
public:
	Koniec();
	~Koniec(void);


void ruszKoniec (sf::RenderWindow &okno, bool m);

	void zmien();
void podstawowy();
void zmientekst();
void zmientekst2();



private:
	sf::Sprite sprajt;
	sf::Sprite sprajt1;
sf::Texture tekstura1;
	sf::Sprite sprajt2;
	sf::Texture tekstura2;

std::string str;
std::string str1;
std::string str2;

	Font czcionka;
Muzyka muzyka;
Odznaki odznaki;
	bool sciszanie;


	sf::Texture tlo;
	sf::Sprite sprajttlo;




};
