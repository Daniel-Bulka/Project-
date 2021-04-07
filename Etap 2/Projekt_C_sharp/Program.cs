using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading.Tasks;

namespace Projekt_C_sharp
{
	[Serializable]
	class Pojazd
	{
		public string marka { get; set; }
		public string model { get; set; }
		public int rok_produkcji { get; set; }
		public int pojemnosc_silnika { get; set; }
		public int przebieg { get; set; }
		public string skrzynia_biegow { get; set; }

		public Pojazd() { }
		public Pojazd(bool fura)
		{
			Console.WriteLine("Marka: ");
			marka = Console.ReadLine();

			Console.WriteLine("Model: ");
			model = Console.ReadLine();

			Console.WriteLine("Rok produkcji: ");
			rok_produkcji = Program.Pobierzliczbe();

			Console.WriteLine("Pojemnosc silnika: ");
			pojemnosc_silnika = Program.Pobierzliczbe();

			Console.WriteLine("Przebieg: ");
			przebieg = Program.Pobierzliczbe();

			Console.WriteLine("Typ skrzyni biegow: ");
			skrzynia_biegow = Console.ReadLine();
		}
		public Pojazd(string marka, string model, int rok_produkcji, int pojemnosc_silnika, int przebieg, string skrzynia_biegow)
		{
			this.marka = marka;
			this.model = model;
			this.rok_produkcji = rok_produkcji;
			this.pojemnosc_silnika = pojemnosc_silnika;
			this.przebieg = przebieg;
			this.skrzynia_biegow = skrzynia_biegow;
		}
		public void wypisz()
		{
			Console.WriteLine("{0} {1} - {2} rok - {3} pojemnosc - {4} km - skrzynia {5} ",
				marka, model, rok_produkcji, pojemnosc_silnika, przebieg, skrzynia_biegow);
		}
		public static void wypisz_katalog(List<Pojazd> katalog)
		{
			foreach (Pojazd pojazd in katalog)
			{
				pojazd.wypisz();
			}
		}
		public static void ZapisDoPliku(List<Pojazd> obiekt)
		{
			using (Stream stream = File.Open("plik.bin", FileMode.Create))
			{
				var binaryFormatter = new BinaryFormatter();
				binaryFormatter.Serialize(stream, obiekt);
			}
		}
		public static List<Pojazd> WczytajPlik()
		{
			using (Stream stream = File.Open("plik.bin", FileMode.Open))
			{
				var binaryFormatter = new BinaryFormatter();
				return (List<Pojazd>)binaryFormatter.Deserialize(stream);
			}
		}
		public static void szukaj_pojazdu(List<Pojazd> katalog)
		{
			Console.WriteLine("Wybierz parametr\n");
			Console.WriteLine("1.Marka\n");
			Console.WriteLine("2.Model\n");
			Console.WriteLine("3.Rok produkcji\n");
			Console.WriteLine("4.Pojemnosc silnika\n");
			Console.WriteLine("5.Przebieg\n");
			Console.WriteLine("6.Typ skrzyni biegow\n");

			char w;
			w = Console.ReadLine()[0];
			switch (w)
			{
				case '1':
					{
						Console.WriteLine("Marka\n");
						string szukaj;
						szukaj = Console.ReadLine();
						foreach (var samochod in katalog)
						{
							if (samochod.marka.Contains(szukaj))
							{
								samochod.wypisz();
							}
						}
						break;
					}
				case '2':
					{
						Console.WriteLine("Model\n");
						string szukaj;
						szukaj = Console.ReadLine();
						foreach (var samochod in katalog)
						{
							if (samochod.model.Contains(szukaj))
							{
								samochod.wypisz();
							}
						}
						break;
					}
				case '3':
					{
						Console.WriteLine("Rok produkjci\n");
						int szukaj;
						szukaj = Program.Pobierzliczbe();
						foreach (var samochod in katalog)
						{
							if (samochod.rok_produkcji == szukaj)
							{
								samochod.wypisz();
							}
						}
						break;
					}
				case '4':
					{
						Console.WriteLine("Pojemnosc silnika\n");
						int szukaj;
						szukaj = Program.Pobierzliczbe();
						foreach (var samochod in katalog)
						{
							if (samochod.pojemnosc_silnika == szukaj)
							{
								samochod.wypisz();
							}
						}
						break;
					}
				case '5':
					{
						Console.WriteLine("Przebieg\n");
						int szukaj;
						szukaj = Program.Pobierzliczbe();
						foreach (var samochod in katalog)
						{
							if (samochod.przebieg == szukaj)
							{
								samochod.wypisz();
							}
						}
						break;
					}
				case '6':
					{
						Conse.WriteLine("Typ Skrzyni biegow\n");
						string szukaj;
						szukaj = Console.ReadLine();
						foreach (var samochod in katalog)
						{
							if (samochod.skrzynia_biegow.Contains(szukaj))
							{
								samochod.wypisz();
							}
						}
						break;
					}
				default:
					{
						break;
					}
			}
		}

	}		
    class Program
    {

		public static char wybor;
		public static char opcja;

		public static int Pobierzliczbe()
		{
			while (true)
			{

				string Wartosc = Console.ReadLine();
				int Wartosc1 = 0;
				if (Int32.TryParse(Wartosc, out Wartosc1))
				{
					return Wartosc1;
				}
			}

		}
		static void Main(string[] args)
		{
			List<Pojazd> katalog = new List<Pojazd>();

			while (wybor != 9)
			{
				Console.WriteLine("------------BAZA DANYCH------------\n");
				Console.WriteLine("WYBIERZ OPCJE:\n ");
				Console.WriteLine("1.Wprowadz dane nowego pojazdu\n");
				Console.WriteLine("2.Wyswietl katalog pojazdow\n");
				Console.WriteLine("3.Wyswietl pojazdy ponizej 200 tysiecy przebiegu\n");
				Console.WriteLine("4.Wyswietl dane pojedynczego pojazdu\n");
				Console.WriteLine("5.Wyszukaj pojazdy po wybranym parametrze\n");
				Console.WriteLine("6.Usun pojazd\n");
				Console.WriteLine("7.Zapisz katalog\n");
				Console.WriteLine("8.Wczytaj katalog\n");
				Console.WriteLine("9.Wyjdz\n");
				Console.WriteLine("\n");

				Console.WriteLine("Wybierz: ");
				wybor = Console.ReadLine()[0];
			 
				switch (wybor)
                {
                    case '1':
						{
						Console.WriteLine("Wprowadz pojazd do katalogu:\n");
							Pojazd wprowadzany_pojazd = new Pojazd (true);
							katalog.Add(wprowadzany_pojazd);
						}
						break;
					case '2':
                        {
							Console.WriteLine("Katalog pojazdow:");
							Pojazd.wypisz_katalog(katalog);
                        }
						break;
					case '3':
                        {
							Console.WriteLine("Pojazdy ponizej 200000 tysiecy przebiegu");
							foreach (var Pojazd in katalog)
                            {
								if(Pojazd.przebieg < 200000)
                                {
									Pojazd.wypisz();
                                }
                            }
                        }
						break;
					case '4':
                        {
							Console.WriteLine("Ktory pojazd chcesz wyswietlic?\n");
							Console.WriteLine("Numer pojazdu: ");
							int numer = Pobierzliczbe();
							
						    if (numer > 0 && numer <= katalog.Count)
								katalog[numer - 1].wypisz();
							else
								Console.WriteLine("Dany pojazd nie istnieje\n");
                        }
						break;
					case '5':
                        {
							Pojazd.szukaj_pojazdu(katalog);
                        }
						break;
					case '6':
                        {
							Console.WriteLine("Ktory pojazd chcesz usunac?\n");
							int numer = Pobierzliczbe();
							if (numer > 0 && numer <= katalog.Count())
								katalog.RemoveAt((numer - 1));
							else
								Console.WriteLine("Dany pojazd nie istnieje!\n");
						}
						break;
					case '7':
                        {
							Console.WriteLine("Zapisano pomyslnie!\n");
							Pojazd.ZapisDoPliku(katalog);
						}
						break;
					case '8':
                        {
							Console.WriteLine("Wczytano pomyslnie!\n");
							katalog=Pojazd.WczytajPlik();
                        }
						break;
					case '9':
                        {
							Environment.Exit(0);
						}
						break;
                }
				Console.ReadKey();
				Console.Clear();
			}
		}
    }
}






















							



						

					



 	
