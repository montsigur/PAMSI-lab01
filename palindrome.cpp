#include <iostream>
#include <string>
using namespace std;

bool jestPalindromem(string napis) {

  int dlugosc = napis.size();
  string podNapis;

  if (dlugosc < 2)
    return true;

  else if (napis[0] == napis[dlugosc-1]) {

    for (int ind=1; ind<dlugosc-1; ind++)
      podNapis += napis[ind];

    return jestPalindromem(podNapis);
  }

  else
    return false;
  
}

int main() {

  string s;
  cout << "Wprowadz slowo: ";
  cin >> s;

  cout << "Czy \"" << s << "\" jest palindromem? " << jestPalindromem(s) << endl;
  
  return 0;

}
