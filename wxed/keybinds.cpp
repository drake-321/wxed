#include "keybinds.h"

#include <memory>
#include <concepts>

#include "common.h"
#include "ui.h"
#include "input.h"

void Keybinds::register_all(const std::vector<std::unique_ptr<Panel>>& panels)
{
  static bool s_registered;

  if (s_registered)
  {
    return;
  }
  
  for (auto& panel : panels)
  {
    // if panel implements the interactive abstract class, call register_keybinds
    auto component = dynamic_cast<Interactive *>(panel.get());
    if (component)
    {
      component->register_keybinds();
    }
  }

  s_registered = true;
}

