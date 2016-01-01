#pragma once

#include <SFML\Graphics.hpp>


class Odznaki: public sf::Drawable, sf:: Transformable

{
public:
	Odznaki(void);
	~Odznaki(void);








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





	virtual void draw(sf::RenderTarget &target,sf::RenderStates states) const;
};
