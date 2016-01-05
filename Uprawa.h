
#pragma once


#include <SFML\Graphics.hpp>
#include <vector>

class Uprawa: public sf::Drawable,
	sf::Transformable
{
public:
	Uprawa(void);
	~Uprawa(void);








	void rzodkiew();
	void papryka();
	void pomarancza();
	void gruszka();
	void slonecznik();
	void stokrotka();



private:
	sf::Sprite sprajtr;
	sf::Sprite sprajtr1;
	sf::Sprite sprajtr2;


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
sf::Texture tekstura7;
	sf::Sprite sprajt7;
sf::Texture tekstura8;
		sf::Sprite sprajt8;
sf::Texture tekstura9;
		sf::Sprite sprajt9;
sf::Texture tekstura10;
		sf::Sprite sprajt10;
sf::Texture tekstura11;
		sf::Sprite sprajt11;

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
