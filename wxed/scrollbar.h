#pragma once

#include "panel.h"
#include "utils.h"

class ScrollBar final : public Panel
{
public:
  ScrollBar()
    : Panel(WX_UIWindowNames[WX_UIWindow::ScrollBar], 0, 1, 1, utils::get_curses_max_y() - 2, WX_UIColor::ScrollBar)
  {
  }

  void render() override
  {
    print_at(0, 0, "-");
  }
};
