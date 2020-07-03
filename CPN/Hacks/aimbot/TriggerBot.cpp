#include "TriggerBot.h"
#include "../../hazedumper.hpp"
#include <vector>
#include <math.h>
#include "../../_Objects/Objects.hpp"
#include "../../Config/Config.h"

void Aim::triggerBot() noexcept
{
    if (!config->trigger_bool) {
        return;
    }
    
    uintptr_t EntityList = MemoryOld::Read<uintptr_t>(MemoryOld::clientBase() + hazedumper::signatures::dwEntityList);

    int crosshairEntity = MemoryOld::Read<int>(MemoryOld::clientBase() + hazedumper::signatures::dwEntityList + (LocalPlayerOld::CrosshairID() - 1) * 16);
    int entityTeam = MemoryOld::Read<int>(crosshairEntity + hazedumper::netvars::m_iTeamNum);

    int entityHP = MemoryOld::Read<int>(crosshairEntity + hazedumper::netvars::m_iHealth);

    if (LocalPlayerOld::CrosshairID() != 0 && crosshairEntity != 0 && LocalPlayerOld::Team() != entityTeam && crosshairEntity > 0 && entityHP > 0)
    {
        /*Sleep(1);
        Client::ForceAttack(true);
        Sleep(10);
        Client::ForceAttack(false);*/
        Client::ForceAttack();
    }
}