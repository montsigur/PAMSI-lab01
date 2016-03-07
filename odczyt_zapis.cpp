// Wojciech Michałowski
// nr 218705

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

bool zapisDoBin(const char* nazwa_pliku, const char* tab) {

  fstream plik(nazwa_pliku, ios::binary | ios::out);
  char c;
  int i = 0;
  
  if (plik.is_open()) {
  
    while ((c = tab[i++]) != EOF) {
      
      plik.put(c);
      
    }
    
    plik.close();

    return true;
  }

  else {
    
    cout << "Nie udalo sie otworzyc pliku." << endl;
    return false;

  }
}

bool zapisDoTxt(const char* nazwa_pliku, const char* tab) {

  fstream plik(nazwa_pliku, ios::out);
  char c;
  int i = 0;

  if (plik.is_open()) {
  
    while ((c = tab[i++]) != EOF) {
      
      plik.put(c);
      
    }
    
    plik.close();

    return true;
  }

  else {
    
    cout << "Nie udalo sie otworzyc pliku." << endl;
    return false;

  }
}

char* odczytZTxt(const char* nazwa_pliku) {

  fstream plik(nazwa_pliku, ios::in);
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
 
char* odczytZBin(const char* nazwa_pliku) {
  
  fstream plik(nazwa_pliku, ios::binary | ios::in);
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

 
int main() {
  
  string input;
  char* output;
  string nazwa_pliku;
  int wybor = -1;
  
  string menu = "############# MENU #############\n\
1 - zapis do pliku binarnego\n\
2 - zapis do pliku tekstowego\n\
3 - odczyt z pliku binarnego\n\
4 - odczyt z pliku tekstowego\n\
5 - wyswietl menu\n\
0 - wyjscie z programu\n";
  
  cout << endl << menu;

  while (wybor != 0) {

    cout << endl << "Wybor (5 - wyswietl menu): ";

    cin >> wybor;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    switch (wybor) {

    case 1:
      cout << "Podaj pelna nazwe pliku: ";
      cin >> nazwa_pliku;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Dane do zapisu: ";
      getline(cin, input);
      zapisDoBin(nazwa_pliku.c_str(), input.c_str());
      break;

    case 2:
      cout << "Podaj pelna nazwe pliku: ";
      cin >> nazwa_pliku;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Dane do zapisu: ";
      getline(cin, input);
      zapisDoTxt(nazwa_pliku.c_str(), input.c_str());
      break;

    case 3:
      cout << "Podaj pelna nazwe pliku: ";
      cin >> nazwa_pliku;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      output = odczytZBin(nazwa_pliku.c_str());
      if (output != NULL) {
	cout << "Odczytano:" << endl;
	cout << output << endl;
	delete output;
      }
      break;

    case 4:
      cout << "Podaj pelna nazwe pliku: ";
      cin >> nazwa_pliku;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      output = odczytZTxt(nazwa_pliku.c_str());
      if (output != NULL) {
	cout << "Odczytano:" << endl;
	cout << output << endl;
	delete output;
      }
      break;

    case 5:
      cout << endl << menu;
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
