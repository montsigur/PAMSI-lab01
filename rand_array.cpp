#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include <cmath>
using namespace std;

void wypelnijLosowymi(int** tab, int nWierszy, int mKolumn, int x) {

  for(int i=0; i<nWierszy; i++)
    for(int j=0; j<mKolumn; j++) {

      tab[i][j] = rand() % (x+1);
      
    }
  
}

int znajdzMaks(int** tab, int nWierszy, int mKolumn) {

  int maxWartosc = 0;
  
  for(int i=0; i<nWierszy; i++)
    for(int j=0; j<mKolumn; j++) {

      if (tab[i][j] > maxWartosc)
	maxWartosc = tab[i][j];
      
    }
  
  return maxWartosc;
  
}

void wyswietl(int** tab, int nWierszy, int mKolumn) {

  int maxWartosc = znajdzMaks(tab, nWierszy, mKolumn);
  int szerokosc = log10(maxWartosc) + 2;

  for(int i=0; i<nWierszy; i++)
    for(int j=0; j<mKolumn; j++) {

      cout << setw(szerokosc) << tab[i][j];
      if (j == mKolumn-1)
	cout << endl;
      
    }

}

int main() {

  srand(time(NULL));

  int mKolumn, nWierszy, x;

  cout << "Podaj ilosc wierszy: ";
  cin >> nWierszy;

  cout << "Podaj ilosc kolumn: ";
  cin >> mKolumn;

  cout << "Podaj gorna granice zakresu wartosci losowych: ";
  cin >> x;

  int** tab = new int*[nWierszy];
  for (int i=0; i<nWierszy; i++)
    tab[i] = new int[mKolumn];

  wypelnijLosowymi(tab, nWierszy, mKolumn, x);

  wyswietl(tab, nWierszy, mKolumn);

  cout << "Najwieksza liczba w tablicy: " << znajdzMaks(tab, nWierszy, mKolumn) << endl;;
  
  return 0;

}
