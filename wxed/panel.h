#pragma once

#include <string_view>
#include <memory>
#include <type_traits>

#include <curses.h>

struct WINDOW_Deleter
{
  void operator()(struct _win* window) const;
};

class Panel
{
public:
  Panel(int posX, int posY, int width, int height, int foreground_color, int background_color);
  ~Panel();

  inline void refresh() const
  {
    ::wrefresh(m_window.get());
  }

  template<typename... Targs>
  inline void print_at(int x, int y, std::string_view fmt, Targs... Fargs)
  {
    // check arguments are formattable with the following curses function
    ::mvwprintw(m_window.get(), y, x, fmt.data(), Fargs...);
  }

  virtual void render() = 0;

protected:
  std::unique_ptr<WINDOW, WINDOW_Deleter> m_window;

private:
  static unsigned sm_colorPairIndex;

  int m_posX, m_posY, m_width, m_height, m_foregroundColor, m_backgroundColor;
};

