#include "framework.hpp"
#include "variables.hpp"

//credits to harcuz for menu framework (https://www.unknowncheats.me/forum/members/2669363.html),
POINT cursor;
POINT cursor_corrected;

void menu_framework::group_box(std::int32_t x, std::int32_t y, std::int32_t w, std::int32_t h, unsigned long font, const std::string string, bool show_label) {
	x += variables::menu::x;
	y += variables::menu::y;

	//groupbox background
	render::draw_filled_rect(x, y, w, h, variables::groupbox_background);

	//groupbox outline
	render::draw_rect(x, y, w, h, variables::groupbox_outline);

	//groupbox label
	if (show_label)
		render::draw_text_string(x + 2, y - 12, font, string, false, variables::groupbox_label);
}

void menu_framework::tab(std::int32_t x, std::int32_t y, std::int32_t w, std::int32_t h, unsigned long font, const std::string string, std::int32_t& tab, std::int32_t count, bool show_outline) {
	GetCursorPos(&cursor);

	x += variables::menu::x;
	y += variables::menu::y;

	if ((cursor.x > x) && (cursor.x < x + w) && (cursor.y > y) && (cursor.y < y + h) && (GetAsyncKeyState(VK_LBUTTON) & 1))
		tab = count;
	
	//tab background
	if (show_outline)
		render::draw_rect(x, y, w, h, tab == count ? variables::tab_background1 : variables::tab_background2);

	//tab label
	render::draw_text_string(x - render::get_text_size(font, string).x / 2 + 50, y + h / 2 - 8, font, string, false, show_outline ? variables::tab_outline : tab == count ? variables::tab_selected : variables::tab_nonselected);
}

void menu_framework::check_box(std::int32_t x, std::int32_t y, std::int32_t position, unsigned long font, const std::string string, bool& value) {
	GetCursorPos(&cursor);

	x += variables::menu::x;
	y += variables::menu::y;
	position += variables::menu::x;

	int w = 10, h = 10;

	if ((cursor.x > position) && (cursor.x < position + w) && (cursor.y > y) && (cursor.y < y + h) && GetAsyncKeyState(VK_LBUTTON) & 1)
		value = !value;

	//checkbox background
	render::draw_filled_rect(position, y, w, h, value ? variables::checkbox_selected : variables::checkbox_background);

	//checkbox label
	render::draw_text_string(x + 2, y - 1, font, string, false, variables::checkbox_label);
}

void menu_framework::slider(std::int32_t x, std::int32_t y, std::int32_t offset, std::int32_t lenght, unsigned long font, const std::string string, float& value, float min_value, float max_value) {
	GetCursorPos(&cursor);

	x += variables::menu::x;
	y += variables::menu::y;
	offset += variables::menu::x;

	//int ix = x + offset;
	int yi = y + 4;

	//if ((cursor.x > ix) && (cursor.x < ix + lenght) && (cursor.y > yi) && (cursor.y < yi + 6) && (GetAsyncKeyState(VK_LBUTTON)))
	if ((cursor.x > offset) && (cursor.x < offset + lenght) && (cursor.y > yi) && (cursor.y < yi + 6) && (GetAsyncKeyState(VK_LBUTTON)))
		value = (cursor.x - offset) / (float(lenght) / float(max_value));

	//slider background
	render::draw_filled_rect(offset, yi, lenght, 6, variables::slider_background);
	render::draw_filled_rect(offset, yi, value * (float(lenght) / float(max_value)), 6, variables::slider_selected);

	//slider label
	render::draw_text_string(x + 2, y - 1, font, (std::stringstream{ } << string << ": " << std::setprecision(3) << value).str(), false, variables::slider_label);
}

void menu_framework::menu_movement(std::int32_t& x, std::int32_t& y, std::int32_t w, std::int32_t h) {
	GetCursorPos(&cursor);
	
	if (GetAsyncKeyState(VK_LBUTTON) < 0 && (cursor.x > x && cursor.x < x + w && cursor.y > y && cursor.y < y + h)) {
		should_drag = true;

		if (!should_move) {
			cursor_corrected.x = cursor.x - x;
			cursor_corrected.y = cursor.y - y;
			should_move = true;
		}
	}
	
	if (should_drag) {
		x = cursor.x - cursor_corrected.x;
		y = cursor.y - cursor_corrected.y;
	}
	
	if (GetAsyncKeyState(VK_LBUTTON) == 0) {
		should_drag = false;
		should_move = false;
	}
}

