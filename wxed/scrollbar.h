#pragma once

#include "panel.h"
#include "utils.h"

class ScrollBar : public Panel
{
public:
  ScrollBar()
    : Panel(WX_UIComponentNames[WX_UIComponentID::ScrollBarComponent], 0, 1, 1, utils::get_curses_max_y() - 2, COLOR_GREEN, COLOR_BLACK)
  {
  }

  void render() override {
    print_at(0, 0, "-");
  }
};
