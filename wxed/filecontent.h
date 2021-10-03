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
  void change_mode(Mode mode);

private:
  void print_text_output() const;
  void print_hex_output() const;
  //void print_disassembly_output() const;

  std::vector<unsigned char> m_file_bytes;

  int64_t m_position = 0;
  int64_t m_cursor_position = 0;

  OutputFormat m_current_format = OutputFormat::text;
  Mode m_current_mode = Mode::viewer;
};