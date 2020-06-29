//#include "../visuals/hitmarker.hpp"
//#include "../../../hazedumper.hpp"
//#include "../../../_Objects/Objects.hpp"
//#include "../../menu/config/config.hpp"
//
//
//c_hitmarker hitmarker;
//int hitmarker_time = 0;
//
//void c_hitmarker::run() noexcept {
//	if (!interfaces::engine->is_connected() && !interfaces::engine->is_in_game())
//		return;
//
//	if (config_system.item.hitmarker || config_system.item.hitmarker_sound) {
//		hitmarker.draw();
//	}
//}
//
//
//void c_hitmarker::event(i_game_event* event) noexcept {
//	if (!event)
//		return;
//
//	if (!LocalPlayer::LocalPlayerPtr()) {
//		return;
//	}
//		
//
//	auto attacker = interfaces::entity_list->get_client_entity(interfaces::engine->get_player_for_user_id(event->get_int("attacker")));
//
//	if (!attacker)
//		return;
//
//	if (attacker == (void*)LocalPlayer::LocalPlayerPtr()) {
//		hitmarker_time = 255;
//
//		switch (config_system.item.hitmarker_sound) {
//		case 0:
//			break;
//		case 1:
//			interfaces::surface->play_sound("buttons\\arena_switch_press_02.wav");
//			break;
//		case 2:
//			interfaces::surface->play_sound("survival\\money_collect_01.wav");
//			break;
//		case 3:
//			interfaces::surface->play_sound("survival\\turret_idle_01.wav");
//			break;
//		}
//	}
//}
//
//
//void c_hitmarker::draw() noexcept {
//
//	int width, height;
//	interfaces::engine->get_screen_size(width, height);
//	int width_mid = width / 2;
//	int height_mid = height / 2;
//	
//	if (hitmarker_time > 0) {
//		float alpha = hitmarker_time;
//
//		render::draw_line(width_mid + 6, height_mid + 6, width_mid + 3, height_mid + 3, color(255, 255, 255, 255));
//		render::draw_line(width_mid - 6, height_mid + 6, width_mid - 3, height_mid + 3, color(255, 255, 255, 255));
//		render::draw_line(width_mid + 6, height_mid - 6, width_mid + 3, height_mid - 3, color(255, 255, 255, 255));
//		render::draw_line(width_mid - 6, height_mid - 6, width_mid - 3, height_mid - 3, color(255, 255, 255, 255));
//
//		hitmarker_time -= 2;
//	}
//}