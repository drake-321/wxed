#pragma once

#include "common.h"
#include "panel.h"
#include "utils.h"

class TitleBar final : public Panel
{
public:
  TitleBar()
    : Panel(WX_UIWindowNames[WX_UIWindow::TitleBar], 0, 0, utils::get_curses_max_x(), 1, WX_UIColor::TitleBar)
  {
  }

  void render() override
  {
    print_at(0, 0, "wxed %s", WX_Version);
  }
};
