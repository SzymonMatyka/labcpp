#include "Data.h"
#include <iostream>
using namespace std;

void Data::Koryguj()
{
	if (m_nRok < 1) {
		m_nRok = 1;
	}

	if (m_nMiesiac < 1) {
		m_nMiesiac = 1;
	}
	else if (m_nMiesiac > 12) {
		m_nMiesiac = 12;
	}

	int LengthMsc[] = { 31, 28, 31, 30, 31, 30,31,31,30,31,30,31 };


	if (m_nRok % 4 == 0 && (m_nRok % 100 != 0 || m_nRok % 400 == 0)) {
		if (m_nMiesiac == 2 && m_nDzien > 29) {
			m_nDzien = 29;
		}
	}
	else {
		if (m_nDzien < 1) {
			m_nDzien = 1;
		}
		else if (m_nDzien > LengthMsc[m_nMiesiac-1]) {
			m_nDzien = LengthMsc[m_nMiesiac-1];
		}
	}
}

Data::Data(int d, int m, int r) : m_nDzien(d), m_nMiesiac(m), m_nRok(r)
{
	Koryguj();
}

void Data::Ustaw(int d, int m, int r)
{
	this->m_nDzien = d;
	this->m_nMiesiac = m;
	this->m_nRok = r;
	this->Koryguj();
}

int Data::Dzien() const
{
	return m_nDzien;
}

int Data::Miesiac() const
{
	return m_nMiesiac;
}

int Data::Rok() const
{
	return m_nRok;
}

void Data::Wypisz() const
{
	cout << m_nDzien << "-" << m_nMiesiac << "-" << m_nRok;
}

void Data::Wpisz()
{
	cout << "Wpisz dzien: ";
	cin >> m_nDzien;
	cout << "Wpisz miesiac: ";
	cin >> m_nMiesiac;
	cout << "Wpisz rok: ";
	cin >> m_nRok;
	Koryguj();
}

int Data::Porownaj(const Data& wzor) const
{
	if (this->m_nRok < wzor.m_nRok) {
		return -1;
	}
	else if (this->m_nRok > wzor.m_nRok) {
		return 1;
	}
	else {
		if (this->m_nMiesiac < wzor.m_nMiesiac) {
			return -1;
		}
		else if (this->m_nMiesiac > wzor.m_nMiesiac) {
			return 1;
		}
		else {
			if (this->m_nDzien < wzor.m_nDzien) {
				return -1;
			}
			else if (this->m_nDzien > wzor.m_nDzien) {
				return 1;
			}
			else {
				return 0;
			}
		}
	}
}

ostream& operator<<(ostream& wy, const Data& d)
{
	wy << d.m_nDzien << " " << d.m_nMiesiac << " " << d.m_nRok;
	return wy;
}

istream& operator>>(istream& we, Data& d)
{
	we >> d.m_nDzien >> d.m_nMiesiac >> d.m_nRok;
	d.Koryguj();
	return we;
}
