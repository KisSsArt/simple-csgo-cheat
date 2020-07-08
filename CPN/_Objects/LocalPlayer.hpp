class LocalPlayerOld {
public:
	static int LocalPlayerPtr() {
		return MemoryOld::Read<int>(MemoryOld::clientBase() + dwLocalPlayer);
	}

	static int Index() {
		return MemoryOld::Read<int>(LocalPlayerPtr() + 0x64);
	}

	static int Team() {
		return MemoryOld::Read<int>(LocalPlayerPtr() + m_iTeamNum);
	}

	static int Flags() {
		return MemoryOld::Read<int>(LocalPlayerPtr() + m_fFlags);
	}

	static int CrosshairID() {
		return MemoryOld::Read<int>(LocalPlayerPtr() + m_iCrosshairId);
	}

	static void FlashAlpha(float value) {
		MemoryOld::Write<float>(LocalPlayerPtr() + m_flFlashMaxAlpha, value);
	}

	static void FovChanger(float FOV) {
		MemoryOld::Write<int>(LocalPlayerPtr() + m_iFOV, FOV);
	}

	static int FovChanger() {
		return MemoryOld::Read<int>(LocalPlayerPtr() + m_iFOV);
	}

	static int Scoped() {
		return MemoryOld::Read<bool>(LocalPlayerPtr() + m_bIsScoped);
	}

	static void SetClanTag(std::string Tag) {
		MemoryOld::Write<std::string>(LocalPlayerPtr() + dwSetClanTag, Tag);
	}

	static int GetClanTag() {
		return MemoryOld::Read<int>(LocalPlayerPtr() + dwSetClanTag);
	}

	//weapon = *(dword*)(localplayer + ENTITY_ACTIVE_WEAPON); // m_hActive_Weapon
	static int GetActiveWeapon() {
		return MemoryOld::Read<int>(LocalPlayerPtr() + m_hActiveWeapon);
	}

	/*static int Attacker() {
		return MemoryOld::Read<int>(LocalPlayerPtr() + );
	}*/

	static bool checkLocalVal() {
		Vec3 val = MemoryOld::Read<Vec3>(LocalPlayerPtr() + m_vecVelocity);
		int vel = val.x + val.y + val.z;

		if (vel != 0) {
			return true;
		}
		else {
			return false;
		}
			
	}
};