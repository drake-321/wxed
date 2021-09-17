#pragma once

#include <string_view>
#include <filesystem>
#include <map>

class SettingsManager
{
  enum class SettingKey
  {
    TestSetting,
    TestSetting2
  };

public:
  static SettingsManager& get_instance()
  {
    static SettingsManager inst;
    return inst;
  }

private:
  SettingsManager() = default;

public:
  SettingsManager(SettingsManager const&) = delete;
  void operator=(SettingsManager const&) = delete;

  std::string_view get_option(std::string_view option);
  void set_option(std::string_view option, std::string_view value);


private:
  void load_from_file(std::filesystem::path path);

  static bool sm_loaded;
  std::map<SettingKey, std::string_view> m_settings = {
    { SettingKey::TestSetting, "hello" },
    { SettingKey::TestSetting2, "hello"}
  };
};
