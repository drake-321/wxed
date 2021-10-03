#pragma once

#include <curses.h>

#include "common.h"
#include "panel.h"
#include "utils.h"
#include "input.h"

class Footer final : public Panel, public Interactive
{
public:
  Footer()
    : Panel(WX_UIWindowNames[WX_UIWindow::Footer], 0, utils::get_curses_max_y() - 1, utils::get_curses_max_x(), 1, WX_UIColor::Footer)
  {
  }

  void render() override {
  }

  void register_keybinds() override
  {
    auto& input_processor = InputProcessor::get_instance();

    input_processor.register_keybind(':', [&]() {
      print_at(0, 0, ":");

      ::echo();
      ::curs_set(1);

      ::move(m_posY, m_posX);

      char buf[50];
      ::wgetnstr(m_window.get(), buf, 50);


      ::curs_set(0);
      ::noecho();
      });
  }
};
