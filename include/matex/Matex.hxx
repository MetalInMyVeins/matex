#pragma once

#include <string>
#include <vector>

enum class Token
{
  NUMBER,
  PLUS,
};

class Matex
{
public:
  Matex() = default;
  void compile(const std::string& expr);

private:
  void scanTokens();

private:
  std::string mExpr{};
  std::vector<Token> mTokens{};
};

