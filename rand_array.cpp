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

  int mKolumn, nWierszy, x, wybor = -1;

  cout << "Podaj ilosc wierszy: ";
  cin >> nWierszy;

  cout << "Podaj ilosc kolumn: ";
  cin >> mKolumn;

  int** tab = new int*[nWierszy];
  for (int i=0; i<nWierszy; i++)
    tab[i] = new int[mKolumn];

  while (wybor != 0) {

    cout << endl << "\t################# MENU #################\n\
\t1 - wypelnij tablice liczbami losowymi\n\
\t2 - wyswietl zawartosc tablicy\n\
\t3 - wyswietl wartosc maksymalna w tablicy\n\
\t0 - wyjscie z programu\n\
\tWybor: ";

    cin >> wybor;
    cout << endl;

    switch (wybor) {

    case 1:
      cout << "Podaj gorna granice zakresu wartosci losowych: ";
      cin >> x;
      wypelnijLosowymi(tab, nWierszy, mKolumn, x);
      cout << "Done." << endl;
      break;

    case 2:
      wyswietl(tab, nWierszy, mKolumn);
      break;

    case 3:
      cout << "Najwieksza liczba w tablicy: " << znajdzMaks(tab, nWierszy, mKolumn) << endl;
      break;

    case 0:
      break;

    default:
      cout << "Nieznana opcja." << endl;
      break;

    }
  }
  
  return 0;

}
