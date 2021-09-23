#include "filecontent.h"

#include <fstream>
#include <iterator>
#include <cstdint>

#include "common.h"
#include "utils.h"

FileContent::FileContent(std::filesystem::path file_path)
  : Panel(WX_UIComponentNames[WX_UIComponentIdentifiers::FileContentComponent], 0, 1, 1, utils::get_curses_max_y(), COLOR_BLACK, COLOR_WHITE)
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

void FileContent::render()
{
  print_hex_output();
}

void FileContent::print_hex_output()
{
  bool exit_loop = false;

  for (uint64 i = m_position; i < (utils::get_curses_max_y() - 2) * 16; i += 16)
  {
    // print bytes in hex
    unsigned hex_cursor_position_offset = 11;
    for (uint64 j = 0; j < 16; j++)
    {
      // check if we reached end of data. if so, set exit_loop to true
      if (i + j > m_file_bytes.size() - 1)
      {
        exit_loop = true;
        break;
      }

      print_at(hex_cursor_position_offset, i / 16, "%02x", m_file_bytes[i + j]);
      hex_cursor_position_offset += 3;
    }

    // print alphanumeric characters
    unsigned ascii_cursor_position_offset = 60;
    for (uint64 j = 0; j < 16; j++)
    {
      // don't reach end of data. if we have, we already set
      // exit_loop earlier so just break
      if (i + j > m_file_bytes.size() - 1)
      {
        break;
      }

      char ascii_character = std::isalnum(m_file_bytes[i + j]) ? m_file_bytes[i + j] : '.';
      print_at(ascii_cursor_position_offset, i / 16, "%c", ascii_character);
      ascii_cursor_position_offset++;
    }

    // print current position in hex
    print_at(0, i / 16, "%08x:", i);

    if (exit_loop)
    {
      break;
    }
  }
}

void FileContent::move_position(uint64 offset)
{
  if (offset < 0)
  {
    if (m_position + offset < 1)
    {
      return;
    }
  }
  else
  {
    if (m_position + offset > m_file_bytes.size() + 16)
    {
      return;
    }
  }

  m_position += offset;
}

