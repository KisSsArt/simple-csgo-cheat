#pragma once

class EngineOld {
public:
	static int ClientStatePtr() {
		return MemoryOld::Read<int>(MemoryOld::engineBase() + dwClientState);
	}

	static int MaxPlayer() {
		return MemoryOld::Read<int>(ClientStatePtr() + dwClientState_MaxPlayer);
	}

	static bool InGame() {
		return MemoryOld::Read<int>(ClientStatePtr() + dwClientState_State) == 6;
	}
};