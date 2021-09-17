#include "settings_manager.h"

std::string_view SettingsManager::get_option(std::string_view option)
{
  return m_settings.at(option);
}

void SettingsManager::set_option(std::string_view option, std::string_view value)
{
  m_settings.find(option)->second = value;
}

void SettingsManager::load_from_file(std::filesystem::path path)
{
}
