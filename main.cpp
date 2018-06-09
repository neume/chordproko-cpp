#include <iostream>
#include "scanner/scanner.cpp"
using namespace std;
string get_token_string(int value) {
  switch(value) {
    case CHORD:       return "CHORD";
    case LYRIC:       return "LYRIC";
    case NEWLINE:     return "NEWLINE";
    case DIRECTIVE:   return "DIRECTIVE";
    case EOF:         return "EOF";
    default:          return "DEFAULT";
  }
}
int main() {
  Scanner scanner = Scanner();
  scanner.print();

  while(true) {
    Token token = scanner.scan();
    cout << get_token_string(token.value) << ": " << token.lexeme << endl;
    if (token.value == EOF) {
      break;
    }
  }
}
