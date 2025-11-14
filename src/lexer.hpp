#include <cstddef>
#include <string>
#include <vector>

enum TokenType {
  // single char tokens
  OPEN_BRACE,
  CLOSE_BRACE,
  OPEN_PARENTH,
  CLOSE_PARENTH,
  SEMICOLON,
  // keywords
  RETURN,
  INT,
  VOID,
  // literals
  IDENTIFIER,
  NUMBER,
  //other
  _EOF
};

class Token {
public:
  TokenType type;
  std::string value;
  std::size_t line;

  Token(TokenType tt, std::string val, size_t line); 
  std::string toString();
};

class Lexer {
  size_t index = 0;
  size_t start = 0;
  size_t line = 15;
  std::string input;
  std::vector<Token> tokens;

  void addToken(TokenType tt, std::string val = "");
  bool isAtEnd();
  char step();
  char peek();
  void scanAlpha();
  void scanNumber();
  void scanToken();
public:
  Lexer(std::string input);
  std::vector<Token> Lex();
  void PrintTokens();
};
