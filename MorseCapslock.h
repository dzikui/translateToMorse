#ifndef MorseCapslock_H
#define MorseCapslock_H
#include <string>
#include "MorseBase.h"





class MorseCapslock : public MorseBase // klasa odpowiedzialna za miganie dioda capslocka w jezyku morsa
{
public:
	virtual void convert(std::string);		// funkcja konwertujaca tekst na miganie dioda
	virtual void convert(int);		// funkcja rzutujaca typ int na typ string
	virtual void convert(double);		// funkcja rzutujaca typ double na typ string	
	virtual void toShine(char);		// funkcja t³uamczaca morsa na miganie dioda	
	MorseCapslock(MorseCapslock&);		// konstruktor kopiujacy
	MorseCapslock();		// konstruktor domyslny	
	~MorseCapslock();		// desrtruktor	
};
#endif //!MorseCapslock_H

