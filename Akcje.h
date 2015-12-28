#pragma once

#include <SFML\Graphics.hpp>
#include <vector>

class Akcje: public sf::Drawable,
	sf::Transformable
{
public:
	Akcje(void);
	~Akcje(void);








private:
	sf::Sprite sprajt;
	sf::Sprite sprajt1;
sf::Texture tekstura1;
	sf::Sprite sprajt2;
	sf::Texture tekstura2;
	sf::Texture tekstura3;
		sf::Sprite sprajt3;






	virtual void draw(sf::RenderTarget &target,sf::RenderStates states) const;
};
