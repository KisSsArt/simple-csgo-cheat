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

	static void FovChanger(float FOV) {
		Memory::Write<int>(LocalPlayerPtr() + m_iFOV , FOV);
	}
	
	static int FovChanger() {
		return Memory::Read<int>(LocalPlayerPtr() + m_iFOV);
	}

	static int Scoped() {
		return Memory::Read<bool>(LocalPlayerPtr() + m_bIsScoped);
	}

	static bool checkLocalVal() {
		Vec3 val = Memory::Read<Vec3>(LocalPlayerPtr() + m_vecVelocity);
		int vel = val.x + val.y + val.z;

		if (vel != 0)
			return true;
		else
			return false;
	}
};