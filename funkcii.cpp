#include "class.h"

/*Wielomian::Wielomian()
{
a=b=c=0;
}
*/
Wielomian::Wielomian()
{
	for (int i = 0; i<n; i++)
		wspolczynnik[i] = 0;
}
Wielomian::~Wielomian(){}

Wielomian::Wielomian(int tabwspol[])
{
	for (int i = 0; i < n; i++) //kopiujemy wsolczynniki
		wspolczynnik[i] = tabwspol[i];
}

Wielomian::Wielomian(const Wielomian &q)  //konstruktor kopiujacy
{
	for (int i = 0; i < n; i++)
		wspolczynnik[i] = q.wspolczynnik[i];
}

 Wielomian Wielomian::operator=(const Wielomian & q) 
{
	for (int i = 0; i < n; i++)
		(*this).wspolczynnik[i] = q.wspolczynnik[i];
	return *this;

}
Macierz::Macierz(const Macierz &q)
{
	for (int j = 0; j < m; j++)
	for (int i = 0; i < m; i++)
		macierz[j][i] = q.macierz[j][i];

}

Wielomian Wielomian::operator+(const Wielomian & q) const
{
	Wielomian suma;
	for (int i = 0; i < n; i++)
		suma.wspolczynnik[i] = wspolczynnik[i] + q.wspolczynnik[i];
	//wspolczynnik[2]=1;
	return suma;
}
Wielomian Wielomian::operator-(const Wielomian & q) const
{
	Wielomian roznica;
	for (int i = 0; i < n; i++)
		roznica.wspolczynnik[i] = wspolczynnik[i] - q.wspolczynnik[i];
	return roznica;

}
Wielomian Wielomian::operator*(const Wielomian & q) const
{
	Wielomian iloczyn;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
		if (i + j < n)
			iloczyn.wspolczynnik[i + j] += (wspolczynnik[i])* (q.wspolczynnik[j]);
	}
	return iloczyn;
}
bool Wielomian::operator==(const Wielomian & q) const
{
	for (int i = 0; i < n; i++)
	{
		if (wspolczynnik[i] != q.wspolczynnik[i])
			return false;
	}
	return true;
}
bool Macierz::operator==(const Macierz & q) const
{
for (int j = 0; j < m; j++)
for (int i = 0; i < m; i++)
{
if (!(macierz[j][i] == q.macierz[j][i]))
return false;
}
return true;
}
/*
bool operator==(const Macierz & q, const Macierz & q1) const
{
	for (int j = 0; j < m; j++)
	for (int i = 0; i < m; i++)
	{
		if (q.macierz[j][i] != q1.macierz[j][i])
			return false;
	}
	return true;
}*/

/*Macierz::Macierz()
{
Wielomian a,b,c,d;
macierz[0]=a;
macierz[1]=b;
macierz[2]=c;
macierz[3]=d;
}*/

Macierz::Macierz()
{}

Macierz::Macierz(Wielomian M[][m])
{
	for (int j = 0; j < m; j++)
	for (int i = 0; i < m; i++)
		macierz[j][i] = M[j][i];
}

Macierz::~Macierz()
{ }

Macierz Macierz:: operator+(const Macierz & q) const
{
	Macierz suma;
	for (int j = 0; j < m; j++)
	for (int i = 0; i < m; i++)
		suma.macierz[j][i] = macierz[j][i] + q.macierz[j][i];
	return suma;
}
Macierz Macierz:: operator-(const Macierz & q) const
{
	Macierz roznica;
	for (int j = 0; j < m; j++)
	for (int i = 0; i < m; i++)
		roznica.macierz[i][j] = macierz[i][j] - q.macierz[i][j];
	return roznica;
}
Macierz Macierz:: operator*(const Macierz & q) const
{
	Macierz iloczyn;
	for (int i = 0; i < m; i++)
	for (int j = 0; j < m; j++)
	for (int g = 0; g < m; g++)
	{
		Wielomian tmp = macierz[j][g] * q.macierz[g][i];
		iloczyn.macierz[i][j] = iloczyn.macierz[i][j] + tmp;
	}
	return iloczyn;
}

ostream & operator<<(ostream & os, const Macierz & q){
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < m; i++)
			os << q.macierz[j][i];
		os << "\n";
	}

	return os;
}
ostream & operator<<(ostream & os, const Wielomian & q)
{
	os << "[";
	for (int i = 0; i <n; i++){
		os << q.wspolczynnik[i] << "x^" << i;
		if (i< n - 1)
			os << "+";
	}
	os << "]";
	return os;
}
/*string Macierz::print(){
string ret;
string tmp;
for(int j = 0; j < m; j++)
{
for(int i = 0; i < m; i++)
{
ret+=macierz[j][i].print();
ret+=tmp;
}
tmp+="\n";
ret+=tmp;
}
return ret;
}*/
/*
string Macierz::operator<<(const Macierz & q){
string ret;
string tmp;
for(int j = 0; j < m; j++)
{
for(int i = 0; i < m; i++)
{
//ret+=<<q.macierz[j][i].print();
ret+=tmp;
}
tmp+="\n";
ret+=tmp;
}
return ret;
}
*/
/*string Wielomian::print()
{
string ret;
for(int i = 0; i < n ; i++)
{
string tmp;
tmp="[";
tmp+=wspolczynnik[i];
tmp+="x^";
tmp+=i;
tmp+="]";
ret+=tmp;
}
cout<<ret;
return ret;
}*/

/*
string Wielomian::operator<<(const Wielomian & q)
{
string ret;
for(int i = 0; i < n ; i++)
ret+=q.wspolczynnik[i]+"x^"+ i;
return ret;
}*/
