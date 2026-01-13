#include <string>
#include <vector>

int main(int argc, char** argv)
{
  std::vector<std::string> cmd_args{};
  for (int i{1}; i < argc; ++i)
  {
    cmd_args.push_back(*(argv + i));
  }
  return 0;
}

