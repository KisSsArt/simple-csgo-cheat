#pragma once

struct UserCmd;
struct Vector;

namespace AimA{
	void AntiAim(UserCmd* cmd, const Vector& previousViewAngles, const Vector& currentViewAngles, bool& sendPacket) noexcept;
}