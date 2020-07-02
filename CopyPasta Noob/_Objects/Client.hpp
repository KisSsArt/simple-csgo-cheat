#pragma once

class Client {
public:
	static void ForceAttack(bool shoot) {
		Memory::Write<int>(Memory::clientBase() + dwForceAttack, shoot ? 5 : 4);
	}

	static void ForceRightAttack(bool trigger) {
		Memory::Write<int>(Memory::clientBase() + dwForceAttack2, trigger ? 5 : 4);
	}

	static void ForceJump()//bool jump 
	{
		Memory::Write<int>(Memory::clientBase() + dwForceJump, 6);
	}

	static void ForceJump(bool jump) {
    	Memory::Write<int>(Memory::clientBase() + dwForceJump, jump ? 5 : 4);
	}

	static uintptr_t GlowObjectManager() {
		return Memory::Read<uintptr_t>(Memory::clientBase() + dwGlowObjectManager);
	}
};