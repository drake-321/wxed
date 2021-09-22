#pragma once

#include <curses.h>

#include "input.h"

class Keybinds
{
public:
  static Keybinds& get_instance()
  {
    static Keybinds inst;
    return inst;
  }

private:
  Keybinds();
  ~Keybinds();

public:
  Keybinds(Keybinds const&) = delete;
  void operator=(Keybinds const&) = delete;

  void register_all();

private:
  void register_filecontent_keybinds(FileContent& file_content);

  static bool sm_registered;
}


  //static void register_default_keybinds()
  //{
  //  // register keybinds
  //  auto& input_processor = InputProcessor::get_instance();
  //  input_processor.register_keybind('j', []() {
  //    int y, x;
  //    getyx(::stdscr, y, x);
  //    ::move(y + 1, x);
  //    });

  //  input_processor.register_keybind('k', []() {
  //    int y, x;
  //    getyx(::stdscr, y, x);
  //    ::move(y - 1, x);
  //    });
  //}
