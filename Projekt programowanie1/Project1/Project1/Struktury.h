#pragma once


#include <string>
using namespace std;


struct Samochod
{
	string marka;					
	string model;					
	int rokProdukcji;				
	int przebieg;					
	string paliwo;				
	int cena;						

	Samochod* pNext;			
	Samochod* pPrev;			
};
