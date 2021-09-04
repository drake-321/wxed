#include "wxed.h"

#include <string>
#include <vector>
#include <algorithm>
#include <memory>

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

  std::vector<Panel*> panels{
    new TitleBar(),
    //new ScrollBar(),
    new FileContent(),
    //new Footer()
  };

  // main loop
  while (true)
  {
    ::refresh();

    std::for_each(panels.begin(), panels.end(), [](Panel* panel) {
      panel->render();
      panel->refresh();
      });

    input_processor.process();
  }

  // cleanup
  std::for_each(panels.begin(), panels.end(), [](Panel* panel) {
    delete panel;
    panel = nullptr;
    });
}

