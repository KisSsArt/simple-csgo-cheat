#pragma once

#include "VirtualMethod.h"

class GameEvent {
public:
    VIRTUAL_METHOD(const char*, getName, 1, (), (this))
    VIRTUAL_METHOD(int, getInt, 6, (const char* keyName, int defaultValue = 0), (this, keyName, defaultValue))
    VIRTUAL_METHOD(float, getFloat, 8, (const char* keyName, float defaultValue = 0.0f), (this, keyName, defaultValue))
    VIRTUAL_METHOD(const char*, getString, 9, (const char* keyName, const char* defaultValue = ""), (this, keyName, defaultValue))
};

class GameEventListener {
public:
    virtual ~GameEventListener() {}
    virtual void fireGameEvent(GameEvent* event) = 0;
    virtual int getEventDebugId() { return 42; }
};

class GameEventManager {
public:
    VIRTUAL_METHOD(void, addListener, 3, (GameEventListener* listener, const char* name, bool serverSide = false), (this, listener, name, serverSide))
    VIRTUAL_METHOD(void, removeListener, 5, (GameEventListener* listener), (this, listener))
};



//Contents
//All events:

//1 player_death
//2 player_hurt
//3 item_purchase
//4 bomb_beginplant
//5 bomb_abortplant
//6 bomb_planted
//7 bomb_defused
//8 bomb_exploded
//9 bomb_dropped
//10 bomb_pickup
//11 defuser_dropped
//12 defuser_pickup
//13 announce_phase_end
//14 cs_intermission
//15 bomb_begindefuse
//16 bomb_abortdefuse
//17 hostage_follows
//18 hostage_hurt
//19 hostage_killed
//20 hostage_rescued
//21 hostage_stops_following
//22 hostage_rescued_all
//23 hostage_call_for_help
//24 vip_escaped
//25 vip_killed
//26 player_radio
//27 bomb_beep
//28 weapon_fire
//29 weapon_fire_on_empty
//30 weapon_outofammo
//31 weapon_reload
//32 weapon_zoom
//33 silencer_detach
//34 inspect_weapon
//35 weapon_zoom_rifle
//36 player_spawned
//37 item_pickup
//38 ammo_pickup
//39 item_equip
//40 enter_buyzone
//41 exit_buyzone
//42 buytime_ended
//43 enter_bombzone
//44 exit_bombzone
//45 enter_rescue_zone
//46 exit_rescue_zone
//47 silencer_off
//48 silencer_on
//49 buymenu_open
//50 buymenu_close
//51 round_prestart
//52 round_poststart
//53 round_start
//54 round_end
//55 grenade_bounce
//56 hegrenade_detonate
//57 flashbang_detonate
//58 smokegrenade_detonate
//59 smokegrenade_expired
//60 molotov_detonate
//61 decoy_detonate
//62 decoy_started
//63 inferno_startburn
//64 inferno_expire
//65 inferno_extinguish
//66 decoy_firing
//67 bullet_impact
//68 player_footstep
//69 player_jump
//70 player_blind
//71 player_falldamage
//72 door_moving
//73 round_freeze_end
//74 mb_input_lock_success
//75 mb_input_lock_cancel
//76 nav_blocked
//77 nav_generate
//78 player_stats_updated
//79 achievement_info_loaded
//80 spec_target_updated
//81 spec_mode_updated
//82 hltv_changed_mode
//83 cs_game_disconnected
//84 cs_win_panel_round
//85 cs_win_panel_match
//86 cs_match_end_restart
//87 cs_pre_restart
//88 show_freezepanel
//89 hide_freezepanel
//90 freezecam_started
//91 player_avenged_teammate
//92 achievement_earned
//93 achievement_earned_local
//94 item_found
//95 item_gifted
//96 repost_xbox_achievements
//97 match_end_conditions
//98 round_mvp
//99 player_decal
//100 teamplay_round_start
//101 client_disconnect
//102 gg_player_levelup
//103 ggtr_player_levelup
//104 ggprogressive_player_levelup
//105 gg_killed_enemy
//106 gg_final_weapon_achieved
//107 gg_bonus_grenade_achieved
//108 switch_team
//109 gg_leader
//110 gg_player_impending_upgrade
//111 write_profile_data
//112 trial_time_expired
//113 update_matchmaking_stats
//114 player_reset_vote
//115 enable_restart_voting
//116 sfuievent
//117 start_vote
//118 player_given_c4
//119 gg_reset_round_start_sounds
//120 tr_player_flashbanged
//121 tr_highlight_ammo
//122 tr_mark_complete
//123 tr_mark_best_time
//124 tr_exit_hint_trigger
//125 bot_takeover
//126 tr_show_finish_msgbox
//127 tr_show_exit_msgbox
//128 reset_player_controls
//129 jointeam_failed
//130 teamchange_pending
//131 material_default_complete
//132 cs_prev_next_spectator
//133 cs_handle_ime_event
//134 nextlevel_changed
//135 seasoncoin_levelup
//136 tournament_reward
//137 start_halftime