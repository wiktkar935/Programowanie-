
#include <iostream>
#include <fstream>


#include "Struktury.h"
#include "Funkcje.h"

int wczytajZpliku(Samochod* &pHead, Samochod* &pTail, Samochod* &pCurrent)
{
	ifstream plik("baza.txt");
	Samochod* nowy;						

	if (plik)
	{

		while (!plik.eof())
		{
			nowy = new Samochod;	

			string dane;

			getline(plik, dane);
			nowy->marka = dane;

			getline(plik, dane);
			nowy->model = dane;

			getline(plik, dane);
			nowy->rokProdukcji = stoi(dane, nullptr, 0);

			getline(plik, dane);
			nowy->przebieg = stoi(dane, nullptr, 0);

			getline(plik, dane);
			nowy->paliwo = dane;

			getline(plik, dane);
			nowy->cena = stoi(dane, nullptr, 0);

			nowy->pNext = nullptr;
			nowy->pPrev = pTail;

			pCurrent = nowy;
			pTail = nowy;

			if (nowy->pPrev)
				nowy->pPrev->pNext = nowy;
			else
				pHead = nowy;
		}
	}
	else
		cout << "Blad odczytu pliku bazy samochodami!" << endl;

	return 0;
}

void usunBiezacy(Samochod* &pHead, Samochod* &pTail, Samochod* &pCurrent)
{
	if (pCurrent)
	{
		if (pCurrent == pHead && pCurrent->pNext != nullptr)	
		{
			pHead = pHead->pNext;
			pHead->pPrev = nullptr;
			delete pCurrent;
			pCurrent = pHead;
		}
		else if (pCurrent == pTail && pCurrent->pPrev != nullptr)	
		{
			pTail = pTail->pPrev;
			pTail->pNext = nullptr;
			delete pCurrent;
			pCurrent = pTail;
		}
		else if (pCurrent->pNext == nullptr || pCurrent->pPrev == nullptr)
		{
			pHead = nullptr;
			pTail = nullptr;
			delete pCurrent;
			pCurrent = nullptr;
		}
		else	
		{
			(pCurrent->pPrev)->pNext = pCurrent->pNext;	
			(pCurrent->pNext)->pPrev = pCurrent->pPrev;	

			delete pCurrent;
			pCurrent = pTail;
		}
	}
}

void dodaj(Samochod* &pHead, Samochod* &pTail, Samochod* &pCurrent)
{
	Samochod* nowy = new Samochod;

	string dane;

	cout << "\n	Podaj marke: ";
	getchar();
	getline(cin, dane);
	nowy->marka = dane;

	cout << "	Podaj model: ";
	getline(cin, dane);
	nowy->model = dane;

	cout << "	Podaj rok produkcji: ";
	getline(cin, dane);
	nowy->rokProdukcji = stoi(dane, nullptr, 0);

	cout << "	Podaj przebieg: ";
	getline(cin, dane);
	nowy->przebieg = stoi(dane, nullptr, 0);

	cout << "	Podaj rodzaj paliwa: ";
	getline(cin, dane);
	nowy->paliwo = dane;

	cout << "	Podaj cene: ";
	getline(cin, dane);
	nowy->cena = stoi(dane, nullptr, 0);


	nowy->pNext = nullptr;
	nowy->pPrev = pTail;

	pCurrent = nowy;

	pTail = nowy;

	if (nowy->pPrev) nowy->pPrev->pNext = nowy;
	else pHead = nowy;
}


void drukuj(Samochod* pHead, Samochod* pCurrent)
{
	Samochod* p = pHead;

	if (pCurrent)
	{
		cout << "\n\n\n";
		cout << "	------Wszystkie auta posiadane przez salon----------\n\n\n";


		while (p)
		{
			cout << "	" << p->marka << " " << p->model << ", rok produkcji " << p->rokProdukcji << ", " <<
				p->paliwo << ", " << p->cena << " PLN " << endl;

			p = p->pNext;
		}

		cout << endl << endl;
	}
	else
		cout << "	Lista aut jest pusta\n\n\n";
}

void zapisz(Samochod* pHead)
{
	ofstream file("baza.txt");

	Samochod* temp = pHead;

	while (temp)
	{
		if (temp->pNext != nullptr)
			file << temp->marka << endl << temp->model << endl << temp->rokProdukcji << endl << temp->paliwo << endl << temp->cena << endl;
		else 
			file << temp->marka << endl << temp->model << endl << temp->rokProdukcji << endl << temp->paliwo << endl << temp->cena;

		temp = temp->pNext;
	}

	cout << "\n	Dane o samochodach zostaly zapisane do bazy!\n\n\n";
}


void wyszukajPoMarce(Samochod* pHead)
{
	int n = 0;		
	string marka;	

	cout << "\nPodaj szukana marke: ";
	cin >> marka;


	Samochod* temp = pHead;

	while (temp)
	{
		if (temp->marka == marka)
		{
			if (n == 0)
			{
				system("cls");
				cout << endl << "	Szukasz marki: " << marka << endl;
				cout << "\n\n			Znalezione elementy to: \n\n";
			}
			cout << " " << temp->marka << " " << temp->model << ", rok produkcji: " << temp->rokProdukcji << ", "
				<< temp->paliwo << ", CENA: " << temp->cena << "PLN" << endl << endl;
			n++;
		}
		temp = temp->pNext;
	}
	if (n == 0)
	{
		cout << "\n\nNie posiadamy zadnego auta marki " << marka << "\n\n\n";
	}
	cout << "\n\n\n";
}

void wyszukajPoModelu(Samochod* pHead)
{
	int n = 0;		
	string model;	

	cout << "\nPodaj szukany model: ";
	cin >> model;


	Samochod* temp = pHead;

	while (temp != nullptr)
	{
		if (temp->model == model)
		{
			if (n == 0)
			{
				system("cls");
				cout << "	Szukasz modelu: " << model << endl;
				cout << "\n\n			Znalezione elementy to: \n\n";
			}
			cout << " " << temp->marka << " " << temp->model << ", rok produkcji: " << temp->rokProdukcji << ", "
				<< temp->paliwo << ", CENA: " << temp->cena << "PLN" << endl << endl;
			n++;
		}
		temp = temp->pNext;
	}
	if (n == 0)
	{
		system("cls");
		cout << "\n\nNiestety nie posiadamy szukanego modelu \n\n\n";
	}

	cout << "\n\n\n";
}

void wyszukajPoRoku(Samochod* pHead)
{
	int n = 0;		
	int rok;

	cout << "\n	Podaj interesujacy Cie rocznik: ";
	cin >> rok;

	Samochod* temp = pHead;

	while (temp != nullptr)
	{
		if (temp->rokProdukcji == rok)
		{
			if (n == 0)
			{
				system("cls");
				cout << "\n Wybrales rocznik " << rok << endl;
				cout << "\n\n		Znalezione elementy to: \n\n";
			}
			cout << " " << temp->marka << " " << temp->model << ", rok produkcji: " << temp->rokProdukcji << ", "
				<< temp->paliwo << ", CENA: " << temp->cena << "PLN" << endl << endl;
			n++;
		}
		temp = temp->pNext;
	}
	if (n == 0)
	{
		system("cls");
		cout << "\n\nNiestety nie posiadamy samochodow z rocznika " << rok << "\n\n\n";
	}

	cout << "\n\n\n";
}


void wyszukajPoPrzebiegu(Samochod* pHead)
{
	int n = 0;		/* Zmienna bêd¹ca prze³¹cznikiem by tylko raz wyœwietlaæ napis "Znalezione elementy" */
	int min, max;	/* Zmienne s³u¿¹ce  do przechowywania przedzia³u przebiegów aut, które interesuj¹ u¿ytkownika programu*/

	cout << "\n	Podaj zakres przebiegu ktory Cie interesuje\n\n";

	cout << "	Minimalny: ";
	cin >> min;

	cout << "\n	Maksymalny: ";
	cin >> max;

	Samochod* temp = pHead;

	while (temp != nullptr)
	{
		if (temp->przebieg >= min && temp->przebieg <= max)
		{
			if (n == 0)
			{
				system("cls");
				cout << "\n Interesujacy Cie przedzial cenowy to " << min << " - " << max << " PLN\n\n";

				cout << "\n\n			Znalezione elementy to: \n\n";
			}
			cout << " " << temp->marka << " " << temp->model << ", rok produkcji: " << temp->rokProdukcji << ", "
				<< temp->paliwo << ", CENA: " << temp->cena << "PLN" << endl << endl;
			n++;
		}
		temp = temp->pNext;
	}

	if (n == 0)
	{
		system("cls");
		cout << "\n\n Niestety nie posiadamy samochodow o zakresie przebiegu ktory zostal podany\n\n\n";
	}

	cout << "\n\n\n";
}

void wyszukajPoPaliwie(Samochod* pHead)
{
	int n = 0;		
	string paliwo;	

	cout << "\nPodaj interesujacy Cie rodzaj paliwa: ";
	cin >> paliwo;


	Samochod* temp = pHead;

	while (temp != nullptr)
	{
		if (temp->paliwo == paliwo)
		{
			if (n == 0)
			{
				system("cls");
				cout << "\nInteresujacy Cie rodzaj paliwa to " << paliwo << endl;

				cout << "\n\n			Znalezione elementy to: \n\n";
			}
			cout << " " << temp->marka << " " << temp->model << ", rok produkcji: " << temp->rokProdukcji << ", "
				<< temp->paliwo << ", CENA: " << temp->cena << "PLN" << endl << endl;
			n++;
		}
		temp = temp->pNext;
	}
	if (n == 0)
	{
		system("cls");
		cout << "\n\nNiestety nie posiadamy aut napedzanych na " << paliwo << "\n\n\n";
	}

	cout << "\n\n\n";
}


void wyszukiwaniePoCenie(struct Samochod* pHead)
{
	int n = 0;		
	int min, max;	

	cout << "\n	Podaj przedzial cenowy ktory Cie interesuje\n\n";

	cout << "	Minimalna: ";
	cin >> min;

	cout << "\n	Maksymalna: ";
	cin >> max;

	Samochod* temp = pHead;

	while (temp != nullptr)
	{
		if (temp->cena >= min && temp->cena <= max)
		{
			if (n == 0)
			{
				system("cls");
				cout << "\n Interesujacy Cie przedzial cenowy to " << min << " - " << max << " PLN\n\n";

				cout << "\n\n			Znalezione elementy to: \n\n";
			}
			cout << " " << temp->marka << " " << temp->model << ", rok produkcji: " << temp->rokProdukcji << ", "
				<< temp->paliwo << ", CENA: " << temp->cena << "PLN" << endl << endl;
			n++;
		}
		temp = temp->pNext;
	}

	if (n == 0)
	{
		system("cls");
		cout << "\n\n Niestety nie posiadamy samochodow z przedzialu cenowego " << min << " - " << max << "PLN\n\n\n";
	}

	cout << "\n\n\n";
}


void menuWyszukiwania(Samochod* pHead)
{

	if (pHead != nullptr)
	{
		int wybor;		

		do
		{
			system("cls");
			cout << "	 _______________________________________\n";
			cout << "	|					|\n";
			cout << "	|		Wyszukiwanie	        |\n";
			cout << "	|_______________________________________|\n\n\n";

			cout << "	Wedlug jakiego kryterium chcesz szukac ?\n\n";
			cout << "	1. Marka\n";
			cout << "	2. Model\n";
			cout << "	3. Rok produkcji\n";
			cout << "	4. Przebieg\n";
			cout << "	5. Rodziaj paliwa\n";
			cout << "	6. Cena\n\n";
			cout << "	Aby wrocic do menu glownego wcisnij 0\n\n\n";


			cout << "	Twoj wybor: ";
			cin >> wybor;

			switch (wybor)
			{
			case 1:
			{
				system("cls");

				wyszukajPoMarce(pHead);

				system("pause");

				break;
			}
			case 2:
			{
				system("cls");

				wyszukajPoModelu(pHead);

				system("pause");

				break;
			}

			case 3:
			{
				system("cls");

				wyszukajPoRoku(pHead);

				cout << "\n\n\n";
				system("pause");

				break;
			}

			case 4:
			{
				system("cls");

				wyszukajPoPrzebiegu(pHead);

				system("pause");

				break;
			}

			case 5:
			{
				system("cls");

				wyszukajPoPaliwie(pHead);

				system("pause");

				break;
			}

			case 6:
			{
				system("cls");

				wyszukiwaniePoCenie(pHead);

				system("pause");

				break;
			}

			case 0:
			{
				break;
			}

			default:
			{
				printf("\n	Prosze podac liczbe calkowita z zakresu 0-6 !\n\n");
				system("pause");
				system("cls");
				break;
			}

			}

		} while (wybor != 0);
	}
	else
	{
		cout << "\n	Lista samochodow jest pusta!\n\n";
	}


}

void zwolnijPamiec(Samochod* &pHead, Samochod* &pTail, Samochod* &pCurrent)
{
	while (pCurrent)
	{

		if (pCurrent == pHead && pCurrent->pNext != nullptr)
		{
			pHead = pHead->pNext;
			pHead->pPrev = nullptr;

			delete pCurrent;

			pCurrent = pHead;
		}
		else if (pCurrent == pTail && pCurrent->pPrev != nullptr)
		{
			pTail = pTail->pPrev;
			pTail->pNext = nullptr;

			delete pCurrent;

			pCurrent = pTail;
		}
		else if (pCurrent->pNext == nullptr || pCurrent->pPrev == nullptr)
		{
			pHead = nullptr;
			pTail = nullptr;
			delete pCurrent;
			pCurrent = nullptr;
		}
		else
		{
			(pCurrent->pPrev)->pNext = pCurrent->pNext;
			(pCurrent->pNext)->pPrev = pCurrent->pPrev;

			delete pCurrent;

			pCurrent = pTail;
		}

	}

}


void menu(Samochod* &pHead, Samochod* &pTail, Samochod* &pCurrent)
{
	int wybor;
	string weryfikacja;

	for (;;)
	{
		if (pCurrent)	 //je¿eli lista nie jest pusta wyœwietl element
		{
			cout << "\n		     Aktualnie wyswietlam: \n\n";
			cout << "	>>";
			cout << " " << pCurrent->marka << " " << pCurrent->model << ", rok produkcji: " << pCurrent->rokProdukcji << ", "
				<< pCurrent->paliwo << ", CENA: " << pCurrent->cena << "PLN";
			cout << "  <<\n\n\n";
		}
		else
		{
			cout << "\n		  Obecnie lista jest pusta!\n\n";
		}

		cout << "\n			MENU GLOWNE \n\n";
		cout << "		1. Wyswietl poprzedni\n";
		cout << "		2. Wyswietl nastepny\n";
		cout << "		3. Dodawanie nowego samochodu\n";
		cout << "		4. Usun aktualnie wyswietlany\n";
		cout << "		5. Usun wszystkie samochody z bazy \n";
		cout << "		6. Wyswietl liste wszystkich aut posiadanych przez salon\n";
		cout << "		7. Menu wyszukiwania\n\n";
		cout << "		Aby wyjsc z programu wybierz 0\n\n";

		cout << "\n	Twoj wybor: ";
		cin >> wybor;

		switch (wybor)
		{
		case 0:
			exit(0);
			break;
		case 1:
		{
			system("cls");

			if (pCurrent != pHead)
			{
				pCurrent = pCurrent->pPrev;
			}
			else
			{
				pCurrent = pTail;
			}

			break;
		}
		case 2:
		{
			system("cls");

			if (pCurrent != pTail)
			{
				pCurrent = pCurrent->pNext;
			}
			else
			{
				pCurrent = pHead;
			}

			break;
		}
		case 3:
			system("cls");

			dodaj(pHead, pTail, pCurrent);

			system("pause");

			system("cls");
			break;

		case 4:
			system("cls");
			usunBiezacy(pHead, pTail, pCurrent);
			system("cls");
			break;

		case 5:
			system("cls");
			cout << "\n		Czy na pewno chcesz usunac wszystkie samochody z bazy ?\n\n\n";

			cout << "\n	Twoj wybor[tak/nie]: ";
			cin >> weryfikacja;

			if (weryfikacja == "Tak" or weryfikacja == "tak" or weryfikacja == "TAK")
			{
				zwolnijPamiec(pHead, pTail, pCurrent);

				system("cls");
				cout << "\n	Dane o wszystkich autach zostaly usuniete\n";
			}
			cout << "\n\n\n";
			system("pause");
			system("cls");
			break;

		case 6:
			system("cls");
			drukuj(pHead, pCurrent);
			system("pause");
			system("cls");
			break;

		case 7:
			system("cls");
			menuWyszukiwania(pHead);
			system("cls");
			break;

		default:
			cout << "\n	Prosze wybrac opcje z zakresu 0-7\n\n";
			system("pause");
			system("cls");
			break;
		}


	}
}
