#pragma once

#include "panel.h"
#include "utils.h"

using namespace utils;

class Footer : public Panel
{
public:
  Footer()
    : Panel(0, get_curses_max_y() - 1, get_curses_max_x(), 1, COLOR_BLACK, COLOR_WHITE)
  {
  }

  void render() override {
    print_at(0, 0, "footer");
  }
}; 
