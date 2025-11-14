#include "lexer.hpp"
#include "utils.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
  // TODO : add support for lex, parse, codegen flags
  if (argc != 2) {
    cerr << "no compilation file provided" << endl;
    exit(1);
  }
  string filename = argv[1];
  ifstream file(filename);
  stringstream buffer;
  buffer << file.rdbuf();

  Lexer tok(buffer.str());
  vector<Token> tokens = tok.Lex();
  tok.PrintTokens();
}