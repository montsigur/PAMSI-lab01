#include <iostream>
using namespace std;

int silnia(int n) {

  if (n == 0 || n == 1)
    return 1;

  else if (n > 1)
    return n * silnia(n-1);

  else
    return -1;
  
}

double potega(int p, int w) {

  if (w == 0)
    return 1;

  else if (w < 0)
    return 1 / potega(p, -w);
  
  else
    return p * potega(p, w-1);

}

int main() {

  int n, w;

  cout << "Podaj pierwsza liczbe: ";
  cin >> n;

  cout << "Podaj druga liczbe: ";
  cin >> w;
  
  cout << n << "! = " << silnia(n) << endl;
  cout << w << "! = " << silnia(w) << endl;
  cout << n << "^" << w << " = " << potega(n, w) << endl;
  cout << w << "^" << n << " = " << potega(w, n)<< endl;
  
  return 0;

}
