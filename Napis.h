#pragma once
#include <iostream>
#include <string.h>

using namespace std;

class Napis
{
private:
	char* m_psznapis;
	int m_nDI;
public:
	Napis(const char* nap = "");
	~Napis();
	Napis(const Napis& wzor);
	Napis& operator=(const Napis& wzor);

	const char* Zwroc() const;
	void Ustaw(const char* nowy_napis);
	void Wypisz() const;
	void Wpisz();
	int SprawdzNapis(const char* por_napis) const;

	bool operator==(const Napis& wzor) const;
	friend ostream& operator<<(ostream& wy, const Napis& n);
	friend istream& operator>>(istream& we, Napis& n);
};

