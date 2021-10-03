#pragma once

#include "panel.h"
#include "utils.h"
#include "interactive.h"

class Dialog final : public Panel, Interactive
{
public:
  Dialog()
    : Panel(WX_UIWindowNames[WX_UIWindow::Dialog], utils::get_curses_max_x() / 2 - 10, utils::get_curses_max_y() / 2 - 5, 20, 10, WX_UIColor::Footer)
  {
  }

  void render() override {
    print_at(m_width / 2, m_height / 2, "hello I am a dialog");
  }

  void register_keybinds() override
  {

  }
};

