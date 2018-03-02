#ifndef MorseBeep_H
#define MorseBeep_H
#include "MorseConsole.h"
#include "MorseBase.h"





class MorseBeep : public MorseBase // klasa odpowiedzialna za beepanie glosnikiem
{
public:
	virtual void convert(std::string);	// funkcja wirtualna odpowiedzialna za konwersje tekstu na beepanie
	virtual void convert(int);	// funkcja rzutujaca typ int na typ string
	virtual void convert(double);	// funkcja rzutujaca typ double na typ string	
	void toBeep(char);	// funkcja beepajaca tekst w jezyku morsa
	void beep();	// funkcja t³umaczaca jezyk morsa na beepanie
	MorseBeep(MorseConsole&);	// konstruktor kopiujacy
	MorseBeep();	// konstruktor domyslny	
	~MorseBeep();	// destruktor	
};

#endif //!MorseBase_H
