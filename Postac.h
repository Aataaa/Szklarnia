
#pragma once

#include <SFML\Graphics.hpp>
#include <Windows.h>


class Postac: public sf::Drawable,
	sf::Transformable
{
public:
	Postac(void);
	~Postac(void);



	void aktualizuj();

	void podstawowy();
	void szpadel();
	void owoce();
	void warz();


protected:


private:
	sf::Sprite sprajt;
	sf::Sprite sprajt1;
sf::Texture tekstura1;
	sf::Sprite sprajt2;
	sf::Texture tekstura2;
	sf::Texture tekstura3;
		sf::Sprite sprajt3;
		sf::Texture tekstura4;
		sf::Sprite sprajt4;



	float szybkosc;
	size_t klatka;

	sf::Clock zegar;

	virtual void draw(sf::RenderTarget &target,sf::RenderStates states) const;
};
