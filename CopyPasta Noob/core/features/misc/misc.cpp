#include "../features.hpp"
#include "../../../hazedumper.hpp"
#include <iostream>
#include "../../../_Objects/Objects.hpp"

void misc::allMisc::bunny_hop(c_usercmd* cmd)
{
    if (!variables::miscEnable) {
        return;
    }
	if (!variables::bunnyhop_bool)
    {
		return;
	}
	if (LocalPlayer::checkLocalVal())
	{
		if (GetAsyncKeyState(VK_SPACE) && LocalPlayer::Flags() & (1 << 0))
		{
			Client::ForceJump();
		}
	}
};

void misc::allMisc::antiflash(c_usercmd* cmd) {
    if (!variables::miscEnable) {
        return;
    }
    if (!variables::antiflash_bool) {
        return;
    }

    LocalPlayer::FlashAlpha(.0f);
};

void visuals::wh::FovChanger(c_usercmd* cmd) {
    if (!variables::miscEnable) {
        return;
    }

    if (LocalPlayer::FovChanger() != (int)variables::FOV) {
        LocalPlayer::FovChanger(variables::FOV);
    }
    else {
        return;
    }

    //me.WriteDWORD(player + m_iFOVStart - 4, 120);
};