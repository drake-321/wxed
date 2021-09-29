#pragma once

class Interactive
{
public:
  virtual void register_keybinds() = 0;

  virtual ~Interactive() = default;
};

