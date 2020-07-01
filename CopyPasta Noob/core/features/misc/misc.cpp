#include "../features.hpp"
#include "../../../hazedumper.hpp"
#include <iostream>
#include "../../../_Objects/Objects.hpp"

void misc::allMisc::bunny_hop(c_usercmd* cmd)
{
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
    if (!variables::antiflash_bool) {
        return;
    }

    LocalPlayer::FlashAlpha(.0f);
};

void visuals::FOV::FovChanger(c_usercmd* cmd) {
    if (!variables::FovEnable) {
        return;
    }

    if (LocalPlayer::FovChanger() != variables::FOV) {
        if (LocalPlayer::Scoped()) 
        {
            LocalPlayer::FovChanger(variables::FOV - 50);
        }
        else
        {
            LocalPlayer::FovChanger(variables::FOV);
        }
    }
};



//void misc::allMisc::ClanTagChanger(c_usercmd* cmd) {
//    if (!variables::clanTag_bool) {
//        return;
//    }
//
//    std::cout << LocalPlayer::GetClanTag() << std::endl;
//
//    /*for (int i = 0; i < 3; i++) {
//        switch (i)
//        {
//        case 1:
//            LocalPlayer::SetClanTag(" ");
//            break;
//        case 2:
//            LocalPlayer::SetClanTag("C");
//            break;
//        case 3:
//            LocalPlayer::SetClanTag("CP");
//            break;
//        case 4:
//            LocalPlayer::SetClanTag("CPN");
//            break;
//        case 5:
//            LocalPlayer::SetClanTag("CP");
//            break;
//        case 6:
//            LocalPlayer::SetClanTag("C");
//            break;
//        case 7:
//            LocalPlayer::SetClanTag(" ");
//            break;
//        }
//    }*/
//
//}