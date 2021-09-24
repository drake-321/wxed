#pragma once

#include <memory>
#include <type_traits>

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

  static void register_all(const std::vector<std::unique_ptr<Panel>>& panels);

private:
  //template<typename ComponentT>
  //void register_component_keybinds(ComponentT& component)
  //{
  //  static_assert(std::is_base_of_v<Panel, ComponentT>);

  //}

  //void register_titlebar_keybinds(TitleBar& title_bar);
  //void register_scrollbar_keybinds(ScrollBar& scroll_bar);
  static void register_filecontent_keybinds(FileContent& file_content);
  //void register_footer_keybinds(Footer& footer);
};

