#pragma once

#include <vector>
#include <filesystem>

#include "panel.h"
#include "utils.h"

using namespace utils;

class FileContent : public Panel
{
public:
  FileContent(std::filesystem::path file_path);

  void render() override {
    print_hex_output();
  }

private:
  void print_hex_output();
  void move_position(int offset);

  std::vector<char> m_file_bytes;
  unsigned m_position = 0;
}; 