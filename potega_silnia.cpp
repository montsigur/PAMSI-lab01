#include <iostream>
#include <cstdlib>
using namespace std;

long int silnia(long int n) {

  if (n == 0 || n == 1)
    return 1;

  else if (n > 1)
    return n * silnia(n-1);

  else {
    cout << "Blad, silnia z liczby ujemnej: ";
    return 0;
  }

}

double potega(long int p, long int w) {

  if (w == 0)
    return 1;

  else if (w < 0)
    return 1 / potega(p, -w);
  
  else
    return p * potega(p, w-1);

}

int main() {

  long int n, w;

  cout << "Podaj pierwsza liczbe: ";
  cin >> n;

  cout << "Podaj druga liczbe: ";
  cin >> w;
  
  cout << n << "^" << w << " = " << potega(n, w) << endl;
  cout << w << "^" << n << " = " << potega(w, n)<< endl;
  cout << n << "! = " << silnia(n) << endl;
  cout << w << "! = " << silnia(w) << endl;  

  return 0;

}
