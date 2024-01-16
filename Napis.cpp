#define _CRT_SECURE_NO_WARNINGS
#include "Napis.h"

Napis::Napis(const char* nap)
{
    /*this->m_nDI = strlen(nap) + 1;
    this->m_psznapis = new char[m_nDI];*/
    this->m_psznapis = nullptr;
    this->m_nDI = 0;
    this->Ustaw(nap);
}

Napis::~Napis()
{
    delete[]m_psznapis;
    m_nDI = 0;
}

Napis::Napis(const Napis& wzor) : m_nDI{wzor.m_nDI}
{
    this->Ustaw(wzor.m_psznapis);
}

Napis& Napis::operator=(const Napis& wzor)
{
    this->~Napis();
    new (this)Napis(wzor);
    return *this;
}

const char* Napis::Zwroc() const
{
    return this->m_psznapis;
}

void Napis::Ustaw(const char* nowy_napis)
{
    this->~Napis();
    this->m_nDI = strlen(nowy_napis) + 1;
    this->m_psznapis = new char[m_nDI];
    strcpy(this->m_psznapis, nowy_napis);
}

void Napis::Wypisz() const
{
    cout << m_psznapis;
}

void Napis::Wpisz()
{
    char buffer[100];
    //cout << "Wprowadz: ";
    cin >> buffer;
    this->Ustaw(buffer);
    //cout << endl;
}

int Napis::SprawdzNapis(const char* por_napis) const
{
    return strcmp(this->m_psznapis, por_napis);
}

bool Napis::operator==(const Napis& wzor)const 
{
    if (this->SprawdzNapis(wzor.Zwroc()) == 0) {
        return true;
    }
    else {
        return false;
    }
    
}

ostream& operator<<(ostream& wy, const Napis& n)
{
    return wy << n.m_psznapis;
}

istream& operator>>(istream& we, Napis& n)
{
    char buffer[40];
    we >> buffer;
    n.Ustaw(buffer);
    return we;
}

