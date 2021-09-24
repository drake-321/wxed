#include "keybinds.h"

#include <memory>
#include <concepts>

#include "common.h"
#include "ui.h"
#include "input.h"

void Keybinds::register_all(const std::vector<std::unique_ptr<Panel>>& panels)
{
  static bool sm_registered;

  // this shouldn't be called more than once for the time being
  if (sm_registered)
  {
    return;
  }

  ////
  ////  register keybinds for interactive panels
  ////
  //for (auto& panel : panels)
  //{
  //  auto component = dynamic_cast<Interactive*>(panel);
  //}

  auto file_content_it = std::ranges::find_if(panels, [](decltype(*panels.begin())& panel) {
    return panel->get_name() == WX_UIComponentNames[WX_UIComponentID::FileContentComponent];
    });

  auto& file_content = dynamic_cast<FileContent&>(**file_content_it);

  register_filecontent_keybinds(file_content);

  sm_registered = true;
}

void Keybinds::register_filecontent_keybinds(FileContent& file_content)
{
  auto& input_processor = InputProcessor::get_instance();

  input_processor.register_keybind('j', [&]() {
    file_content.move_position(16);
    });

  input_processor.register_keybind('k', [&]() {
    file_content.move_position(-16);
    });
}

