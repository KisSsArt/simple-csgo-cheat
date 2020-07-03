#pragma once
#include "../Memory.h"

class Client {
public:
	static void ForceAttack(bool shoot) {
		MemoryOld::Write<int>(MemoryOld::clientBase() + dwForceAttack, shoot ? 5 : 4);
	}

	static void ForceAttack() {
		MemoryOld::Write<int>(MemoryOld::clientBase() + dwForceAttack, 6);
	}

	static void ForceRightAttack(bool trigger) {
		MemoryOld::Write<int>(MemoryOld::clientBase() + dwForceAttack2, trigger ? 5 : 4);
	}

	static void ForceJump()//bool jump 
	{
		MemoryOld::Write<int>(MemoryOld::clientBase() + dwForceJump, 6);
	}

	static void ForceJump(bool jump) {
		MemoryOld::Write<int>(MemoryOld::clientBase() + dwForceJump, jump ? 5 : 4);
	}

	static uintptr_t GlowObjectManager() {
		return MemoryOld::Read<uintptr_t>(MemoryOld::clientBase() + dwGlowObjectManager);
	}
};