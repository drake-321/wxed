#include "keybinds.h"

#include <memory>
#include <algorithm>

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

  // get panel const_iterator
  auto file_content_it = std::find_if(panels.begin(), panels.end(), [](const decltype(*panels.begin())& panel) {
    return panel->get_name() == WX_UIComponentNames[WX_UIComponentIdentifiers::FileContentComponent];
    });

  auto& file_content = dynamic_cast<FileContent&>(**file_content_it);

  register_filecontent_keybinds(file_content);

  sm_registered = true;
}

void Keybinds::register_filecontent_keybinds(FileContent& file_content)
{
  auto& input_processor = InputProcessor::get_instance();

  input_processor.register_keybind('j', [&]() {
    //file_content.move_position(16);
    file_content.print_at(0, 0, "hello world");
    });

  input_processor.register_keybind('k', [&]() {
    //file_content.move_position(-16);
    });
}

