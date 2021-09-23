#pragma once

#include "panel.h"
#include "utils.h"

using namespace utils;

class ScrollBar : public Panel
{
public:
  ScrollBar()
    : Panel(WX_UIComponentNames[WX_UIComponentIdentifiers::ScrollBarComponent], 0, 1, 1, get_curses_max_y(), COLOR_BLACK, COLOR_WHITE)
  {
  }

  void render() override {
    print_at(0, 0, "-");
  }
};
