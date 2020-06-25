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