#pragma once

#include <string>
#include <vector>

#include "matex/Token.hxx"

class Matex
{
public:
  Matex() = default;
  void compile(const std::string& expr);

private:
  std::string mExpr{};
  Token* mTokenStream{nullptr};
};

