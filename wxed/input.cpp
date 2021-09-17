#include "input.h"

#include <curses.h>

void InputProcessor::process()
{
  auto input = static_cast<char>(::getch());

  auto it = m_keybinds.find(input);
  if (it != m_keybinds.end())
  {
    auto func = it->second;
    func();
  }
}

void InputProcessor::register_keybind(char key, fn_ptr callback)
{
  m_keybinds.insert({ key, callback });
}

