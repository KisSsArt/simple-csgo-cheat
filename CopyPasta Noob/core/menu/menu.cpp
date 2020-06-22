#include "menu.hpp"

using namespace menu_framework;
using namespace render::fonts;
using namespace variables;

//todo auto elements positioning

//
//   **
//  ****
//  |  |
//  |  |
//  |  |
// ( )( )

auto do_frame = [&](std::int32_t x, std::int32_t y, std::int32_t width, std::int32_t height, color background, color header_text, color header_line, const std::string& name) {
		render::draw_filled_rect(x, y, width, height, background);
		render::draw_filled_rect(x, y, width, 30, header_text);
		render::draw_filled_rect(x, y + 30, width, 2, header_line);
		render::draw_text_string(x + 10, y + 8, watermark_font, name, false, color::white());
};

void menu::render() {
	if (!menu_params::opened) {
		return;
	}

	do_frame(menu_params::x, menu_params::y, menu_params::width, menu_params::height, menu_params::main_menu_background, menu_params::main_label_backgound, menu_params::main_line, menu_params::watermark);
	
	group_box(5, 35, 100, menu_params::height - 40, watermark_font, "tabs", false); {
		tab(5, (260 / 2) - 35, 100, 30, group_label_font, "Aimbot", menu::current_tab, 0, false);
		tab(5, (260 / 2), 100, 30, group_label_font, "Visuals", menu::current_tab, 1, false);
		tab(5, (260 / 2) + 35, 100, 30, group_label_font, "Misc", menu::current_tab, 2, false);
		//tab(5, (260 / 2) + 70, 100, 30, test_font, "Test", menu::current_tab, 3, false);
	}

	switch (current_tab) {
	case 0: // Aimbot
		group_box(110, 35, 685, menu_params::height - 40, watermark_font, "Aimbot", false); {
			check_box(135, 60, 310, watermark_font, "Trigger", trigger_bool);
			check_box(135, 75, 310, watermark_font, "RageAim", rageaim_bool);
		}
		break;
	case 1: // Visuals
		group_box(110, 35, 685, menu_params::height - 40, watermark_font, "Visuals", false); {
			check_box(120, 45, 310, watermark_font, "Glow", Glow_bool);

			/////////////////////////TEAM

			check_box(135, 60, 310, watermark_font, "Team", TeamGlow_bool);
			{
				check_box(150, 75, 310, watermark_font, "GlowHealthBased", GlowHealth_Team);

				slider(150, 90, 310, 125, watermark_font, "Team Color Red", TeamColorR, 0.f, 255.f);
				slider(150, 105, 310, 125, watermark_font, "Team Color Green", TeamColorG, 0.f, 255.f);
				slider(150, 120, 310, 125, watermark_font, "Team Color Blue", TeamColorB, 0.f, 255.f);

				slider(150, 135, 310, 60, watermark_font, "Brightness", Brightness_Team, 0.f, 2.f);
				check_box(150, 150, 310, watermark_font, "Full Bloom", FullBloomTeam);
				check_box(150, 165, 310, watermark_font, "Glow Only", GlowOnly_Team);
			}

			/////////////////////////ENEMY

			check_box(135, 225, 310, watermark_font, "Enemy", EnemyGlow_bool);
			{
				check_box(150, 240, 310, watermark_font, "GlowHealthBased", GlowHealth_Enemy);

				slider(150, 255, 310, 125, watermark_font, "Enemy Color Red", EnemyColorR, 0.f, 255.f);
				slider(150, 270, 310, 125, watermark_font, "Enemy Color Green", EnemyColorG, 0.f, 255.f);
				slider(150, 285, 310, 125, watermark_font, "Enemy Color Blue", EnemyColorB, 0.f, 255.f);

				slider(150, 300, 310, 60, watermark_font, "Brightness", Brightness_Enemy, 0.f, 2.f);
				check_box(150, 315, 310, watermark_font, "Full Bloom", FullBloomEnemy);
				check_box(150, 330, 310, watermark_font, "Glow Only", GlowOnly_Enemy);
			}
		}
		break;
	case 2: // Misc
		group_box(110, 35, 685, menu_params::height - 40, watermark_font, "Misc", false); {
			check_box(120, 45, 310, watermark_font, "BunnyHop", bunnyhop_bool);
			check_box(120, 60, 310, watermark_font, "AntiFlash", antiflash_bool);
		}
		break;

	/*case 3: // Test
		group_box(110, 35, 685, menu::h - 40, watermark_font, "TEST", false); {
			check_box(120, 45, 310, watermark_font, "Test Bool", test_bool);
			slider(120, 60, 310, 125, watermark_font, "Test Slider", test_float, 0.f, 100.f);
		}
		break;*/
	}

	menu_movement(menu_params::x, menu_params::y, menu_params::width, 30);
}

void menu::toggle() {
	if (GetAsyncKeyState(VK_INSERT) & 1) {
		menu_params::opened = !menu_params::opened;
	}
}
