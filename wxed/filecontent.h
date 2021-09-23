#pragma once

#include <vector>
#include <filesystem>
#include <cstdint>

#include "common.h"
#include "panel.h"
#include "utils.h"

class FileContent : public Panel
{
public:
  FileContent(std::filesystem::path file_path);

  void render() override;
  void move_position(uint64 offset);

private:
  void print_hex_output();

  std::vector<char> m_file_bytes;
  uint64_t m_position;
}; 