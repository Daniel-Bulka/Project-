#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <vector>

using namespace std;

char wybor;

class pojazd
{
public:
	string marka;
	string model;
	int rok_produkcji;
	float pojemnosc_silnika;
	int przebieg;
	string skrzynia_biegow;
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

void wczytaj_pojazd(pojazd*pojazd)
{
	cout << "Marka: ";
	cin >> pojazd->marka;

	cout << "Model: ";
	cin >> pojazd->model;

	cout << "Rok produkcji: ";
	cin >> pojazd->rok_produkcji;

	cout << "Pojemnosc silnika: ";
	cin >> pojazd->pojemnosc_silnika;

	cout << "Przebieg: ";
	cin >> pojazd->przebieg;

	cout << "Typ skrzyni biegow: ";
	cin >> pojazd->skrzynia_biegow;
}

void zapisz_pojazd(vector <pojazd> katalog)
{
	ofstream plik;
	plik.open("baza.txt");
	for (pojazd pojazd : katalog)
	{
    plik << pojazd.marka << " ";
	plik << pojazd.model << " ";
	plik << pojazd.rok_produkcji << " ";
	plik << pojazd.pojemnosc_silnika << " ";
	plik << pojazd.przebieg << " ";
	plik << pojazd.skrzynia_biegow;
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
	pojazd pojazd{};
	ifstream plik;
	plik.open("baza.txt");
	while (plik.peek()!=EOF)
	{
		plik >> pojazd.marka;
		plik >> pojazd.model;
		plik >> pojazd.rok_produkcji;
		plik >> pojazd.pojemnosc_silnika;
		plik >> pojazd.przebieg;
		plik >> pojazd.skrzynia_biegow;
		
		if (!plik.eof())
		{
			katalog.push_back(pojazd);
		}
	}
	plik.close();
	return katalog;
}

int main()
{
	vector <pojazd> katalog;
	while (wybor !=9)
	{
		cout << "------------BAZA DANYCH------------\n" << endl;
		cout << "Wybierz opcje:\n " << endl;
		cout << "1.Wprowadz dane nowego pojazdu\n" << endl;
		cout << "2.Wyswietl liste pojazdow\n" << endl;
		cout << "3.Wyswietl pojazdy powyzej 100 koni\n" << endl;
		cout << "4.Wyswietl dane pojedynczego pojazdu\n" << endl;
		cout << "5.Posortuj pojazdy po wybranym parametrze\n" << endl;
		cout << "6.Usun pojazd\n" << endl;
		cout << "7.Zapisz baze\n" << endl;
		cout << "8.Wczytaj baze\n" << endl;
		cout << "9.Wyjdz\n" << endl;
		cout << "\n";
		
		cout << "Wybierz: ";
		cin >> wybor;

		switch (wybor)
		{
		case '1':
		{
			cout << "Wprowadz pojazd do bazy:\n " << endl; 
			pojazd wprowadzany_pojazd=pojazd(true);
			katalog.push_back(wprowadzany_pojazd);
		}
		break;
		
		case '2':
		{
			cout << "Lista pojazdow: " << endl;
			wypisz_katalog(katalog);
		}
		break;
		
	    case '3':
		{
			cout << "Pojazdy powyzej 100 koni: " << endl;
		}
		break;

		case '4':
		{
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
			
		}
		break;
		
		case '6':
		{
			cout << "Ktory pojazd chcesz usunac? " << endl;
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


