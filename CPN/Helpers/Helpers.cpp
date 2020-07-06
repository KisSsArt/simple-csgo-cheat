#include <cmath>
#include <tuple>

#include "../imgui/imgui.h"

#include "../ConfigStructs.h"
#include "Helpers.h"
#include "../Memory.h"
#include "../SDK/GlobalVars.h"
#include "../_Objects/Structs/Structs.hpp"

static auto rainbowColor(float time, float speed, float alpha) noexcept
{
    return std::array{ std::sin(speed * time) * 0.5f + 0.5f,
                       std::sin(speed * time + 2 * static_cast<float>(M_PI) / 3) * 0.5f + 0.5f,
                       std::sin(speed * time + 4 * static_cast<float>(M_PI) / 3) * 0.5f + 0.5f,
                       alpha };
}

unsigned int Helpers::calculateColor(const Color& color) noexcept
{
    return ImGui::ColorConvertFloat4ToU32(color.rainbow ? rainbowColor(memory->globalVars->realtime, color.rainbowSpeed, color.color[3]) : color.color);
}

std::array<float, 4> Helpers::calculateColorArr(const Color& color) noexcept
{
    return color.rainbow ? rainbowColor(memory->globalVars->realtime, color.rainbowSpeed, color.color[3]) : color.color;
}
