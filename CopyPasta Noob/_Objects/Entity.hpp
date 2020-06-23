#include "Structs/Structs.hpp"

class Entity 
{
private:
    int index;

public:
    Entity(int Index)
    {
        index = Index;
    }
    
    uintptr_t Base()
    {
        return Memory::Read<uintptr_t>((Memory::clientBase() + dwEntityList) + index * 0x10);
    }

    int Team()
    {
        return Memory::Read<int>(Base() + m_iTeamNum);
    }

    int Health()
    {
        return Memory::Read<int>(Base() + m_iHealth);
    }

    bool Dormant()
    {
        return Memory::Read<int>(Base() + m_bDormant) == 1;
    }

    void GlowObject(GlowObjectDefinition value) {
        Memory::Write<GlowObjectDefinition>(GlowObjectDefinition::Ptr() + GlowIndex() * GlowObjectDefinition::GetSize(), value);
	}

    GlowObjectDefinition GlowObject() {
        return Memory::Read<GlowObjectDefinition>(GlowObjectDefinition::Ptr() + GlowIndex() * GlowObjectDefinition::GetSize());
    }

    int GlowIndex()
    {
        return Memory::Read<int>(Base() + m_iGlowIndex);
    }

    Vec3 Location() {
        return Memory::Read<Vec3>(Base() + m_vecOrigin);
	}

    int BoneMatrix() {
        return Memory::Read<int>(Base() + m_dwBoneMatrix);
	}

    Vec3 BonePos(Hitbox BoneID) {
        return { Memory::Read<float>(BoneMatrix() + 0x30 * BoneID + 0x0C), Memory::Read<float>(BoneMatrix() + 0x30 * BoneID + 0x1C), Memory::Read<float>(BoneMatrix() + 0x30 * BoneID + 0x2C) }; //9
	}
};