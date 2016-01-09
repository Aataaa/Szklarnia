
#pragma once

#include <SFML\Audio.hpp>

using namespace sf;

class Muzyka
{
public:
	Muzyka(bool laduj_wszystko=false,bool menu=false);
	~Muzyka(void);



	bool ladujmuzyke(bool menu);


	void puscmuzyke();
	void stopmuzyka();


	void glosnosc(bool wycisz);

private:
	Music muzyka;



};
