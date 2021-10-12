#pragma once

#include <memory>

#include "ui.h"

namespace keybinds
{
  static void register_all(const std::vector<std::unique_ptr<Panel>>& panels)
  {
    static bool s_registered;

    if (s_registered)
    {
      return;
    }

    for (auto& panel : panels)
    {
      // if panel implements the interactive abstract class, call register_keybinds() method
      if (const auto interactive_panel = dynamic_cast<Interactive*>(panel.get()); interactive_panel)
      {
        interactive_panel->register_keybinds();
      }
    }

    s_registered = true;
  }
};

