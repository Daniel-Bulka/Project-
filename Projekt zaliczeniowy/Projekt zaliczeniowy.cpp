#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char wybor;
char opcja;

class pojazd 
{
	string marka;
	string model;
	int rok_produkcji;
	float pojemnosc_silnika;
	int przebieg;
	string skrzynia_biegow;

	friend void sortuj(vector<pojazd>& katalog, int opcja, int mniejsza);

public:
	pojazd(){};
    pojazd(bool fura)
	{
		cout << "Marka: ";
		cin >> marka;

		cout << "Model: ";
		cin >> model;

		cout << "Rok produkcji: ";
		cin >> rok_produkcji;

		cout << "Pojemnosc silnika: ";
		cin >> pojemnosc_silnika;

		cout << "Przebieg: ";
		cin >> przebieg;

		cout << "Typ skrzyni biegow: ";
		cin >> skrzynia_biegow;
	 }
	pojazd(string marka, string model, int rok_produkcji, float pojemnosc_silnika, int przebieg, string skrzynia_biegow) 
	{
		this->marka = marka;
		this->model = model;
		this->rok_produkcji = rok_produkcji;
		this->pojemnosc_silnika = pojemnosc_silnika;
		this->przebieg = przebieg;
		this->skrzynia_biegow = skrzynia_biegow;
    }
	string getmarka()
	{
		return marka;
	}
	string getmodel()
	{
		return model;
	}
	int getrok_produkcji()
	{
		return rok_produkcji;
	}
	float getpojemnosc_silnika()
	{
		return pojemnosc_silnika;
	}
	int getprzebieg()
	{
		return przebieg;
	}
	string getskrzynia_biegow()
	{
		return skrzynia_biegow;
	}
	
	void wypisz() 
	{
		cout << marka << " ";
		cout << model << " ";
		cout << rok_produkcji << " ";
		cout << pojemnosc_silnika << " ";
		cout << przebieg << " ";
		cout << skrzynia_biegow << " ";
		cout << endl;
	}
};

pojazd wczytaj_pojazd()
{
	string marka, model, skrzynia_biegow;
	int rok_produkcji, przebieg;
	float pojemnosc_silnika;

	cout << "Marka: ";
	cin >> marka;

	cout << "Model: ";
	cin >> model;

	cout << "Rok produkcji: ";
	cin >> rok_produkcji;

	cout << "Pojemnosc silnika: ";
	cin >> pojemnosc_silnika;

	cout << "Przebieg: ";
	cin >> przebieg;

	cout << "Typ skrzyni biegow: ";
	cin >> skrzynia_biegow;

	pojazd nowypojazd(marka, model, rok_produkcji, pojemnosc_silnika, przebieg, skrzynia_biegow);
	return nowypojazd;
}

void zapisz_pojazd(vector <pojazd> katalog)
{
	ofstream plik;
	plik.open("baza.txt");
	for (pojazd pojazd : katalog)
	{
    plik << pojazd.getmarka() << " ";
	plik << pojazd.getmodel() << " ";
	plik << pojazd.getrok_produkcji() << " ";
	plik << pojazd.getpojemnosc_silnika() << " ";
	plik << pojazd.getprzebieg() << " ";
	plik << pojazd.getskrzynia_biegow();
	plik << endl;
	}
	plik.close();
}

void wypisz_katalog(vector <pojazd> katalog)
{
	for (pojazd pojazd : katalog) 
	{
		pojazd.wypisz();
	}
}

vector <pojazd> wczytaj_baze()
{
	vector <pojazd> katalog;
	ifstream plik;
	plik.open("baza.txt");
	while (plik.peek()!=EOF)
	{
		string marka, model, skrzynia_biegow;
	    int rok_produkcji, przebieg;
	    float pojemnosc_silnika;

		plik >> marka;
		plik >> model;
		plik >> rok_produkcji;
		plik >> pojemnosc_silnika;
		plik >> przebieg;
		plik >> skrzynia_biegow;
		
		pojazd nowypojazd(marka, model, rok_produkcji, pojemnosc_silnika, przebieg, skrzynia_biegow);

		if (!plik.eof())
		{
			katalog.push_back(nowypojazd);
		}
	}
	plik.close();
	return katalog;
}

void sortuj(vector<pojazd> &katalog, int opcja, int mniejsza)
{
	
	sort(katalog.begin(), katalog.end(), [opcja, mniejsza](const pojazd& x, const pojazd& y)
		{
			bool wynik = false;

			switch (opcja)
			{
			case'1':
			{
				if (mniejsza)
					wynik = x.marka > y.marka;
				else
					wynik = x.marka < y.marka;

			}
			break;

			case'2':
			{
				if (mniejsza)
					wynik = x.model > y.model;
				else
					wynik = x.model < y.model;
			}
			break;

			case'3':
			{
				if (mniejsza)
					wynik = x.rok_produkcji > y.rok_produkcji;
				else
					wynik = x.rok_produkcji < y.rok_produkcji;
			}
			break;

			case'4':
			{
				if (mniejsza)
					wynik = x.pojemnosc_silnika > y.pojemnosc_silnika;
				else
					wynik = x.pojemnosc_silnika < y.pojemnosc_silnika;
			}
			break;

			case'5':
			{
				if (mniejsza)
					wynik = x.przebieg > y.przebieg;
				else
					wynik = x.przebieg < y.przebieg;
			}
			break;

			case'6':
			{
				if (mniejsza)
					wynik = x.skrzynia_biegow > y.skrzynia_biegow;
				else
					wynik = x.skrzynia_biegow < y.skrzynia_biegow;
			}
			break;
			}
			return wynik;
		}
	);
}

int main()
{
	vector <pojazd> katalog;
	
	while (wybor !=9)
	{
		cout << "------------BAZA DANYCH------------\n" << endl;
		cout << "WYBIERZ OPCJE:\n " << endl;
		cout << "1.Wprowadz dane nowego pojazdu\n" << endl;
		cout << "2.Wyswietl katalog pojazdow\n" << endl;
		cout << "3.Wyswietl pojazdy ponizej 200 tysiecy przebiegu\n" << endl;
		cout << "4.Wyswietl dane pojedynczego pojazdu\n" << endl;
		cout << "5.Posortuj pojazdy po wybranym parametrze\n" << endl;
		cout << "6.Usun pojazd\n" << endl;
		cout << "7.Zapisz katalog\n" << endl;
		cout << "8.Wczytaj katalog\n" << endl;
		cout << "9.Wyjdz\n" << endl;
		cout << "\n";
		
		cout << "Wybierz: ";
		cin >> wybor;

		switch (wybor)
		{
		case '1':
		{
			cout << "Wprowadz pojazd do katalogu:\n " << endl; 
			pojazd wprowadzany_pojazd=pojazd(true);
			katalog.push_back(wprowadzany_pojazd);
		}
		break;
		
		case '2':
		{
			cout << "Katalog pojazdow:" << endl;
			wypisz_katalog(katalog);
		}
		break;
		
	    case '3':
		{
			int i = 1;
			for (pojazd pojazd : katalog)
			{
				if (pojazd.getprzebieg() < 200000)
				{
					pojazd.wypisz();
				}
			}
		}
		break;

		case '4':
		{
			cout << "Ktory pojazd chcesz wyswietlic?\n";
			cout << "Numer pojazdu: ";
			int numer;
			cin >> numer;
			if (numer > 0 && numer <= katalog.size())
				katalog[numer - 1].wypisz();
			else
				cout << "Dany pojazd nie istnieje!\n";
		}
		break;

		case '5':
		{
			char opcja;
			cout << "Wybierz po jakim parametrze chcesz posortowac:\n" << endl;
			cout << "1.Marka\n" << endl;
			cout << "2.Model\n" << endl;
			cout << "3.Rok produkcji\n" << endl;
			cout << "4.Pojemnosc silnika\n" << endl;
			cout << "5.Przebieg\n" << endl;
			cout << "6.Typ skrzyni biegow\n" << endl;
			cout << "Wybierz: ";
			cin >> opcja;
			cout << "0.Wieksza\n";
			cout << "1.Mniejsza\n";

			int mniejsza;
			cin >> mniejsza;

			sortuj (katalog, opcja, mniejsza);
			wypisz_katalog(katalog);
		}
		break;
		
		case '6':
		{
			cout << "Ktory pojazd chcesz usunac?" << endl;
			int numer;
			cin >> numer;
			if (numer > 0 && numer <= katalog.size())
				katalog.erase(katalog.begin() + (numer - 1));
			else
				cout << "Dany pojazd nie istnieje!\n";
		 }
		break;

		case '7':
		{
			cout << "Zapisano pomyslnie\n";
			zapisz_pojazd(katalog);
		}
		break;
		case '8':
		{

			cout << "Wczytano pomyslnie\n";
			katalog = wczytaj_baze();
		}
		break;
		
		case '9':
		{
			exit(0);
		}
		break;
		
	    default: cout << "Nie ma takiej opcji w menu!" << endl;
		}
		_getch();

		system("cls");
     }
}


