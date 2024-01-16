#pragma once
#include "Pracownik.h"
#include <iostream>
#include <fstream>

class ListaPracownikow
{
private:
	Pracownik* m_pPoczatek;
	int m_nLiczbaPracownikow;
public:
	ListaPracownikow();
	~ListaPracownikow();
	void Dodaj(const Pracownik& p);
	void Usun(const Pracownik& wzorzec);
	void WypiszPracownikow() const;
	const Pracownik* Szukaj(const char* nazwisko, const char* imie) const;

	void ZapiszDoPliku(std::string nazwa) const;
	void WczytajZPliku(std::string nazwa);

};

