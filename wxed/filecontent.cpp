#include "filecontent.h"

#include <fstream>

FileContent::FileContent(std::filesystem::path file_path)
  : Panel(1, 1, get_curses_max_x() - 1, get_curses_max_y() - 1, COLOR_WHITE, COLOR_BLACK),
  m_file_path(file_path)
{
  std::ifstream input{ m_file_path, std::ios::binary };
  input.seekg(m_position);
}

void FileContent::print_hex_output()
{
  std::ifstream input{ m_file_path, std::ios::binary };

  for (unsigned i = m_position; i < (get_curses_max_y() - 2) * 16; i += 16)
  {
    print_at(0, i / 16, "%08x:", i);

    char buf[16];
    input.read(buf, 16);

    unsigned hex_cursor_position_offset = 11;
    for (unsigned j = 0; j < 16; j++)
    {
      print_at(hex_cursor_position_offset, i / 16, "%02x", buf[j]);
      hex_cursor_position_offset += 3;
    }

    unsigned ascii_cursor_position_offset = 60;
    for (unsigned j = 0; j < 16; j++)
    {
      char ascii_character = std::isalnum(buf[j]) ? buf[j] : '.';
      print_at(ascii_cursor_position_offset, i / 16, "%c", ascii_character);
      ascii_cursor_position_offset++;
    }
  }
}

