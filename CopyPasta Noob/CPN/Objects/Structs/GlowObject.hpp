#include <vector>
#include "../../Memory.hpp"

struct GlowObjectDefinition
{
	uintptr_t m_pEntity;
	float r;
	float g;
	float b;
	float m_flGlowAlpha;
	char m_unk[4];
	float m_flUnk;
	float m_flBloomAmount;
	float m_flUnk1;
	bool m_bRenderWhenOccluded;
	bool m_bRenderWhenUnoccluded;
	bool m_bFullBloomRender;
	char m_unk1;
	int m_nFullBloomStencilTestValue;
	int m_nGlowStyle;
	int m_nSplitScreenSlot;
	int m_nNextFreeSlot;

	static int Ptr() {
		return Memory::Read<int>(Memory::clientBase() + dwGlowObjectManager);
	}

	static int GetSize()
	{
		return 0x38;
	}
};