#pragma once

#include "panel.h"

class Interactive
{
public:
  virtual void register_keybinds() = 0;

  virtual ~Interactive() = default;
};

