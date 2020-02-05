
#include <iostream>

#include "Struktury.h"
#include "Funkcje.h"

using namespace std;


int main()
{
	Samochod* pHead = nullptr;		
	Samochod* pTail = nullptr;		
	Samochod* pCurrent = nullptr;	

	if (wczytajZpliku(pHead, pTail, pCurrent) == 0)
		cout << "\n	Wczytano dane!\n\n\n";
	else
		cout << "\n	Nie wczytano danych!\n\n\n";

	cout << "\n Nacisnij ENTER aby kontynuowac";
	getchar();

	system("cls");

	menu(pHead, pTail, pCurrent);

	return 0;
}