#include <Windows.h>
#include <iostream>
#include "../../../dependencies/utilities/renderer/renderer.hpp"
#include "../features.hpp"
#include "../../../_Objects/Objects.hpp"
#include "../../../dependencies/math/math.hpp"
#include "../../../dependencies/utilities/csgo.hpp"

//DWORD gameModule;
//DWORD localPlayer;
//DWORD localPlayerAddy = 0xCF1A4C;
//DWORD vectorOrigin = 0x138; //
//DWORD entityList = 0x4D03AA4;
//DWORD viewMatrix = 0x4CF54D4;
//DWORD boneMatrix = 0x26A8;
//DWORD dormat = 0xED;
//DWORD team = 0xF4;
//DWORD healthOffset = 0x100;
HWND hwndCSGO;
HBRUSH Brush;
HDC hdcCSGO;

float Matrix[16];



//render::draw_filled_rect();
void DrawFilledRect(int x, int y, int w, int h)
{
    RECT rect = { x, y, x + w, y + h };
    FillRect(hdcCSGO, &rect, Brush);
}

//render::draw_rect();
void DrawBorderBox(int x, int y, int w, int h, int thickness)
{
    DrawFilledRect(x, y, w, thickness);
    DrawFilledRect(x, y, thickness, h);
    DrawFilledRect((x + w), y, thickness, h);
    DrawFilledRect(x, y + h, w + thickness, thickness);
}





//this is the world to screen function for directX
//math::world_to_screen()
bool WorldToScreen(Vec3 pos, Vec2& screen, float matrix[16], int windowWidth, int windowHeight)
{
    Vec4 clipCoords;
    clipCoords.x = pos.x * matrix[0] + pos.y * matrix[1] + pos.z * matrix[2] + matrix[3];
    clipCoords.y = pos.x * matrix[4] + pos.y * matrix[5] + pos.z * matrix[6] + matrix[7];
    clipCoords.z = pos.x * matrix[8] + pos.y * matrix[9] + pos.z * matrix[10] + matrix[11];
    clipCoords.w = pos.x * matrix[12] + pos.y * matrix[13] + pos.z * matrix[14] + matrix[15];

    if (clipCoords.w < 0.1f)
        return false;


    Vec3 NDC;
    NDC.x = clipCoords.x / clipCoords.w;
    NDC.y = clipCoords.y / clipCoords.w;
    NDC.z = clipCoords.z / clipCoords.w;

    screen.x = (windowWidth / 2 * NDC.x) + (NDC.x + windowWidth / 2);
    screen.y = -(windowHeight / 2 * NDC.y) + (NDC.y + windowHeight / 2);
    return true;
}


void visuals::wh::ESP(c_usercmd* cmd) {
    if (!variables::ESP_bool) {
        return;
    }

    hwndCSGO = FindWindow(0, ("Counter-Strike: Global Offensive"));//Gets Window
    hdcCSGO = GetDC(hwndCSGO);

    Vec2 vScreen;
    Vec2 vHead;

    memcpy(&Matrix, (PBYTE*)(Memory::clientBase() + hazedumper::signatures::dwViewMatrix), sizeof(Matrix));
    
    for (int i = 0; i < 32; i++)
    {
        if (Entity(i).Base() != NULL)
        {
            if (Entity(i).Base() != LocalPlayer::LocalPlayerPtr())//Makes sure we dont draw on our own player
            {

                if (Entity(i).Dormant() == 0)//Checks if the entity is culled
                {
                    if (Entity(i).Health() > 0)
                    {
                        if (WorldToScreen(Entity(i).Location(), vScreen, Matrix, 1920, 1080))
                        {
                            if (WorldToScreen(Entity(i).BonePos(Hitbox::HEAD), vHead, Matrix, 1920, 1080))
                            {
                                float head = vHead.y - vScreen.y;
                                float width = head / 2;
                                float center = width / -2;

                                if (LocalPlayer::Team() == Entity(i).Team())
                                {
                                    //render::draw_rect(vScreen.x + center, vScreen.y, width, head - 5, color::green());
                                    //std::cout << "X: " << vScreen.x + center << std::endl;
                                    //std::cout << "Y: " << vScreen.y << std::endl;
                                    //std::cout << "W: " << width << std::endl;
                                    //std::cout << "H: " << head - 5 << std::endl;
                                }
                                else
                                {
                                    //render::draw_rect(vScreen.x + center, vScreen.y, width, head - 5, color::red());
                                    //std::cout << "X: " << vScreen.x + center << std::endl;
                                    //std::cout << "Y: " << vScreen.y << std::endl;
                                    //std::cout << "W: " << width << std::endl;
                                    //std::cout << "H: " << head - 5 << std::endl;

                                    //Brush = CreateSolidBrush(RGB(255, 000, 000));
                                    //DrawBorderBox(vScreen.x + center, vScreen.y, width, head - 5, 2);
                                    render::draw_rect(vScreen.x + center, vScreen.y, width, head - 5, color::red());
                                    //DeleteObject(Brush);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    Sleep(1);
    DeleteObject(hdcCSGO);
}

//H: -291.539
//X: 902.302
//Y: 750.52
//W: -143.27
//H: -291.539X: 902.302

//int mainThread()
//{
//    //gameModule = (DWORD)GetModuleHandle("client.dll");//creates the game module
//    //hwndCSGO = FindWindow(0, ("Counter-Strike: Global Offensive"));//Gets Window
//    
//    //Base of player
//    Vec2 vScreen;
//    //Head of player
//    Vec2 vHead;
//
//    //memcpy(&Matrix, (PBYTE*)(Memory::clientBase() + viewMatrix), sizeof(Matrix));
//    memcpy(&Matrix, (PBYTE*)(Memory::clientBase() + hazedumper::signatures::dwViewMatrix), sizeof(Matrix));
//
//    //localPlayer = *(DWORD*)(gameModule + localPlayerAddy);//Creates your local player
//
//    //if (localPlayer == NULL)//checks if your local player is existant
//    //{
//    //    while (localPlayer == NULL)
//    //    {
//    //        localPlayer = LocalPlayer::LocalPlayerPtr();
//    //    }
//    //}
//
//    //hdcCSGO = GetDC(hwndCSGO);
//
//    //int myTeam = *(int*)(localPlayer + team);
//
//    //our entity list loop
//    for (int i = 0; i < 32; i++)
//    {
//        //each entity is 0x10 apart in memory
//        ///DWORD entity = *(DWORD*)(gameModule + entityList + i * 0x10);
//
//
//        if (Entity(i).Base() != NULL)
//        {
//            if (Entity(i).Base() != LocalPlayer::LocalPlayerPtr())//Makes sure we dont draw on our own player
//            {
//                //int entityTeam = *(int*)(entity + team);
//
//                //Vec3 entityLocation = *(Vec3*)(entity + vectorOrigin);
//
//                //DWORD dwBoneMatrix = *(DWORD*)(entity + boneMatrix);
//
//                //DWORD health = *(DWORD*)(entity + healthOffset);
//                //int isDormat = *(int*)(entity + dormat);
//
//                if (Entity(i).Dormant() == 0)//Checks if the entity is culled
//                {
//                    if (Entity(i).Health() > 0)
//                    {
//                        if (WorldToScreen(Entity(i).Location(), vScreen, Matrix, 1920, 1080))
//                        {
//                            //float enemyHeadX = Memory::Read<float>(dwBoneMatrix + 0x30 * 9 + 0x0C);
//                                //*(float*)(dwBoneMatrix + 0x30 * 9 + 0x0C);
//                            //float enemyHeadY = Memory::Read<float>(dwBoneMatrix + 0x30 * 9 + 0x1C);
//                                //*(float*)(dwBoneMatrix + 0x30 * 9 + 0x1C);
//                            //float enemyHeadZ = Memory::Read<float>(dwBoneMatrix + 0x30 * 9 + 0x2C);
//                                //*(float*)(dwBoneMatrix + 0x30 * 9 + 0x2C);
//
//                            //turns the head bone floats into a Vec3
//                            //Vec3 enemyHeadPos = { enemyHeadX, enemyHeadY, enemyHeadZ };
//
//                            //this takes the entitys cords and the players view matrix turning them into screen cords
//                            if (WorldToScreen(Entity(i).BonePos(Hitbox::HEAD), vHead, Matrix, 1920, 1080))
//                            {
//                                float head = vHead.y - vScreen.y;
//                                float width = head / 2;
//                                float center = width / -2;
//
//                                if (LocalPlayer::Team() == Entity(i).Team())
//                                {
//                                    //Brush = CreateSolidBrush(RGB(000, 000, 255));//Any color you want
//                                    //DrawBorderBox(vScreen.x + center, vScreen.y, width, head - 5, 2);//Draws the boxes
//                                    render::draw_rect(vScreen.x + center, vScreen.y, width, head - 5, color::green());
//                                    //DeleteObject(Brush);
//                                }
//                                else
//                                {
//                                    //Brush = CreateSolidBrush(RGB(255, 000, 000));
//                                    //DrawBorderBox(vScreen.x + center, vScreen.y, width, head - 5, 2);
//                                    render::draw_rect(vScreen.x + center, vScreen.y, width, head - 5, color::red());
//                                    //DeleteObject(Brush);
//                                }
//                            }
//                        }
//                    }
//                }
//            }
//        }
//    }
//    Sleep(1);
//    //DeleteObject(hdcCSGO);
//}