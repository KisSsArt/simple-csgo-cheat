#include "../features.hpp"
#include "../../../_Objects/Objects.hpp"

void misc::allMisc::radarHack(c_usercmd* cmd) {
	if (!variables::radar_bool) {
		return;
	}

	int mp = Engine::MaxPlayer();
	for (int i = 0; i < mp; i++) {

		if (Entity(i).Base() == NULL) {
			continue;
		}
		if (Entity(i).Dormant()) {
			continue;
		}
		if (Entity(i).Team() == LocalPlayer::Team()) {
			continue;
		}

		if (!Entity(i).Spotted()) {
			Entity(i).Spotted(true);
		}
	}
	
	Sleep(100);
}