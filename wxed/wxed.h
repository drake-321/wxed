#pragma once

#include <filesystem>

#include "panel.h"

class Wxed
{
public:
  static Wxed& get_instance()
  {
    static Wxed inst;
    return inst;
  }

private:
  Wxed();
  ~Wxed();

public:
  Wxed(Wxed const&) = delete;
  void operator=(Wxed const&) = delete;

  void run(const std::filesystem::path& file_path) const;

private:
  void init();

  bool m_initialized = false;
};
