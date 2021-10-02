#include "wxed.h"

#include <vector>
#include <memory>

#include <curses.h>

#include "input.h"
#include "keybinds.h"

#include "ui.h"

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

  // hide cursor
  ::curs_set(0);

  // init colors and color pairs
  ::start_color();
  for (const auto& component_color : WX_UIComponentColors)
  {
    ::init_pair(static_cast<short>(component_color.first), component_color.second.first, component_color.second.second);
  }

  m_initialized = true;
}

void Wxed::run(const std::filesystem::path& file_path) const
{
  auto& input_processor = InputProcessor::get_instance();

  std::vector<std::unique_ptr<Panel>> panels;
  panels.push_back(std::make_unique<TitleBar>());
  panels.push_back(std::make_unique<ScrollBar>());
  panels.push_back(std::make_unique<FileContent>(file_path));
  panels.push_back(std::make_unique<Footer>());

  // register keybinds
  Keybinds::register_all(panels);

  // main loop
  while (true)
  {
    ::refresh();

    for (const auto& panel : panels)
    {
      panel->clear();
      panel->render();
      panel->refresh();
    }

    input_processor.process();
  }
}

