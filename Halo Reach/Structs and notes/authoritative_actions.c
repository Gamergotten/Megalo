
bool Action_DoesntNeedAuth(longlong Action)
{
  switch(Action->ID) {

  // these actions below are the ones allowed to be used on local
  case 0x00: // none
  case 0x09: // set
  case 0x10: // hud post message
  case 0x12: // debug print_variable
  case 0x13: // get_player_holding_object
  case 0x14: // for_each - idk why its called this, but this is call_trigger
  case 0x19: // random
  case 0x1b: // object_get_orientation
  case 0x1c: // object_get_velocity
  case 0x23: // player_get_place
  case 0x24: // team_get_place
  case 0x28: // player_get_vehicle
  case 0x32: // hud_widget_set_visibility
  case 0x33: // play_sound
  case 0x36: // object_get_shield
  case 0x37: // object_get_health
  case 0x3e: // player_get_fireteam_index
  case 0x42: // object_get_distance
  case 0x47: // device_get_power
  case 0x49: // device_get_position
  case 0x51: // saved_film_insert_marker
  case 0x54: // player_get_equipment
  case 0x58: // debug_force_player_view_count
  case 0x59: // player_pick_up_weapon
  case 0x5b: // object_set_orientation
  case 0x5c: // object_face_object
  case 0x5d: // biped_give_weapon
  case 0x5e: // biped_drop_weapon
  case 0x5f: // set_scenario_interpolator_state
  case 0x61: // game_grief_record_custom_penalty
    return true;

  // these actions below are the ones NOT allowed to be used on local (according to tag test)
  case 0x01: // set_score
  case 0x02: // create_object
  case 0x03: // delete_object
  case 0x04: // navpoint_set_visible
  case 0x05: // navpoint_set_icon
  case 0x06: // navpoint_set_priority
  case 0x07: // navpoint_set_timer
  case 0x08: // navpoint_set_visible_range
  case 0x0a: // set_boundary
  case 0x0b: // apply_player_traits
  case 0x0c: // set_pickup_filter
  case 0x0d: // set_respawn_filter
  case 0x0e: // set_fireteam_respawn_filter
  case 0x0f: // set_progress_bar
  case 0x11: // timer_set_rate
  case 0x15: // end_round
  case 0x16: // boundary_set_visible
  case 0x17: // object_destroy
  case 0x18: // object_set_invincibility
  case 0x1a: // break_into_debugger
  case 0x1d: // player_death_get_killing_player
  case 0x1e: // player_death_get_damage_type
  case 0x1f: // player_death_get_special_type
  case 0x20: // debugging_enable_tracing
  case 0x21: // object_attach
  case 0x22: // object_detach
  case 0x25: // player_get_killing_spree_count
  case 0x26: // player_adjust_money
  case 0x27: // player_enable_purchases
  case 0x29: // player_set_vehicle
  case 0x2a: // player_set_unit
  case 0x2b: // timer_reset
  case 0x2c: // weapon_set_pickup_priority
  case 0x2d: // object_bounce
  case 0x2e: // hud_widget_set_text
  case 0x2f: // hud_widget_set_value
  case 0x30: // hud_widget_set_meter
  case 0x31: // hud_widget_set_icon
  case 0x34: // object_set_scale
  case 0x35: // navpoint_set_text
  case 0x38: // player_set_objective
  case 0x39: // player_set_objective_allegiance
  case 0x3a: // player_set_objective_allegiance_icon
  case 0x3b: // team_set_coop_spawning
  case 0x3c: // team_set_primary_respawn_object
  case 0x3d: // player_set_primary_respawn_object
  case 0x3f: // player_set_fireteam_index
  case 0x40: // object_adjust_shield
  case 0x41: // object_adjust_health
  case 0x43: // object_adjust_maximum_shield
  case 0x44: // object_adjust_maximum_health
  case 0x45: // player_set_requisition_palette
  case 0x46: // device_set_power
  case 0x48: // device_set_position
  case 0x4a: // adjust_grenades
  case 0x4b: // submit_incident
  case 0x4c: // submit_incident_with_custom_value
  case 0x4d: // set_loadout_palette
  case 0x4e: // device_set_position_track
  case 0x4f: // device_animate_position
  case 0x50: // device_set_position_immediate
  case 0x52: // respawn_zone_enable
  case 0x53: // player_get_weapon
  case 0x55: // object_set_never_garbage
  case 0x56: // player_get_target_object
  case 0x57: // create_tunnel
  case 0x5a: // player_set_coop_spawning
  case 0x60: // get_random_object
  case 0x62: // boundary_set_player_color
  }
  return false;
}

