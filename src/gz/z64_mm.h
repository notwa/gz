// NOTE: everything is a little different between J 1.0/1.1, and future versions
#define Z64_ETAB_LENGTH       0x09B8

typedef enum
{
  Z64_ITEM_NULL2 = -3, // sometimes used for B button
  Z64_ITEM_NULL = -1,

  Z64_ITEM_OCARINA,
  Z64_ITEM_BOW,
  Z64_ITEM_FIRE_ARROWS,
  Z64_ITEM_ICE_ARROWS,
  Z64_ITEM_LIGHT_ARROWS,
  Z64_ITEM_UNUSED0, // "Fairy Ocarina" acts like Pictobox
  Z64_ITEM_BOMBS,
  Z64_ITEM_BOMBCHU,
  Z64_ITEM_DEKU_STICK,
  Z64_ITEM_DEKU_NUT,
  Z64_ITEM_MAGIC_BEANS,
  Z64_ITEM_UNUSED1, // "Longshot" acts like Pictobox
  Z64_ITEM_POWDER_KEG,
  Z64_ITEM_PICTOGRAPH,
  Z64_ITEM_LENS_OF_TRUTH,
  Z64_ITEM_HOOKSHOT,
  Z64_ITEM_FAIRY_SWORD,
  Z64_ITEM_UNUSED2, // "Fairy's Slingshot" acts like Pictobox

  Z64_ITEM_EMPTY_BOTTLE,
  Z64_ITEM_RED_POTION,
  Z64_ITEM_GREEN_POTION,
  Z64_ITEM_BLUE_POTION,
  Z64_ITEM_FAIRY,
  Z64_ITEM_DEKU_PRINCESS,
  Z64_ITEM_MILK_FULL,
  Z64_ITEM_MILK_HALF,
  Z64_ITEM_FISH,
  Z64_ITEM_BUGS,
  Z64_ITEM_BLUE_FIRE, // acts like bugs
  Z64_ITEM_POE,
  Z64_ITEM_BIG_POE,
  Z64_ITEM_SPRING_WATER,
  Z64_ITEM_HOT_SPRING_WATER,
  Z64_ITEM_ZORA_EGG,
  Z64_ITEM_GOLD_DUST,
  Z64_ITEM_MAGICAL_MUSHROOM,
  Z64_ITEM_SEA_HORSE,
  Z64_ITEM_CHATEAU_ROMANI,
  Z64_ITEM_HYLIAN_LOACH, // "This item doesn't seem to work here..."
  Z64_ITEM_OBABAS_DRINK, // acts like Poe

  Z64_ITEM_MOONS_TEAR,
  Z64_ITEM_LAND_TITLE_DEED,
  Z64_ITEM_SWAMP_TITLE_DEED,
  Z64_ITEM_MOUNTAIN_TITLE_DEED,
  Z64_ITEM_OCEAN_TITLE_DEED,
  Z64_ITEM_ROOM_KEY,
  Z64_ITEM_SPECIAL_DELIVERY,
  Z64_ITEM_LETTER_TO_KAFEI,
  Z64_ITEM_PENDANT_OF_MEMORIES,
  Z64_ITEM_UNUSED3,

  Z64_ITEM_MASK_DEKU,
  Z64_ITEM_MASK_GORON,
  Z64_ITEM_MASK_ZORA,
  Z64_ITEM_MASK_FIERCE_DEITY,
  Z64_ITEM_MASK_TRUTH,
  Z64_ITEM_MASK_KAFEI,
  Z64_ITEM_MASK_ALL_NIGHT,
  Z64_ITEM_MASK_BUNNY,
  Z64_ITEM_MASK_KEATON,
  Z64_ITEM_MASK_GAROS,
  Z64_ITEM_MASK_ROMANI,
  Z64_ITEM_MASK_TROUPE_LEADER,
  Z64_ITEM_MASK_POSTMAN,
  Z64_ITEM_MASK_COUPLES,
  Z64_ITEM_MASK_GREAT_FAIRY,
  Z64_ITEM_MASK_GIBDO,
  Z64_ITEM_MASK_DON_GERO,
  Z64_ITEM_MASK_KAMARO,
  Z64_ITEM_MASK_CAPTAINS,
  Z64_ITEM_MASK_STONE,
  Z64_ITEM_MASK_BREMEN,
  Z64_ITEM_MASK_BLAST,
  Z64_ITEM_MASK_SCENTS,
  Z64_ITEM_MASK_GIANTS,

  Z64_ITEM_KOKIRI_SWORD       = 0x4D,
  Z64_ITEM_RAZOR_SWORD        = 0x4E,
  Z64_ITEM_GILDED_SWORD       = 0x4F,
} z64_item_t;

typedef enum
{
  Z64_SLOT_NONE = -1,

  Z64_SLOT_OCARINA,
  Z64_SLOT_BOW,
  Z64_SLOT_FIRE_ARROWS,
  Z64_SLOT_ICE_ARROWS,
  Z64_SLOT_LIGHT_ARROWS,
  Z64_SLOT_EVENT_1,
  Z64_SLOT_BOMBS,
  Z64_SLOT_BOMBCHU,
  Z64_SLOT_DEKU_STICK,
  Z64_SLOT_DEKU_NUT,
  Z64_SLOT_MAGIC_BEANS,
  Z64_SLOT_EVENT_2,
  Z64_SLOT_POWDER_KEG,
  Z64_SLOT_PICTOGRAPH,
  Z64_SLOT_LENS_OF_TRUTH,
  Z64_SLOT_HOOKSHOT,
  Z64_SLOT_FAIRY_SWORD,
  Z64_SLOT_EVENT_3,
  Z64_SLOT_BOTTLE_1,
  Z64_SLOT_BOTTLE_2,
  Z64_SLOT_BOTTLE_3,
  Z64_SLOT_BOTTLE_4,
  Z64_SLOT_BOTTLE_5,
  Z64_SLOT_BOTTLE_6,

  Z64_SLOT_MASK_POSTMAN,
  Z64_SLOT_MASK_ALL_NIGHT,
  Z64_SLOT_MASK_BLAST,
  Z64_SLOT_MASK_STONE,
  Z64_SLOT_MASK_GREAT_FAIRY,
  Z64_SLOT_MASK_DEKU,
  Z64_SLOT_MASK_KEATON,
  Z64_SLOT_MASK_BREMEN,
  Z64_SLOT_MASK_BUNNY,
  Z64_SLOT_MASK_DON_GERO,
  Z64_SLOT_MASK_SCENTS,
  Z64_SLOT_MASK_GORON,
  Z64_SLOT_MASK_ROMANI,
  Z64_SLOT_MASK_TROUPE_LEADER,
  Z64_SLOT_MASK_KAFEI,
  Z64_SLOT_MASK_COUPLES,
  Z64_SLOT_MASK_TRUTH,
  Z64_SLOT_MASK_ZORA,
  Z64_SLOT_MASK_KAMARO,
  Z64_SLOT_MASK_GIBDO,
  Z64_SLOT_MASK_GAROS,
  Z64_SLOT_MASK_CAPTAINS,
  Z64_SLOT_MASK_GIANTS,
  Z64_SLOT_MASK_FIERCE_DEITY,
} z64_slot_t;

typedef struct
{ // 803824D0
  // update_rate has been moved to z64_game_t in MM
  char      unk_00_[0x0B52];
  int16_t   minimap_disabled;
} z64_gameinfo_t;

typedef struct
{
  int32_t         entrance_index;     /* 0x0000 */
  char            wearing_mask;
  char            opening_flag; // Has completed intro
  char            text_skip_timer; // Prevents skipping text for a period

  char            unknown0; // Something to do with picking up items?

  int16_t         cutscene_index;
  uint16_t        time_of_day;
  uint16_t        owl_id;
  uint32_t        day_night;
  int32_t         time_speed;
  uint32_t        day;
  uint32_t        days_elapsed;
  char            transformation;

  char            unknown1; // spring_flag?

  char            have_tatl; // boolean
  char            owl_save; // boolean
  char            file_validation[6];
  uint16_t        song_of_time_count;
  char            file_name[8];
  uint16_t        heart_containers; // 0x10 per heart
  uint16_t        health; // 0x10 per heart
  char            magic_meter_size;
  char            magic; // 0x30 for normal, 0x60 for double
  uint16_t        rupees;
  uint32_t        navi_timer;
  char            has_normal_magic; // boolean
  char            has_double_magic; // boolean
  uint16_t        double_defense; // boolean? actually seems unused in MM

  uint16_t        unknown2;

  union {
    uint16_t      owls_hit;
    struct
    {
      uint16_t    owl_hidden            : 1;
      uint16_t                          : 5;
      uint16_t    owl_stone_tower       : 1;
      uint16_t    owl_ikana_canyon      : 1;
      uint16_t    owl_southern_swamp    : 1;
      uint16_t    owl_woodfall          : 1;
      uint16_t    owl_milk_road         : 1;
      uint16_t    owl_clock_town        : 1;
      uint16_t    owl_mountain_village  : 1;
      uint16_t    owl_snowhead          : 1;
      uint16_t    owl_zora_cape         : 1;
      uint16_t    owl_great_bay_coast   : 1;
    };
  };

  uint32_t        unknown3;

  int8_t          button_items[4];
  int8_t          button_items_goron[4];
  int8_t          button_items_zora[4];
  int8_t          button_items_deku[4];
  //ZSaveItemsEquipped items_human; // also used for fierce deity
  //ZSaveItemsEquipped items_goron;
  //ZSaveItemsEquipped items_zora;
  //ZSaveItemsEquipped items_deku;
  char unused; // this is where the b button slot would be
  int8_t          c_button_slots[3];

  uint32_t unknown4;
  uint32_t unknown5;
  uint32_t unknown6;

  union
  {
    uint16_t      equips;
    struct
    {
      uint16_t    equip_boots         : 4;
      uint16_t    equip_tunic         : 4;
      uint16_t    equip_shield        : 4;
      uint16_t    equip_sword         : 4;
    };
  };

  uint16_t unknown7;

  int8_t          items[24];
  uint8_t         ammo[24];

  union
  {
    uint32_t      equipment_items;
    struct
    {
      uint32_t                        : 9;
      uint32_t    nut_upgrade         : 3;
      uint32_t    stick_upgrade       : 3;
      uint32_t    bullet_bag          : 3;
      uint32_t    wallet              : 2;
      uint32_t    diving_upgrade      : 3;
      uint32_t    strength_upgrade    : 3;
      uint32_t    bomb_bag            : 3;
      uint32_t    quiver              : 3;
    };
  };

  union
  {
    uint32_t      quest_items;
    struct
    {
      uint32_t    heart_pieces        : 4;
      uint32_t    unused0             : 3;
      uint32_t    song_lullaby_intro  : 1;
      uint32_t    unused1             : 4;
      uint32_t    unknown             : 1; // TODO
      uint32_t    bombers_notebook    : 1;
      uint32_t    suns_song           : 1;
      uint32_t    song_of_storms      : 1;
      uint32_t    song_of_soaring     : 1;
      uint32_t    eponas_song         : 1;
      uint32_t    song_of_healing     : 1;
      uint32_t    song_of_time        : 1;
      uint32_t    sarias_song         : 1;
      uint32_t    oath_to_order       : 1;
      uint32_t    elegy_of_emptiness  : 1;
      uint32_t    new_wave_bossa_nova : 1;
      uint32_t    goron_lullaby       : 1;
      uint32_t    sonata_of_awakening : 1;
      uint32_t    unused2             : 2;
      uint32_t    remains_twinmold    : 1;
      uint32_t    remains_gyorg       : 1;
      uint32_t    remains_goht        : 1;
      uint32_t    remains_odolwa      : 1;
    };
  };

  union
  {
    uint8_t       items;
    struct
    {
      uint8_t                         : 5;
      uint8_t     map                 : 1;
      uint8_t     compass             : 1;
      uint8_t     boss_key            : 1;
    };
  }               dungeon_items[10];
  int8_t          dungeon_keys[9];
  uint8_t         defense_hearts;     /* 0x00CF */
  int8_t          fairies[10];

  char unknown_name0[8];
  char unknown_name1[8];
  char unknown_name2[8];

  char unknown9[0x37A];

  struct
  {
    uint32_t      scene_flags_1;
    uint32_t      scene_flags_2;
    uint32_t      scene_flags_3;
    uint32_t      scene_flags_4;
    uint32_t      scene_flags_5;
    uint32_t      scene_flags_6;
  }               scene_flags[120];

  char unknown10[0xAA];

  char pictograph_special;
  char pictograph_quality;
  char pictograph_unknown;

  char unknown11[0x27];

  char minimaps[7*4];

  uint16_t skulltulas_woodfall;
  uint16_t skulltulas_great_bay;

  char unknown12[0x1A];

  uint16_t banked_rupees;

  char unknown13[0x18];

  char week_event_reg[100];

  char area_arrival[4];
  char cloud_clear[4];

  uint16_t scarecrows_song_acquired;
  uint8_t scarecrows_song[0x80];

  char bombers_caught;
  char bombers_order[5];
  char lottery_codes[3];
  char spider_house_mask_order[6];
  char bombers_code[5];

  uint16_t epona_scene;
  int16_t epona_x;
  int16_t epona_y;
  int16_t epona_z;
  int16_t epona_angle;
  uint16_t checksum;

/*
  char            unk_0E_[0x0003];
  int8_t          file_index;
  char            unk_0F_[0x0004];
  int32_t         interface_flag;
  uint32_t        scene_setup_index;
  int32_t         void_flag;
  char            unk_10_[0x0010];
  int16_t         void_entrance;
  char            unk_11_[0x0002];
  uint32_t        temp_switch_flags;
  uint32_t        unk_flags_4;
  char            unk_12_[0x0044];
  uint16_t        nayrus_love_timer;
  char            unk_13_[0x0004];
  int16_t         timer_1_state;
  int16_t         timer_1_value;
  int16_t         timer_2_state;
  int16_t         timer_2_value;
  char            unk_14_[0x000A];
  int8_t          seq_index;
  char            unk_15_[0x0022];
  uint8_t         minimap_index;
  int16_t         minigame_state;
  char            unk_16_[0x0003];
  uint8_t         language;
  char            unk_17_[0x0002];
  uint8_t         z_targeting;
  char            unk_18_[0x0001];
  uint16_t        disable_music_flag;
  char            unk_19_[0x0020];
  z64_gameinfo_t *gameinfo;
  char            unk_1A_[0x001C];
*/
} z64_file_t;

typedef struct
{
  uint32_t scene_vrom_start;
  uint32_t scene_vrom_end;
  uint32_t title_vrom_start;
  uint32_t title_vrom_end;
  char     unk_00_;
  uint8_t  scene_config;
  char     unk_01_;
  char     padding_00_;
} z64_scene_table_t;

typedef struct z64_actor_s z64_actor_t;
struct z64_actor_s
{
/*
  uint16_t      actor_index;
  uint8_t       actor_type;
  int8_t        room_index;
  char          unk_00_[0x0004];
  z64_xyz_t     pos_1;
  z64_rot_t     rot_init;
  char          unk_01_[0x0002];
  uint16_t      actor_variable;
  uint8_t       alloc_index;
  char          unk_02_;
  uint16_t      sound_effect;
  char          unk_03_[0x0002];
  z64_xyz_t     pos_2;
  char          unk_04_[0x0002];
  uint16_t      xz_dir;
  char          unk_05_[0x0004];
  z64_xyz_t     pos_3;
  z64_rot_t     rot_1;
  char          unk_06_[0x0002];
  float         unk_07_;
  z64_xyz_t     scale;
  z64_xyz_t     vel_1;
  float         xz_speed;
  float         gravity;
  float         min_vel_y;
  void         *unk_08_;
  void         *unk_09_;
  char          unk_0A_[0x001C];
  void         *damage_table;
  z64_xyz_t     vel_2;
  char          unk_0B_[0x0006];
  int16_t       health;
  char          unk_0C_;
  uint8_t       damage_effect;
  char          unk_0D_[0x0002];
  z64_rot_t     rot_2;
  char          unk_0E_[0x0046];
  z64_xyz_t     pos_4;
  uint16_t      unk_0F_;
  uint16_t      text_id;
  int16_t       actor_frozen;
  char          unk_10_[0x0003];
  uint8_t       actor_active;
  char          unk_11_[0x0002];
  z64_actor_t  *unk_12_;
  char          unk_13_[0x0004];
  z64_actor_t  *actor_prev;
  z64_actor_t  *actor_next;
  void         *unk_14_;
  void         *actor_init_proc;
  void         *actor_main_proc;
  void         *actor_draw_proc;
  void         *code_entry;
*/
};

typedef struct
{
  z64_actor_t common;
/*
  char        unk_00_[0x02F8];
  uint8_t     action;
  char        unk_01_[0x0237];
  uint32_t    state_flags_1;
  uint32_t    state_flags_2;
  char        unk_02_[0x01B4];
  float       linear_vel;
  char        unk_03_[0x0002];
  uint16_t    target_yaw;
  char        unk_04_[0x0054];
  int16_t     drop_y;
  int16_t     drop_distance;
*/
} z64_link_t;

typedef struct
{
  z64_ctxt_t      common;
  char            unk_00_[0xA2];
  uint8_t         update_rate;
  char            unk_01_;
  char            unk_02_[0];

  // at the moment, we only need the following:

  // for func command_break:
  //   camera_flag_1        /* 0x362 ? */
  //   camera_mode          /* 0x360 ? */
  //   cutscene_state
  //   event_flag
  //   textbox_state_1
  //   textbox_state_2
  //   textbox_state_3

  // for func command_loadmemfile:
  //   chest_flags          /* 0x1E58 ish */
  //   collectible_flags    /* 0x1E58 ish */
  //   room_clear_flags     /* 0x1E58 ish */
  //   switch_flags         /* 0x1E58 ish */

  // for func clear_csp_proc:
  //   cutscene_ptr

  // for func zu_execute_game:
  //   entrance_index

  // uncategorized:
  //   link_age
  //   no_rooms
  //   restriction_flags
  //   room_index
  //   room_ptr
  //   scene_index
  //   temp_switch_flags
  //   unk_flags_4

} z64_game_t;

#if Z64_VERSION == Z64_MMU

// dram addresses
#define z64_osSendMesg_addr                     0x80087B10 /*80001E20*/
#define z64_osRecvMesg_addr                     0x80087ED0 /*80002030*/
#define z64_osCreateMesgQueue_addr              0x8008F240 /*80004220*/
#define z64_file_mq_addr                        0x80099F50 /*80007D40*/
#define z64_vi_counter_addr                     0x8009E5BC /*80009E8C*/
// around 80117824 maybe?
#define z64_minimap_disable_1_addr              0 /*8006CD50*/
#define z64_minimap_disable_2_addr              0 /*8006D4E4*/
#define z64_UpdateItemButton_addr               0x8012E96C /*8006FB50*/
#define z64_UpdateEquipment_addr                0 /*80079764*/
#define z64_LoadRoom_addr                       0 /*80080A3C*/
#define z64_UnloadRoom_addr                     0 /*80080C98*/
#define z64_Io_addr                             0 /*80091474*/
#define z64_entrance_offset_hook_addr           0 /*8009AA44*/
#define z64_frame_update_func_addr              0 /*8009AF1C*/
#define z64_frame_update_call_addr              0 /*8009CAE8*/
#define z64_frame_input_func_addr               0 /*800A0BA0*/
#define z64_frame_input_call_addr               0 /*800A16AC*/
#define z64_day_speed_addr                      0 /*800F1650*/
#define z64_entrance_table_addr                 0x801C43B0 /*800F9C90*/
#define z64_scene_table_addr                    0x801C5720 /*800FB4E0*/
#define z64_scene_config_table_addr             0 /*800FBD18*/
#define z64_seq_pos_addr                        0 /*801043B0*/
#define z64_file_addr                           0 /*8011A5D0*/
#define z64_input_direct_addr                   0 /*8011D730*/
#define z64_stab_addr                           0 /*80120C38*/
#define z64_seq_buf_addr                        0 /*80124800*/
#define z64_ctxt_addr                           0 /*801C84A0*/
#define z64_link_addr                           0 /*801DAA30*/

// rom addresses
#define z64_icon_item_static_vaddr              0 /*007BD000*/
#define z64_icon_item_static_vsize              0 /*000888A0*/
#define z64_icon_item_24_static_vaddr           0 /*00846000*/
#define z64_icon_item_24_static_vsize           0 /*0000B400*/
#define z64_nes_font_static_vaddr               0 /*00928000*/
#define z64_nes_font_static_vsize               0 /*00004580*/
#define z64_parameter_static_vaddr              0 /*01A3C000*/
#define z64_parameter_static_vsize              0 /*00003B00*/

// context info
#define z64_ctxt_filemenu_ctor                  0 /*80812394*/
#define z64_ctxt_filemenu_size                  0 /*0001CAD0*/
#define z64_ctxt_game_ctor                      0 /*8009A750*/
#define z64_ctxt_game_size                      0 /*00012518*/

#endif
