#include "Config.h"
#include "SDK/Engine.h"
#include "SDK/Entity.h"
#include "SDK/EntityList.h"
#include "SDK/UserCmd.h"

/*
#include "../features.hpp"
#include "../../../hazedumper.hpp"
#include <vector>
#include <math.h>
#include "../../../_Objects/Objects.hpp"

//void ForceAttack(bool shoot, uintptr_t client)
//{
//    *(int*)(client + hazedumper::signatures::dwForceAttack) = shoot ? 5 : 4;
//}


////AIM
//bool smooth = false;
////IClientEntity* PlayerToAim;
//uintptr_t* PlayerToAim;
//float AimFOV;
//bool isaimbotting;
//
////Hard Coded Made when TroubleShooting.
//int ScreenCenterX = 960;
//int ScreenCenterY = 540;
//
//
//void AimAtPos(float x, float y)
//{
//
//    //int width = GetSystemMetrics(SM_CXSCREEN);
//    //int height = GetSystemMetrics(SM_CYSCREEN);
//    //int ScreenCenterY = height * 0.5f;
//    //int ScreenCenterX = width * 0.5f;
//
//
//
//    float AimSpeed = 5;
//    float TargetX = 0;
//    float TargetY = 0;
//
//    //X Axis
//    if (x != 0)
//    {
//        if (x > ScreenCenterX)
//        {
//            TargetX = -(ScreenCenterX - x);
//            TargetX /= AimSpeed;
//            if (TargetX + ScreenCenterX > ScreenCenterX * 2) TargetX = 0;
//        }
//
//        if (x < ScreenCenterX)
//        {
//            TargetX = x - ScreenCenterX;
//            TargetX /= AimSpeed;
//            if (TargetX + ScreenCenterX < 0) TargetX = 0;
//        }
//    }
//
//    //Y Axis
//
//    if (y != 0)
//    {
//        if (y > ScreenCenterY)
//        {
//            TargetY = -(ScreenCenterY - y);
//            TargetY /= AimSpeed;
//            if (TargetY + ScreenCenterY > ScreenCenterY * 2) TargetY = 0;
//        }
//
//        if (y < ScreenCenterY)
//        {
//            TargetY = y - ScreenCenterY;
//            TargetY /= AimSpeed;
//            if (TargetY + ScreenCenterY < 0) TargetY = 0;
//        }
//    }
//
//    if (!smooth)
//    {
//        mouse_event(MOUSEEVENTF_MOVE, (DWORD)(TargetX), (DWORD)(TargetY), NULL, NULL);
//        return;
//    }
//
//    TargetX /= 10;
//    TargetY /= 10;
//
//    //Mouse even't will round to 0 a lot of the time, so we can add this, to make it more accurrate on slow speeds.
//    if (fabs(TargetX) < 1)
//    {
//        if (TargetX > 0)
//        {
//            TargetX = 1;
//        }
//        if (TargetX < 0)
//        {
//            TargetX = -1;
//        }
//    }
//    if (fabs(TargetY) < 1)
//    {
//        if (TargetY > 0)
//        {
//            TargetY = 1;
//        }
//        if (TargetY < 0)
//        {
//            TargetY = -1;
//        }
//    }
//    mouse_event(MOUSEEVENTF_MOVE, TargetX, TargetY, NULL, NULL);
//}
//
//
//float DistanceBetweenCross(float X, float Y)
//{
//    float ydist = (Y - ScreenCenterY);/*GetSystemMetrics(SM_CYSCREEN)/2*/
//    float xdist = (X - ScreenCenterX);/*GetSystemMetrics(SM_CXSCREEN)/2*/
//    float Hypotenuse = sqrt(pow(ydist, 2) + pow(xdist, 2));
//    return Hypotenuse;
//}
//
//
//bool GetAimKey()
//{
//    return (GetAsyncKeyState(VK_LBUTTON));
//}
//
//
//void AimAt(uintptr_t* plr)
//{
//    if (plr)
//    {
//        if (!cEng.IsAlive(plr))
//        {
//            isaimbotting = false;
//            return;
//        }
//
//        std::vector Head;
//        std::vector w2sHead;
//
//        //Head = cEng.GetEyePosition(plr);
//        if (cEng.GetBonePosition(plr, Head, 10))
//        {
//            cMath.WorldToScreen(Head, w2sHead);
//            if (w2sHead.Y != 0 || w2sHead.X != 0)
//            {
//                if ((DistanceBetweenCross(w2sHead.X, w2sHead.Y) <= AimFOV * 8) || isaimbotting)
//                {
//                    isaimbotting = true;
//                    AimAtPos(w2sHead.X, w2sHead.Y);
//                }
//            }
//        }
//    }
//}
//
//
//void Aimbot()
//{
//    static bool aimbotON = false;
//
//    ////Lazy!!!!, Make a fucking menu!
//    //if (GetAsyncKeyState(VK_DELETE) & 1) { aimbotON = !aimbotON; }
//    //if (GetAsyncKeyState(VK_INSERT) & 1) { smooth = !smooth; }
//    //char msg[1024];
//    //sprintf(msg, "[COUNTERNOOB v1.0] AIM: %s - Status: %s", aimbotON ? "ON!" : "OFF", smooth ? "Smooth" : "Precise");
//    //cDraw.DrawString(espfont, 0, 10, 5, Color(255, 255, 255, 255), msg);
//
//    if (aimbotON)
//    {
//        if ((PlayerToAim != 0))
//        {
//            if (GetAimKey())
//            {
//                AimAt(PlayerToAim);
//            }
//            else
//            {
//                isaimbotting = false;
//            }
//        }
//    }
//}
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*void aimbot::aim::trigger(c_usercmd* cmd) {
    if (!variables::trigger_bool) {
        return;
    }

    uintptr_t EntityList = Memory::Read<uintptr_t>(Memory::clientBase() + hazedumper::signatures::dwEntityList);

    int crosshairEntity = Memory::Read<int>(Memory::clientBase() + hazedumper::signatures::dwEntityList + (LocalPlayer::CrosshairID() - 1) * 16);
    int entityTeam = Memory::Read<int>(crosshairEntity + hazedumper::netvars::m_iTeamNum);

    int entityHP = Memory::Read<int>(crosshairEntity + hazedumper::netvars::m_iHealth);

    if (LocalPlayer::CrosshairID() != 0 && crosshairEntity != 0 && LocalPlayer::Team() != entityTeam && crosshairEntity > 0 && entityHP > 0)
    {
        Sleep(1);
        Client::ForceAttack(true);
        Sleep(10);
        Client::ForceAttack(false);
    }
}

void aimbot::aim::rageAim(c_usercmd* cmd) {
    if (!variables::rageaim_bool) {
        return;
    }



}
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////









//void GetClosestPlayerToCrossHair(IClientEntity* Player, float& max, float aimfov)
//{
//    if (!GetAimKey() || !isaimbotting)
//    {
//        if (Player)
//        {
//            Vector Head;
//            Vector w2sHead;
//            //Head = cEng.GetEyePosition(Player);
//            if (cEng.GetBonePosition(Player, Head, 10))
//            {
//                cMath.WorldToScreen(Head, w2sHead);
//                float Dist = DistanceBetweenCross(w2sHead.X, w2sHead.Y);
//                if (Dist < max)
//                {
//                    max = Dist;
//                    PlayerToAim = Player;
//                    AimFOV = aimfov;
//                }
//            }
//        }
//    }
//
//}

//void GetClosestPlayerToCrossHair(uintptr_t* EntityToAim, float& max, float aimfov)
//{
//    if (!GetAimKey() || !isaimbotting)
//    {
//        if (EntityToAim)
//        {
//            std::vector Head;
//            std::vector w2sHead;
//            //Head = cEng.GetEyePosition(Player);
//            if (cEng.GetBonePosition(EntityToAim, Head, 10))
//            {
//                cMath.WorldToScreen(Head, w2sHead);
//                float Dist = DistanceBetweenCross(w2sHead.X, w2sHead.Y);
//                if (Dist < max)
//                {
//                    max = Dist;
//                    PlayerToAim = EntityToAim;
//                    AimFOV = aimfov;
//                }
//            }
//        }
//    }
//
//}