#pragma once

#include <filesystem>

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
  static void init();

  static bool m_initialized;
};
