#pragma once

#include <string>

#include "panel.h"
#include "utils.h"

using namespace utils;

class TitleBar : public Panel
{
public:
  TitleBar()
    : Panel(0, 0, get_curses_max_x(), get_curses_max_y(), COLOR_BLACK, COLOR_WHITE)
  {
    print_at(0, 0, "wxed");
  }

  void render() override {
  }
};
