#include "panel.h"

void WINDOW_Deleter::operator()(struct _win* window) const
{
  ::delwin(window);
}

Panel::Panel(const std::string_view name, const int posX, const int posY, const int width, const int height, WX_UIColor color)
  : m_name(name), m_posX(posX), m_posY(posY), m_width(width), m_height(height)
{
  m_window = std::unique_ptr<WINDOW, WINDOW_Deleter>(::newwin(height, width, posY, posX));

  ::wbkgd(m_window.get(), COLOR_PAIR(color));
  ::touchwin(m_window.get());
}

