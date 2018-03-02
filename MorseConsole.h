#pragma once
#ifndef MorseConsole_H
#define MorseConsole_H
#include <string>
#include "MorseBase.h"




class MorseConsole : public MorseBase // klasa wyswietlajaca 
{
public:
	virtual void view(char);		// funkcja wyswietlajaca morsa
	virtual void convert(std::string);	// funkcja konwertujaca tekstu do jezyka morsa
	virtual void convert(int);		// funkcja rzutujaca typ int na typ string
	virtual void convert(double) ;      // funkcja rzutujaca typ double na typ string
	MorseConsole(MorseConsole&);	// konstruktor kopiujacy
	MorseConsole();		// konstruktor domyslny	
	~MorseConsole();	// destruktor	
};

#endif //!MorseBase_H