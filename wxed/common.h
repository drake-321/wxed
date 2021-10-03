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
  Footer,
  Dialog,
  COUNT
};

constexpr static utils::CTMap<WX_UIWindow, std::string_view, static_cast<int>(WX_UIWindow::COUNT)> WX_UIWindowNames{
  {
    { WX_UIWindow::TitleBar, "TitleBar" },
    { WX_UIWindow::FileContent, "FileContent" },
    { WX_UIWindow::ScrollBar, "ScrollBar" },
    { WX_UIWindow::Footer, "Footer" },
    { WX_UIWindow::Dialog, "Dialog" }
  }
};

enum class WX_UIColor
{
  _,
  TitleBar,
  FileContent,
  ScrollBar,
  Footer,
  Dialog,
  UnselectedByte,
  SelectedByte,
};

static std::map<WX_UIColor, std::pair<short, short>> WX_UIComponentColors{
  { WX_UIColor::TitleBar, { COLOR_BLACK, COLOR_WHITE } },
  { WX_UIColor::FileContent, { COLOR_WHITE, COLOR_BLACK } },
  { WX_UIColor::ScrollBar, { COLOR_GREEN, COLOR_BLACK} },
  { WX_UIColor::Footer, { COLOR_BLACK, COLOR_WHITE } },
  { WX_UIColor::Dialog, { COLOR_WHITE, COLOR_BLUE } },
  { WX_UIColor::UnselectedByte, { COLOR_WHITE, COLOR_BLACK } },
  { WX_UIColor::SelectedByte, { COLOR_BLACK, COLOR_WHITE } }
};

