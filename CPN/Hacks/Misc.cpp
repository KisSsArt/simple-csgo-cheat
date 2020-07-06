#include "Misc.h"

#include "../imgui/imgui.h"
#define IMGUI_DEFINE_MATH_OPERATORS
#include "../imgui/imgui_internal.h"

#include "../Config/Config.h"
#include "../fnv.h"
#include "../GameData/GameData.h"
#include "../GUI.h"
#include "../Helpers/Helpers.h"
#include "../Interfaces.h"
#include "../Memory.h"
#include "../SDK/ConVar.h"
#include "../SDK/Cvar.h"
#include "../SDK/Engine.h"
#include "../SDK/Entity.h"
#include "../SDK/EntityList.h"
#include "../SDK/GameEvent.h"
#include "../SDK/GlobalVars.h"
#include "../SDK/ItemSchema.h"
#include "../SDK/LocalPlayer.h"
#include "../SDK/WeaponInfo.h"
#include "../SDK/WeaponSystem.h"

#include <numeric>
#include <unordered_map>
#include <vector>
#include "../_Objects/Objects.hpp"
#include <iostream>
//#include <iostream>

void Misc::drawReloadProgress(ImDrawList* drawList) noexcept
{
    if (!config->reloadProgress.enabled || !interfaces->engine->isInGame())
        return;

    GameData::Lock lock;
    const auto& localPlayerData = GameData::local();

    if (!localPlayerData.exists || !localPlayerData.alive)
        return;

    static float reloadLength = 0.0f;

    if (localPlayerData.inReload) {
        if (!reloadLength)
            reloadLength = localPlayerData.nextWeaponAttack - memory->globalVars->currenttime;

        constexpr int segments = 40;
        constexpr float min = -IM_PI / 2;
        const float max = std::clamp(IM_PI * 2 * (0.75f - (localPlayerData.nextWeaponAttack - memory->globalVars->currenttime) / reloadLength), -IM_PI / 2, -IM_PI / 2 + IM_PI * 2);

        drawList->PathArcTo(ImGui::GetIO().DisplaySize / 2.0f + ImVec2{ 1.0f, 1.0f }, 20.0f, min, max, segments);
        const ImU32 color = Helpers::calculateColor(config->reloadProgress);
        drawList->PathStroke(color & 0xFF000000, false, config->reloadProgress.thickness);
        drawList->PathArcTo(ImGui::GetIO().DisplaySize / 2.0f, 20.0f, min, max, segments);
        drawList->PathStroke(color, false, config->reloadProgress.thickness);
    } else {
        reloadLength = 0.0f;
    }
}

static void drawCrosshair(ImDrawList* drawList, const ImVec2& pos, ImU32 color, float thickness) noexcept
{
    drawList->Flags &= ~ImDrawListFlags_AntiAliasedLines;

    drawList->AddLine(ImVec2{ pos.x, pos.y - 10 } + ImVec2{ 1.0f, 1.0f }, ImVec2{ pos.x, pos.y - 3 } + ImVec2{ 1.0f, 1.0f }, color & IM_COL32_A_MASK, thickness);
    drawList->AddLine(ImVec2{ pos.x, pos.y + 3 } + ImVec2{ 1.0f, 1.0f }, ImVec2{ pos.x, pos.y + 10 } + ImVec2{ 1.0f, 1.0f }, color & IM_COL32_A_MASK, thickness);

    drawList->AddLine(ImVec2{ pos.x - 10, pos.y } + ImVec2{ 1.0f, 1.0f }, ImVec2{ pos.x - 3, pos.y } + ImVec2{ 1.0f, 1.0f }, color & IM_COL32_A_MASK, thickness);
    drawList->AddLine(ImVec2{ pos.x + 3, pos.y } + ImVec2{ 1.0f, 1.0f }, ImVec2{ pos.x + 10, pos.y } + ImVec2{ 1.0f, 1.0f }, color & IM_COL32_A_MASK, thickness);

    drawList->AddLine({ pos.x, pos.y - 10 }, { pos.x, pos.y - 3 }, color, thickness);
    drawList->AddLine({ pos.x, pos.y + 3 }, { pos.x, pos.y + 10 }, color, thickness);

    drawList->AddLine({ pos.x - 10, pos.y }, { pos.x - 3, pos.y }, color, thickness);
    drawList->AddLine({ pos.x + 3, pos.y }, { pos.x + 10, pos.y }, color, thickness);

    drawList->Flags |= ImDrawListFlags_AntiAliasedLines;
}

void Misc::drawRecoilCrosshair(ImDrawList* drawList) noexcept
{
    if (!config->recoilCrosshair.enabled || !interfaces->engine->isInGame())
        return;

    GameData::Lock lock;
    const auto& localPlayerData = GameData::local();

    if (!localPlayerData.exists || !localPlayerData.alive)
        return;

    if (!localPlayerData.shooting)
        return;

    auto pos = ImGui::GetIO().DisplaySize;
    pos.x *= 0.5f - localPlayerData.aimPunch.y / (localPlayerData.fov * 2.0f);
    pos.y *= 0.5f + localPlayerData.aimPunch.x / (localPlayerData.fov * 2.0f);

    drawCrosshair(drawList, pos, Helpers::calculateColor(config->recoilCrosshair), config->recoilCrosshair.thickness);
}

void Misc::purchaseList(GameEvent* event) noexcept
{
    static std::mutex mtx;
    std::scoped_lock _{ mtx };

    static std::unordered_map<std::string, std::pair<std::vector<std::string>, int>> purchaseDetails;
    static std::unordered_map<std::string, int> purchaseTotal;
    static int totalCost;

    static auto freezeEnd = 0.0f;

    if (event) {
        switch (fnv::hashRuntime(event->getName())) {
        case fnv::hash("item_purchase"): {
            const auto player = interfaces->entityList->getEntity(interfaces->engine->getPlayerForUserId(event->getInt("userid")));

            if (player && localPlayer && memory->isOtherEnemy(player, localPlayer.get())) {
                const auto weaponName = event->getString("weapon");
                auto& purchase = purchaseDetails[player->getPlayerName()];

                if (const auto definition = memory->itemSystem()->getItemSchema()->getItemDefinitionByName(weaponName)) {
                    if (const auto weaponInfo = memory->weaponSystem->getWeaponInfo(definition->getWeaponId())) {
                        purchase.second += weaponInfo->price;
                        totalCost += weaponInfo->price;
                    }
                }

                std::string weapon = weaponName;

                if (weapon.starts_with("weapon_"))
                    weapon.erase(0, 7);
                else if (weapon.starts_with("item_"))
                    weapon.erase(0, 5);

                if (weapon.starts_with("smoke"))
                    weapon.erase(5);
                else if (weapon.starts_with("m4a1_s"))
                    weapon.erase(6);
                else if (weapon.starts_with("usp_s"))
                    weapon.erase(5);

                purchase.first.push_back(weapon);
                ++purchaseTotal[weapon];
            }
            break;
        }
        case fnv::hash("round_start"):
            freezeEnd = 0.0f;
            purchaseDetails.clear();
            purchaseTotal.clear();
            totalCost = 0;
            break;
        case fnv::hash("round_freeze_end"):
            freezeEnd = memory->globalVars->realtime;
            break;
        }
    } else {
        if (!config->purchaseList.enabled || !interfaces->engine->isInGame())
            return;

        static const auto mp_buytime = interfaces->cvar->findVar("mp_buytime");

        if ((!interfaces->engine->isInGame() || freezeEnd != 0.0f && memory->globalVars->realtime > freezeEnd + (!config->purchaseList.onlyDuringFreezeTime ? mp_buytime->getFloat() : 0.0f) || purchaseDetails.empty() || purchaseTotal.empty()) && !gui->open)
            return;
        
        if (config->purchaseList.pos != ImVec2{}) {
            ImGui::SetNextWindowPos(config->purchaseList.pos);
            config->purchaseList.pos = {};
        }

        if (config->purchaseList.size != ImVec2{}) {
            ImGui::SetNextWindowSize(ImClamp(config->purchaseList.size, {}, ImGui::GetIO().DisplaySize));
            config->purchaseList.size = {};
        }

        ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoCollapse;
        if (!gui->open)
            windowFlags |= ImGuiWindowFlags_NoInputs;
        if (config->purchaseList.noTitleBar)
            windowFlags |= ImGuiWindowFlags_NoTitleBar;

        ImGui::Begin("Purchases", nullptr, windowFlags);

        if (config->purchaseList.mode == PurchaseList::Details) {
            for (const auto& [playerName, purchases] : purchaseDetails) {
                std::string s = std::accumulate(purchases.first.begin(), purchases.first.end(), std::string{}, [](std::string s, const std::string& piece) { return s += piece + ", "; });
                if (s.length() >= 2)
                    s.erase(s.length() - 2);

                if (config->purchaseList.showPrices)
                    ImGui::TextWrapped("%s $%d: %s", playerName.c_str(), purchases.second, s.c_str());
                else
                    ImGui::TextWrapped("%s: %s", playerName.c_str(), s.c_str());
            }
        } else if (config->purchaseList.mode == PurchaseList::Summary) {
            for (const auto& purchase : purchaseTotal)
                ImGui::TextWrapped("%d x %s", purchase.second, purchase.first.c_str());

            if (config->purchaseList.showPrices && totalCost > 0) {
                ImGui::Separator();
                ImGui::TextWrapped("Total: $%d", totalCost);
            }
        }
        ImGui::End();
    }
}

void Misc::drawObserverList() noexcept
{
    if (!config->observerList.enabled || !interfaces->engine->isInGame())
        return;

    GameData::Lock lock;

    const auto& observers = GameData::observers();

    if (std::none_of(observers.begin(), observers.end(), [](const auto& obs) { return obs.targetIsLocalPlayer; }) && !gui->open)
        return;

    if (config->observerList.pos != ImVec2{}) {
        ImGui::SetNextWindowPos(config->observerList.pos);
        config->observerList.pos = {};
    }

    if (config->observerList.size != ImVec2{}) {
        ImGui::SetNextWindowSize(ImClamp(config->observerList.size, {}, ImGui::GetIO().DisplaySize));
        config->observerList.size = {};
    }

    ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoCollapse;
    if (!gui->open)
        windowFlags |= ImGuiWindowFlags_NoInputs;
    if (config->observerList.noTitleBar)
        windowFlags |= ImGuiWindowFlags_NoTitleBar;

    ImGui::Begin("Observer List", nullptr, windowFlags);

    for (const auto& observer : observers) {
        if (!observer.targetIsLocalPlayer)
            continue;

        ImGui::TextWrapped("%s", observer.name);
    }

    ImGui::End();
}

//
void Misc::drawNoscopeCrosshair(ImDrawList* drawList) noexcept
{
    if (!config->noscopeCrosshair.enabled || !interfaces->engine->isInGame())
        return;

    GameData::Lock lock;
    const auto& localPlayerData = GameData::local();

    if (!localPlayerData.exists || !localPlayerData.alive)
        return;

    if (!localPlayerData.noScope)
        return;

    drawCrosshair(drawList, ImGui::GetIO().DisplaySize / 2, Helpers::calculateColor(config->noscopeCrosshair), config->noscopeCrosshair.thickness);
}
//

//new
void Misc::antiflash() noexcept
{
    if (!config->antiflash) {
        return;
    }

    LocalPlayerOld::FlashAlpha(.0f);
}

void Misc::bunny_hop() noexcept
{
    if (!config->bunnyhop || !interfaces->engine->isInGame()) {
        return;
    }

    if (LocalPlayerOld::checkLocalVal())
    {
        if (GetAsyncKeyState(VK_SPACE) && LocalPlayerOld::Flags() & (1 << 0))
        {
            Client::ForceJump();
        }
    }
}

void Misc::radarHack() noexcept
{
    if (!config->radar_bool || !interfaces->engine->isInGame()) {
        return;
    }

    if (EngineOld::InGame()) {
        int mp = EngineOld::MaxPlayer();
        for (int i = 0; i < mp; i++) {

            if (EntityOld(i).Base() == NULL) {
                continue;
            }
            if (EntityOld(i).Dormant()) {
                continue;
            }
            if (EntityOld(i).Team() == LocalPlayerOld::Team()) {
                continue;
            }

            if (!EntityOld(i).Spotted()) {
                EntityOld(i).Spotted(true);
            }
        }
    }
    //Sleep(100);
}

void Misc::fovChanger() noexcept
{
    if (!config->fovEnable || !interfaces->engine->isInGame()) {
        return;
    }

    if (LocalPlayerOld::FovChanger() != config->FOV) {
        if (LocalPlayerOld::Scoped())
        {
            LocalPlayerOld::FovChanger(config->FOV - 50);
        }
        else
        {
            LocalPlayerOld::FovChanger(config->FOV);
        }
    }
}

static void drawMarker(ImDrawList* drawList, const ImVec2& pos, ImU32 color, float thickness) noexcept
{
    drawList->Flags &= ~ImDrawListFlags_AntiAliasedLines;

    drawList->AddLine(ImVec2{ pos.x + 8, pos.y + 8 } + ImVec2{ 1.0f, 1.0f }, ImVec2{ pos.x + 3, pos.y + 3 } + ImVec2{ 1.0f, 1.0f }, color & IM_COL32_A_MASK, thickness + 0.3f);
    drawList->AddLine(ImVec2{ pos.x - 8, pos.y + 8 } + ImVec2{ 1.0f, 1.0f }, ImVec2{ pos.x - 3, pos.y + 3 } + ImVec2{ 1.0f, 1.0f }, color & IM_COL32_A_MASK, thickness + 0.3f);

    drawList->AddLine(ImVec2{ pos.x + 8, pos.y - 8 } + ImVec2{ 1.0f, 1.0f }, ImVec2{ pos.x + 3, pos.y - 3 } + ImVec2{ 1.0f, 1.0f }, color & IM_COL32_A_MASK, thickness + 0.3f);
    drawList->AddLine(ImVec2{ pos.x - 8, pos.y - 8 } + ImVec2{ 1.0f, 1.0f }, ImVec2{ pos.x - 3, pos.y - 3 } + ImVec2{ 1.0f, 1.0f }, color & IM_COL32_A_MASK, thickness + 0.3f);

    drawList->AddLine({ pos.x + 8, pos.y + 8 }, { pos.x + 3, pos.y + 3 }, color, thickness + 0.3f);
    drawList->AddLine({ pos.x - 8, pos.y + 8 }, { pos.x - 3, pos.y + 3 }, color, thickness + 0.3f);

    drawList->AddLine({ pos.x + 8, pos.y - 8 }, { pos.x + 3, pos.y - 3 }, color, thickness + 0.3f);
    drawList->AddLine({ pos.x - 8, pos.y - 8 }, { pos.x - 3, pos.y - 3 }, color, thickness + 0.3f);

    drawList->Flags |= ImDrawListFlags_AntiAliasedLines;
}


bool KillShot = false;

void Misc::Killmarker(GameEvent* event) noexcept
{
    if (!config->killMarker.enabled || !interfaces->engine->isInGame() || !config->killSound) {
        return;
    }

    KillShot = true;

    int attacker = interfaces->engine->getPlayerForUserId(event->getInt("attacker"));

    if (attacker == LocalPlayerOld::Index()) {
        if (config->killMarker.enabled)
            config->killmarker_time = 255;
        if (config->killSound)
            interfaces->engine->clientCmdUnrestricted("play /player/orch_hit_csharp_short.wav");
    }
}

void Misc::Hitmarker(GameEvent* event) noexcept
{
    if (!config->hitMarker.enabled || !interfaces->engine->isInGame() || !config->hitSound) {
        return;
    }

    if (!KillShot) {

        int attacker = interfaces->engine->getPlayerForUserId(event->getInt("attacker"));

        if (attacker == LocalPlayerOld::Index()) {
            if (config->hitMarker.enabled)
                config->hitmarker_time = 255;
            if (config->hitSound) {
                interfaces->engine->clientCmdUnrestricted("play buttons/arena_switch_press_02");
            }
        }
    }
}

void Misc::HitmarkerRender() noexcept
{
    if (!config->hitMarker.enabled || !interfaces->engine->isInGame()) {
        return;
    }

    if (config->hitmarker_time > 0) {

        config->hitMarker.color[3] = config->hitmarker_time / 255.f;

        drawMarker(ImGui::GetBackgroundDrawList(), ImGui::GetIO().DisplaySize / 2, Helpers::calculateColor(config->hitMarker), config->hitMarker.thickness);

        config->hitmarker_time -= 3;
    }
}


void Misc::KillmarkerRender() noexcept
{
    if (!config->killMarker.enabled || !interfaces->engine->isInGame()) {
        return;
    }

    if (config->killmarker_time > 0) {

        config->killMarker.color[3] = config->killmarker_time / 255.f;

        drawMarker(ImGui::GetBackgroundDrawList(), ImGui::GetIO().DisplaySize / 2, Helpers::calculateColor(config->killMarker), config->killMarker.thickness);

        config->killmarker_time -= 3;
    }
    else {
        KillShot = false;
	}
}






//void Misc::Hitmarker(GameEvent* event) noexcept
//{
//    if (!config->hitMarker.enabled || !interfaces->engine->isInGame()) {
//        return;
//    }
//
//    int attacker = interfaces->engine->getPlayerForUserId(event->getInt("attacker"));
//
//    if (attacker == LocalPlayerOld::Index()) {
//        config->hitmarker_time = 255;
//        interfaces->engine->clientCmdUnrestricted("play buttons/arena_switch_press_02");
//    }
//}
//
//void Misc::HitmarkerRender() noexcept
//{
//    if (!config->hitMarker.enabled || !interfaces->engine->isInGame()) {
//        return;
//    }
//
//    if (config->hitmarker_time > 0) {
//
//        config->hitMarker.color[3] = config->hitmarker_time / 255.f;
//
//        drawMarker(ImGui::GetBackgroundDrawList(), ImGui::GetIO().DisplaySize / 2, Helpers::calculateColor(config->hitMarker), config->hitMarker.thickness);
//
//        config->hitmarker_time -= 3;
//    }
//}
//
//void Misc::Killmarker(GameEvent* event) noexcept
//{
//    if (!config->killMarker.enabled || !interfaces->engine->isInGame()) {
//        return;
//    }
//
//    int attacker = interfaces->engine->getPlayerForUserId(event->getInt("attacker"));
//
//    if (attacker == LocalPlayerOld::Index()) {
//        config->killmarker_time = 255;
//    }
//}
//
//void Misc::KillmarkerRender() noexcept
//{
//    if (!config->killMarker.enabled || !interfaces->engine->isInGame()) {
//        return;
//    }
//
//    if (config->killmarker_time > 0) {
//
//        config->killMarker.color[3] = config->killmarker_time / 255.f;
//
//        drawMarker(ImGui::GetBackgroundDrawList(), ImGui::GetIO().DisplaySize / 2, Helpers::calculateColor(config->killMarker), config->killMarker.thickness);
//
//        config->killmarker_time -= 3;
//    }
//}