#include "ListaPracownikow.h"

ListaPracownikow::ListaPracownikow()
{
	this->m_pPoczatek = nullptr;
	this->m_nLiczbaPracownikow = 0;
}

ListaPracownikow::~ListaPracownikow()
{
	/*Pracownik* pp = this->m_pPoczatek;
	for (int i = 0; i < this->m_nLiczbaPracownikow; i++) {
		delete pp;
		pp = pp->m_pNastepny;
	}*/
	Pracownik* pp = this->m_pPoczatek;
	while (pp != nullptr) {
		Pracownik* nextPracownik = pp->m_pNastepny;
		delete pp;
		pp = nextPracownik;
	}

	this->m_pPoczatek = nullptr;
	this->m_nLiczbaPracownikow = 0;
}

void ListaPracownikow::Dodaj(const Pracownik& p)
{
	Pracownik* pom;
	Pracownik* kopia = new Pracownik(p);
	if (this->m_nLiczbaPracownikow == 0) {
		this->m_pPoczatek = new Pracownik(p);
		this->m_pPoczatek->m_pNastepny = nullptr;
		this->m_nLiczbaPracownikow++;
	}
	else {
		pom = m_pPoczatek;
		if (this->m_pPoczatek->Porownaj(p) > 0) {
			m_pPoczatek = kopia;
			kopia->m_pNastepny = pom;
			m_nLiczbaPracownikow++;
		}
		else {
			//for (int i = 0; i < m_nLiczbaPracownikow; i++) {
			while(pom){
				if (pom->Porownaj(p) == 0) {
					break;
				}
				if (pom->m_pNastepny != nullptr) {
					if (pom->Porownaj(p) < 0 && pom->m_pNastepny->Porownaj(p) > 0) {
						kopia->m_pNastepny = pom->m_pNastepny;
						pom->m_pNastepny = kopia;
						m_nLiczbaPracownikow++;
						//break;
					}
				}

				if (pom->Porownaj(p) < 0 && pom->m_pNastepny == nullptr) {
					pom->m_pNastepny = kopia;
					kopia->m_pNastepny = nullptr;
					m_nLiczbaPracownikow++;
					//break;
				}
				pom = pom->m_pNastepny;
			}
		}
	}
}

void ListaPracownikow::Usun(const Pracownik& wzorzec)
{
	if (this->m_nLiczbaPracownikow > 0) {
		Pracownik* pom;
		if (m_pPoczatek->Porownaj(wzorzec) == 0) {
			m_pPoczatek = m_pPoczatek->m_pNastepny;
			m_nLiczbaPracownikow--;
		}
		else {
			pom = m_pPoczatek;
			for (int i = 1; i < m_nLiczbaPracownikow; i++) {
				if (pom->m_pNastepny->Porownaj(wzorzec) == 0) {
					pom->m_pNastepny = pom->m_pNastepny->m_pNastepny;
					break;
				}
				pom = pom->m_pNastepny;
			}

		}
		std::cout << "Usunieto pracownika!" << std::endl;
	}
	else std::cout << "Najpierw musisz dodac pracownikow!" << std::endl;
}

void ListaPracownikow::WypiszPracownikow() const
{
	Pracownik* pom = m_pPoczatek;
	std::cout << "LISTA PRACOWNIKOW : " << std::endl;
	for (int i = 0; i < m_nLiczbaPracownikow; i++) {
		pom->Wypisz();
		pom = pom->m_pNastepny;
	}

}

const Pracownik* ListaPracownikow::Szukaj(const char* nazwisko, const char* imie) const
{
	if (this->m_nLiczbaPracownikow > 0) {
		Pracownik* pom = m_pPoczatek;
		for (int i = 0; i < m_nLiczbaPracownikow; i++) {
			if (pom->SprawdzImie(imie) == 0 && pom->SprawdzNazwisko(nazwisko) == 0) {
				return pom;
			}
		}
	}
	return nullptr;
}

void ListaPracownikow::ZapiszDoPliku(std::string nazwa) const
{
	ofstream Plik(nazwa, std::ios::trunc);

	Pracownik* aktualny = this->m_pPoczatek;

	while (aktualny != nullptr) {
		Plik << *(aktualny) << "\n";
		aktualny = aktualny->m_pNastepny;
	}

	Plik.close();
}

void ListaPracownikow::WczytajZPliku(std::string nazwa)
{
	ifstream Plik(nazwa, ifstream::in);
	Pracownik tymczasowy;

	while (Plik >> tymczasowy) {
		Dodaj(tymczasowy);
	}
	Plik.close();
}
