#pragma once

#include <map>

#include "utils.h"

static const constexpr char* WX_Version = "0.1";


//
// type definitions
//

using int8 = int8_t;
using int16 = int16_t;
using int32 = int32_t;
using int64 = int64_t;

using uint8 = uint8_t;
using uint16 = uint16_t;
using uint32 = uint32_t;
using uint64 = uint64_t;


enum class WX_UIWindow
{
  TitleBar,
  FileContent,
  ScrollBar,
  Footer
};

constexpr static utils::CTMap<WX_UIWindow, std::string_view, 4> WX_UIWindowNames{
  {
    { WX_UIWindow::TitleBar, "TitleBar" },
    { WX_UIWindow::FileContent, "FileContent" },
    { WX_UIWindow::ScrollBar, "ScrollBar" },
    { WX_UIWindow::Footer, "Footer" },
  }
};

enum class WX_UIColor
{
  TitleBar,
  FileContent,
  ScrollBar,
  Footer,
  UnselectedByte,
  SelectedByte,
};

static std::map<WX_UIColor, std::pair<short, short>> WX_UIComponentColors{
{ WX_UIColor::TitleBar, { COLOR_BLACK, COLOR_WHITE } },
{ WX_UIColor::FileContent, { COLOR_WHITE, COLOR_BLACK } },
{ WX_UIColor::ScrollBar, { COLOR_BLACK, COLOR_GREEN } },
{ WX_UIColor::Footer, { COLOR_BLACK, COLOR_WHITE } },
{ WX_UIColor::UnselectedByte, { COLOR_WHITE, COLOR_BLACK } },
{ WX_UIColor::SelectedByte, { COLOR_BLACK, COLOR_WHITE } }
};

