#pragma once

#include <vector>
#include <filesystem>
#include <cstdint>

#include "common.h"
#include "panel.h"
//#include "interactive.h"
#include "utils.h"

class FileContent final : public Panel // , public Interactive
{
  enum class OutputFormat
  {
    text,
    hexadecimal,
    disassembly
  };

public:
  FileContent(const std::filesystem::path& file_path);

  void render() override;

  void move_position(const int64 offset);

private:
  void print_text_output() const;
  void print_hex_output() const;
  //void print_disassembly_output() const;


  std::vector<unsigned char> m_file_bytes;
  uint64_t m_position = 0;
  OutputFormat m_current_format = OutputFormat::hexadecimal;
};