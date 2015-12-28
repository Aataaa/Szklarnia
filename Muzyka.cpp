
#include "Muzyka.h"
#include <string>

using namespace std;

Muzyka::Muzyka(bool laduj,bool menu)
{
	if(laduj)
	{
		ladujmuzyke(menu);

	}
}


Muzyka::~Muzyka(void)
{
}


bool Muzyka::ladujmuzyke(bool menu)
{
	string sciezka;
	if(menu)
		sciezka="sprajty/muzyka/1.ogg";
	else
		sciezka="sprajty/muzyka/2.ogg";

	if(!muzyka.openFromFile(sciezka))
		return false;
	muzyka.setLoop(true);
	return true;
}




void Muzyka::puscmuzyke()
{
	muzyka.play();
}


void Muzyka::stopmuzyka()
{
	muzyka.stop();
}

void Muzyka::glosnosc(bool wycisz)
{
	if(wycisz)
	{
		muzyka.stop();
		muzyka.setVolume(0);

	}
	else
	{
		muzyka.play();
		muzyka.setVolume(100);

	}
}
