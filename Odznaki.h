#pragma once

#include <SFML\Graphics.hpp>


class Odznaki: public sf::Drawable, sf:: Transformable

{
public:
	Odznaki(void);
	~Odznaki(void);



void zmienodwarz();
	void zmienodow();
	void zmienodkwi();

		void zmienodznaka();




private:



sf::Sprite sprajto1;
	sf::Sprite sprajto2;
	sf::Sprite sprajto3;
	sf::Sprite sprajto4;
	sf::Sprite sprajt1;
sf::Texture tekstura1;
	sf::Sprite sprajt2;
	sf::Texture tekstura2;
	sf::Texture tekstura3;
		sf::Sprite sprajt3;
	sf::Texture tekstura4;
		sf::Sprite sprajt4;

sf::Texture tekstura5;
		sf::Sprite sprajt5;




	virtual void draw(sf::RenderTarget &target,sf::RenderStates states) const;
};
