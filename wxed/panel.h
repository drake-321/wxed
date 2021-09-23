#pragma once

#include <string_view>
#include <memory>
#include <type_traits>

#include <curses.h>

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

// maybe turn this into an inheritable abstract singleton class
// https://sourcemaking.com/design_patterns/singleton/cpp/2

class Panel
{
public:
  Panel(std::string_view name, int posX, int posY, int width, int height, int foreground_color, int background_color);
  ~Panel();

  inline void refresh() const
  {
    ::wrefresh(m_window.get());
  }

  template<typename... Ts> // <is_formattable_v... Ts>
  inline void print_at(unsigned x, unsigned y, std::string_view fmt, Ts... Fargs) const
  {
    ::mvwprintw(m_window.get(), y, x, fmt.data(), Fargs...);
  }

  inline std::string_view get_name()
  {
    return m_name;
  }

  virtual void render() = 0;

protected:
  std::unique_ptr<WINDOW, WINDOW_Deleter> m_window;

private:
  static unsigned sm_colorPairIndex;

  std::string_view m_name;
  int m_posX, m_posY, m_width, m_height, m_foregroundColor, m_backgroundColor;
};

