class LocalPlayer {
public:
	static int LocalPlayerPtr() {
		return Memory::Read<int>(Memory::clientBase() + dwLocalPlayer);
	}

	static int Team() {
		return Memory::Read<int>(LocalPlayerPtr() + m_iTeamNum);
	}

	static int Flags() {
		return Memory::Read<int>(LocalPlayerPtr() + m_fFlags);
	}

	static int CrosshairID() {
		return Memory::Read<int>(LocalPlayerPtr() + m_iCrosshairId);
	}

	static void FlashAlpha(float value) {
		Memory::Write<float>(LocalPlayerPtr() + m_flFlashMaxAlpha, value);
	}
};