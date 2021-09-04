#include "panel.h"

void WINDOW_Deleter::operator()(struct _win* window) const
{
  ::delwin(window);
}

Panel::Panel(int posX, int posY, int width, int height, int foreground_color, int background_color)
  : m_posX(posX), m_posY(posY), m_width(width), m_height(height), m_foregroundColor(foreground_color), m_backgroundColor(background_color)
{
  m_window = std::unique_ptr<WINDOW, WINDOW_Deleter>(::newwin(height,width,posY,posX));

  ::init_pair(1, foreground_color, background_color);
  ::wbkgd(m_window.get(), COLOR_PAIR(1));
  ::touchwin(m_window.get());
}

Panel::~Panel()
{
}

void Panel::refresh() const
{
  ::wrefresh(m_window.get());
}

void Panel::print_at(int x, int y, std::string_view string) const
{
  ::mvwprintw(m_window.get(), m_posY + y, m_posX + x, string.data());
}
