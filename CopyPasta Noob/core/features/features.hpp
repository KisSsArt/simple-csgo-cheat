#include "../../dependencies/utilities/csgo.hpp"
#include "../menu/variables.hpp"

namespace misc {
	namespace allMisc {
		void bunny_hop(c_usercmd* cmd);
		void antiflash(c_usercmd* cmd);
		void radarHack(c_usercmd* cmd);
		void ClanTagChanger(c_usercmd* cmd);
	};
	
}

namespace visuals {
	namespace wh {
		void glow(c_usercmd* cmd);
		void ESP(c_usercmd* cmd);
	};
	namespace FOV {
		void FovChanger(c_usercmd* cmd);
	};
}

//class c_hitmarker {
//public:
//	void run() noexcept;
//	void event(i_game_event * event) noexcept;
//protected:
//	void draw() noexcept;
//};
//extern c_hitmarker hitmarker;
//
////namespace hitmarker {
////};

namespace aimbot {
	namespace aim {
		void trigger(c_usercmd* cmd);
		void rageAim(c_usercmd* cmd);
	};
}