#include "keybinds.h"

#include <memory>

#include "filecontent.h"

void Keybinds::register_all(const std::vector<unique_ptr<Panel>>& panels)
{
  if (sm_registered)
  {
    return;
  }

  register_filecontent_keybinds()

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

