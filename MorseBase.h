#pragma once
#ifndef MorseBase_H
#define MorseBase_H
#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>



class MorseBase			// bazowa klasa po której inne beda dziedziczy³y informacje
{
public:
	int m_workMode;		// zmienna przechowujaca tryb pracy
	std::string m_morse, m_text, m_fileName; // zmienne przechowujace odpowiednio: tekst w morsie, tekst, nazwe pliku.														
	std::string morseTable(char);	// tabela znakow morsa								
	void toMorse();	// funkcja tlumaczaca tekst do morsa											
	
	virtual void convert(int)=0; //czysta funkcja wirtualna wykonywana w klasach pochodnych								
	virtual void convert(double)=0; //czysta funkcja wirtualna wykonywana w klasach pochodnych										
	virtual void convert(std::string)=0; //czysta funkcja wirtualna wykonywana w klasach pochodnych									
	void describe(); // funkcja wypisujaca na ekran ustawione parametry dla morsa													

	MorseBase(MorseBase&);	// konstruktor kopiujacy										
	MorseBase(); // konstruktor domyslny														
	~MorseBase(); // destruktor														
protected:
	int m_morseValues[5]; // zmienna przechowujaca wartosci parametrow morsa
	int m_frequency, m_dotTime, m_dashTime, m_pause, m_spacePause, m_charPause; // parametry jezyka morsa
};

#endif //!MorseBase_H