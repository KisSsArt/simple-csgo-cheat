class Engine {
public:
	static int ClientStatePtr() {
		return Memory::Read<int>(Memory::engineBase() + dwClientState);
	}

	static int MaxPlayer() {
		return Memory::Read<int>(ClientStatePtr() + dwClientState_MaxPlayer);
	}

	static bool InGame() {
		return Memory::Read<int>(ClientStatePtr() + dwClientState_State) == 6;
	}
};