#pragma once

#include "common.h"
#include "panel.h"
#include "utils.h"

class Footer final : public Panel
{
public:
  Footer()
    : Panel(WX_UIComponentNames[WX_UIComponentID::FooterComponent], 0, utils::get_curses_max_y() - 1, utils::get_curses_max_x(), 1, COLOR_BLACK, COLOR_WHITE)
  {
  }

  void render() override {
    print_at(0, 0, "footer");
  }
}; 
