#include "parser.hpp"

#include <cstddef>
#include <iostream>
#include <memory>
#include <string>
#include <utility>

#include "token/token.hpp"

using namespace std;
using namespace ast;

string repeatTabs(size_t n) {
    string tab = "   ";
    string ret;
    ret.reserve(n * tab.size());

    for (size_t i = 0; i < n; i++) {
        ret += tab;
    }

    return ret;
}

string parseIdentifier(token::Tokens& tokens) {
    return tokens.expect(token::IDENTIFIER).value;
}

AST::AST(vector<token::Token> tokens) : tokens(std::move(tokens)) {}

const token::Token& token::Tokens::expect(token::Type type) {
    if (index < tokens.size() && tokens[index].type == type) {
        index++;
        return tokens[index - 1];
    } else {
        cerr << "unexpected token: " << tokens[index].toString() << " on line "
             << tokens[index].line << endl;
        exit(3);
    }
}

FunctionDef::FunctionDef(token::Tokens& tokens) {
    tokens.expect(token::INT);
    name = tokens.expect(token::IDENTIFIER).value;
    tokens.expect(token::OPEN_BRACE);
    tokens.expect(token::VOID);
    tokens.expect(token::CLOSE_BRACE);
    tokens.expect(token::OPEN_PARENTH);
    body = make_unique<Return>(tokens);
    tokens.expect(token::CLOSE_PARENTH);
}

string FunctionDef::toString(size_t scope) {
    string str = repeatTabs(scope) + "Function(";
    str += "\n" + repeatTabs(scope + 1) + "name=" + this->name;
    str += "\n" + repeatTabs(scope + 1) +
           "body=" + this->body->toString(scope + 1);
    str += "\n" + repeatTabs(scope) + ")";
    return str;
}

Return::Return(token::Tokens& tokens) {
    tokens.expect(token::RETURN);
    exp = make_unique<Constant>(tokens);
    tokens.expect(token::SEMICOLON);
}

string Return::toString(size_t scope) {
    string str = "Return(";
    str += "\n" + this->exp->toString(scope + 1);
    str += "\n" + repeatTabs(scope) + ")";
    return str;
}

Constant::Constant(token::Tokens& tokens) {
    value = tokens.expect(token::NUMBER).value;
}

string Constant::toString(size_t scope) {
    return repeatTabs(scope) + "Constant(" + this->value + ")";
}

Program::Program(token::Tokens& tokens) {
    function = make_unique<FunctionDef>(tokens);
}

string Program::toString(size_t scope) {
    string str = repeatTabs(scope) + "Program(";
    str += "\n" + this->function->toString(scope + 1);
    str += "\n" + repeatTabs(scope) + ")";
    return str;
}

unique_ptr<Program> AST::ParseProgram() {
    return make_unique<Program>(this->tokens);
}