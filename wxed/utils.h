#pragma once

#include "curses.h"

namespace utils
{
  //
  // curses helpers
  //
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

  //
  // compile-time key-value store
  //
  template<typename Key, typename Value, int N>
  class CTMap
  {
  public:
    struct KV
    {
      Key key;
      Value value;
    };

    constexpr Value operator[](Key key) const
    {
      return Get(key);
    }

  private:
    constexpr Value Get(Key key, int i = 0) const
    {
      return i == N ?
        KeyNotFound() :
        pairs[i].key == key ? pairs[i].value : Get(key, i + 1);
    }

    static Value KeyNotFound()
    {
      return {};
    }

  public:
    KV pairs[N];
  };
}
