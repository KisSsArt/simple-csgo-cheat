#include "menu.hpp"

//todo auto elements positioning

auto do_frame = [&](std::int32_t x, std::int32_t y, std::int32_t w, std::int32_t h, color bg, color header_text, color header_line, const std::string& name) {
		render::draw_filled_rect(x, y, w, h, bg);
		render::draw_filled_rect(x, y, w, 30, header_text);
		render::draw_filled_rect(x, y + 30, w, 2, header_line);
		render::draw_text_string(x + 10, y + 8, render::fonts::watermark_font, name, false, color::white());
};

void menu::render() {
	if (!variables::menu::opened)
		return;

	do_frame(variables::menu::x, variables::menu::y, variables::menu::w, variables::menu::h, variables::main_menu_background, variables::main_label_backgound, variables::main_line, variables::watermark);
	
	menu_framework::group_box(5, 35, 100, variables::menu::h - 40, render::fonts::watermark_font, "tabs", false); {
		menu_framework::tab(5, (260 / 2) - 35, 100, 30, render::fonts::group_label_font, "Aimbot", menu::current_tab, 0, false);
		menu_framework::tab(5, (260 / 2), 100, 30, render::fonts::group_label_font, "Visuals", menu::current_tab, 1, false);
		menu_framework::tab(5, (260 / 2) + 35, 100, 30, render::fonts::group_label_font, "Misc", menu::current_tab, 2, false);
		menu_framework::tab(5, (260 / 2) + 70, 100, 30, render::fonts::test_font, "Test", menu::current_tab, 3, false);
	}

	switch (current_tab) {
	case 0:
		menu_framework::group_box(110, 35, 685, variables::menu::h - 40, render::fonts::watermark_font, "Aimbot", false); {
			menu_framework::check_box(135, 60, 310, render::fonts::watermark_font, "Trigger", variables::trigger_bool);
			menu_framework::check_box(135, 75, 310, render::fonts::watermark_font, "RageAim", variables::rageaim_bool);
		}
		break;
	case 1://GlowHealthBased
		menu_framework::group_box(110, 35, 685, variables::menu::h - 40, render::fonts::watermark_font, "Visuals", false); {
			menu_framework::check_box(120, 45, 310, render::fonts::watermark_font, "Glow", variables::Glow_bool);

			menu_framework::check_box(135, 60, 310, render::fonts::watermark_font, "Team", variables::TeamGlow_bool);
			{
				menu_framework::check_box(150, 75, 310, render::fonts::watermark_font, "GlowHealthBased", variables::GlowHealth_Team);

				menu_framework::slider(150, 90, 310, 125, render::fonts::watermark_font, "Team Color Red", variables::TeamColorR, 0.f, 255.f);
				menu_framework::slider(150, 105, 310, 125, render::fonts::watermark_font, "Team Color Green", variables::TeamColorG, 0.f, 255.f);
				menu_framework::slider(150, 120, 310, 125, render::fonts::watermark_font, "Team Color Blue", variables::TeamColorB, 0.f, 255.f);

				menu_framework::slider(150, 135, 310, 60, render::fonts::watermark_font, "Brightness", variables::Brightness_Team, 0.f, 2.f);
				//menu_framework::check_box(150, 150, 310, render::fonts::watermark_font, "Full Bloom", variables::FullBloomTeam);
			}

			menu_framework::check_box(135, 165, 310, render::fonts::watermark_font, "Enemy", variables::EnemyGlow_bool);
			{
				menu_framework::check_box(150, 180, 310, render::fonts::watermark_font, "GlowHealthBased", variables::GlowHealth_Enemy);

				menu_framework::slider(150, 195, 310, 125, render::fonts::watermark_font, "Enemy Color Red", variables::EnemyColorR, 0.f, 255.f);
				menu_framework::slider(150, 210, 310, 125, render::fonts::watermark_font, "Enemy Color Green", variables::EnemyColorG, 0.f, 255.f);
				menu_framework::slider(150, 225, 310, 125, render::fonts::watermark_font, "Enemy Color Blue", variables::EnemyColorB, 0.f, 255.f);

				menu_framework::slider(150, 240, 310, 60, render::fonts::watermark_font, "Brightness", variables::Brightness_Enemy, 0.f, 2.f);
				//menu_framework::check_box(150, 255, 310, render::fonts::watermark_font, "Full Bloom", variables::FullBloomEnemy);
			}
		}
		break;
	case 2:
		menu_framework::group_box(110, 35, 685, variables::menu::h - 40, render::fonts::watermark_font, "Misc", false); {
			menu_framework::check_box(120, 45, 310, render::fonts::watermark_font, "BunnyHop", variables::bunnyhop_bool);
			menu_framework::check_box(120, 60, 310, render::fonts::watermark_font, "AntiFlash", variables::antiflash_bool);
		}
		break;
	case 3:
		menu_framework::group_box(110, 35, 685, variables::menu::h - 40, render::fonts::watermark_font, "TEST", false); {
			menu_framework::check_box(120, 45, 310, render::fonts::watermark_font, "Test Bool", variables::test_bool);
			menu_framework::slider(120, 60, 310, 125, render::fonts::watermark_font, "Test Slider", variables::test_float, 0.f, 100.f);
		}
		break;
	}

	menu_framework::menu_movement(variables::menu::x, variables::menu::y, variables::menu::w, 30);
}

void menu::toggle() {
	if (GetAsyncKeyState(VK_INSERT) & 1) {
		variables::menu::opened = !variables::menu::opened;
	}
}