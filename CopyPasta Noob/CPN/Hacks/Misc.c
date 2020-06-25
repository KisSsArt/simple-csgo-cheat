#include "../Base/Config/Config.h"
#include "Misc.hpp"
#include "../SDK/Engine.h"
#include "../SDK/Entity.h"
#include "../SDK/EntityList.h"
#include "../SDK/UserCmd.h"

VOID Misc_bunnyhop(UserCmd* cmd)
{
    PVOID localPlayer = EntityList_getEntity(Engine_getLocalPlayer());
    static BOOLEAN wasLastTimeOnGround = TRUE;

    if (config.misc.bunnyhop && !(*Entity_flags(localPlayer) & 1) && !wasLastTimeOnGround && *Entity_moveType(localPlayer) != MoveType_Ladder)
        cmd->buttons &= ~IN_JUMP;

    wasLastTimeOnGround = *Entity_flags(localPlayer) & 1;
}

VOID Misc_autostrafe(UserCmd* cmd)
{
    if (config.misc.autostrafe && !(*Entity_flags(EntityList_getEntity(Engine_getLocalPlayer())) & 1)) {
        if (cmd->mousedx < 0)
            cmd->sidemove = -450.0f;
        else if (cmd->mousedx > 0)
            cmd->sidemove = 450.0f;

        //ConVar_setValueInt(Cvar_findVar("sv_cheats"), 1);
        //ConVar_setValueInt(Cvar_findVar("sv_autobunnyhopping"), 1);
        //ConVar_setValueInt(Cvar_findVar("sv_enablebunnyhopping"), 1000);
        //ConVar_setValueInt(Cvar_findVar("sv_airaccelerate"), 1000);
        
    }
}

VOID Misc_moonwalk(UserCmd* cmd)
{
    if (config.misc.moonwalk && *Entity_moveType(EntityList_getEntity(Engine_getLocalPlayer())) != MoveType_Ladder)
        cmd->buttons ^= IN_FORWARD | IN_BACK | IN_MOVELEFT | IN_MOVERIGHT;
}

VOID Misc_sv_cheats(UserCmd* cmd)
{
    if (config.misc.sv_cheats && !(*Entity_flags(EntityList_getEntity(Engine_getLocalPlayer())) & 1)) {
        ConVar_setValueInt(Cvar_findVar("sv_cheats"), 1);
        
        //ConVar_setValueInt(Cvar_findVar("host_timescale"), 1);
    }
}

/*

#include "../features.hpp"
#include "../../../hazedumper.hpp"
#include <iostream>
#include "../../../_Objects/Objects.hpp"

void misc::movement::bunny_hop(c_usercmd* cmd) {
    if (!variables::bunnyhop_bool) {
        return;
    }

    if (GetAsyncKeyState(VK_SPACE) != 0)
    {
        if (LocalPlayer::Flags() == 257 || LocalPlayer::Flags() == 261 || LocalPlayer::Flags() == 263)
        {
            Client::ForceJump(true);
            Sleep(10);
            Client::ForceJump(false);
        }
    }
};

void misc::visuals::antiflash(c_usercmd* cmd) {
    if (!variables::antiflash_bool) {
        return;
    }

    LocalPlayer::FlashAlpha(.0f);
};

*/