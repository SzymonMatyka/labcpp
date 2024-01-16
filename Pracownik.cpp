#include "Pracownik.h"
#include <iostream>

using namespace std;

Pracownik::Pracownik(const char* im, const char* naz,
    int dzien, int miesiac, int rok) : m_nIDZatrudnienia{ ++id }, m_DataUrodzenia(dzien, miesiac, rok)
{
    m_Imie.Ustaw(im);
    m_Nazwisko.Ustaw(naz);

    m_pNastepny = nullptr;
}

////////wa¿ne!!!!!!///////////
int Pracownik::id{};

Pracownik::Pracownik(const Pracownik& wzor) : m_nIDZatrudnienia{wzor.m_nIDZatrudnienia},
    m_DataUrodzenia(wzor.m_DataUrodzenia.Dzien(), wzor.m_DataUrodzenia.Miesiac(), wzor.m_DataUrodzenia.Rok())
{
    this->m_Imie.Ustaw(wzor.Imie());
    this->m_Nazwisko.Ustaw(wzor.Nazwisko());

    m_pNastepny = nullptr;
    
    //coœ jeszcze?
}

Pracownik& Pracownik::operator=(const Pracownik& wzor)
{
    //Pracownik temp(wzor); //????????
    //return temp;

    return *(new Pracownik(wzor));
}

const char* Pracownik::Imie() const
{
    return m_Imie.Zwroc();
}

const char* Pracownik::Nazwisko() const
{
    return m_Nazwisko.Zwroc();
}

void Pracownik::Imie(const char* nowe_imie)
{
    m_Imie.Ustaw(nowe_imie);
}

void Pracownik::Nazwisko(const char* nowe_nazwisko)
{
    m_Nazwisko.Ustaw(nowe_nazwisko);
}

void Pracownik::DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok)
{
    m_DataUrodzenia.Ustaw(nowy_dzien, nowy_miesiac, nowy_rok);
}

void Pracownik::Wypisz() const
{
    if (this->Imie() != nullptr && this->Nazwisko() != nullptr) {
        m_Imie.Wypisz();
        cout << "\t";
        m_Nazwisko.Wypisz();
        cout << "\t";
        m_DataUrodzenia.Wypisz();
        cout << "\t";
        cout << endl;
    }
    else {
        cout << "NIEZNALEZIONO!";
    }
}

void Pracownik::Wpisz()
{
    cout << "Imie: ";
    m_Imie.Wpisz();
    cout << "Nazwisko: ";
    m_Nazwisko.Wpisz();
    cout << "Data urodzenia:\n";
    m_DataUrodzenia.Wpisz();
}

int Pracownik::SprawdzImie(const char* por_imie) const
{
    return m_Imie.SprawdzNapis(por_imie);
}

int Pracownik::SprawdzNazwisko(const char* por_nazwisko) const
{
    return m_Nazwisko.SprawdzNapis(por_nazwisko);
}

int Pracownik::Porownaj(const Pracownik& wzorzec) const
{
    int wynik = this->SprawdzNazwisko(wzorzec.Nazwisko());

    if (!wynik) {
        wynik = this->SprawdzImie(wzorzec.Imie());
        if (!wynik) {
            wynik = this->m_DataUrodzenia.Porownaj(wzorzec.m_DataUrodzenia);
        }
    }
    
    return wynik;
}

bool Pracownik::operator==(const Pracownik& wzor) const
{
    if (this->Porownaj(wzor) == 0) return true;
    else return false;
}

ostream& operator<<(ostream& wy, const Pracownik& p)
{
    return wy << p.m_Imie << " " << p.m_Nazwisko << " " << p.m_DataUrodzenia;
}

istream& operator>>(istream& we, Pracownik& p)
{
    return we >> p.m_Imie >> p.m_Nazwisko >> p.m_DataUrodzenia;
}
