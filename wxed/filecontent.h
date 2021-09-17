#pragma once

#include "panel.h"
#include "utils.h"

using namespace utils;

class FileContent : public Panel
{
public:
  FileContent()
    : Panel(1, 1, get_curses_max_x(), get_curses_max_y() - 1, COLOR_WHITE, COLOR_BLACK)
  {
  }

  void render() override {
    //print_at(10, 10, "hello world");
  }
}; 