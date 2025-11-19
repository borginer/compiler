#pragma once

#include <string>
#include <vector>

namespace token {
enum Type {
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
    // other
    _EOF
};

struct Token {
    Type type;
    std::string value;
    std::size_t line;

    std::string toString() const;
};

class Tokens {
    size_t index = 0;
    std::vector<token::Token> tokens;

   public:
    const token::Token& expect(token::Type type);
    Tokens(std::vector<token::Token> tokens);
};

}  // namespace token
