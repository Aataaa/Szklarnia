
#pragma once


#include <SFML\Graphics.hpp>
#include <vector>

class Uprawa: public sf::Drawable,
	sf::Transformable
{
public:
	Uprawa(void);
	~Uprawa(void);








	void ktoraros();
	void owoce();
	void warz();




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
sf::Texture tekstura5;
		sf::Sprite sprajt5;
sf::Texture tekstura6;
		sf::Sprite sprajt6;



	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
