#include "matex/Lexer.hxx"

Lexer::Lexer(const std::string& expr)
  : mExpr{expr}
{}

void Lexer::tokenize()
{}

std::vector<Token> Lexer::getTokenStream()
{
  return mTokens;
}

