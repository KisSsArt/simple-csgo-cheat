#pragma once

class GameEvent;
struct ImDrawList;

namespace Misc
{
    //old
    void drawReloadProgress(ImDrawList* drawList) noexcept;
    void drawRecoilCrosshair(ImDrawList* drawList) noexcept;
    void purchaseList(GameEvent* event = nullptr) noexcept;
    void drawObserverList() noexcept;
    void drawNoscopeCrosshair(ImDrawList* drawList) noexcept;
    //new
    void hitmarker(GameEvent* event = nullptr) noexcept;
    void radarHack() noexcept;
    void antiflash() noexcept;
    void bunny_hop() noexcept;
    void fovChanger() noexcept;
}
