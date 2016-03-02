#include <iostream>
#include <fstream>
using namespace std;

int main() {

  fstream F("binfile.bin", fstream::binary | fstream::out);

  string s;
  s = "string";

  F.write((char*) &s, sizeof(s));
  
  F.close();

  return 0;
  
}
