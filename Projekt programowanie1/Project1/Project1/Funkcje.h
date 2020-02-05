#pragma once


int wczytajZpliku(Samochod* &pHead, Samochod* &pTail, Samochod* &pCurrent);


void usunBiezacy(Samochod* &pHead, Samochod* &pTail, Samochod* &pCurrent);


void dodaj(Samochod* &pHead, Samochod* &pTail, Samochod* &pCurrent);


void drukuj(Samochod* pHead, Samochod* pCurrent);


void zapisz(Samochod* pHead);


void wyszukajPoMarce(Samochod* pHead);


void wyszukajPoModelu(Samochod* pHead);


void wyszukajPoRoku(Samochod* pHead);


void wyszukajPoPrzebiegu(Samochod* pHead);


void wyszukajPoPaliwie(Samochod* pHead);


void wyszukiwaniePoCenie(Samochod* pHead);


void menuWyszukiwania(Samochod* pHead);


void zwolnijPamiec(Samochod* &pHead, Samochod* &pTail, Samochod* &pCurrent);


void menu(Samochod* &pHead, Samochod* &pTail, Samochod* &pCurrent);
