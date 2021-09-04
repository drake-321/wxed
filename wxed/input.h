#pragma once

#include <type_traits>
#include <map>
#include <functional>

class InputProcessor
{
  using fn_ptr = std::function<void()>;

public:
  static InputProcessor& get_instance()
  {
    static InputProcessor inst;
    return inst;
  }

private:
  InputProcessor() = default;

public:
  InputProcessor(InputProcessor const&) = delete;
  void operator=(InputProcessor const&) = delete;

  void process();
  void register_keybind(char key, fn_ptr callback);

private:
  std::map<char, fn_ptr> keybinds{};
};
