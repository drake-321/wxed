#include "filecontent.h"

#include <fstream>
#include <iterator>

FileContent::FileContent(std::filesystem::path file_path)
  : Panel(1, 1, get_curses_max_x() - 1, get_curses_max_y() - 1, COLOR_WHITE, COLOR_BLACK)
{
  std::ifstream input{ file_path, std::ios::binary };

  //m_file_bytes = std::vector<char>();

  //auto file_size = input.tellg();
  //m_file_bytes.reserve(file_size);

  //input.seekg({ 0 });

  //m_file_bytes.assign(std::istreambuf_iterator<char>(input), std::istream_iterator<char>());

  m_file_bytes = std::vector<char>({
    std::istreambuf_iterator<char>(input),
    std::istreambuf_iterator<char>()
    });
}

void FileContent::print_hex_output()
{
  for (unsigned i = m_position; i < (get_curses_max_y() - 2) * 16; i += 16)
  {
    print_at(0, i / 16, "%08x:", i);

    unsigned hex_cursor_position_offset = 11;
    for (unsigned j = 0; j < 16; j++)
    {
      print_at(hex_cursor_position_offset, i / 16, "%02x", m_file_bytes[m_position + j]);
      hex_cursor_position_offset += 3;
    }

    unsigned ascii_cursor_position_offset = 60;
    for (unsigned j = 0; j < 16; j++)
    {
      char ascii_character = std::isalnum(m_file_bytes[m_position + j]) ? m_file_bytes[m_position + j] : '.';
      print_at(ascii_cursor_position_offset, i / 16, "%c", ascii_character);
      ascii_cursor_position_offset++;
    }
  }
}

