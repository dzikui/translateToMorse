#ifndef MorseFactory_H
#define MorseFactory_H
#include "MorseBase.h"
#include "MorseDisc.h"
#include "MorseBeep.h"
#include "MorseConsole.h"
#include "MorseCapslock.h"
#include <string>

class MorseFactory : public MorseBase
{
public:
	enum Numberic{beep,console,disk,capslock};	 // enumerator przypisujacy wartosc do trybu pracy.
	void setOutput(Numberic);		// funkcja sprawdzajaca jaki tryb pracy ma sie wykonac

	void setExternalInfo(std::string);	// funkcja zalezna od trybu pracy. Mo¿e wczytaæ nazwe pliku, badz ustawic parametry.					
	virtual void convert(std::string);	// konwersja napisu do stringa							
	virtual void convert(int);	// konwersja inta do stringa
	virtual void convert(double);	// konwersja doubla do stringa

	MorseFactory(MorseFactory&);	// konstruktor kopiujacy				
	MorseFactory();		// konstruktor bezparametryczny											
	~MorseFactory();	// destruktor 										
protected:
	MorseBase * _indicator;		// utworzenie obiektu, wskaznika klasy MorseBase									
};
#endif //!MorseFactory_H