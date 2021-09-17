#include "wxed.h"

#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <iterator>

#include <curses.h>

#include "input.h"
#include "keybinds.h"

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

  keybinds::register_default_keybinds();

  m_initialized = true;
}

void Wxed::run(std::filesystem::path file_path)
{
  auto& input_processor = InputProcessor::get_instance();

  std::vector<std::unique_ptr<Panel>> panels;
  panels.push_back(std::make_unique<TitleBar>());
  panels.push_back(std::make_unique<ScrollBar>());
  panels.push_back(std::make_unique<FileContent>(file_path));
  panels.push_back(std::make_unique<Footer>());

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

