#pragma once

#include <string>
#include <vector>

class Matex
{
public:
  Matex() = default;
  void compile(const std::string& expr);

private:
  std::string mExpr{};
};

