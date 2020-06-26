#include "menu.hpp"

using namespace menu_framework;
using namespace render::fonts;
using namespace variables;

//todo auto elements positioning

//fix bugs
//   **
//  ****
//  |  |
//  |  |
//  |  |
// ( )( )

auto do_frame = [&](std::int32_t x, std::int32_t y, std::int32_t width, std::int32_t height, color background, color header_text, color header_line, const std::string& name) {
		render::draw_filled_rect(x, y + menu_params::HeaderHeight + menu_params::HeaderMargin, width, height, background);										//Background
		render::draw_filled_rect(x, y, width, menu_params::HeaderHeight, header_text);	//"Header - верхн€€ хуевина" @KisSsArt
		//render::draw_filled_rect(x, y + 30, width, 2, header_line);									//Header underline
		render::draw_text_string(x + 10,  y + 20, group_label_font, name, false, color::red());			//Header Name
};

void menu::render() {
	if (!menu_params::opened) {
		return;
	}

	do_frame(menu_params::x, menu_params::y, menu_params::width, menu_params::height, menu_params::main_menu_background, menu_params::main_label_backgound, menu_params::main_line, "CPN");
	//-150 115 100
	group_box(5, 5, menu_params::HeaderHeight - 5, menu_params::HeaderHeight - 10, watermark_font, "tabs", false); {
/*5*/	tab(75, 0, 100, 30, group_label_font, "Aimbot", menu::current_tab, 0, false);
		tab(165, 0, 100, 30, group_label_font, "Glow", menu::current_tab, 1, false);
		tab(255, 0, 100, 30, group_label_font, "ESP", menu::current_tab, 2, false);
		tab(345, 0, 100, 30, group_label_font, "Misc", menu::current_tab, 3, false);
	}

	switch (current_tab) {
	case 0: // Aimbot
		group_box(menu_params::MenuMargin, 85, menu_params::width - menu_params::MenuMargin * 2, menu_params::height - menu_params::MenuMargin * 2, watermark_font, "Aimbot", false); {
			check_box(menu_params::MenuMargin + 10, 95, 310, watermark_font, "Trigger", trigger_bool);

			slider(menu_params::MenuMargin + 10, 110, 310, 60, watermark_font, "Delay Shoot", variables::delay_shoot, 0.f, 5.f);
			slider(menu_params::MenuMargin + 10, 125, 310, 60, watermark_font, "Duration Of The Shoot", variables::durationOfTheShoot, 3.5f, 20.f);

			check_box(menu_params::MenuMargin + 10, 170, 310, watermark_font, "RageAim", rageaim_bool);
		}
		break;
	case 1: // Visuals
		group_box(menu_params::MenuMargin, 85, menu_params::width - menu_params::MenuMargin * 2, menu_params::height - menu_params::MenuMargin * 2, watermark_font, "Glow", false); {
			check_box(menu_params::MenuMargin + 10, 95, 310, watermark_font, "Glow", Glow_bool);

			/////////////////////////TEAM

			check_box(menu_params::MenuMargin + 25, 110, 310, watermark_font, "Team", TeamGlow_bool);
			{
				check_box(menu_params::MenuMargin + 40, 125, 310, watermark_font, "GlowHealthBased", GlowHealth_Team);

				slider(menu_params::MenuMargin + 50, 140, 310, 125, watermark_font, "Team Color Red", TeamColorR, 0.f, 255.f);
				slider(menu_params::MenuMargin + 50, 155, 310, 125, watermark_font, "Team Color Green", TeamColorG, 0.f, 255.f);
				slider(menu_params::MenuMargin + 50, 170, 310, 125, watermark_font, "Team Color Blue", TeamColorB, 0.f, 255.f);

				slider(menu_params::MenuMargin + 40, 185, 310, 60, watermark_font, "Brightness", Brightness_Team, 0.f, 2.f);

				check_box(menu_params::MenuMargin + 40, 200, 310, watermark_font, "Full Bloom", FullBloomTeam);
				check_box(menu_params::MenuMargin + 40, 215, 310, watermark_font, "Glow Only", GlowOnly_Team);
			}

			/////////////////////////ENEMY

			check_box(menu_params::MenuMargin + 25, 275, 310, watermark_font, "Enemy", EnemyGlow_bool);
			{
				check_box(menu_params::MenuMargin + 40, 290, 310, watermark_font, "GlowHealthBased", GlowHealth_Enemy);

				slider(menu_params::MenuMargin + 50, 305, 310, 125, watermark_font, "Enemy Color Red", EnemyColorR, 0.f, 255.f);
				slider(menu_params::MenuMargin + 50, 320, 310, 125, watermark_font, "Enemy Color Green", EnemyColorG, 0.f, 255.f);
				slider(menu_params::MenuMargin + 50, 335, 310, 125, watermark_font, "Enemy Color Blue", EnemyColorB, 0.f, 255.f);

				slider(menu_params::MenuMargin + 40, 350, 310, 60, watermark_font, "Brightness", Brightness_Enemy, 0.f, 2.f);

				check_box(menu_params::MenuMargin + 40, 365, 310, watermark_font, "Full Bloom", FullBloomEnemy);
				check_box(menu_params::MenuMargin + 40, 380, 310, watermark_font, "Glow Only", GlowOnly_Enemy);
			}
		}
		break;
	case 2: // ESP
		group_box(menu_params::MenuMargin, 85, menu_params::width - menu_params::MenuMargin * 2, menu_params::height - menu_params::MenuMargin * 2, watermark_font, "ESP", false); {
			check_box(menu_params::MenuMargin + 10, 95, 310, watermark_font, "ESP", ESP_bool);
		}
		break;
	case 3: // Misc
		group_box(menu_params::MenuMargin, 85, menu_params::width - menu_params::MenuMargin * 2, menu_params::height - menu_params::MenuMargin * 2, watermark_font, "Misc", false); {
			check_box(menu_params::MenuMargin + 10, 95, 310, watermark_font, "BunnyHop", bunnyhop_bool);
			check_box(menu_params::MenuMargin + 10, 110, 310, watermark_font, "AntiFlash", antiflash_bool);
			check_box(menu_params::MenuMargin + 10, 125, 310, watermark_font, "RadarHack", radar_bool);
		}
		break;
	}

	menu_movement(menu_params::x, menu_params::y, menu_params::width, menu_params::HeaderHeight);
}

void menu::toggle() {
	if (GetAsyncKeyState(VK_INSERT) & 1) {
		menu_params::opened = !menu_params::opened;
	}
}
