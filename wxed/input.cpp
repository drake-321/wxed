#include "input.h"

#include <curses.h>

void InputProcessor::process()
{
  auto input = static_cast<char>(::getch());

  auto it = keybinds.find(input);
  if (it != keybinds.end())
  {
    auto func = it->second;
    func();
  }
}

void InputProcessor::register_keybind(char key, fn_ptr callback)
{
  keybinds.insert({ key, callback });
}

