#include <Windows.h>
#include <iostream>
#include "../features.hpp"
#include "../../../_Objects/Objects.hpp"
#include "../../menu/framework.hpp"

#include "../../../dependencies/utilities/utilities.hpp"

//#include "..\SDK\IVEngineClient.h"
//#include "..\SDK\PlayerInfo.h"

///////#include "../../../source-sdk/structs/weaponinfo.hpp" Возможно

//#include "../../../dependencies/math/math.cpp"
#include "../../../_D3DDraw/DrawManager.hpp"
#include "../../../_D3DDraw/D3DFont.hpp"
//#include "../../../dependencies/interfaces/iv_engine_client.hpp"


void RenderBox(int i)
{
    vec3_t vecBottom;
    //vec3_t vecOrigin = vecBottom = Entity(2).Location();
    Vec3 ELOC = Entity(i).Location();
    vec3_t vecOrigin = vecBottom = { ELOC.x, ELOC.y, ELOC.z };

    vecBottom.z += (Entity(i).Flags() & 261/* хуй знает какое тут число  263 */) ? 55.f : 74.f; // duck

    vec3_t vecScreenBottom;

    if (!math::world_to_screen(vecBottom, vecScreenBottom)) {
        return;
    }

    vec3_t vecScreenOrigin;

    if (!math::world_to_screen(vecOrigin, vecScreenOrigin))
    {
        return;
    }

    float sx = vecScreenOrigin.x;
    float sy = vecScreenOrigin.y;
    float h = vecScreenBottom.y - vecScreenOrigin.y;
    float w = h * 0.25f;


    /* Draw rect around the entity */
    /*            pos1    pos2 pos3   pos4      get ent team       equals urs  */
    g_Render.Rect(sx - w, sy, sx + w, sy + h, (Entity(i).Team() == LocalPlayer::Team()) ? color(255, 0, 0, 255) : color(0, 255, 0, 255));


    /* Draw rect outline */
    g_Render.Rect(sx - w + 1, sy + 1, sx + w - 1, sy + h - 1, color(0, 0, 0, 255));


    std::cout << "RenderBoxEnd" << std::endl;
}

void RenderName(int i)
{
    vec3_t vecBottom;
    //vec3_t vecOrigin = vecBottom = Entity(i).Location();
    Vec3 ELOC = Entity(i).Location();
    vec3_t vecOrigin = vecBottom = { ELOC.x, ELOC.y, ELOC.z };

    player_info_t *pInfo = new player_info_t;
    //g_pEngine->GetPlayerInfo(i, &pInfo);
    iv_engine_client ivec;
    ivec.get_player_info(i, pInfo);

    vecBottom.z += (Entity(i).Flags() & 261/* хуй знает какое тут число  263 */) ? 55.f : 74.f; //diff sizes when ppl crouch (cant use 80f for height cuz it re-breaks esp) 

    vec3_t vecScreenBottom;

    if (!math::world_to_screen(vecBottom, vecScreenBottom))
    {
        return;
    }

    vec3_t vecScreenOrigin;

    if (!math::world_to_screen(vecOrigin, vecScreenOrigin))
    {
        return;
    }

    float sx = vecScreenOrigin.x;
    float sy = vecScreenOrigin.y;
    float h = vecScreenBottom.y - vecScreenOrigin.y;

    g_Render.String(sx, sy + (h - 16), CD3DFONT_CENTERED_X | CD3DFONT_DROPSHADOW, /*pos&font*/
        (LocalPlayer::Team() == Entity(i).Team()) ? color(0, 255, 0, 255) : color(255, 0, 0, 255), /*get team & color*/
        g_Fonts.pFontTahoma10.get(), pInfo->name); //font & name
    std::cout << "RenderNameEnd" << std::endl;
}

void RenderWeaponName(int i)
{
    vec3_t vecBottom;
    //vec3_t vecOrigin = vecBottom = Entity(i).Location();
    Vec3 ELOC = Entity(i).Location();
    vec3_t vecOrigin = vecBottom = { ELOC.x, ELOC.y, ELOC.z };

    vecBottom.z += (Entity(i).Flags() & 261/* хуй знает какое тут число  263 */) ? 55.f : 74.f; //im retarded rn so im just commenting shit

    vec3_t vecScreenBottom;

    if (!math::world_to_screen(vecBottom, vecScreenBottom))
    {
        return;
    }

    vec3_t vecScreenOrigin;

    if (!math::world_to_screen(vecOrigin, vecScreenOrigin))
    {
        return;
    }

    float sx = vecScreenOrigin.x;
    float sy = vecScreenOrigin.y;
    float h = vecScreenBottom.y - vecScreenOrigin.y; //up to here is just getting pos n shit

    int weapon = Entity(i).GetActiveWeapon();


    if (!weapon)
    {
        return;
    }

    std::string strWeaponName = std::to_string(weapon);
    strWeaponName.erase(0, 7);

    const auto stringToUpper = [](std::string strToConv) -> std::string
    {
        std::string tmp{};
        for (std::string::iterator p = strToConv.begin(); strToConv.end() != p; ++p)
        {
            *p = toupper(*p);
            tmp.push_back(*p);
        }

        return tmp;
    };


    g_Render.String(sx, sy, CD3DFONT_CENTERED_X | CD3DFONT_DROPSHADOW,
        (LocalPlayer::Team() == Entity(i).Team()) ? color(0, 255, 0, 255) : color(255, 0, 0, 255),
        g_Fonts.pFontTahoma10.get(), stringToUpper(strWeaponName).c_str());
    std::cout << "RenderWeaponNameEnd" << std::endl;
}



void visuals::wh::ESP(c_usercmd* cmd) {
    if (!variables::ESP_bool) {
        return;
    }

    for (int i = 0; i < 32; ++i)
    {
        if (Entity(i).Base() == NULL || Entity(i).Health() == 0 || Entity(i).Dormant() || LocalPlayer::LocalPlayerPtr() == Entity(i).Base()) {
            continue;
        }

        std::cout << "StartESP" << std::endl;

        if (variables::ShowBoxes) {
            std::cout << "RenderBoxStart" << std::endl;
            RenderBox(i);
        }

        if (variables::ShowNames) {
            std::cout << "RenderNameStart" << std::endl;
            RenderName(i);
        }

        if (variables::ShowWeapons) {
            std::cout << "RenderWeaponNameStart" << std::endl;
            RenderWeaponName(i);
        } 
    }
}