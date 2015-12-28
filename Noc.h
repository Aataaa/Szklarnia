
#pragma once

 #include "Muzyka.h"




#include <Windows.h>

#include <SFML\Graphics.hpp>
#include <vector>

class Noc
//: public sf::Drawable,	sf::Transformable
{
public:
	Noc();
	~Noc(void);


void ruszNoc (sf::RenderWindow &okno, bool m);



	void aktualizuj();


	void zmien();
void podstawowy();


private:
	sf::Sprite sprajt;
	sf::Sprite sprajt1;
sf::Texture tekstura1;
	sf::Sprite sprajt2;
	sf::Texture tekstura2;

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
