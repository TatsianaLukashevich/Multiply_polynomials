#ifndef WSPOL_H_
#define WSPOL_H_
#include <iostream>
using namespace std;
const int n = 3;/**< ilosc wspolczynnikow w wielomianie */
const int m = 2;/**< rozmiar macierzy*/
//!klasa Wieomianow
/*!
Tworzymy z pomoca tej klasy wielomiany
*/
class Wielomian
{
private:
	int wspolczynnik[n]; /**<Tablica wspolczynnikow wielomianu>**/
public:
	//!Konstruktor
	/*!
	Z pomoca konstruktora tworzymy klase wielomianow
	*/
	Wielomian(int tabwspol[]);
	//!Konstruktor domyslny
	/*!
	Z pomoca konstruktora tworzymy domyslna klase wielomianow
	*/
	Wielomian();
	//! Konstruktor kopiujuacy lub Wielomian(Wielomian)
	/*!
	Za pomoca tego konstruktora kopiujemy wartosci jednego wielomiana w drugi
	*/
	Wielomian(const Wielomian &q); 
	//! Destruktor
	/*!
	Z pomoca destruktora usuwamy klase wielomianow
	*/
	~Wielomian();
	//!Przyrownanie wielomianow
	/*!
	\ Arg: wielomian ktory przyrownujemy
	\ work: przyrownujemy wielomiany
	\ return: drugi wielomian do ktorego przyrownywali
	*/
	Wielomian operator=(const Wielomian & q) ;
	//!Suma wielomianow
	/*!
	\ Arg: wielomian ktory dodaemy
	\ work: dodajemy wielomiany
	\ ret: sume wielomianow
	*/
	Wielomian operator+(const Wielomian & q) const;
	//!Roznica wielomianow
	/*!
	\ Arg: wielomian ktory odejmujemy
	\ work: odejmowanie  wielomiany
	\ ret: roznice wielomianow
	*/
	Wielomian operator-(const Wielomian & q) const;
	//!Mnozenie wielomianow
	/*!
	\ Arg: wielomian ktory mnozymy
	\ work: mnozenie  wielomiany
	\ ret: pomnozone wielomiane
	*/
	Wielomian operator*(const Wielomian & q) const;
	//!Porownanie wielomianow
	/*!
	\ Arg: wielomian ktory porownujemy
	\ work: porownywanie  wielomianow
	\ ret: true-jesli wielomiany rowny sobie,false-kiedy nie sa rowne
	*/
	bool operator==(const Wielomian & q) const;

};
//!klasa Macierzy
/*!
Tworzymy z pomoca tej klasy macierzy
*/
class Macierz
{
private:
	Wielomian macierz[m][m]; /**<Tablica sluzaca do przechwywaia wilomianow>*/
public:
	//!Konstruktor
	/*!
	Z pomoca konstruktora tworzymy klase macierzy
	*/
	Macierz(Wielomian M[m][m]); 
	//!Konstruktor domyslny
	/*!
	Z pomoca konstruktora tworzymy domyslna klase macierzy
	*/
	Macierz();
	//! Konstruktor kopiujuacy lub Macierz(Macierz)
	/*!
	Za pomoca tego konstruktora kopiujemy wartosci jednej macierzy w drugi
	*/
	Macierz(const Macierz &q);
	//! Destruktor
	/*!
	Z pomoca destruktora usuwamy klase macierzy
	*/
	~Macierz();
	//!Suma macierzy
	/*!
	\ Arg: macierzy ktory dodaemy
	\ work: dodajemy macierzy
	\ ret: sume macierzy
	*/
	Macierz operator+(const Macierz & q) const; 
	//!Odejmowanie macierzy
	/*!
	\ Arg: macierz ktora odejmujemy
	\ work: odejmujemy dwie macierzy
	\ ret: roznice dwoch macierzy
	*/
		Macierz operator-(const Macierz & q) const; 
		//!Mnozenie macierzy
		/*!
		\ Arg: macierz ktora mnozymy
		\ work: mnozymy dwie macierzy
		\ ret: mnozenie dwoch macierzy
		*/
	Macierz operator*(const Macierz & q) const;
	//!Porownanie macierzy
	/*!
	\ Arg: macierz ktory porownujemy
	\ work: porownywanie  maciezry
	\ ret: true-jesli macierzy rowny sobie,false-kiedy nie sa rowne
	*/
	bool operator==(const Macierz & q) const;
};
#endif 
