#pragma once

#include <memory>

#include <curses.h>

#include "ui.h"

class Keybinds
{
public:
  static Keybinds& get_instance()
  {
    static Keybinds inst;
    return inst;
  }

private:
  Keybinds() = default;
  ~Keybinds() = default;

public:
  Keybinds(Keybinds const&) = delete;
  void operator=(Keybinds const&) = delete;

  void register_all(const std::vector<std::unique_ptr<Panel>>& panels);

private:
  //template<typename ComponentT>
  //void register_component_keybinds(ComponentT& component)

  //void register_titlebar_keybinds(TitleBar& title_bar);
  //void register_scrollbar_keybinds(ScrollBar& scroll_bar);
  void register_filecontent_keybinds(FileContent& file_content);
  //void register_footer_keybinds(Footer& footer);
};

