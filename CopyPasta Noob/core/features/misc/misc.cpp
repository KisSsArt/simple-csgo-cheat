#include "../features.hpp"
#include "../../../hazedumper.hpp"
#include <iostream>
#include "../../../_Objects/Objects.hpp"

void misc::movement::bunny_hop(c_usercmd* cmd)
{
	if (!variables::bunnyhop_bool)
	{
		return;
	}
	if (LocalPlayer::checkLocalVal() == true)
	{
		if (GetAsyncKeyState(VK_SPACE) && LocalPlayer::Flags() & (1 << 0))
		{
			Client::ForceJump();
		}
	}
};

void misc::visuals::antiflash(c_usercmd* cmd) {
    if (!variables::antiflash_bool) {
        return;
    }

    LocalPlayer::FlashAlpha(.0f);
};