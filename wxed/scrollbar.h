#pragma once

#include "panel.h"
#include "utils.h"

using namespace utils;

class ScrollBar : public Panel
{
public:
  ScrollBar()
    : Panel(0, 1, 1, get_curses_max_x(), COLOR_GREEN, COLOR_YELLOW)
  {
  }

  void render() override {
    refresh();
  }
};