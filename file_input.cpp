// Wojciech Michałowski
// nr 218705

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void zapiszDoBin(const char* tab, int rozmiar) {

  ostream F("inbin.bin");
  char c = rozmiar + '0';
  
  F.write(&c, 1);
  F.write(tab, rozmiar);

  F.close();

}

void zapiszDoTxt(char* tab, int rozmiar) {

  ostream F("intxt.txt");

  F << rozmiar;

  for(int i=0; i<rozmiar; i++)
    F << " "<< tab[i];

  F.close();
}

char* odczytZTxt(string nazwaPliku) {

  istream F(nazwaPliku);

  char* tab = F.getline();

  
}


int main() {

  return 0;
  
}
