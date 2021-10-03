#include "input.h"

#include <curses.h>

void InputProcessor::process()
{
  const auto input = static_cast<char>(::getch());

  if (const auto it = m_keybinds.find(input); it != m_keybinds.end())
  {
    const auto func = it->second;
    func();
  }
}

void InputProcessor::register_keybind(char key, const fn_ptr& callback)
{
  m_keybinds.insert({ key, callback });
}

