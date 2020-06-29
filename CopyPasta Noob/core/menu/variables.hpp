#pragma once

namespace variables {
	inline bool test_bool = false;
	inline float test_float = 0.f;

	//Misc
	inline bool FovEnable = false;

	//FOV
	inline float FOV = 90.f;


#pragma region Aimbot
	//TriggerBot
	inline bool trigger_bool = false;

	inline float delay_shoot = 10;
	inline float durationOfTheShoot = 100;

	//rageaim
	inline bool rageaim_bool = false;
#pragma endregion

#pragma region Glow
	//Glow
	inline bool Glow_bool = false;
	//Teammate//////////////////////////////////////////////
	inline bool TeamGlow_bool = false;
	inline bool GlowOnly_Team = false;
	
	//Team Color
	inline bool GlowHealth_Team = false;
	inline float Brightness_Team = 1.7;
	inline bool FullBloomTeam = false;

	inline float TeamColorR = 0;
	inline float TeamColorG = 100;
	inline float TeamColorB = 0;

	//Eneny//////////////////////////////////////////////////
	inline bool EnemyGlow_bool = true;
	inline bool GlowOnly_Enemy = false;

	//Enemy Color
	inline bool GlowHealth_Enemy = false;
	inline float Brightness_Enemy = 1.7;
	inline bool FullBloomEnemy = false;

	inline float EnemyColorR = 150;
	inline float EnemyColorG = 0;
	inline float EnemyColorB = 0;
    //////////////////////////////////////////////////////////
#pragma endregion

#pragma region ESP
	inline bool ESP_bool = false;

#pragma endregion


#pragma region Misc
	//Misc
	inline bool bunnyhop_bool = false;
	inline bool antiflash_bool = false;
	inline bool radar_bool = false;
#pragma endregion

#pragma region MenuSettings
	namespace menu_params {
		inline bool opened = false;
		inline int x = 140, y = 140;
		inline int width = 600, height = 600;							//DEF: w = 400, h = 300;

		inline std::int32_t MenuMargin = 5;

		inline std::int32_t HeaderHeight = 70;
		inline std::int32_t HeaderMargin = 10;

		//main
		inline std::string watermark = "CopyPastaNoob's";
		inline color main_menu_background = color(36, 36, 36, 200);
		inline color main_label_backgound = color(25, 25, 25, 200);
		inline color main_line = color(36, 36, 36, 200);
	
		//groupbox
		inline color groupbox_background = color(25, 25, 25, 200);	//Ôîí ãðóïï
		inline color groupbox_outline = color(45, 45, 45, 200);
		inline color groupbox_label = color(255, 255, 255, 255);

		//tab
		inline color tab_background1 = color(255, 0, 0, 200);		//ÕÇ color(52, 134, 235, 255)
		inline color tab_background2 = color(25, 25, 25, 200);		//ÕÇ
		inline color tab_outline = color(255, 255, 255, 200);
		inline color tab_selected = color(255, 0, 0, 255);			//DEF: color(52, 134, 235, 255)
		inline color tab_nonselected = color(255, 255, 255, 255);

		//checkbox
		inline color checkbox_background = color(60, 60, 60, 255);
		inline color checkbox_selected = color(255, 0, 0, 255);		//DEF: color(52, 134, 235, 255)
		inline color checkbox_label = color(255, 255, 255, 255);

		//slider
		inline color slider_background = color(60, 60, 60, 255);
		inline color slider_selected = color(255, 0, 0, 255);		//DEF: color(52, 134, 235, 255)
		inline color slider_label = color(255, 255, 255, 255);
	}
#pragma endregion
}