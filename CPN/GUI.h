#pragma once
#include <memory>
#include <string>
#include <functional>
#include "imgui/imgui.h"

class CTab
{
public:
    const char* szName = nullptr;
    std::function<void()> pRenderFunction = nullptr;
};

class GUI {
public:
    GUI() noexcept;
    void render() noexcept;

    bool open = true;

    static void updateColors() noexcept;
    static void SetupStyle();
};

namespace T {
    template <std::size_t S>
    void Render(const char* szTabBar, const std::array<CTab, S> arrTabs, int* nCurrentTab, const ImVec4& colActive, ImGuiTabBarFlags flags = ImGuiTabBarFlags_Reorderable | ImGuiTabBarFlags_NoCloseWithMiddleMouseButton | ImGuiTabBarFlags_NoTooltip);

    inline int iMainTab = 0;

    void drawAimbotTab() noexcept;
    void drawGlowTab() noexcept;
    void drawESPTab() noexcept;
    void drawMiscTab() noexcept;
    void drawConfigTab() noexcept;

    void drawStyleTab() noexcept;

    void renderMenu() noexcept;
}

inline std::unique_ptr<GUI> gui;
