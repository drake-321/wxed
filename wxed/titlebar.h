#pragma once

#include <string>

#include "common.h"
#include "panel.h"
#include "utils.h"

using namespace utils;

class TitleBar : public Panel
{
public:
  TitleBar()
    : Panel(WX_UIComponentNames[WX_UIComponentIdentifiers::TitleBarComponent], 0, 0, get_curses_max_x(), 1, COLOR_BLACK, COLOR_WHITE)
  {
  }

  void render() override {
    print_at(0, 0, "wxed %s", WX_Version);
  }
};
