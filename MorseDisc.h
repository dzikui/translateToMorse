#ifndef MorseDisc_H
#define MorseDisc_H
#include "MorseBase.h"





class MorseDisc : public MorseBase // klasa odpowiedzialna za zapis morsa do pliku
{
public:
	virtual void toSave(std::string, std::string);	// funkcja zapisujaca morsa do pliku
	virtual void convert(std::string);		// funkcja konwertujaca tekst na morsa 
	virtual void convert(int);		// funkcja rzutujaca typ int na typ string
	virtual void convert(double);	// funkcja rzutujaca typ double na typ string
	MorseDisc(MorseDisc&);		// konstruktor kopiujacy
	MorseDisc();		// konstruktor besparametryczny
	~MorseDisc();		// destruktor
};
#endif //!MORSED_H