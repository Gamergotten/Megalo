


// 0x00007FFA36700000
// 0x1c7954

// 0x00007FFC55F50000
// 0x1c795d

long 


struct the_mega_struct // sizeof = 
{
   long*[63] pointers; // 504 bytes long

   // game_state = pointers[gamestate_pindex]
}

template<typename T> struct array_of<T> // size_of = 0x70 (excluding the array elements)
{
   char[32] Header; // 0x00
   int struct_size; // 0x20
   int unknown; //0x24
   char[4] odd_signature; // 0x28
   int maximum_elements; // 0x2C
   char[4] unknown; // 0x30
   int unknown; // 0x34
   long* functions_pointer; // 0x38
   int last_modified; // 0x40
   int max_length; // 0x44
   int current_length; // 0x48

   uint unknown; // 0x4C
   T[maximum_elements]* array_pointer; // 0x50
   long* end_array_pointer; // 0x58

   int size_of_self; // 0x60
   int unknown; // 0x64

   int overall_size; // 0x68 // this includes the 112 bytes from this struct
   int unknown; //0x6C
}
// somewhere in the debug build, it just dumps a list of all the address/types, that could be referenced here
struct gamestate // sizeof = 4096?
{
   long* unknown; // 0x0 // was null
   array_of<object_wrapper>* objects; // 0x8 
   long* actor; // 0x10
   array_of<player_data>* players; // 0x18
   MegaloStuff megalo_stuff; // 0x20 // unknown
   long unknown;
   long* unknown;
   long* prop_reg;
   long* det_hs_thread; // "det.hs.thread"
   long* squad;
   long* ActiveGamemode; // this is a pointer to the actual gamemode
   long* prop;
   long* unknown;
   long* effect;
   long* command_scripts; // "command scripts"
   long* unknown;
   long unknown; // looks like its a couple of shorts
   long* unknown; // null
   long* unknown; // looks like a blank type structure
   long* unknown; // null
   long* unknownlist; 
   long* unknown; // sits just above the 'players'
   long* clump;
   long* flocks;
   long* unknown;
   long* unknown; // null
   long* unknown; // null
   long* performance;
   long* unknown;
   long* unknown;
   long* sim_object_glue; // "sim. object glue"
   long* effect_event; // "effect event"
   long* stimulas_data; // "stimulas-data"
   long* lights;
   long* boids;
   long* unknown;
   long* unknown;
   long* unknown;
   long* unknown;
   long* fire_team; // "fire team"
   long* unknown; // null
   long* unknown;
   long* unknown;
   long* xuid_related; // spotted an xuid in this struct
   long* unknown;
   long* unknown; // null
   long* unknown;
   long* joint_state; // "joint state"
   long* ai_directives; // "ai directives"
   long* collision_hierarchy_node_header; // "collision hierarchy node header"
   long* unknown;
   long* unknown;
   long* recycling_group; 
   long* unknown;
   long* effect_location; // "effect location"
   long* unknown;
   long* unknown;
   long* vocalization_records; // "vocalization records"
   long* impacts;
   long* unknown;
   long* unknown;
   long* collision_hierarchy_element_hea; // "collision hierarchy element hea"
   long* unknown; // null
   long* unknown;
   long* unknown;
   long* unknown; // null
   long* unknown;
   long* device_groups; // "device groups"
   long* unknown; // null
   long* unknown;
   long* objectives;
   long* swarm;
   long* ai_sync_action_arranger;
   long* unknown;
   long* cloth;
   long* unknown; // null
   long* unknown; 
   long* unknown;
   long* unknown;
   long* squad_group; // "squad group"
   long* breakable_surface_set_broken_ev; // "breakable surface set broken ev"
   long* unknown;
   long* unknown; // null
   long* unknown;
   long* widget;
   long* unknown;
   long* unknown; // null
   long* unknown; // null
   long* squad_patrol; 
   long* leaf_system; // "leaf system"
   long* unknown;
   long* havok_proxies; // "havok proxies"
   long* unknown;
   long* dynamic_firing_points; // "dynamic firing points"
   long* unknown;
   long* unknown; // null
   long* unknown; // null
   long* unknown; // null
   long* tracking;
   long* stimulus_ref; // "stimulus-ref"
   long* unknown; // null
   long* screen_effect;
   long* unknown; // null
   long* unknown;
   long unknown; // 2 4bytes
   long* path_influence;
   long* prop_search;
   long* loop__objects; // not the same structure as the rest of them
   long* unknown;
   long* unknown; // null
   long* effect_geometry_sample; // "effect geometry sample"
   long* object_list_header; // "object list header"
   long* hs_globals; // "hs globals"
   long* formations;
   long* unknown; // null
   long* cheap_particle_emitters;
   long* unknown;
   long* antenna;
   long* unknown;
   long* unknown;
   long* unknown;
   long* unknown; // null
   long* unknown;
   long* unknown; // null
   long* unknown; // null
   long* unknown; // null
   long* impact_arrarys; // "impact arrarys"
   long* unknown;
   long* unknown; // null
   long* water_physics_cache; // "water physics cache"
   long* unknown;
   long* unknown;
   long* unknown; // null
   long* shield_render_cache_message;
   long* unknown; // null
   long* unknown; // null
   long* unknown; // null
   long* ragdolls;
   long* lasing;
   long* unknown;
   long* ai_cue;
   long* character_properties_cache; // "character properties cache"
   long* unknown; // null
   long* unknown; // null
   long* unknown;
   long* unknown;
   long* unknown;
   long* object_activation_regions; // "object activation regions"
   long* unknown; // just above the "object" table
   long* unknown; // null
   long* unknown; // null
   long* recorded_animations; // "recorded animations"
   long* unknown;
   long* unknown; // null
   long* unknown; // null
   long* unknown; // null
   long* unknown; // null
   long* megalo_objects;
   long* unknown;
   long* unknown;
   long* unknown;
   long* unknown;
   long* unknown; // null
   long* list_object_reference; // "list object reference"
   long* unknown; // null
   long* unknown;
   long* unknown;
   long* unknown;
   long* unknown;
   long* unknown;
   long* unknown;
   long* performance_runtime_definition;
   long* unknown;
   long* unknown;
   long* non_det_hs_thread; // "non-det hs thread"
   long* unknown;
   long* unknown;
   long* unknown;
   long* unknown;
   long* unknown;
   long* unknown; // null
   long* unknown;
   long* unknown; // null
   long* unknown;
   long* unknown;
   long* unknown; // just above the "prop" table
   long* unknown;
   long* unknown; // just above the "impact arrarys" table
   long* unknown;
   long* unknown;
   long* unknown;
   long* unknown;
   long* unknown;
   long* unknown; // null
   long* unknown; // null
   long* unknown;
   long* unknown; // just above the "fire team" label
   long* unknown;
   long* unknown;
   long* unknown; // null
   long* unknown;
   long* unknown;
   long* unknown;
   long* unknown;
   long* unknown;
   long* unknown;
   long* unknown; // null
   long* unknown;
   long* unknown; // something "!dar" - point of interest
   long* unknown; // null
   long* unknown; // null
   long* unknown;
   long* unknown;
   long* unknown;
   long* chud_widgets0; // "chud widgets[0]"
   long* chud_widgets1; // "chud widgets[1]"
   long* chud_widgets2; // "chud widgets[2]"
   long* chud_widgets3; // "chud widgets[3]"
   long* unknown;
   long* MapPointer; // somewhere it says "levels\multi\50_panopticon\50_panopticon" - point of interest
   long* unknown;
   long* unknown; // null
   long* unknown; // null
   long* unknown;
   long* unknown;
   long* unknown; // null
   long* unknown;
   // everything beyond this is mostly just nulls or incomprehensible
}
struct MegaloStuff 
{
   game_object current_object; // 0x168
   uint current_player; // 0x16C
   uint current_team; //0x170

   game_object[] objects_with_labels_table; // 0x1360

}
struct megalotable
{
	int ConditionCount; // 0xf08

}


struct player_data // sizeof = 0x558
{
   int unknown; // 0x000
   int unknown; // 0x004
   long xuid; // 0x008
   //
   game_object biped; // 0x028 
   // 
   string16[32] gamertag; // 0x0B0
   long xuid; // 0x0D0
   //
   string16[8] servicetag; // 0x0F4
   // very incomplete
}
struct object_wrapper // sizeof = 0x18
{
   short unique_id; // 0x00
   short object_type; // 0x02
   short child_type; // 0x04
   char[2] unk_identifiers; // 0x04
   long object_data_offset; // 0x08
   // this can refer to several different classes of objects, so you literally need the structs for each of those
   long* object_data; // 0x10
}
struct object_data // sizeof = 
{
   char garbage_collection_disabled; // 0x147
   short* something_ptr; // 0x196
}
struct object_data::biped_data // sizeof = 0x4830 // object_wrapper.child_type = 0
{
   int Owner_player; // 0x1CC
   char Frag_grenades; // 0x37E
   char Plasma_grenades; // 0x37F
}

/////////////////////////
// GAME MEGALO STRUCTS //
/////////////////////////
struct game_object // sizeof = 0x4
{
   ushort index; // 0x0
   ushort id; // 0x2
}
struct string_token // 4 bytes
{
   char param3;
   char param2;
   char param1;
   char var_type; // is two incremented from what it would be in megalo code
}
struct player_set // 8 bytes
{
   int player_set_type;
   int set_players;
}
struct team_ref // 1 byte
{
   char team_ID;
}
struct timer_ref // 4 bytes
{
   int24 time; // is multiplied by 1200 of the timers actual number
   char rate; // enum type
}
struct player_ref // 1 byte
{
   char player_ID;
}

struct megalo_object // 132 bytes
{
   ushort index; // 0x00
   ushort fireteam_spawn_perms;   // 0x02

   string_token waypoint_token1;  // 0x04
   string_token waypoint_token2;  // 0x08
   short waypoint_string_index;   // 0x0C

   short waypoint_icon;     // 0x0E
   player_set waypoint_vis; // 0x10
   char waypoint_priority;  // 0x18
   char waypoint_timer;     // 0x19
   char waypoint_min_range; // 0x1A
   char waypoint_max_range; // 0x1B

   player_set pickup_perms; // 0x1C
   player_set spawn_perms;  // 0x24

   player_set boundary_vis_perms; // 0x2C
   int boundary_player_color;     // 0x34

   game_object object_identifier; // 0x38

   game_object[4] objects; // 0x3C - 0x4B
   team_ref[2] teams;      // 0x4C - 0x4D
   short[8] numbers;       // 0x4E - 0x5D
   int16 unknown2byte;     // 0x5E
   timer_ref[4] timers;    // 0x60 - 0x6F
   player_ref[4] players;  // 0x70 - 0x73

   int tick_thing;                // 0x74
   player_set progress_bar_perms; // 0x78
   int unknown_or_padding;        // 0x80
}