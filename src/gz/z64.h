#ifndef Z64_H
#define Z64_H
#include <stdint.h>
#include <n64.h>

#define Z64_OOT10             0x00
#define Z64_OOT11             0x01
#define Z64_OOT12             0x02
#define Z64_OOTDEBUG          0x03
#define Z64_MMU               0x04

#ifndef Z64_VERSION
#define Z64_VERSION           Z64_OOT10
#endif

#define Z64_SCREEN_WIDTH      320
#define Z64_SCREEN_HEIGHT     240

#define Z64_SEG_PHYS          0x00
#define Z64_SEG_TITLE         0x01
#define Z64_SEG_SCENE         0x02
#define Z64_SEG_ROOM          0x03
#define Z64_SEG_KEEP          0x04
#define Z64_SEG_SKEEP         0x05
#define Z64_SEG_OBJ           0x06
#define Z64_SEG_ZIMG          0x0E
#define Z64_SEG_CIMG          0x0F

typedef struct
{
  float x;
  float y;
  float z;
} z64_xyz_t;

typedef uint16_t z64_angle_t;
typedef struct
{
  z64_angle_t x;
  z64_angle_t y;
  z64_angle_t z;
} z64_rot_t;

typedef enum
{
  Z64_ITEMBTN_B,
  Z64_ITEMBTN_CL,
  Z64_ITEMBTN_CD,
  Z64_ITEMBTN_CR,
} z64_itembtn_t;

typedef struct
{
  uint32_t seg[16];
} z64_stab_t;

typedef struct
{
  uint8_t       scene_index;
  uint8_t       entrance_index;
  union
  {
    uint16_t    variable;
    struct
    {
      uint16_t  transition_out  : 7;
      uint16_t  transition_in   : 7;
      uint16_t  unk_00_         : 1;
      uint16_t  continue_music  : 1;
    };
  };
} z64_entrance_table_t;

typedef struct
{
  Gfx      *poly_opa_disp_w;      /* 0x0000 */
  Gfx      *poly_xlu_disp_w;      /* 0x0004 */
  char      unk_00_[0x0008];      /* 0x0008 */
  Gfx      *overlay_disp_w;       /* 0x0010 */
  char      unk_01_[0x00A4];      /* 0x0014 */
  Gfx      *work_disp_c;          /* 0x00B8 */
  size_t    work_disp_c_size;     /* 0x00BC */
  char      unk_02_[0x00F0];      /* 0x00C0 */
  Gfx      *work_disp_w;          /* 0x01B0 */
  size_t    work_disp_size;       /* 0x01B4 */
  Gfx      *work_disp;            /* 0x01B8 */
  Gfx      *work_disp_p;          /* 0x01BC */
  Gfx      *work_disp_e;          /* 0x01C0 */
  char      unk_03_[0x00E4];      /* 0x01C4 */
  size_t    overlay_disp_size;    /* 0x02A8 */
  Gfx      *overlay_disp;         /* 0x02AC */
  Gfx      *overlay_disp_p;       /* 0x02B0 */
  Gfx      *overlay_disp_e;       /* 0x02B4 */
  size_t    poly_opa_disp_size;   /* 0x02B8 */
  Gfx      *poly_opa_disp;        /* 0x02BC */
  Gfx      *poly_opa_disp_p;      /* 0x02C0 */
  Gfx      *poly_opa_disp_e;      /* 0x02C4 */
  size_t    poly_xlu_disp_size;   /* 0x02C8 */
  Gfx      *poly_xlu_disp;        /* 0x02CC */
  Gfx      *poly_xlu_disp_p;      /* 0x02D0 */
  Gfx      *poly_xlu_disp_e;      /* 0x02D4 */
  size_t    frame_count_1;        /* 0x02D8 */
  void     *frame_buffer;         /* 0x02DC */
  char      unk_04_[0x0008];      /* 0x02E0 */
  size_t    frame_count_2;        /* 0x02E8 */
                                  /* 0x02EC */
} z64_gfx_t;

typedef union
{
  struct
  {
    uint32_t a  : 1;
    uint32_t b  : 1;
    uint32_t z  : 1;
    uint32_t s  : 1;
    uint32_t du : 1;
    uint32_t dd : 1;
    uint32_t dl : 1;
    uint32_t dr : 1;
    uint32_t    : 2;
    uint32_t l  : 1;
    uint32_t r  : 1;
    uint32_t cu : 1;
    uint32_t cd : 1;
    uint32_t cl : 1;
    uint32_t cr : 1;
    int32_t  x  : 8;
    int32_t  y  : 8;
  };
  uint16_t pad;
  uint32_t data;
} z64_controller_t;

typedef struct
{
  z64_controller_t  ctrl;
  char              unk_00_[0x0014];
} z64_input_t;

typedef struct
{
  z64_gfx_t      *gfx;                    /* 0x0000 */
  void           *state_main;             /* 0x0004 */
  void           *state_dtor;             /* 0x0008 */
  void           *next_ctor;              /* 0x000C */
  uint32_t        next_size;              /* 0x0010 */
  z64_input_t     input[4];               /* 0x0014 */
  size_t          state_heap_size;        /* 0x0074 */
  void           *state_heap;             /* 0x0078 */
  void           *heap_start;             /* 0x007C */
  void           *heap_end;               /* 0x0080 */
  void           *state_heap_node;        /* 0x0084 */
  char            unk_00_[0x0010];        /* 0x0088 */
  int32_t         state_continue;         /* 0x0098 */
  int32_t         state_frames;           /* 0x009C */
  uint32_t        unk_01_;                /* 0x00A0 */
                                          /* 0x00A4 */
} z64_ctxt_t;

typedef struct
{
  /* file loading params */
  uint32_t      vrom_addr;
  void         *dram_addr;
  size_t        size;
  /* unknown, seem to be unused */
  void         *unk_00_;
  uint32_t      unk_01_;
  uint32_t      unk_02_;
  /* completion notification params */
  OSMesgQueue  *notify_queue;
  OSMesg        notify_message;
} z64_getfile_t;

#if Z64_VERSION == Z64_MMU
#include "z64_mm.h"
#else
#include "z64_oot.h"
#endif

/* function prototypes */
typedef void (*z64_UpdateItemButton_proc) (z64_game_t *ctxt, int button_index);
typedef void (*z64_UpdateEquipment_proc)  (z64_game_t *ctxt, z64_link_t *link);
typedef void (*z64_LoadRoom_proc)         (z64_game_t *ctxt,
                                           void *p_ctxt_room_index,
                                           uint8_t room_index);
typedef void (*z64_UnloadRoom_proc)       (z64_game_t *ctxt,
                                           void *p_ctxt_room_index);
typedef void (*z64_Io_proc)               (uint32_t dev_addr, void *dram_addr,
                                           size_t size, int32_t direction);
typedef void (*z64_SceneConfig_proc)      (z64_game_t *ctxt);

/* data */
#define z64_file_mq             (*(OSMesgQueue*)      z64_file_mq_addr)
#define z64_vi_counter          (*(uint32_t*)         z64_vi_counter_addr)
#define z64_stab                (*(z64_stab_t*)       z64_stab_addr)
#define z64_scene_table         ( (z64_scene_table_t*)z64_scene_table_addr)
#define z64_day_speed           (*(uint16_t*)         z64_day_speed_addr)
#define z64_entrance_table      ( (z64_entrance_table_t*)                     \
                                   z64_entrance_table_addr)
#define z64_scene_config_table  ( (z64_SceneConfig_proc*)                     \
                                   z64_scene_config_table_addr)
#define z64_file                (*(z64_file_t*)       z64_file_addr)
#define z64_input_direct        (*(z64_controller_t*) z64_input_direct_addr)
#define z64_gameinfo            (*                    z64_file.gameinfo)
#define z64_ctxt                (*(z64_ctxt_t*)       z64_ctxt_addr)
#define z64_game                (*(z64_game_t*)      &z64_ctxt)
#define z64_link                (*(z64_link_t*)       z64_link_addr)

/* functions */
#define z64_osSendMesg          ((osSendMesg_t)       z64_osSendMesg_addr)
#define z64_osRecvMesg          ((osRecvMesg_t)       z64_osRecvMesg_addr)
#define z64_osCreateMesgQueue   ((osCreateMesgQueue_t)                        \
                                 z64_osCreateMesgQueue_addr)
#define z64_UpdateItemButton    ((z64_UpdateItemButton_proc)                  \
                                                      z64_UpdateItemButton_addr)
#define z64_UpdateEquipment     ((z64_UpdateEquipment_proc)                   \
                                                      z64_UpdateEquipment_addr)
#define z64_LoadRoom            ((z64_LoadRoom_proc)  z64_LoadRoom_addr)
#define z64_UnloadRoom          ((z64_UnloadRoom_proc)                        \
                                                      z64_UnloadRoom_addr)
#define z64_Io                  ((z64_Io_proc)        z64_Io_addr)

#endif
