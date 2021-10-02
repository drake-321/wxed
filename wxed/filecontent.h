#pragma once

#include <vector>
#include <filesystem>
#include <cstdint>

#include "common.h"
#include "panel.h"
#include "interactive.h"

class FileContent final : public Panel, public Interactive
{
  enum class OutputFormat
  {
    text,
    hexadecimal,
    disassembly
  };

  enum class Mode
  {
    viewer,
    editor,
    editing
  };

public:
  FileContent(const std::filesystem::path& file_path);

  void render() override;
  void register_keybinds() override;

  void move_position(int64 offset);

private:
  void print_text_output() const;
  void print_hex_output() const;
  //void print_disassembly_output() const;

  std::vector<unsigned char> m_file_bytes;

  uint64_t m_position = 0;
  uint64_t m_cursor_position = 0;

  OutputFormat m_current_format = OutputFormat::hexadecimal;
  Mode m_current_mode = Mode::viewer;
};