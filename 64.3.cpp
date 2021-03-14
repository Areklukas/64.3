#include <iostream>
#include <fstream>
using namespace std;

const int SIZE = 200;
ifstream in("dane_obrazki.txt");
char tab[21][21];

void czytaj() 
{
	for (int i=0; i<21; i++) 
	{
    	for (int j=0; j<21; j++) 
		{
      		if (i==20 && j==20) return;
      		in>>tab[i][j];
    	}
  	}
}

int licz_niepr_poz() 
{
	int suma=0, licz=0;
  	for (int i=0; i<20; i++) 
	{
    	for (int j=0; j<21; j++) 
		{
      		if (tab[i][j]=='1' && j!=20) suma++;
      		if (j==20) 
			{
        		if (suma % 2 == 0 && tab[i][j] == '1') licz++;
        		if (suma % 2 == 1 && tab[i][j] == '0') licz++; 
      		}
    	}
		suma=0;
  	}
return licz;
}
int licz_niepr_pion() 
{
	int suma=0, licz=0;
	for (int i=0; i<20; i++) 
	{
    	for (int j=0; j<21; j++) 
		{
      		if (tab[j][i]=='1' && j!=20) suma++;
      		if (j==20) 
			{
        		if (suma % 2 == 0 && tab[j][i] == '1') licz++;
        		if (suma % 2 == 1 && tab[j][i] == '0') licz++; 
      		}
    	}
    	suma=0;
  	}
	return licz;
}
int licz_niepr() 
{
	return licz_niepr_poz() + licz_niepr_pion();
}
bool poprawne () 
{
	if (licz_niepr()==0) return true;
}
bool licz_napr() 
{
	if (poprawne()) return false;
  	if (licz_niepr_pion()<2 && licz_niepr_poz()<2)
	return true;
}

int main() {
	int licz_popr=0, licz_naprawialne=0, licz_nienaprawialne=0, 
	max_zla_parzystosc=0, zla_parzystosc;

for (int n=0; n<SIZE; n++) 
{
	czytaj();
	if (poprawne()) licz_popr++;
    else if (licz_napr()) licz_naprawialne++;
    else licz_nienaprawialne++;
    zla_parzystosc = licz_niepr();
    if (zla_parzystosc > max_zla_parzystosc) max_zla_parzystosc = zla_parzystosc;
}

cout<<"Liczba obrazkow poprawnych: "<<licz_popr<<endl;
cout<<"Liczba obrazkow naprawialnych: "<<licz_naprawialne<<endl;
cout<<"Liczba obrazkow nienaprawialnych: "<<licz_nienaprawialne<<endl;
cout<<"Najwieksza liczba blednych parzystoœci: "<<max_zla_parzystosc<<endl;  
}

/* Wyniki
Liczba obrazkow poprawnych:171
Liczba obrazkow naprawialnych: 14
Liczba obrazkow nienaprawialnych: 15
Najwieksza liczba blednych parzystosci: 7
*/
