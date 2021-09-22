#include "keybinds.h"

#include <memory>
#include <algorithm>

#include "input.h"
#include "filecontent.h"

void Keybinds::register_all(const std::vector<std::unique_ptr<Panel>>& panels)
{
  if (sm_registered)
  {
    return;
  }

  auto it = std::ranges::find(panels, [](const std::unique_ptr<Panel>& panel) {
    panel->get_name()
    });

  //auto file_content_ref = dynamic_cast<FileContent&>()

  //register_filecontent_keybinds()

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

