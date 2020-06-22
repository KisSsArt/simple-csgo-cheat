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
};