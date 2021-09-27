#include "panel.h"

void WINDOW_Deleter::operator()(struct _win* window) const
{
  ::delwin(window);
}

Panel::Panel(const std::string_view name, const int posX, const int posY, const int width, const int height, const short foreground_color, const short background_color)
  : m_name(name), m_posX(posX), m_posY(posY), m_width(width), m_height(height), m_foregroundColor(foreground_color), m_backgroundColor(background_color)
{
  static short sm_colorPairIndex = 1;

  m_window = std::unique_ptr<WINDOW, WINDOW_Deleter>(::newwin(height, width, posY, posX));

  ::init_pair(sm_colorPairIndex, m_foregroundColor, m_backgroundColor);
  ::wbkgd(m_window.get(), COLOR_PAIR(sm_colorPairIndex));

  sm_colorPairIndex++;

  ::touchwin(m_window.get());
}

