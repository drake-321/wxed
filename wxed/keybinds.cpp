#include "keybinds.h"

#include <memory>

void Keybinds::register_all(const std::vector<std::unique_ptr<Panel>>& panels)
{
  static bool s_registered;

  if (s_registered)
  {
    return;
  }
  
  for (auto& panel : panels)
  {
    // if panel implements the interactive abstract class, call register_keybinds() method
    auto interactive_panel = dynamic_cast<Interactive *>(panel.get());
    if (interactive_panel)
    {
      interactive_panel->register_keybinds();
    }
  }

  s_registered = true;
}

