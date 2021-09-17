#include "wxed.h"

#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <iterator>

#include <curses.h>

#include "input.h"

#include "titlebar.h"
#include "scrollbar.h"
#include "filecontent.h"
#include "footer.h"

Wxed::Wxed()
{
  init();
}

Wxed::~Wxed()
{
  if (m_initialized)
  {
    // cleanup
    ::endwin();
  }
}

void Wxed::init()
{
  if (m_initialized)
    return;

  // init cursor mode
  ::initscr();

  // disable inline buffering
  ::raw();

  // echo off
  ::noecho();

  // read function keys
  ::keypad(::stdscr, true);

  ::start_color();

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


  m_initialized = true;
}

void Wxed::run()
{
  auto& input_processor = InputProcessor::get_instance();

  std::vector<std::unique_ptr<Panel>> panels;
  panels.push_back(std::make_unique<TitleBar>());

  // main loop
  while (true)
  {
    ::refresh();

    for (auto& panel : panels)
    {
      panel.get()->render();
      panel.get()->refresh();
    }

    input_processor.process();
  }
}

