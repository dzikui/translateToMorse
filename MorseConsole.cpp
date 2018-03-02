#include "MorseConsole.h"

MorseConsole::MorseConsole(MorseConsole&_pattern) {} // konstruktor kopiujacy
MorseConsole::MorseConsole() {} // kostruktor domyslny
MorseConsole::~MorseConsole() {} // destruktor

void MorseConsole::view(char _partOfMorseLetter) // funkcja tlumaczaca morsa z tabeli do "czystego" morsa
{
	switch (_partOfMorseLetter) 
	{
	case '.': {std::cout << "."; break; }
	case '-': {std::cout << "-"; break; }
	case '^': {std::cout << " "; break; }
	case '?': {std::cout << "   "; break;  }
	}
}

void MorseConsole::convert(std::string _text) // funkcja wyswietlajaca morsa w konsoli
{
	m_text = _text;
	toMorse();
	int number = m_morse.length();
	std::cout << m_text << " -> toMorse(" << m_text << ") = ";
	for (int i = 0; i < number; i++) { view(m_morse[i]); }
	std::cout << std::endl;
	m_text.clear();
	m_morse.clear();
}

void MorseConsole::convert(int _text) // // konswersja inta na stringa z wykorzystaniem rekurencyjnego wywolania
{
	this->m_text = std::to_string(_text);convert(m_text);
}

void MorseConsole::convert(double _text) // // konswersja doubla na stringa z wykorzystaniem rekurencyjnego wywolania
{
	this->m_text = std::to_string(_text);convert(m_text);
}


