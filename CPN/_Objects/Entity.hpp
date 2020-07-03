#pragma once
#include "Structs/Structs.hpp"
#include "../Memory.h"

class EntityOld 
{
private:
    int index;

public:
    EntityOld(int Index)
    {
        index = Index;
    }
    
    uintptr_t Base()
    {
        return MemoryOld::Read<uintptr_t>((MemoryOld::clientBase() + dwEntityList) + index * 0x10);
    }

    int Team()
    {
        return MemoryOld::Read<int>(Base() + m_iTeamNum);
    }

    int Health()
    {
        return MemoryOld::Read<int>(Base() + m_iHealth);
    }

    bool Dormant()
    {
        return MemoryOld::Read<int>(Base() + m_bDormant) == 1;
    }

    void GlowObject(GlowObjectDefinition value) {
        MemoryOld::Write<GlowObjectDefinition>(GlowObjectDefinition::Ptr() + GlowIndex() * GlowObjectDefinition::GetSize(), value);
	}

    GlowObjectDefinition GlowObject() {
        return MemoryOld::Read<GlowObjectDefinition>(GlowObjectDefinition::Ptr() + GlowIndex() * GlowObjectDefinition::GetSize());
    }

    int GlowIndex()
    {
        return MemoryOld::Read<int>(Base() + m_iGlowIndex);
    }

    Vec3 Location() {
        return MemoryOld::Read<Vec3>(Base() + m_vecOrigin);
	}

    int BoneMatrix() {
        return MemoryOld::Read<int>(Base() + m_dwBoneMatrix);
	}

    Vec3 BonePos(Hitbox BoneID) {
        return { MemoryOld::Read<float>(BoneMatrix() + 0x30 * BoneID + 0x0C), MemoryOld::Read<float>(BoneMatrix() + 0x30 * BoneID + 0x1C), MemoryOld::Read<float>(BoneMatrix() + 0x30 * BoneID + 0x2C) }; //9
	}

    bool Spotted() {
        return MemoryOld::Read<int>(Base() + m_bSpotted)  == 1;
	}

    void Spotted(bool Spotted) {
        MemoryOld::Write<int>(Base() + m_bSpotted, Spotted ? 1 : 0);
	}
};