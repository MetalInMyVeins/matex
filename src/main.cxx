#include <string>
#include <vector>

int main(int argc, char** argv)
{
  std::vector<std::string> cmd_args{};
  cmd_args.reserve(static_cast<size_t>(argc));
  for (int i{1}; i < argc; ++i)
  {
    cmd_args.push_back(*(argv + i));
  }

  // Matex matex;
  // matex.compile("3 + 2 - 9");
  // matex.getAsm();

  return 0;
}

