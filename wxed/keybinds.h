#pragma once

#include <memory>

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
};

