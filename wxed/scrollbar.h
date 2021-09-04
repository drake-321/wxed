#pragma once

#include "panel.h"
#include "utils.h"

using namespace utils;

class ScrollBar : public Panel
{
public:
  ScrollBar()
    : Panel(0, 1, 1, get_curses_max_y(), COLOR_GREEN, COLOR_BLACK)
  {
  }

  void render() override {
    print_at(0, 0, "-");
    refresh();
  }
};
