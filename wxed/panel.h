#pragma once

#include <memory>
#include <stdexcept>

#include <curses.h>

#include "common.h"

struct WINDOW_Deleter
{
  void operator()(struct _win* window) const;
};

class Panel
{
public:
  Panel(std::string_view name, int posX, int posY, int width, int height, WX_UIColor color);
  virtual ~Panel() = default;

  void refresh() const
  {
    ::wrefresh(m_window.get());
  }

  void clear() const
  {
    ::wclear(m_window.get());
  }

  template<typename... Ts>
  void print_at(unsigned x, unsigned y, std::string_view fmt, Ts... Targs) const
  {
    if (x > m_width || y > m_height)
    {
      throw std::runtime_error(__func__);
    }

    ::mvwprintw(m_window.get(), y, x, fmt.data(), Targs...);
  }

  [[nodiscard]]
  std::string_view get_name() const
  {
    return m_name;
  }

  virtual void render() = 0;

protected:
  std::unique_ptr<WINDOW, WINDOW_Deleter> m_window;
  int m_posX, m_posY, m_width, m_height;

private:
  std::string_view m_name;
};

