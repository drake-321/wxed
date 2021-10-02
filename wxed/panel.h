#pragma once

#include <memory>
#include <stdexcept>

#include <curses.h>

#include "common.h"

struct WINDOW_Deleter
{
  void operator()(struct _win* window) const;
};

//template<typename... Ts>
//struct is_string_v : public std::disjunction_v<
//  std::is_same_v<char*, typename std::decay_t<Ts> && ...>,
//  std::is_same_v<const char*, typename std::decay_t<Ts> && ...>
//> {};

//template<typename... Ts>
//concept is_formattable_v = requires {
//  std::disjunction_v<std::is_fundamental_v<Ts ...>, is_string_v<Ts ...>>;
//};

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

  template<typename... Ts> // <is_formattable_v... Ts>
  void print_at(unsigned x, unsigned y, std::string_view fmt, Ts... Fargs) const
  {
    if (x > m_width || y > m_height)
    {
      throw std::runtime_error(__func__);
    }

    ::mvwprintw(m_window.get(), y, x, fmt.data(), Fargs...);
  }

  [[nodiscard]]
  std::string_view get_name() const
  {
    return m_name;
  }

  virtual void render() = 0;

protected:
  std::unique_ptr<WINDOW, WINDOW_Deleter> m_window;

private:
  std::string_view m_name;
  int m_posX, m_posY, m_width, m_height;
  short m_foregroundColor, m_backgroundColor;
};

