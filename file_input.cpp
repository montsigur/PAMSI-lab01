// Wojciech Michałowski
// nr 218705

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

void zapisDoBin(const char* tab) {

  fstream plik("binarny.dat", ios::binary | ios::out);
  char c;
  int i = 0;
  
  if (plik.is_open()) {
  
    while ((c = tab[i++]) != EOF) {
      
      plik.put(c);
      
    }
    
    plik.close();
    
  }

  else
    cout << "Nie udalo sie otworzyc pliku." << endl;
}

void zapisDoTxt(const char* tab) {

  fstream plik("tekstowy.txt", ios::out);
  char c;
  int i = 0;

  if (plik.is_open()) {
  
    while ((c = tab[i++]) != EOF) {
      
      plik.put(c);
      
    }
    
    plik.close();
    
  }

  else
    cout << "Nie udalo sie otworzyc pliku." << endl;
}

char* odczytZTxt() {

  fstream plik("tekstowy.txt", ios::in);
  int dlugosc;
  char* odczyt = NULL;

  if (plik.is_open()) {
  
    plik.seekg(0, ios::end);
    dlugosc = plik.tellg();
    plik.seekg(0, ios::beg);
    
    odczyt = new char[dlugosc];
    
    plik.read(odczyt, dlugosc);
    
    plik.close();

  }

  else
    cout << "Nie udalo sie otworzyc pliku." << endl;
  
  return odczyt;
}
 
char* odczytZBin() {
  
  fstream plik("binarny.dat", ios::binary | ios::in);
  int dlugosc;
  char* odczyt;

  if (plik.is_open()) {
  
    plik.seekg(0, ios::end);
    dlugosc = plik.tellg();
    plik.seekg(0, ios::beg);
    
    odczyt = new char[dlugosc];
    
    plik.read(odczyt, dlugosc);
    
    plik.close();

  }

  else
    cout << "Nie udalo sie otworzyc pliku." << endl;

  return odczyt;
}

 
int main() {
  
  string input;
  char* output;
  int wybor = -1;
  
  string menu = "1 - zapis do pliku binarnego\n\
2 - zapis do pliku tekstowego\n\
3 - odczyt z pliku binarnego\n\
4 - odczyt z pliku tekstowego\n\
5 - wyswietl menu\n\
0 - wyjscie z programu\n";
  
  cout << menu;

  while (wybor != 0) {

    cout << endl << "Wybor (5 - wyswietl menu): ";

    cin >> wybor;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.sync();
    
    switch (wybor) {

    case 1:
      getline(cin, input);
      zapisDoBin(input.c_str());
      break;

    case 2:
      getline(cin, input);
      zapisDoTxt(input.c_str());
      break;

    case 3:
      output = odczytZBin();
      cout << output << endl;
      delete output;
      break;

    case 4:
      output = odczytZTxt();
      cout << output << endl;
      delete output;
      break;

    case 5:
      cout << menu;
      break;
      
    case 0:
      break;

    default:
      cout << "Nieznana opcja. Sprobuj ponownie." << endl;
      break;
      
    }
  }
  
  return 0;
  
}
