#include "MorseDisc.h"

MorseDisc::MorseDisc(MorseDisc&_pattern) {} // konstruktor kopiujacy	
MorseDisc::MorseDisc() {} // konstruktor bezparametryczny
MorseDisc::~MorseDisc() {} // destruktor

void MorseDisc::toSave(std::string _text, std::string _fileName) // funkcja zapisujaca tekst do pliku
{
	std::ofstream fileOut;
	fileOut.open(_fileName, std::ios::out);
	int number = _text.length();
	for (int i = 0; i<number; i++)	
	{fileOut << _text[i];}
	fileOut.close();
}

void MorseDisc::convert(std::string _text) // funkcja informujaca o zapisie do pliku
{
	m_text = _text;
	toMorse();
	std::cout << m_text << " zapisano do pliku: " << m_fileName << std::endl;
	toSave(m_morse, m_fileName);
	m_text.clear();
	m_morse.clear();
}

void MorseDisc::convert(int _text) // konswersja inta na stringa z wykorzystaniem rekurencyjnego wywolania
{
	(*this).m_text = std::to_string(_text);convert(m_text);
}

void MorseDisc::convert(double _text) // konswersja doubla na stringa z wykorzystaniem rekurencyjnego wywolania
{
	(*this).m_text = std::to_string(_text);	convert(m_text);
}


