#include "wxed.h"

#include <iostream>
#include <filesystem>

[[noreturn]]
inline void print_usage()
{
  std::cout << "usage: wxed [file]";
  std::exit(1);
}

int main(int argc, char* argv[])
{
  std::filesystem::path file_path;

  if (argc > 1)
  {
    file_path = argv[1];
  }
  else
  {
    print_usage();
  }

  if (!exists(file_path))
  {
    std::cerr << "File does not exist.\n";
    return 1;
  }

  const auto& wxed = Wxed::get_instance();
  wxed.run(file_path);
}
