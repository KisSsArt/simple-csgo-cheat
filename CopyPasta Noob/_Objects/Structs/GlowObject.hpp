[StructLayout(LayoutKind.Explicit)]
struct GlowObject
{
    [FieldOffset(0x00)]
    int EntityPointer;
    [FieldOffset(0x04)]
    float r;
    [FieldOffset(0x08)]
    float g;
    [FieldOffset(0x0C)]
    float b;
    [FieldOffset(0x10)]
    float a;
    
    [FieldOffset(0x14)]
    int unk1;
    [FieldOffset(0x18)]
    int unk2;

    [FieldOffset(0x1C)]
    float BloomAmount;
    [FieldOffset(0x20)]
    float LocalPlayerIs0_3;
    [FieldOffset(0x24)]
    bool m_bRenderWhenOccluded;
    [FieldOffset(0x25)]
    bool m_bRenderWhenUnoccluded;
    [FieldOffset(0x26)]
    bool m_bFullBloom;

    [FieldOffset(0x27)]
    byte unk3;

    [FieldOffset(0x28)]
    int FullBloomStencilValue;
    [FieldOffset(0x2C)]
    int m_nGlowStyle;
    [FieldOffset(0x30)]
    int SplitScreenSlot;
    [FieldOffset(0x34)]
    int NextFreeSlot;

    static int GetSize()
    {
        return 0x38;
    }

    static int Ptr()
    {
        return Memory::Read<int>(Memory::clientBase() + dwGlowObjectManager);
    }
};