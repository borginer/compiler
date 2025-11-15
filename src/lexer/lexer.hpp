#pragma once

#include <cstddef>
#include <string>
#include <vector>

#include "token/token.hpp"

namespace lexer {
class Lexer {
    size_t index = 0;
    size_t start = 0;
    size_t line = 1;
    std::string input;
    std::vector<token::Token> tokens;

    void addToken(token::Type tt, std::string val = "");
    bool isAtEnd();
    char step();
    char peek();
    void scanAlpha();
    void scanNumber();
    void scanToken();

   public:
    Lexer(std::string input);
    std::vector<token::Token> Lex();
    void PrintTokens();
};
}  // namespace lexer
