#include <iostream> 
#include "MorseFactory.h"   ///klasa ta ma dostep do wszystkich typów morsa i potrafi sie nimi odpowiednio poslugiwac
#include "MorseBase.h"      ///klasa bazowa dla pozostalych, tutaj ma byc wiekszosc mechaniki morsa
#include "MorseBeep.h"      ///klasa, ktora przekazuje przetlumaczony morse przez gloœnik
#include "MorseConsole.h"   ///klasa, ktora przekazuje przetlumaczony morse przez wypis na konsoli
#include "MorseCapslock.h"  ///klasa, ktora przekazuje przetlumaczony morse przez wypis na konsoli, gdzie przy kazdej . lub -
///miga lampka CapsLocka (programowo "wciskamy klawisz" CapsLock na klawiaturze)

int main()
{
	try
	{
		MorseBase* mb;
		MorseConsole m;
		mb = &m;
		mb->describe(); ///dane o tej konkretnej instancji klasy wypisane na konsole, wartosci takie jak czestotliwosc, pause, spacePause itd.

		MorseBeep n(m);///klasa, która specjalizuje sie w wysylaniu tlumaczenia morsa na gloœnik
		n.describe();

		m.convert("ala");///funkcja convert tlumaczy dany tekst/liczbe na morsa
		n.convert(36);

		MorseFactory f;
		///Glosnik
		f.setOutput(MorseFactory::beep);   ///tryb pracy, w którym efekt tlumaczenia pojdzie na glosnik
		f.convert("ala");               ///tak jak w przypadkach powyzej - funkcja tlumaczy na morsa to co sie w niej poda

										///Konsola
		f.setOutput(MorseFactory::console);  ///tryb pracy, w którym efekt tlumaczenia zostanie wypisany na konsoli
		f.convert(123);

		///Zapis na dysk
		f.setOutput(MorseFactory::disk);     ///tryb pracy, w którym efekt tlumaczenia zostanie zapisany na dysku w pliku
		f.setExternalInfo("test.txt");  ///w przypadku ustawienia zapisu na dysk ta funkcja przyjmuje nazwê pliku, do którego bêdzie zapisane tlumaczenie morse
		f.convert(123456);

		///Konsola z programowym wciskaniem CapsLocka
		f.setOutput(MorseFactory::capslock);///wyœwietlaniu kazdej . lub - ma towarzyszyæ blysniecie lampki CapsLock, poza tym wypisa na konsole
		f.setExternalInfo("2000 100 200 400 200 300");
		/**w przypadku ustawienia beep lub capslock, ta funkcja ustawia parametry dzialania - kolejno:
		[0] - frequency
		[1] - charPause
		[2] - dotTime
		[3] - dashTime
		[4] - spacePause
		[5] - pause
		gdzie kazda z tych wartosci jest oddzielona spacja. Wartosci moze byæ kilka, niekoniecznie musza wystepowaæ wszystkie (zaleznie co ma byc nadpisane)
		*/
		f.convert("Kobyla ma maly boK");///w przypadku CapsLocka wejsciem jest pojedynczy znak (char)
		system("PAUSE");
	}
	catch (char *_exception)
	{
		std::cout << _exception << std::endl;
		Sleep(7000);
		exit(0);
	}
}


/***
1) https://msdn.microsoft.com/pl-pl/library/windows/desktop/ms646310(v=vs.85).aspx - funkcja SendInput
2) https://msdn.microsoft.com/pl-pl/library/windows/desktop/ms646270(v=vs.85).aspx - struktura INPUT
***/
