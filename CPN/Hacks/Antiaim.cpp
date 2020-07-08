#include "../Interfaces.h"
#include "Antiaim.h"
#include "../SDK/Engine.h"
#include "../SDK/Entity.h"
#include "../SDK/EntityList.h"
#include "../Config/Config.h"
#include "../SDK/UserCmd.h"
#include "../SDK/LocalPlayer.h"

void AimA::AntiAim(UserCmd* cmd, const Vector& previousViewAngles, const Vector& currentViewAngles, bool& sendPacket) noexcept {
	if (!config->antiAim.enabled || !interfaces->engine->isInGame()) {
		return;
	}

    if (config->antiAim.pitch && cmd->viewangles.x == currentViewAngles.x) {
        cmd->viewangles.x = config->antiAim.pitchAngle;
    }
        
    if (config->antiAim.yaw && !sendPacket && cmd->viewangles.y == currentViewAngles.y) {
        cmd->viewangles.y += localPlayer->getMaxDesyncAngle();
        if (fabsf(cmd->sidemove) < 5.0f) {
            if (cmd->buttons & UserCmd::IN_DUCK) {
                cmd->sidemove = cmd->tickCount & 1 ? 3.25f : -3.25f;
            }
            else {
                cmd->sidemove = cmd->tickCount & 1 ? 1.1f : -1.1f;
            }     
        }
    }
}