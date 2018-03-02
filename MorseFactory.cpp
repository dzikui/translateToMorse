#include "MorseFactory.h"

MorseFactory::MorseFactory(MorseFactory & _pattern) {} // konstruktor kopiujacy
MorseFactory::MorseFactory() {} // konstruktor domyslny
MorseFactory::~MorseFactory() {} // destruktor

void MorseFactory::setOutput(Numberic _number) // funkcja sprawdzajaca jaki tryb pracy zostal wybrany
{
	delete _indicator;
	if (_number == 0){m_workMode = 0; _indicator = new MorseBeep;}
	else if (_number == 1) { m_workMode = 1; _indicator = new MorseConsole; }
	else if (_number == 2) { m_workMode = 2; _indicator = new MorseDisc; }
	else if (_number == 3) { m_workMode = 3; _indicator = new MorseCapslock; }
}

void MorseFactory::setExternalInfo(std::string _fileName) // funkcja ustawiajaca nazwe pliku w przypadku trybu pracy zapisu na dysk, w innym przypadku wczytuje ustawienia dla morsa.
{
	if (m_workMode == 2)
		{_indicator->m_fileName = _fileName;}
	else if (m_workMode == 0 || m_workMode == 3){
		int j = 0;	int i = 0;	std::string _worker;
		while (1){
			_worker += _fileName[i];
			if (_fileName.length() == i)
			{++j;m_morseValues[j] = atoi(_worker.c_str());
			break;}
			if (_fileName[i] == ' '){m_morseValues[j] = atoi(_worker.c_str());++j;_worker.clear();}
			++i;
		}
		for (int i = 0; i<j + 1; i++){
			if (i == 1){m_frequency = m_morseValues[0];}
			else if (i == 2){m_charPause = m_morseValues[1];}
			else if (i == 3){m_dotTime = m_morseValues[2];}
			else if (i == 4){m_dashTime = m_morseValues[3];}
			else if (i == 5){m_spacePause = m_morseValues[4];}
			else if (i == 6){m_pause = m_morseValues[5];}}
		return;	}
}

void MorseFactory::convert(std::string _text) // wywolanie funkcji convert
{_indicator->convert(_text);}

void MorseFactory::convert(int _text) // konswersja inta na stringa z wykorzystaniem rekurencyjnego wywolania
{_indicator->convert(_text);}

void MorseFactory::convert(double _text)// konswersja doubla na stringa z wykorzystaniem rekurencyjnego wywolania
{_indicator->convert(_text);}


