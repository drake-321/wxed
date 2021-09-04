#pragma once

#include "curses.h"

namespace utils
{
  static int maxY, maxX;

  static inline int get_curses_max_x()
  {
    getmaxyx(::stdscr, maxY, maxX);
    return maxX;
  }

  static inline int get_curses_max_y()
  {
    getmaxyx(::stdscr, maxY, maxX);
    return maxY;
  }
}
