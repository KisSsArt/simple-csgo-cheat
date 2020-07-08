#pragma once

#include <string>

#include "AnimState.h"
#include "Vector.h"
#include "VirtualMethod.h"
#include "WeaponInfo.h"

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <random>

struct ClientClass;
class Matrix3x4;
enum class WeaponId : short;
struct WeaponInfo;
enum class WeaponType;

class Collideable {
public:
    VIRTUAL_METHOD(const Vector&, obbMins, 1, (), (this))
    VIRTUAL_METHOD(const Vector&, obbMaxs, 2, (), (this))
};

struct Model {
    void* handle;
    char name[260];
    int	loadFlags;
    int	serverCount;
    int	type;
    int	flags;
    Vector mins, maxs;
};

#define PROP(func_name, offset, type) \
[[nodiscard]] std::add_lvalue_reference_t<std::add_const_t<type>> func_name() noexcept \
{ \
    return *reinterpret_cast<std::add_pointer_t<type>>(this + offset); \
}

enum class ObsMode {
    None = 0,
    Deathcam,
    Freezecam,
    Fixed,
    InEye,
    Chase,
    Roaming
};

class Entity {
public:
    VIRTUAL_METHOD(ClientClass*, getClientClass, 2, (), (this + 8))
    VIRTUAL_METHOD(bool, isDormant, 9, (), (this + 8))
    VIRTUAL_METHOD(int, index, 10, (), (this + 8))

    VIRTUAL_METHOD(const Model*, getModel, 8, (), (this + 4))
    VIRTUAL_METHOD(bool, setupBones, 13, (Matrix3x4* out, int maxBones, int boneMask, float currentTime), (this + 4, out, maxBones, boneMask, currentTime))
    VIRTUAL_METHOD(const Matrix3x4&, toWorldTransform, 32, (), (this + 4))

    VIRTUAL_METHOD(int&, handle, 2, (), (this))
    VIRTUAL_METHOD(Collideable*, getCollideable, 3, (), (this))
    VIRTUAL_METHOD(Vector&, getAbsOrigin, 10, (), (this))
    VIRTUAL_METHOD(int, getHealth, 121, (), (this))
    VIRTUAL_METHOD(bool, isAlive, 155, (), (this))
    VIRTUAL_METHOD(bool, isPlayer, 157, (), (this))
    VIRTUAL_METHOD(bool, isWeapon, 165, (), (this))
    VIRTUAL_METHOD(Entity*, getActiveWeapon, 267, (), (this))
    VIRTUAL_METHOD(ObsMode, getObserverMode, 293, (), (this))
    VIRTUAL_METHOD(Entity*, getObserverTarget, 294, (), (this))
    VIRTUAL_METHOD(WeaponType, getWeaponType, 454, (), (this))
    VIRTUAL_METHOD(WeaponInfo*, getWeaponInfo, 460, (), (this))
    VIRTUAL_METHOD(WeaponInfo*, getWeaponData, 460, (), (this))

    /*auto getWeaponType() noexcept
    {
        const auto weaponData = getWeaponData();
        if (weaponData)
            return weaponData->type;
        return WeaponType::Unknown;
    }*/

    auto isSniperRifle() noexcept
    {
        return getWeaponType() == WeaponType::SniperRifle;
    }

    auto getEyePosition() noexcept
    {
        Vector vec;
        VirtualMethod::call<void, 284>(this, std::ref(vec));
        return vec;
    }

    auto getAimPunch() noexcept
    {
        Vector vec;
        VirtualMethod::call<void, 345>(this, std::ref(vec));
        return vec;
    }
    
    /*auto isPistol()
    {
        return getWeaponType() == WeaponType::Pistol;
    }

    auto getEyePosition()
    {
        Vector vec;
        VirtualMethod::call<void, 284>(this, std::ref(vec));
        return vec;
    }

    auto getUserId()
    {
        PlayerInfo playerInfo;
        if (playerInfo; interfaces->engine->getPlayerInfo(index(), playerInfo))
            return playerInfo.userId;

        return -1;
    }*/

    AnimState* getAnimstate() noexcept
    {
        return *reinterpret_cast<AnimState**>(this + 0x3900);
    }

    float getMaxDesyncAngle() noexcept
    {
        const auto animState = getAnimstate();

        if (!animState)
            return 0.0f;

        float yawModifier = (animState->stopToFullRunningFraction * -0.3f - 0.2f) * std::clamp(animState->footSpeed, 0.0f, 1.0f) + 1.0f;

        if (animState->duckAmount > 0.0f)
            yawModifier += (animState->duckAmount * std::clamp(animState->footSpeed2, 0.0f, 1.0f) * (0.5f - yawModifier));

        return animState->velocitySubtractY * yawModifier;
    }

    bool canSee(Entity* other, const Vector& pos) noexcept;
    bool visibleTo(Entity* other) noexcept;
    [[nodiscard]] std::string getPlayerName() noexcept;
    void getPlayerName(char(&out)[128]) noexcept;

    PROP(hitboxSet, 0x9FC, int)                                                    // CBaseAnimating->m_nHitboxSet

    PROP(weaponId, 0x2FAA, WeaponId)                                               // CBaseAttributableItem->m_iItemDefinitionIndex

    PROP(clip, 0x3264, int)                                                        // CBaseCombatWeapon->m_iClip1
    PROP(isInReload, 0x3264 + 0x41, bool)                                          // CBaseCombatWeapon->m_iClip1 + 0x41
    PROP(reserveAmmoCount, 0x326C, int)                                            // CBaseCombatWeapon->m_iPrimaryReserveAmmoCount
    PROP(nextPrimaryAttack, 0x3238, float)                                         // CBaseCombatWeapon->m_flNextPrimaryAttack

    PROP(prevOwner, 0x3384, int)                                                   // CWeaponCSBase->m_hPrevOwner
        
    PROP(ownerEntity, 0x14C, int)                                                  // CBaseEntity->m_hOwnerEntity
    PROP(spotted, 0x93D, bool)                                                     // CBaseEntity->m_bSpotted
    
    PROP(fovStart, 0x31E8, int)                                                    // CBasePlayer->m_iFOVStart

    PROP(isScoped, 0x3928, bool)                                                   // CCSPlayer->m_bIsScoped
    PROP(inBombZone, 0x3954, bool)                                                 // CCSPlayer->m_bInBombZone
    PROP(flashDuration, 0xA41C - 0x8, float)                                       // CCSPlayer->m_flFlashMaxAlpha - 0x8
    PROP(shotsFired, 0xA390, int)                                                  // CCSPlayer->m_iShotsFired
        
    PROP(thrower, 0x29A0, int)                                                     // CBaseGrenade->m_hThrower
    PROP(grenadeExploded, 0x29E8, bool)
};
