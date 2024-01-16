#include "Pracownik.h"
#include <iostream>
#include "Napis.h"
#include "Data.h"
#include "ListaPracownikow.h"

using namespace std;

int main() {

	ListaPracownikow lista_pracownikow;

	Pracownik pracownik;

	pracownik.Imie("Janusz");
	pracownik.Nazwisko("Zubr");
	pracownik.DataUrodzenia(12, 12, 1980);
	
	pracownik.Wypisz();

	
	
	bool isRun = true;
	char imie[20] = "";
	char nazwisko[20] = "";
	

	while (isRun) {
		unsigned int wybor = 9;

		cout << endl << "Menu wybierz opcje" << endl;
		cout << "1-zwroc imie" << endl;
		cout << "2-zwroc nazwisko" << endl;
		cout << "3-ustaw nowe imie" << endl;
		cout << "4-ustaw nowe nazwisko" << endl;
		cout << "5-ustaw nowe dane" << endl;
		cout << "6-wypisz dane" << endl;
		cout << "7-sprawdz imie" << endl;
		cout << "8-sprawdz nazwisko" << endl;
		cout << "9-wyjscie" << endl;
		cout << "10-dodaj pracownika do listy" << endl;
		cout << "11-usun pracownika z listy" << endl;
		cout << "12-wypisz liste pracownikow" << endl;
		cout << "13-szukaj pracownika w liscie" << endl;
		cout << "14-zapisz do pliku" << endl;
		cout << "15-wczytaj z pliku" << endl;
		cin >> wybor;


		switch (wybor) {
		case 1:
			cout << "Imie pracownika: " << pracownik.Imie() << endl;
			break;
		case 2:
			cout << "Nazwisko pracownika: " << pracownik.Nazwisko() << endl;
			break;
		case 3:
			cout << "Ustaw nowe imie" << endl;
			cin >> imie;
			pracownik.Imie(imie);
			break;
		case 4:
			cout << "Ustaw nowe nazwisko" << endl;
			cin >> nazwisko;
			pracownik.Nazwisko(nazwisko);
			break;
		case 5:
			cout << "Ustaw nowe dane:" << endl;
			pracownik.Wpisz();
			break;
		case 6:
			cout << "Wypisz dane:" << endl;
			pracownik.Wypisz();
			break;
		case 7:
			cout << "Sprawdz imie" << endl;
			cin >> imie;
			if (pracownik.SprawdzImie(imie) == 0) {
				cout << "Imie sie zgadza!" << endl;
			}
			else {
				cout << "Imie sie nie zgadza!" << endl;
			}
			break;
		case 8:
			cout << "Sprawdz nazwisko" << endl;
			
			cin >> nazwisko;
			if (pracownik.SprawdzNazwisko(nazwisko) == 0) {
				cout << "Nazwisko sie zgadza!" << endl;
			}
			else {
				cout << "Nazwisko sie nie zgadza!" << endl;
			}
			break;
		case 9:
			cout << "wyjscie" << endl;
			isRun = false;
			break;
		case 10: {
			Pracownik nowy;
			nowy.Wpisz();
			lista_pracownikow.Dodaj(nowy);
			break;
		}
		case 11: {
			Pracownik do_usuniecia;
			do_usuniecia.Wpisz();
			lista_pracownikow.Usun(do_usuniecia);
			break;
		}
		case 12:
			lista_pracownikow.WypiszPracownikow();
			break;
		case 13: {
			cout << "Podaj imie do wyszukania: ";
			cin >> imie;
			cout << "Podaj nazwisko do wyszukania: ";
			cin >> nazwisko;
			cout << "Szukany pracownik: ";
			const Pracownik* temp = lista_pracownikow.Szukaj(nazwisko, imie);
			if (temp != nullptr) {
				temp->Wypisz();
			}
			else {
				cout << "Nie znaleziono" << endl;
			}
			break;
			}
		case 14:
			lista_pracownikow.ZapiszDoPliku("pawel.kox");
			break;
		case 15:
			lista_pracownikow.WczytajZPliku("pawel.kox");
			break;
		}

		memset(&imie[0], 0, sizeof(imie));
		memset(&nazwisko[0], 0, sizeof(nazwisko));
	}
	return 0;
}