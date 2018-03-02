#include "MorseBase.h"

MorseBase::~MorseBase() {} // destruktor
MorseBase::MorseBase(MorseBase&_pattern) {} // konstruktor kopiujacy

MorseBase::MorseBase() // Kostruktor domyslny
{
	m_workMode = 1;
	m_text.clear(); m_morse.clear();
	m_frequency = 800;	m_dotTime = 200;	m_dashTime = 400;	m_pause = 100;	m_spacePause = 400;	m_charPause = 200;
	m_morseValues[0] = 800; m_morseValues[0] = 800;	m_morseValues[2] = 200;	m_morseValues[3] = 200;
	m_morseValues[4] = 400;	m_morseValues[5] = 400;	m_morseValues[6] = 100;
}

void MorseBase::describe() // funkcja wypisujaca na ustawienia na ekran
{
	std::cout << "Wartosc Pause to: " << m_pause << std::endl;
	std::cout << "Wartosc DotTime to: " << m_dotTime << std::endl;
	std::cout << "Wartosc DashTime to: " << m_dashTime << std::endl;
	std::cout << "Wartosc CharPause to: " << m_charPause << std::endl;
	std::cout << "Wartosc Frequency to: " << m_frequency << std::endl;
	std::cout << "Wartosc SpacePause to: " << m_spacePause << std::endl << std::endl;
}

void MorseBase::toMorse() // funkcja t³uamcz¹ca tekst do Morsa
{
	for (int i = 0; i < m_text.length(); i++)
	{m_morse += morseTable(m_text[i]);}
}

std::string MorseBase::morseTable(char _letter) // Tabela znaków Morsa
{
	if (_letter == '$') throw "\n\nElement nie istnieje w tablicy Morse'a"; // obslugiwany wyjatek, ale nie do konca dzia³a poprawnie 

		switch (_letter) {
		case 'a': case 'A': {return ". - ^"; break; }
		case 'b': case 'B': {return "- . . . ^"; break; }
		case 'c': case 'C': {return "- . - . ^"; break; }
		case 'd': case 'D': {return "- . . ^"; break; }
		case 'e': case 'E': {return ". ^"; break; }
		case 'f': case 'F': {return ". . - . ^"; break; }
		case 'g': case 'G': {return "- - . ^"; break; }
		case 'h': case 'H': {return ". . . . ^"; break; }
		case 'i': case 'I': {return ". . ^"; break; }
		case 'j': case 'J': {return ". - - - ^"; break; }
		case 'k': case 'K': {return "- . - ^"; break; }
		case 'l': case 'L': {return ". - . . ^"; break; }
		case 'm': case 'M': {return "- - ^"; break; }
		case 'n': case 'N': {return "_ . ^"; break; }
		case 'o': case 'O': {return "- - - ^"; break; }
		case 'p': case 'P': {return ". - - . ^"; break; }
		case 'q': case 'Q': {return "- - . - ^"; break; }
		case 'r': case 'R': {return ". - . ^"; break; }
		case 's': case 'S': {return ". . . ^"; break; }
		case 't': case 'T': {return "- ^"; break; }
		case 'u': case 'U': {return ". . - ^"; break; }
		case 'v': case 'V': {return ". . . - ^"; break; }
		case 'w': case 'W': {return ". - - ^"; break; }
		case 'x': case 'X': {return "- . . - ^"; break; }
		case 'y': case 'Y': {return "- . - - ^"; break; }
		case 'z': case 'Z': {return "- - . . ^"; break; }
		case '1': {return ". - - - - ^"; break; }
		case '2': {return ". . - - - ^"; break; }
		case '3': {return ". . . - - ^"; break; }
		case '4': {return ". . . . - ^"; break; }
		case '5': {return ". . . . . ^"; break; }
		case '6': {return "- . . . . ^"; break; }
		case '7': {return "- - . . . ^"; break; }
		case '8': {return "- - - . . ^"; break; }
		case '9': {return "- - - - . ^"; break; }
		case '0': {return "- - - - - ^"; break; }
		case '.': {return ". - . - . - ^"; break; }
		case ',': {return "- - . . - - ^"; break; }
		case '"': {return ". - - - - . ^"; break; }
		case '_': {return ". . - - . - ^"; break; }
		case ':': {return "- - - . . . ^"; break; }
		case ';': {return "- . - . - . ^"; break; }
		case '?': {return ". . - - . . ^"; break; }
		case '!': {return "- . - . - - ^"; break; }
		case '-': {return "- . . . . - ^"; break; }
		case '+': {return ". - . - . ^"; break; }
		case '/': {return "- . . - . ^"; break; }
		case '(': {return "- . - - . ^"; break; }
		case ')': {return "- . - - . - ^"; break; }
		case '=': {return "- . . . - ^"; break; }
		case '@': {return ". - - . - . ^"; break; }
		case ' ': {return "?"; break; }
		}
}

