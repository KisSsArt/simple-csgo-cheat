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
    //std::cout << "[HazedumperUpdater] - Downloading \"hazedumper/master/csgo.json\", please wait." << '\n';
    std::cout << "[HazedumperUpdater] - Updating, please wait." << "\n";

    auto location = std::filesystem::current_path().string();

    location += "\\";

    std::string fileToSaveAs = "hazedumper.json";
    location += fileToSaveAs;

    //std::cout << location << std::endl;

    std::string downloadURL = "https://raw.githubusercontent.com/frk1/hazedumper/master/csgo.json";

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

    nlohmann::json j = nlohmann::json::parse(jsonf);
    {
        hazedumper::timestamp = j["timestamp"].get<int>();
        //Netvars
        cs_gamerules_data = j["netvars"]["cs_gamerules_data"].get<int>();
        m_ArmorValue = j["netvars"]["m_ArmorValue"].get<int>();
        m_Collision = j["netvars"]["m_Collision"].get<int>();
        m_CollisionGroup = j["netvars"]["m_CollisionGroup"].get<int>();
        m_Local = j["netvars"]["m_Local"].get<int>();
        m_MoveType = j["netvars"]["m_MoveType"].get<int>();
        m_OriginalOwnerXuidHigh = j["netvars"]["m_OriginalOwnerXuidHigh"].get<int>();
        m_OriginalOwnerXuidLow = j["netvars"]["m_OriginalOwnerXuidLow"].get<int>();
        m_SurvivalGameRuleDecisionTypes = j["netvars"]["m_SurvivalGameRuleDecisionTypes"].get<int>();
        m_SurvivalRules = j["netvars"]["m_SurvivalRules"].get<int>();
        m_aimPunchAngle = j["netvars"]["m_aimPunchAngle"].get<int>();
        m_aimPunchAngleVel = j["netvars"]["m_aimPunchAngleVel"].get<int>();
        m_angEyeAnglesX = j["netvars"]["m_angEyeAnglesX"].get<int>();
        m_angEyeAnglesY = j["netvars"]["m_angEyeAnglesY"].get<int>();
        m_bBombPlanted = j["netvars"]["m_bBombPlanted"].get<int>();
        m_bFreezePeriod = j["netvars"]["m_bFreezePeriod"].get<int>();
        m_bGunGameImmunity = j["netvars"]["m_bGunGameImmunity"].get<int>();
        m_bHasDefuser = j["netvars"]["m_bHasDefuser"].get<int>();
        m_bHasHelmet = j["netvars"]["m_bHasHelmet"].get<int>();
        m_bInReload = j["netvars"]["m_bInReload"].get<int>();
        m_bIsDefusing = j["netvars"]["m_bIsDefusing"].get<int>();
        m_bIsQueuedMatchmaking = j["netvars"]["m_bIsQueuedMatchmaking"].get<int>();
        m_bIsScoped = j["netvars"]["m_bIsScoped"].get<int>();
        m_bIsValveDS = j["netvars"]["m_bIsValveDS"].get<int>();
        m_bSpotted = j["netvars"]["m_bSpotted"].get<int>();
        m_bSpottedByMask = j["netvars"]["m_bSpottedByMask"].get<int>();
        m_bStartedArming = j["netvars"]["m_bStartedArming"].get<int>();
        m_bUseCustomAutoExposureMax = j["netvars"]["m_bUseCustomAutoExposureMax"].get<int>();
        m_bUseCustomAutoExposureMin = j["netvars"]["m_bUseCustomAutoExposureMin"].get<int>();
        m_bUseCustomBloomScale = j["netvars"]["m_bUseCustomBloomScale"].get<int>();
        m_clrRender = j["netvars"]["m_clrRender"].get<int>();
        m_dwBoneMatrix = j["netvars"]["m_dwBoneMatrix"].get<int>();
        m_fAccuracyPenalty = j["netvars"]["m_fAccuracyPenalty"].get<int>();
        m_fFlags = j["netvars"]["m_fFlags"].get<int>();
        m_flC4Blow = j["netvars"]["m_flC4Blow"].get<int>();
        m_flCustomAutoExposureMax = j["netvars"]["m_flCustomAutoExposureMax"].get<int>();
        m_flCustomAutoExposureMin = j["netvars"]["m_flCustomAutoExposureMin"].get<int>();
        m_flCustomBloomScale = j["netvars"]["m_flCustomBloomScale"].get<int>();
        m_flDefuseCountDown = j["netvars"]["m_flDefuseCountDown"].get<int>();
        m_flDefuseLength = j["netvars"]["m_flDefuseLength"].get<int>();
        m_flFallbackWear = j["netvars"]["m_flFallbackWear"].get<int>();
        m_flFlashDuration = j["netvars"]["m_flFlashDuration"].get<int>();
        m_flFlashMaxAlpha = j["netvars"]["m_flFlashMaxAlpha"].get<int>();
        m_flLastBoneSetupTime = j["netvars"]["m_flLastBoneSetupTime"].get<int>();
        m_flLowerBodyYawTarget = j["netvars"]["m_flLowerBodyYawTarget"].get<int>();
        m_flNextAttack = j["netvars"]["m_flNextAttack"].get<int>();
        m_flNextPrimaryAttack = j["netvars"]["m_flNextPrimaryAttack"].get<int>();
        m_flSimulationTime = j["netvars"]["m_flSimulationTime"].get<int>();
        m_flTimerLength = j["netvars"]["m_flTimerLength"].get<int>();
        m_hActiveWeapon = j["netvars"]["m_hActiveWeapon"].get<int>();
        m_hMyWeapons = j["netvars"]["m_hMyWeapons"].get<int>();
        m_hObserverTarget = j["netvars"]["m_hObserverTarget"].get<int>();
        m_hOwner = j["netvars"]["m_hOwner"].get<int>();
        m_hOwnerEntity = j["netvars"]["m_hOwnerEntity"].get<int>();
        m_iAccountID = j["netvars"]["m_iAccountID"].get<int>();
        m_iClip1 = j["netvars"]["m_iClip1"].get<int>();
        m_iCompetitiveRanking = j["netvars"]["m_iCompetitiveRanking"].get<int>();
        m_iCompetitiveWins = j["netvars"]["m_iCompetitiveWins"].get<int>();
        m_iCrosshairId = j["netvars"]["m_iCrosshairId"].get<int>();
        m_iEntityQuality = j["netvars"]["m_iEntityQuality"].get<int>();
        m_iFOV = j["netvars"]["m_iFOV"].get<int>();
        m_iFOVStart = j["netvars"]["m_iFOVStart"].get<int>();
        m_iGlowIndex = j["netvars"]["m_iGlowIndex"].get<int>();
        m_iHealth = j["netvars"]["m_iHealth"].get<int>();
        m_iItemDefinitionIndex = j["netvars"]["m_iItemDefinitionIndex"].get<int>();
        m_iItemIDHigh = j["netvars"]["m_iItemIDHigh"].get<int>();
        m_iMostRecentModelBoneCounter = j["netvars"]["m_iMostRecentModelBoneCounter"].get<int>();
        m_iObserverMode = j["netvars"]["m_iObserverMode"].get<int>();
        m_iShotsFired = j["netvars"]["m_iShotsFired"].get<int>();
        m_iState = j["netvars"]["m_iState"].get<int>();
        m_iTeamNum = j["netvars"]["m_iTeamNum"].get<int>();
        m_lifeState = j["netvars"]["m_lifeState"].get<int>();
        m_nFallbackPaintKit = j["netvars"]["m_nFallbackPaintKit"].get<int>();
        m_nFallbackSeed = j["netvars"]["m_nFallbackSeed"].get<int>();
        m_nFallbackStatTrak = j["netvars"]["m_nFallbackStatTrak"].get<int>();
        m_nForceBone = j["netvars"]["m_nForceBone"].get<int>();
        m_nTickBase = j["netvars"]["m_nTickBase"].get<int>();
        m_rgflCoordinateFrame = j["netvars"]["m_rgflCoordinateFrame"].get<int>();
        m_szCustomName = j["netvars"]["m_szCustomName"].get<int>();
        m_szLastPlaceName = j["netvars"]["m_szLastPlaceName"].get<int>();
        m_thirdPersonViewAngles = j["netvars"]["m_thirdPersonViewAngles"].get<int>();
        m_vecOrigin = j["netvars"]["m_vecOrigin"].get<int>();
        m_vecVelocity = j["netvars"]["m_vecVelocity"].get<int>();
        m_vecViewOffset = j["netvars"]["m_vecViewOffset"].get<int>();
        m_viewPunchAngle = j["netvars"]["m_viewPunchAngle"].get<int>();
        //Signatures
        anim_overlays = j["signatures"]["anim_overlays"].get<int>();
        clientstate_choked_commands = j["signatures"]["clientstate_choked_commands"].get<int>();
        clientstate_delta_ticks = j["signatures"]["clientstate_delta_ticks"].get<int>();
        clientstate_last_outgoing_command = j["signatures"]["clientstate_last_outgoing_command"].get<int>();
        clientstate_net_channel = j["signatures"]["clientstate_net_channel"].get<int>();
        convar_name_hash_table = j["signatures"]["convar_name_hash_table"].get<int>();
        dwClientState = j["signatures"]["dwClientState"].get<int>();
        dwClientState_GetLocalPlayer = j["signatures"]["dwClientState_GetLocalPlayer"].get<int>();
        dwClientState_IsHLTV = j["signatures"]["dwClientState_IsHLTV"].get<int>();
        dwClientState_Map = j["signatures"]["dwClientState_Map"].get<int>();
        dwClientState_MapDirectory = j["signatures"]["dwClientState_MapDirectory"].get<int>();
        dwClientState_MaxPlayer = j["signatures"]["dwClientState_MaxPlayer"].get<int>();
        dwClientState_PlayerInfo = j["signatures"]["dwClientState_PlayerInfo"].get<int>();
        dwClientState_State = j["signatures"]["dwClientState_State"].get<int>();
        dwClientState_ViewAngles = j["signatures"]["dwClientState_ViewAngles"].get<int>();
        dwEntityList = j["signatures"]["dwEntityList"].get<int>();
        dwForceAttack = j["signatures"]["dwForceAttack"].get<int>();
        dwForceAttack2 = j["signatures"]["dwForceAttack2"].get<int>();
        dwForceBackward = j["signatures"]["dwForceBackward"].get<int>();
        dwForceForward = j["signatures"]["dwForceForward"].get<int>();
        dwForceJump = j["signatures"]["dwForceJump"].get<int>();
        dwForceLeft = j["signatures"]["dwForceLeft"].get<int>();
        dwForceRight = j["signatures"]["dwForceRight"].get<int>();
        dwGameDir = j["signatures"]["dwGameDir"].get<int>();
        dwGameRulesProxy = j["signatures"]["dwGameRulesProxy"].get<int>();
        dwGetAllClasses = j["signatures"]["dwGetAllClasses"].get<int>();
        dwGlobalVars = j["signatures"]["dwGlobalVars"].get<int>();
        dwGlowObjectManager = j["signatures"]["dwGlowObjectManager"].get<int>();
        dwInput = j["signatures"]["dwInput"].get<int>();
        dwInterfaceLinkList = j["signatures"]["dwInterfaceLinkList"].get<int>();
        dwLocalPlayer = j["signatures"]["dwLocalPlayer"].get<int>();
        dwMouseEnable = j["signatures"]["dwMouseEnable"].get<int>();
        dwMouseEnablePtr = j["signatures"]["dwMouseEnablePtr"].get<int>();
        dwPlayerResource = j["signatures"]["dwPlayerResource"].get<int>();
        dwRadarBase = j["signatures"]["dwRadarBase"].get<int>();
        dwSensitivity = j["signatures"]["dwSensitivity"].get<int>();
        dwSensitivityPtr = j["signatures"]["dwSensitivityPtr"].get<int>();
        dwSetClanTag = j["signatures"]["dwSetClanTag"].get<int>();
        dwViewMatrix = j["signatures"]["dwViewMatrix"].get<int>();
        dwWeaponTable = j["signatures"]["dwWeaponTable"].get<int>();
        dwWeaponTableIndex = j["signatures"]["dwWeaponTableIndex"].get<int>();
        dwYawPtr = j["signatures"]["dwYawPtr"].get<int>();
        dwZoomSensitivityRatioPtr = j["signatures"]["dwZoomSensitivityRatioPtr"].get<int>();
        dwbSendPackets = j["signatures"]["dwbSendPackets"].get<int>();
        dwppDirect3DDevice9 = j["signatures"]["dwppDirect3DDevice9"].get<int>();
        find_hud_element = j["signatures"]["find_hud_element"].get<int>();
        force_update_spectator_glow = j["signatures"]["force_update_spectator_glow"].get<int>();
        interface_engine_cvar = j["signatures"]["interface_engine_cvar"].get<int>();
        is_c4_owner = j["signatures"]["is_c4_owner"].get<int>();
        m_bDormant = j["signatures"]["m_bDormant"].get<int>();
        m_flSpawnTime = j["signatures"]["m_flSpawnTime"].get<int>();
        m_pStudioHdr = j["signatures"]["m_pStudioHdr"].get<int>();
        m_pitchClassPtr = j["signatures"]["m_pitchClassPtr"].get<int>();
        m_yawClassPtr = j["signatures"]["m_yawClassPtr"].get<int>();
        model_ambient_min = j["signatures"]["model_ambient_min"].get<int>();
        set_abs_angles = j["signatures"]["set_abs_angles"].get<int>();
        set_abs_origin = j["signatures"]["set_abs_origin"].get<int>();
    }

    fin.close();
    std::cout << "[HazedumperUpdater] - Successfully Updated!" << "\n\n";
}