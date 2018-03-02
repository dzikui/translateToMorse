#include "MorseBeep.h"


MorseBeep::MorseBeep(MorseConsole & _pattern) {} // konstruktor kopiujacy
MorseBeep::MorseBeep() { m_workMode = 0; } // konstruktor domyslny
MorseBeep::~MorseBeep() {} // destruktor

void MorseBeep::beep() 
{
	if (m_workMode == 0)
	{for (int i = 0; i < m_morse.length(); i++)
	{toBeep(m_morse[i]);}	}
}

void MorseBeep::toBeep(char _morse) // funckja beepajaca dla znakow morsa
{
	switch (_morse)
	{
	case '.': {Beep(DWORD(m_frequency), DWORD(m_dotTime)); Sleep(m_pause); break; }
	case '_': {Beep(DWORD(m_frequency), DWORD(m_dashTime)); Sleep(m_pause); break; }
	case '^': {Sleep(m_charPause); break;  }
	case ' ': {Sleep(m_spacePause); break;  }
	}
}

void MorseBeep::convert(std::string _text) // funkcja konwertujaca tekst na beepanie morsa
{
	m_text = _text;
	toMorse();
	std::cout << "Wlacz glosnik, a uslyszysz: " << m_text << " w jezyku morsa." << std::endl;
	for (int i = 0; i < m_morse.length(); i++)	
	{toBeep(m_morse[i]);}
	m_text.clear();
	m_morse.clear();
}

void MorseBeep::convert(int _text) // konswersja inta na stringa z wykorzystaniem rekurencyjnego wywolania
{
	(*this).m_text = std::to_string(_text);	convert(m_text);
}

void MorseBeep::convert(double _pattern) // // konswersja doubla na stringa z wykorzystaniem rekurencyjnego wywolania
{
	(*this).m_text = std::to_string(_pattern);	convert(m_text);
}

