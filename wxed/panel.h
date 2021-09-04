#pragma once

#include <string_view>
#include <memory>

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

  void refresh() const;

  void print_at(int x, int y, std::string_view string) const;

  virtual void render() = 0;

protected:
  std::unique_ptr<WINDOW, WINDOW_Deleter> m_window;

private:
  inline static unsigned sm_colorPairIndex;

  int m_posX, m_posY, m_width, m_height, m_foregroundColor, m_backgroundColor;
};

