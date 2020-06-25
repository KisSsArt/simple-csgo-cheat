#include "DownloadHazedumper.h"

#include <fstream>

#include <Windows.h>
#include <iostream>
#include <String>
#include <TChar.h>
#include <urlmon.h>
#include <filesystem>

#include "json.hpp"
#include "../../hazedumper.hpp"

#pragma comment(lib, "urlmon.lib")

using namespace hazedumper::signatures;
using namespace hazedumper::netvars;

DownloadHazedumper::DownloadHazedumper() {
    
    //std::cout << "[" << __FUNCTION__ << "] - Downloading \"hazedumper/master/csgo.json\", please wait." << '\n';
    std::cout << "[HazedumperUpdater] - Downloading \"https://github.com/MrSoczekXD/hazedumper/blob/master/csgo.json\", please wait." << '\n';
    //std::cout << "[HazedumperUpdater] - Updating, please wait." << "\n";

    auto location = std::filesystem::current_path().string();

    location += "\\";

    std::string fileToSaveAs = "hazedumper.json";
    location += fileToSaveAs;

    //std::cout << location << std::endl;

    std::string downloadURL = "https://raw.githubusercontent.com/MrSoczekXD/hazedumper/master/csgo.json";

    HRESULT hResult = URLDownloadToFile(NULL, _T(downloadURL.c_str()), _T(location.c_str()), 0, NULL);
    if (hResult != S_OK) {
        MessageBoxA(NULL, "[HazedumperUpdater] Error: " + GetLastError(), "Updated Failed", MB_OK | MB_ICONERROR);
        ExitProcess(EXIT_FAILURE);
    }

    std::cout << "[HazedumperUpdater] - Successfully Downloaded!" << "\n";

    std::ifstream fin;
    fin.open(location, std::ios_base::in);

    std::string line;
    std::string jsonf = "";
    
    while (getline(fin, line)) {
        jsonf += line;
    }

    //(\w+) = j\["(\w+)"\]\["(\w+)"\].get<int>\(\);
    //if \(j["\2"]["\3"].is_number\(\) == 1\) { \n            \1 = j["\2"]["\3"].get<int>\(\); \n        } else { \n            std::cout << "\1: not found" << std::endl; \n        }\n

    nlohmann::json j = nlohmann::json::parse(jsonf);
    {
        hazedumper::timestamp = j["timestamp"].get<int>();
        //Netvars
        if (j["netvars"]["cs_gamerules_data"].is_number() == 1) {
            cs_gamerules_data = j["netvars"]["cs_gamerules_data"].get<int>();
        }
        else {
            std::cout << "cs_gamerules_data: not found" << std::endl;
        }

        if (j["netvars"]["m_ArmorValue"].is_number() == 1) {
            m_ArmorValue = j["netvars"]["m_ArmorValue"].get<int>();
        }
        else {
            std::cout << "m_ArmorValue: not found" << std::endl;
        }

        if (j["netvars"]["m_Collision"].is_number() == 1) {
            m_Collision = j["netvars"]["m_Collision"].get<int>();
        }
        else {
            std::cout << "m_Collision: not found" << std::endl;
        }

        if (j["netvars"]["m_CollisionGroup"].is_number() == 1) {
            m_CollisionGroup = j["netvars"]["m_CollisionGroup"].get<int>();
        }
        else {
            std::cout << "m_CollisionGroup: not found" << std::endl;
        }

        if (j["netvars"]["m_Local"].is_number() == 1) {
            m_Local = j["netvars"]["m_Local"].get<int>();
        }
        else {
            std::cout << "m_Local: not found" << std::endl;
        }

        if (j["netvars"]["m_MoveType"].is_number() == 1) {
            m_MoveType = j["netvars"]["m_MoveType"].get<int>();
        }
        else {
            std::cout << "m_MoveType: not found" << std::endl;
        }

        if (j["netvars"]["m_OriginalOwnerXuidHigh"].is_number() == 1) {
            m_OriginalOwnerXuidHigh = j["netvars"]["m_OriginalOwnerXuidHigh"].get<int>();
        }
        else {
            std::cout << "m_OriginalOwnerXuidHigh: not found" << std::endl;
        }

        if (j["netvars"]["m_OriginalOwnerXuidLow"].is_number() == 1) {
            m_OriginalOwnerXuidLow = j["netvars"]["m_OriginalOwnerXuidLow"].get<int>();
        }
        else {
            std::cout << "m_OriginalOwnerXuidLow: not found" << std::endl;
        }

        if (j["netvars"]["m_SurvivalGameRuleDecisionTypes"].is_number() == 1) {
            m_SurvivalGameRuleDecisionTypes = j["netvars"]["m_SurvivalGameRuleDecisionTypes"].get<int>();
        }
        else {
            std::cout << "m_SurvivalGameRuleDecisionTypes: not found" << std::endl;
        }

        if (j["netvars"]["m_SurvivalRules"].is_number() == 1) {
            m_SurvivalRules = j["netvars"]["m_SurvivalRules"].get<int>();
        }
        else {
            std::cout << "m_SurvivalRules: not found" << std::endl;
        }

        if (j["netvars"]["m_aimPunchAngle"].is_number() == 1) {
            m_aimPunchAngle = j["netvars"]["m_aimPunchAngle"].get<int>();
        }
        else {
            std::cout << "m_aimPunchAngle: not found" << std::endl;
        }

        if (j["netvars"]["m_aimPunchAngleVel"].is_number() == 1) {
            m_aimPunchAngleVel = j["netvars"]["m_aimPunchAngleVel"].get<int>();
        }
        else {
            std::cout << "m_aimPunchAngleVel: not found" << std::endl;
        }

        if (j["netvars"]["m_angEyeAnglesX"].is_number() == 1) {
            m_angEyeAnglesX = j["netvars"]["m_angEyeAnglesX"].get<int>();
        }
        else {
            std::cout << "m_angEyeAnglesX: not found" << std::endl;
        }

        if (j["netvars"]["m_angEyeAnglesY"].is_number() == 1) {
            m_angEyeAnglesY = j["netvars"]["m_angEyeAnglesY"].get<int>();
        }
        else {
            std::cout << "m_angEyeAnglesY: not found" << std::endl;
        }

        if (j["netvars"]["m_bBombPlanted"].is_number() == 1) {
            m_bBombPlanted = j["netvars"]["m_bBombPlanted"].get<int>();
        }
        else {
            std::cout << "m_bBombPlanted: not found" << std::endl;
        }

        if (j["netvars"]["m_bFreezePeriod"].is_number() == 1) {
            m_bFreezePeriod = j["netvars"]["m_bFreezePeriod"].get<int>();
        }
        else {
            std::cout << "m_bFreezePeriod: not found" << std::endl;
        }

        if (j["netvars"]["m_bGunGameImmunity"].is_number() == 1) {
            m_bGunGameImmunity = j["netvars"]["m_bGunGameImmunity"].get<int>();
        }
        else {
            std::cout << "m_bGunGameImmunity: not found" << std::endl;
        }

        if (j["netvars"]["m_bHasDefuser"].is_number() == 1) {
            m_bHasDefuser = j["netvars"]["m_bHasDefuser"].get<int>();
        }
        else {
            std::cout << "m_bHasDefuser: not found" << std::endl;
        }

        if (j["netvars"]["m_bHasHelmet"].is_number() == 1) {
            m_bHasHelmet = j["netvars"]["m_bHasHelmet"].get<int>();
        }
        else {
            std::cout << "m_bHasHelmet: not found" << std::endl;
        }

        if (j["netvars"]["m_bInReload"].is_number() == 1) {
            m_bInReload = j["netvars"]["m_bInReload"].get<int>();
        }
        else {
            std::cout << "m_bInReload: not found" << std::endl;
        }

        if (j["netvars"]["m_bIsDefusing"].is_number() == 1) {
            m_bIsDefusing = j["netvars"]["m_bIsDefusing"].get<int>();
        }
        else {
            std::cout << "m_bIsDefusing: not found" << std::endl;
        }

        if (j["netvars"]["m_bIsQueuedMatchmaking"].is_number() == 1) {
            m_bIsQueuedMatchmaking = j["netvars"]["m_bIsQueuedMatchmaking"].get<int>();
        }
        else {
            std::cout << "m_bIsQueuedMatchmaking: not found" << std::endl;
        }

        if (j["netvars"]["m_bIsScoped"].is_number() == 1) {
            m_bIsScoped = j["netvars"]["m_bIsScoped"].get<int>();
        }
        else {
            std::cout << "m_bIsScoped: not found" << std::endl;
        }

        if (j["netvars"]["m_bIsValveDS"].is_number() == 1) {
            m_bIsValveDS = j["netvars"]["m_bIsValveDS"].get<int>();
        }
        else {
            std::cout << "m_bIsValveDS: not found" << std::endl;
        }

        if (j["netvars"]["m_bSpotted"].is_number() == 1) {
            m_bSpotted = j["netvars"]["m_bSpotted"].get<int>();
        }
        else {
            std::cout << "m_bSpotted: not found" << std::endl;
        }

        if (j["netvars"]["m_bSpottedByMask"].is_number() == 1) {
            m_bSpottedByMask = j["netvars"]["m_bSpottedByMask"].get<int>();
        }
        else {
            std::cout << "m_bSpottedByMask: not found" << std::endl;
        }

        if (j["netvars"]["m_bStartedArming"].is_number() == 1) {
            m_bStartedArming = j["netvars"]["m_bStartedArming"].get<int>();
        }
        else {
            std::cout << "m_bStartedArming: not found" << std::endl;
        }

        if (j["netvars"]["m_bUseCustomAutoExposureMax"].is_number() == 1) {
            m_bUseCustomAutoExposureMax = j["netvars"]["m_bUseCustomAutoExposureMax"].get<int>();
        }
        else {
            std::cout << "m_bUseCustomAutoExposureMax: not found" << std::endl;
        }

        if (j["netvars"]["m_bUseCustomAutoExposureMin"].is_number() == 1) {
            m_bUseCustomAutoExposureMin = j["netvars"]["m_bUseCustomAutoExposureMin"].get<int>();
        }
        else {
            std::cout << "m_bUseCustomAutoExposureMin: not found" << std::endl;
        }

        if (j["netvars"]["m_bUseCustomBloomScale"].is_number() == 1) {
            m_bUseCustomBloomScale = j["netvars"]["m_bUseCustomBloomScale"].get<int>();
        }
        else {
            std::cout << "m_bUseCustomBloomScale: not found" << std::endl;
        }

        if (j["netvars"]["m_clrRender"].is_number() == 1) {
            m_clrRender = j["netvars"]["m_clrRender"].get<int>();
        }
        else {
            std::cout << "m_clrRender: not found" << std::endl;
        }

        if (j["netvars"]["m_dwBoneMatrix"].is_number() == 1) {
            m_dwBoneMatrix = j["netvars"]["m_dwBoneMatrix"].get<int>();
        }
        else {
            std::cout << "m_dwBoneMatrix: not found" << std::endl;
        }

        if (j["netvars"]["m_fAccuracyPenalty"].is_number() == 1) {
            m_fAccuracyPenalty = j["netvars"]["m_fAccuracyPenalty"].get<int>();
        }
        else {
            std::cout << "m_fAccuracyPenalty: not found" << std::endl;
        }

        if (j["netvars"]["m_fFlags"].is_number() == 1) {
            m_fFlags = j["netvars"]["m_fFlags"].get<int>();
        }
        else {
            std::cout << "m_fFlags: not found" << std::endl;
        }

        if (j["netvars"]["m_flC4Blow"].is_number() == 1) {
            m_flC4Blow = j["netvars"]["m_flC4Blow"].get<int>();
        }
        else {
            std::cout << "m_flC4Blow: not found" << std::endl;
        }

        if (j["netvars"]["m_flCustomAutoExposureMax"].is_number() == 1) {
            m_flCustomAutoExposureMax = j["netvars"]["m_flCustomAutoExposureMax"].get<int>();
        }
        else {
            std::cout << "m_flCustomAutoExposureMax: not found" << std::endl;
        }

        if (j["netvars"]["m_flCustomAutoExposureMin"].is_number() == 1) {
            m_flCustomAutoExposureMin = j["netvars"]["m_flCustomAutoExposureMin"].get<int>();
        }
        else {
            std::cout << "m_flCustomAutoExposureMin: not found" << std::endl;
        }

        if (j["netvars"]["m_flCustomBloomScale"].is_number() == 1) {
            m_flCustomBloomScale = j["netvars"]["m_flCustomBloomScale"].get<int>();
        }
        else {
            std::cout << "m_flCustomBloomScale: not found" << std::endl;
        }

        if (j["netvars"]["m_flDefuseCountDown"].is_number() == 1) {
            m_flDefuseCountDown = j["netvars"]["m_flDefuseCountDown"].get<int>();
        }
        else {
            std::cout << "m_flDefuseCountDown: not found" << std::endl;
        }

        if (j["netvars"]["m_flDefuseLength"].is_number() == 1) {
            m_flDefuseLength = j["netvars"]["m_flDefuseLength"].get<int>();
        }
        else {
            std::cout << "m_flDefuseLength: not found" << std::endl;
        }

        if (j["netvars"]["m_flFallbackWear"].is_number() == 1) {
            m_flFallbackWear = j["netvars"]["m_flFallbackWear"].get<int>();
        }
        else {
            std::cout << "m_flFallbackWear: not found" << std::endl;
        }

        if (j["netvars"]["m_flFlashDuration"].is_number() == 1) {
            m_flFlashDuration = j["netvars"]["m_flFlashDuration"].get<int>();
        }
        else {
            std::cout << "m_flFlashDuration: not found" << std::endl;
        }

        if (j["netvars"]["m_flFlashMaxAlpha"].is_number() == 1) {
            m_flFlashMaxAlpha = j["netvars"]["m_flFlashMaxAlpha"].get<int>();
        }
        else {
            std::cout << "m_flFlashMaxAlpha: not found" << std::endl;
        }

        if (j["netvars"]["m_flLastBoneSetupTime"].is_number() == 1) {
            m_flLastBoneSetupTime = j["netvars"]["m_flLastBoneSetupTime"].get<int>();
        }
        else {
            std::cout << "m_flLastBoneSetupTime: not found" << std::endl;
        }

        if (j["netvars"]["m_flLowerBodyYawTarget"].is_number() == 1) {
            m_flLowerBodyYawTarget = j["netvars"]["m_flLowerBodyYawTarget"].get<int>();
        }
        else {
            std::cout << "m_flLowerBodyYawTarget: not found" << std::endl;
        }

        if (j["netvars"]["m_flNextAttack"].is_number() == 1) {
            m_flNextAttack = j["netvars"]["m_flNextAttack"].get<int>();
        }
        else {
            std::cout << "m_flNextAttack: not found" << std::endl;
        }

        if (j["netvars"]["m_flNextPrimaryAttack"].is_number() == 1) {
            m_flNextPrimaryAttack = j["netvars"]["m_flNextPrimaryAttack"].get<int>();
        }
        else {
            std::cout << "m_flNextPrimaryAttack: not found" << std::endl;
        }

        if (j["netvars"]["m_flSimulationTime"].is_number() == 1) {
            m_flSimulationTime = j["netvars"]["m_flSimulationTime"].get<int>();
        }
        else {
            std::cout << "m_flSimulationTime: not found" << std::endl;
        }

        if (j["netvars"]["m_flTimerLength"].is_number() == 1) {
            m_flTimerLength = j["netvars"]["m_flTimerLength"].get<int>();
        }
        else {
            std::cout << "m_flTimerLength: not found" << std::endl;
        }

        if (j["netvars"]["m_hActiveWeapon"].is_number() == 1) {
            m_hActiveWeapon = j["netvars"]["m_hActiveWeapon"].get<int>();
        }
        else {
            std::cout << "m_hActiveWeapon: not found" << std::endl;
        }

        if (j["netvars"]["m_hMyWeapons"].is_number() == 1) {
            m_hMyWeapons = j["netvars"]["m_hMyWeapons"].get<int>();
        }
        else {
            std::cout << "m_hMyWeapons: not found" << std::endl;
        }

        if (j["netvars"]["m_hObserverTarget"].is_number() == 1) {
            m_hObserverTarget = j["netvars"]["m_hObserverTarget"].get<int>();
        }
        else {
            std::cout << "m_hObserverTarget: not found" << std::endl;
        }

        if (j["netvars"]["m_hOwner"].is_number() == 1) {
            m_hOwner = j["netvars"]["m_hOwner"].get<int>();
        }
        else {
            std::cout << "m_hOwner: not found" << std::endl;
        }

        if (j["netvars"]["m_hOwnerEntity"].is_number() == 1) {
            m_hOwnerEntity = j["netvars"]["m_hOwnerEntity"].get<int>();
        }
        else {
            std::cout << "m_hOwnerEntity: not found" << std::endl;
        }

        if (j["netvars"]["m_iAccountID"].is_number() == 1) {
            m_iAccountID = j["netvars"]["m_iAccountID"].get<int>();
        }
        else {
            std::cout << "m_iAccountID: not found" << std::endl;
        }

        if (j["netvars"]["m_iClip1"].is_number() == 1) {
            m_iClip1 = j["netvars"]["m_iClip1"].get<int>();
        }
        else {
            std::cout << "m_iClip1: not found" << std::endl;
        }

        if (j["netvars"]["m_iCompetitiveRanking"].is_number() == 1) {
            m_iCompetitiveRanking = j["netvars"]["m_iCompetitiveRanking"].get<int>();
        }
        else {
            std::cout << "m_iCompetitiveRanking: not found" << std::endl;
        }

        if (j["netvars"]["m_iCompetitiveWins"].is_number() == 1) {
            m_iCompetitiveWins = j["netvars"]["m_iCompetitiveWins"].get<int>();
        }
        else {
            std::cout << "m_iCompetitiveWins: not found" << std::endl;
        }

        if (j["netvars"]["m_iCrosshairId"].is_number() == 1) {
            m_iCrosshairId = j["netvars"]["m_iCrosshairId"].get<int>();
        }
        else {
            std::cout << "m_iCrosshairId: not found" << std::endl;
        }

        if (j["netvars"]["m_iEntityQuality"].is_number() == 1) {
            m_iEntityQuality = j["netvars"]["m_iEntityQuality"].get<int>();
        }
        else {
            std::cout << "m_iEntityQuality: not found" << std::endl;
        }

        if (j["netvars"]["m_iFOV"].is_number() == 1) {
            m_iFOV = j["netvars"]["m_iFOV"].get<int>();
        }
        else {
            std::cout << "m_iFOV: not found" << std::endl;
        }

        if (j["netvars"]["m_iFOVStart"].is_number() == 1) {
            m_iFOVStart = j["netvars"]["m_iFOVStart"].get<int>();
        }
        else {
            std::cout << "m_iFOVStart: not found" << std::endl;
        }

        if (j["netvars"]["m_iGlowIndex"].is_number() == 1) {
            m_iGlowIndex = j["netvars"]["m_iGlowIndex"].get<int>();
        }
        else {
            std::cout << "m_iGlowIndex: not found" << std::endl;
        }

        if (j["netvars"]["m_iHealth"].is_number() == 1) {
            m_iHealth = j["netvars"]["m_iHealth"].get<int>();
        }
        else {
            std::cout << "m_iHealth: not found" << std::endl;
        }

        if (j["netvars"]["m_iItemDefinitionIndex"].is_number() == 1) {
            m_iItemDefinitionIndex = j["netvars"]["m_iItemDefinitionIndex"].get<int>();
        }
        else {
            std::cout << "m_iItemDefinitionIndex: not found" << std::endl;
        }

        if (j["netvars"]["m_iItemIDHigh"].is_number() == 1) {
            m_iItemIDHigh = j["netvars"]["m_iItemIDHigh"].get<int>();
        }
        else {
            std::cout << "m_iItemIDHigh: not found" << std::endl;
        }

        if (j["netvars"]["m_iMostRecentModelBoneCounter"].is_number() == 1) {
            m_iMostRecentModelBoneCounter = j["netvars"]["m_iMostRecentModelBoneCounter"].get<int>();
        }
        else {
            std::cout << "m_iMostRecentModelBoneCounter: not found" << std::endl;
        }

        if (j["netvars"]["m_iObserverMode"].is_number() == 1) {
            m_iObserverMode = j["netvars"]["m_iObserverMode"].get<int>();
        }
        else {
            std::cout << "m_iObserverMode: not found" << std::endl;
        }

        if (j["netvars"]["m_iShotsFired"].is_number() == 1) {
            m_iShotsFired = j["netvars"]["m_iShotsFired"].get<int>();
        }
        else {
            std::cout << "m_iShotsFired: not found" << std::endl;
        }

        if (j["netvars"]["m_iState"].is_number() == 1) {
            m_iState = j["netvars"]["m_iState"].get<int>();
        }
        else {
            std::cout << "m_iState: not found" << std::endl;
        }

        if (j["netvars"]["m_iTeamNum"].is_number() == 1) {
            m_iTeamNum = j["netvars"]["m_iTeamNum"].get<int>();
        }
        else {
            std::cout << "m_iTeamNum: not found" << std::endl;
        }

        if (j["netvars"]["m_lifeState"].is_number() == 1) {
            m_lifeState = j["netvars"]["m_lifeState"].get<int>();
        }
        else {
            std::cout << "m_lifeState: not found" << std::endl;
        }

        if (j["netvars"]["m_nFallbackPaintKit"].is_number() == 1) {
            m_nFallbackPaintKit = j["netvars"]["m_nFallbackPaintKit"].get<int>();
        }
        else {
            std::cout << "m_nFallbackPaintKit: not found" << std::endl;
        }

        if (j["netvars"]["m_nFallbackSeed"].is_number() == 1) {
            m_nFallbackSeed = j["netvars"]["m_nFallbackSeed"].get<int>();
        }
        else {
            std::cout << "m_nFallbackSeed: not found" << std::endl;
        }

        if (j["netvars"]["m_nFallbackStatTrak"].is_number() == 1) {
            m_nFallbackStatTrak = j["netvars"]["m_nFallbackStatTrak"].get<int>();
        }
        else {
            std::cout << "m_nFallbackStatTrak: not found" << std::endl;
        }

        if (j["netvars"]["m_nForceBone"].is_number() == 1) {
            m_nForceBone = j["netvars"]["m_nForceBone"].get<int>();
        }
        else {
            std::cout << "m_nForceBone: not found" << std::endl;
        }

        if (j["netvars"]["m_nTickBase"].is_number() == 1) {
            m_nTickBase = j["netvars"]["m_nTickBase"].get<int>();
        }
        else {
            std::cout << "m_nTickBase: not found" << std::endl;
        }

        if (j["netvars"]["m_rgflCoordinateFrame"].is_number() == 1) {
            m_rgflCoordinateFrame = j["netvars"]["m_rgflCoordinateFrame"].get<int>();
        }
        else {
            std::cout << "m_rgflCoordinateFrame: not found" << std::endl;
        }

        if (j["netvars"]["m_szCustomName"].is_number() == 1) {
            m_szCustomName = j["netvars"]["m_szCustomName"].get<int>();
        }
        else {
            std::cout << "m_szCustomName: not found" << std::endl;
        }

        if (j["netvars"]["m_szLastPlaceName"].is_number() == 1) {
            m_szLastPlaceName = j["netvars"]["m_szLastPlaceName"].get<int>();
        }
        else {
            std::cout << "m_szLastPlaceName: not found" << std::endl;
        }

        if (j["netvars"]["m_thirdPersonViewAngles"].is_number() == 1) {
            m_thirdPersonViewAngles = j["netvars"]["m_thirdPersonViewAngles"].get<int>();
        }
        else {
            std::cout << "m_thirdPersonViewAngles: not found" << std::endl;
        }

        if (j["netvars"]["m_vecOrigin"].is_number() == 1) {
            m_vecOrigin = j["netvars"]["m_vecOrigin"].get<int>();
        }
        else {
            std::cout << "m_vecOrigin: not found" << std::endl;
        }

        if (j["netvars"]["m_vecVelocity"].is_number() == 1) {
            m_vecVelocity = j["netvars"]["m_vecVelocity"].get<int>();
        }
        else {
            std::cout << "m_vecVelocity: not found" << std::endl;
        }

        if (j["netvars"]["m_vecViewOffset"].is_number() == 1) {
            m_vecViewOffset = j["netvars"]["m_vecViewOffset"].get<int>();
        }
        else {
            std::cout << "m_vecViewOffset: not found" << std::endl;
        }

        if (j["netvars"]["m_viewPunchAngle"].is_number() == 1) {
            m_viewPunchAngle = j["netvars"]["m_viewPunchAngle"].get<int>();
        }
        else {
            std::cout << "m_viewPunchAngle: not found" << std::endl;
        }

        //Signatures
        if (j["signatures"]["anim_overlays"].is_number() == 1) {
            anim_overlays = j["signatures"]["anim_overlays"].get<int>();

        }
        else {
            std::cout << "anim_overlays: not found" << std::endl;
        }

        if (j["signatures"]["clientstate_choked_commands"].is_number() == 1) {
            clientstate_choked_commands = j["signatures"]["clientstate_choked_commands"].get<int>();
        }
        else {
            std::cout << "clientstate_choked_commands: not found" << std::endl;
        }

        if (j["signatures"]["clientstate_delta_ticks"].is_number() == 1) {
            clientstate_delta_ticks = j["signatures"]["clientstate_delta_ticks"].get<int>();
        }
        else {
            std::cout << "clientstate_delta_ticks: not found" << std::endl;
        }

        if (j["signatures"]["clientstate_last_outgoing_command"].is_number() == 1) {
            clientstate_last_outgoing_command = j["signatures"]["clientstate_last_outgoing_command"].get<int>();
        }
        else {
            std::cout << "clientstate_last_outgoing_command: not found" << std::endl;
        }

        if (j["signatures"]["clientstate_net_channel"].is_number() == 1) {
            clientstate_net_channel = j["signatures"]["clientstate_net_channel"].get<int>();
        }
        else {
            std::cout << "clientstate_net_channel: not found" << std::endl;
        }

        if (j["signatures"]["convar_name_hash_table"].is_number() == 1) {
            convar_name_hash_table = j["signatures"]["convar_name_hash_table"].get<int>();
        }
        else {
            std::cout << "convar_name_hash_table: not found" << std::endl;
        }

        if (j["signatures"]["dwClientState"].is_number() == 1) {
            dwClientState = j["signatures"]["dwClientState"].get<int>();
        }
        else {
            std::cout << "dwClientState: not found" << std::endl;
        }

        if (j["signatures"]["dwClientState_GetLocalPlayer"].is_number() == 1) {
            dwClientState_GetLocalPlayer = j["signatures"]["dwClientState_GetLocalPlayer"].get<int>();
        }
        else {
            std::cout << "dwClientState_GetLocalPlayer: not found" << std::endl;
        }

        if (j["signatures"]["dwClientState_IsHLTV"].is_number() == 1) {
            dwClientState_IsHLTV = j["signatures"]["dwClientState_IsHLTV"].get<int>();
        }
        else {
            std::cout << "dwClientState_IsHLTV: not found" << std::endl;
        }

        if (j["signatures"]["dwClientState_Map"].is_number() == 1) {
            dwClientState_Map = j["signatures"]["dwClientState_Map"].get<int>();
        }
        else {
            std::cout << "dwClientState_Map: not found" << std::endl;
        }

        if (j["signatures"]["dwClientState_MapDirectory"].is_number() == 1) {
            dwClientState_MapDirectory = j["signatures"]["dwClientState_MapDirectory"].get<int>();
        }
        else {
            std::cout << "dwClientState_MapDirectory: not found" << std::endl;
        }

        if (j["signatures"]["dwClientState_MaxPlayer"].is_number() == 1) {
            dwClientState_MaxPlayer = j["signatures"]["dwClientState_MaxPlayer"].get<int>();
        }
        else {
            std::cout << "dwClientState_MaxPlayer: not found" << std::endl;
        }

        if (j["signatures"]["dwClientState_PlayerInfo"].is_number() == 1) {
            dwClientState_PlayerInfo = j["signatures"]["dwClientState_PlayerInfo"].get<int>();
        }
        else {
            std::cout << "dwClientState_PlayerInfo: not found" << std::endl;
        }

        if (j["signatures"]["dwClientState_State"].is_number() == 1) {
            dwClientState_State = j["signatures"]["dwClientState_State"].get<int>();
        }
        else {
            std::cout << "dwClientState_State: not found" << std::endl;
        }

        if (j["signatures"]["dwClientState_ViewAngles"].is_number() == 1) {
            dwClientState_ViewAngles = j["signatures"]["dwClientState_ViewAngles"].get<int>();
        }
        else {
            std::cout << "dwClientState_ViewAngles: not found" << std::endl;
        }

        if (j["signatures"]["dwEntityList"].is_number() == 1) {
            dwEntityList = j["signatures"]["dwEntityList"].get<int>();
        }
        else {
            std::cout << "dwEntityList: not found" << std::endl;
        }

        if (j["signatures"]["dwForceAttack"].is_number() == 1) {
            dwForceAttack = j["signatures"]["dwForceAttack"].get<int>();
        }
        else {
            std::cout << "dwForceAttack: not found" << std::endl;
        }

        if (j["signatures"]["dwForceAttack2"].is_number() == 1) {
            dwForceAttack2 = j["signatures"]["dwForceAttack2"].get<int>();
        }
        else {
            std::cout << "dwForceAttack2: not found" << std::endl;
        }

        if (j["signatures"]["dwForceBackward"].is_number() == 1) {
            dwForceBackward = j["signatures"]["dwForceBackward"].get<int>();
        }
        else {
            std::cout << "dwForceBackward: not found" << std::endl;
        }

        if (j["signatures"]["dwForceForward"].is_number() == 1) {
            dwForceForward = j["signatures"]["dwForceForward"].get<int>();
        }
        else {
            std::cout << "dwForceForward: not found" << std::endl;
        }

        if (j["signatures"]["dwForceJump"].is_number() == 1) {
            dwForceJump = j["signatures"]["dwForceJump"].get<int>();
        }
        else {
            std::cout << "dwForceJump: not found" << std::endl;
        }

        if (j["signatures"]["dwForceLeft"].is_number() == 1) {
            dwForceLeft = j["signatures"]["dwForceLeft"].get<int>();
        }
        else {
            std::cout << "dwForceLeft: not found" << std::endl;
        }

        if (j["signatures"]["dwForceRight"].is_number() == 1) {
            dwForceRight = j["signatures"]["dwForceRight"].get<int>();
        }
        else {
            std::cout << "dwForceRight: not found" << std::endl;
        }

        if (j["signatures"]["dwGameDir"].is_number() == 1) {
            dwGameDir = j["signatures"]["dwGameDir"].get<int>();
        }
        else {
            std::cout << "dwGameDir: not found" << std::endl;
        }

        if (j["signatures"]["dwGameRulesProxy"].is_number() == 1) {
            dwGameRulesProxy = j["signatures"]["dwGameRulesProxy"].get<int>();
        }
        else {
            std::cout << "dwGameRulesProxy: not found" << std::endl;
        }

        if (j["signatures"]["dwGetAllClasses"].is_number() == 1) {
            dwGetAllClasses = j["signatures"]["dwGetAllClasses"].get<int>();
        }
        else {
            std::cout << "dwGetAllClasses: not found" << std::endl;
        }

        if (j["signatures"]["dwGlobalVars"].is_number() == 1) {
            dwGlobalVars = j["signatures"]["dwGlobalVars"].get<int>();
        }
        else {
            std::cout << "dwGlobalVars: not found" << std::endl;
        }

        if (j["signatures"]["dwGlowObjectManager"].is_number() == 1) {
            dwGlowObjectManager = j["signatures"]["dwGlowObjectManager"].get<int>();
        }
        else {
            std::cout << "dwGlowObjectManager: not found" << std::endl;
        }

        if (j["signatures"]["dwInput"].is_number() == 1) {
            dwInput = j["signatures"]["dwInput"].get<int>();
        }
        else {
            std::cout << "dwInput: not found" << std::endl;
        }

        if (j["signatures"]["dwInterfaceLinkList"].is_number() == 1) {
            dwInterfaceLinkList = j["signatures"]["dwInterfaceLinkList"].get<int>();
        }
        else {
            std::cout << "dwInterfaceLinkList: not found" << std::endl;
        }

        if (j["signatures"]["dwLocalPlayer"].is_number() == 1) {
            dwLocalPlayer = j["signatures"]["dwLocalPlayer"].get<int>();
        }
        else {
            std::cout << "dwLocalPlayer: not found" << std::endl;
        }

        if (j["signatures"]["dwMouseEnable"].is_number() == 1) {
            dwMouseEnable = j["signatures"]["dwMouseEnable"].get<int>();
        }
        else {
            std::cout << "dwMouseEnable: not found" << std::endl;
        }

        if (j["signatures"]["dwMouseEnablePtr"].is_number() == 1) {
            dwMouseEnablePtr = j["signatures"]["dwMouseEnablePtr"].get<int>();
        }
        else {
            std::cout << "dwMouseEnablePtr: not found" << std::endl;
        }

        if (j["signatures"]["dwPlayerResource"].is_number() == 1) {
            dwPlayerResource = j["signatures"]["dwPlayerResource"].get<int>();
        }
        else {
            std::cout << "dwPlayerResource: not found" << std::endl;
        }

        if (j["signatures"]["dwRadarBase"].is_number() == 1) {
            dwRadarBase = j["signatures"]["dwRadarBase"].get<int>();
        }
        else {
            std::cout << "dwRadarBase: not found" << std::endl;
        }

        if (j["signatures"]["dwSensitivity"].is_number() == 1) {
            dwSensitivity = j["signatures"]["dwSensitivity"].get<int>();
        }
        else {
            std::cout << "dwSensitivity: not found" << std::endl;
        }

        if (j["signatures"]["dwSensitivityPtr"].is_number() == 1) {
            dwSensitivityPtr = j["signatures"]["dwSensitivityPtr"].get<int>();
        }
        else {
            std::cout << "dwSensitivityPtr: not found" << std::endl;
        }

        if (j["signatures"]["dwSetClanTag"].is_number() == 1) {
            dwSetClanTag = j["signatures"]["dwSetClanTag"].get<int>();
        }
        else {
            std::cout << "dwSetClanTag: not found" << std::endl;
        }

        if (j["signatures"]["dwViewMatrix"].is_number() == 1) {
            dwViewMatrix = j["signatures"]["dwViewMatrix"].get<int>();
        }
        else {
            std::cout << "dwViewMatrix: not found" << std::endl;
        }

        if (j["signatures"]["dwWeaponTable"].is_number() == 1) {
            dwWeaponTable = j["signatures"]["dwWeaponTable"].get<int>();
        }
        else {
            std::cout << "dwWeaponTable: not found" << std::endl;
        }

        if (j["signatures"]["dwWeaponTableIndex"].is_number() == 1) {
            dwWeaponTableIndex = j["signatures"]["dwWeaponTableIndex"].get<int>();
        }
        else {
            std::cout << "dwWeaponTableIndex: not found" << std::endl;
        }

        if (j["signatures"]["dwYawPtr"].is_number() == 1) {
            dwYawPtr = j["signatures"]["dwYawPtr"].get<int>();
        }
        else {
            std::cout << "dwYawPtr: not found" << std::endl;
        }

        if (j["signatures"]["dwZoomSensitivityRatioPtr"].is_number() == 1) {
            dwZoomSensitivityRatioPtr = j["signatures"]["dwZoomSensitivityRatioPtr"].get<int>();
        }
        else {
            std::cout << "dwZoomSensitivityRatioPtr: not found" << std::endl;
        }

        if (j["signatures"]["dwbSendPackets"].is_number() == 1) {
            dwbSendPackets = j["signatures"]["dwbSendPackets"].get<int>();
        }
        else {
            std::cout << "dwbSendPackets: not found" << std::endl;
        }

        if (j["signatures"]["dwppDirect3DDevice9"].is_number() == 1) {
            dwppDirect3DDevice9 = j["signatures"]["dwppDirect3DDevice9"].get<int>();
        }
        else {
            std::cout << "dwppDirect3DDevice9: not found" << std::endl;
        }

        if (j["signatures"]["find_hud_element"].is_number() == 1) {
            find_hud_element = j["signatures"]["find_hud_element"].get<int>();
        }
        else {
            std::cout << "find_hud_element: not found" << std::endl;
        }

        if (j["signatures"]["force_update_spectator_glow"].is_number() == 1) {
            force_update_spectator_glow = j["signatures"]["force_update_spectator_glow"].get<int>();
        }
        else {
            std::cout << "force_update_spectator_glow: not found" << std::endl;
        }

        if (j["signatures"]["interface_engine_cvar"].is_number() == 1) {
            interface_engine_cvar = j["signatures"]["interface_engine_cvar"].get<int>();
        }
        else {
            std::cout << "interface_engine_cvar: not found" << std::endl;
        }

        if (j["signatures"]["is_c4_owner"].is_number() == 1) {
            is_c4_owner = j["signatures"]["is_c4_owner"].get<int>();
        }
        else {
            std::cout << "is_c4_owner: not found" << std::endl;
        }

        if (j["signatures"]["m_bDormant"].is_number() == 1) {
            m_bDormant = j["signatures"]["m_bDormant"].get<int>();
        }
        else {
            std::cout << "m_bDormant: not found" << std::endl;
        }

        if (j["signatures"]["m_flSpawnTime"].is_number() == 1) {
            m_flSpawnTime = j["signatures"]["m_flSpawnTime"].get<int>();
        }
        else {
            std::cout << "m_flSpawnTime: not found" << std::endl;
        }

        if (j["signatures"]["m_pStudioHdr"].is_number() == 1) {
            m_pStudioHdr = j["signatures"]["m_pStudioHdr"].get<int>();
        }
        else {
            std::cout << "m_pStudioHdr: not found" << std::endl;
        }

        if (j["signatures"]["m_pitchClassPtr"].is_number() == 1) {
            m_pitchClassPtr = j["signatures"]["m_pitchClassPtr"].get<int>();
        }
        else {
            std::cout << "m_pitchClassPtr: not found" << std::endl;
        }

        if (j["signatures"]["m_yawClassPtr"].is_number() == 1) {
            m_yawClassPtr = j["signatures"]["m_yawClassPtr"].get<int>();
        }
        else {
            std::cout << "m_yawClassPtr: not found" << std::endl;
        }

        if (j["signatures"]["model_ambient_min"].is_number() == 1) {
            model_ambient_min = j["signatures"]["model_ambient_min"].get<int>();
        }
        else {
            std::cout << "model_ambient_min: not found" << std::endl;
        }

        if (j["signatures"]["set_abs_angles"].is_number() == 1) {
            set_abs_angles = j["signatures"]["set_abs_angles"].get<int>();
        }
        else {
            std::cout << "set_abs_angles: not found" << std::endl;
        }

        if (j["signatures"]["set_abs_origin"].is_number() == 1) {
            set_abs_origin = j["signatures"]["set_abs_origin"].get<int>();
        }
        else {
            std::cout << "set_abs_origin: not found" << std::endl;
        }
    }

    fin.close();
    std::cout << "[HazedumperUpdater] - Successfully Updated!" << "\n\n";
}