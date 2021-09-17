#pragma once

#include <curses.h>

#include "input.h"

namespace keybinds
{
  static void register_default_keybinds()
  {
    //// register keybinds
    //auto& input_processor = InputProcessor::get_instance();
    //input_processor.register_keybind('h', []() {
    //  int y, x;
    //  getyx(::stdscr, y, x);
    //  ::move(y, x - 1);
    //  });

    //input_processor.register_keybind('j', []() {
    //  int y, x;
    //  getyx(::stdscr, y, x);
    //  ::move(y + 1, x);
    //  });

    //input_processor.register_keybind('k', []() {
    //  int y, x;
    //  getyx(::stdscr, y, x);
    //  ::move(y - 1, x);
    //  });

    //input_processor.register_keybind('l', []() {
    //  int y, x;
    //  getyx(::stdscr, y, x);
    //  ::move(y, x + 1);
    //  });
  }
}
