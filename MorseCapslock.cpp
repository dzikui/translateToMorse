#include "MorseCapslock.h"

MorseCapslock::MorseCapslock(MorseCapslock & _pattern) {} // konstruktor kopiujacy
MorseCapslock::MorseCapslock() { m_workMode = 5; } // konstruktor domyslny
MorseCapslock::~MorseCapslock() {} // destruktor

void MorseCapslock::toShine(char _partOfMorseLetter) // funkcja zmieniajaca morsa na miganie dioda
{
	switch (_partOfMorseLetter)
	{
	case '.': {keybd_event(VK_CAPITAL, 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0); Sleep(m_dotTime);
		keybd_event(VK_CAPITAL, 0, KEYEVENTF_EXTENDEDKEY | 0, 0); Sleep(m_pause); break; }
	case '_': {keybd_event(VK_CAPITAL, 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0); Sleep(m_dashTime);
		keybd_event(VK_CAPITAL, 0, KEYEVENTF_EXTENDEDKEY | 0, 0); Sleep(m_pause); break; }
	case '^': {Sleep(m_charPause); break; }
	case ' ': {Sleep(m_spacePause); break; }
	}
}

void MorseCapslock::convert(std::string _text) // funkcja œwiec¹ca capslockiem dla wczytanego morsa
{
	m_text = _text;
	toMorse();
	std::cout << "Patrz na CAPSLOCK, bo tam dzieje sie MAGIA!!!" << std::endl;
	for (int i = 0; i <m_morse.length(); i++)	
	{toShine(m_morse[i]);}
	m_text.clear();
	m_morse.clear();
}

void MorseCapslock::convert(int _text) // konswersja inta na stringa z wykorzystaniem rekurencyjnego wywolania
{
	this->m_text = std::to_string(_text);convert(m_text); // odwolanie do wskaznika przy uzyciu ->
}

void MorseCapslock::convert(double _text) // konwersja doubla na stringa z wykorzystaniem rekurencyjnego wywolania
{
	(*this).m_text = std::to_string(_text);convert(m_text); // odwolanie do wskaznika przy uzyciu (*x).x
}