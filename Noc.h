
#pragma once

 #include "Muzyka.h"




#include <Windows.h>
#include <SFML\Graphics.hpp>
#include <vector>
#include <string>

class Noc

{
public:
	Noc();
	~Noc(void);


void ruszNoc (sf::RenderWindow &okno, bool m);



	void aktualizuj();


	void zmien();
void podstawowy();
	void zmien2();
void zmientekst();
void zmientekst2();
void zmientekst3();
void zmientekst4();

private:
	sf::Sprite sprajt;
	sf::Sprite sprajt1;
sf::Texture tekstura1;
	sf::Sprite sprajt2;
	sf::Texture tekstura2;
		sf::Sprite sprajt3;
	sf::Texture tekstura3;
std::string str;
std::string str1;
std::string str2;
std::string str3;
std::string str4;
	Font czcionka;
Muzyka muzyka;
	bool sciszanie;


	sf::Texture tlo;
	sf::Sprite sprajttlo;

	float szybkosc;
	size_t klatka;

	sf::Clock zegar;
	sf::Clock zegar2;
//void draw(sf::RenderTarget &target, sf::RenderStates states) const;

};
