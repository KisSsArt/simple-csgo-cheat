class Entity 
{
private:
    int index;

    int Ptr() {
        return Memory::Read<int>(Memory::clientBase() + dwGlowObjectManager);
	}

    int GetSize()
    {
        return 0x38;
    }

public:
    //Entity() {}

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
    
    void GlowObject(float r, float g, float b, float a, bool FullBloom/*, int GlowOnly*/) {
        Memory::Write<float>(Ptr()+((GlowIndex() * GetSize()) + 0x4), r);
        Memory::Write<float>(Ptr()+((GlowIndex() * GetSize()) + 0x8), g);
        Memory::Write<float>(Ptr()+((GlowIndex() * GetSize()) + 0xC), b);
        Memory::Write<float>(Ptr()+((GlowIndex() * GetSize()) + 0x10), a);
        Memory::Write<float>(Ptr()+((GlowIndex() * GetSize()) + 0x26), FullBloom);
        //Memory::Write<float>(Ptr()+((GlowIndex() * GetSize()) + 0x2C), GlowOnly);
	}

    void RenderWhenOccluded(bool RWO) {
        Memory::Write<bool>(Ptr()+((GlowIndex() * GetSize()) + 0x24), RWO);
	}

    void RenderWhenUnoccluded(bool RWU) {
        Memory::Write<bool>(Ptr()+((GlowIndex() * GetSize()) + 0x25), RWU);
	}

    //*(bool*)((GlowObjectManager)+((glowIndex * 0x38) + 0x24)) = true;
    //*(bool*)((GlowObjectManager)+((glowIndex * 0x38) + 0x25)) = false;

    //return Memory::Read<GlowObject>(GlowObject::Ptr() + GlowIndex() * 0x38);
    //Memory.Write<GlowObject>(GlowObject::Ptr() + GlowIndex * 0x38, value);

    int GlowIndex()
    {
        return Memory::Read<int>(Base() + m_iGlowIndex);
    }
};




//class EntityList 
//{
//private:
//    Entity *entities[4096];
//
//public:
//
//	EntityList()
//    {
//        for (int i = 0; i < 4096; i++)
//        {
//            entities[i] = new Entity(i);
//        }
//    }
//
//    //Entity this[int index]
//    Entity* TakeEntityIndex()
//    {
//        return entities[Entity::GetIndex()];
//    }
//};
//
//class Entity 
//{
//private:
//    static int index;
//public:
//    Entity() {}
//
//    Entity(int Index)
//    {
//        index = Index;
//    }
//
//    static int GetIndex()
//    {
//        return index;
//    }
//
//    void SetIndex(int Index) 
//    {
//        index = Index;
//    }
//
//    int Base()
//    {
//        return Memory::Read<int>(Memory::clientBase() + dwEntityList + index * 0x10);
//    }
//
//    int Health()
//    {
//        return Memory::Read<int>(Base() + m_iHealth);
//    }
//
//    bool Dormant()
//    {
//        return Memory::Read<int>(Base() + m_bDormant) == 1;
//    }
//};