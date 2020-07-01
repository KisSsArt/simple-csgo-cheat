//#include "../visuals/hitmarker.hpp"
//#include "../../../hazedumper.hpp"
//#include "../../../_Objects/Objects.hpp"
//#include "../../menu/config/config.hpp"
//
//
//c_hitmarker hitmarker;
//int hitmarker_time = 0;
//
//void c_hitmarker::run(c_usercmd* cmd, i_game_event* event){
//	if (!interfaces::engine->is_connected() && !interfaces::engine->is_in_game())
//		return;
//
//
//	int width, height;
//	interfaces::engine->get_screen_size(width, height);
//	int width_mid = width / 2;
//	int height_mid = height / 2;
//
//	auto attacker = interfaces::entity_list->get_client_entity(interfaces::engine->get_player_for_user_id(event->get_int("attacker")));
//
//	if (!attacker)
//		return;
//
//	if (attacker == (void*)LocalPlayer::LocalPlayerPtr()) {
//		hitmarker_time = 255;
//	}
//
//	if (hitmarker_time > 0) {
//		float alpha = hitmarker_time;
//
//		render::draw_line(width_mid + 6, height_mid + 6, width_mid + 3, height_mid + 3, color(255, 255, 255, alpha));
//		render::draw_line(width_mid - 6, height_mid + 6, width_mid - 3, height_mid + 3, color(255, 255, 255, alpha));
//		render::draw_line(width_mid + 6, height_mid - 6, width_mid + 3, height_mid - 3, color(255, 255, 255, alpha));
//		render::draw_line(width_mid - 6, height_mid - 6, width_mid - 3, height_mid - 3, color(255, 255, 255, alpha));
//
//		hitmarker_time -= 2;
//	}
//}