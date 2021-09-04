#pragma once

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

  void run();

private:
  void init();

  bool m_initialized;
};
