#pragma once

#include <array>
#include <string>
#include <vector>

#include "Token.hxx"

class Lexer
{
public:
  Lexer(const std::string& expr);
  void tokenize();
  std::vector<Token> getTokenStream();

private:
  static constexpr std::array<std::string, 10> mDigits
  {
    "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"
  };
  static constexpr std::array<std::string, 2> mOps
  {
    "+", "-",
  };
  const std::string mExpr{};
  std::vector<Token> mTokens{};
};

