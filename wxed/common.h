#pragma once

#include <string_view>

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


enum class WX_UIComponentIdentifiers
{
  TitleBarComponent,
  FileContentComponent,
  ScrollBarComponent,
  FooterComponent
};

constexpr utils::CTMap<WX_UIComponentIdentifiers, std::string_view, 4> WX_UIComponentNames{
  {
    { WX_UIComponentIdentifiers::TitleBarComponent, "TitleBar" },
    { WX_UIComponentIdentifiers::FileContentComponent, "FileContent" },
    { WX_UIComponentIdentifiers::ScrollBarComponent, "ScrollBar" },
    { WX_UIComponentIdentifiers::FooterComponent, "Footer" },
  }
};

