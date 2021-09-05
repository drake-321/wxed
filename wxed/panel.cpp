#include "panel.h"

unsigned Panel::sm_colorPairIndex = 1;

void WINDOW_Deleter::operator()(struct _win* window) const
{
  ::delwin(window);
}

Panel::Panel(int posX, int posY, int width, int height, int foreground_color, int background_color)
  : m_posX(posX), m_posY(posY), m_width(width), m_height(height), m_foregroundColor(foreground_color), m_backgroundColor(background_color)
{
  m_window = std::unique_ptr<WINDOW, WINDOW_Deleter>(::newwin(height, width, posY, posX));

  ::init_pair(sm_colorPairIndex, m_foregroundColor, m_backgroundColor);
  ::wbkgd(m_window.get(), COLOR_PAIR(sm_colorPairIndex));

  sm_colorPairIndex++;

  ::touchwin(m_window.get());
}

Panel::~Panel()
{
}

