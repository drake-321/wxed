#pragma once

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

  std::filesystem::path m_file_path;
  unsigned m_position = 0;
}; 