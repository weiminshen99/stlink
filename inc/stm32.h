/*
 * File: stm32.h
 *
 * STM32-specific defines & identification parametres
 */

#ifndef STM32_H
#define STM32_H

/* Cortex-M core ids (CPUTAPID) */
#define STM32_CORE_ID_M3_F2_JTAG    0x0ba00477 // unused // F2 JTAG (RM0033 p.1326)
//#define STM32_CORE_ID_M33_JTAG      0x0ba04477 // unused // L5 JTAG
#define STM32_CORE_ID_M0            0x0bb11477 // unused // F0
#define STM32_CORE_ID_M0P           0x0bc11477 // unused // L0, G0
#define STM32_CORE_ID_M33           0x0be01477 // unused // L5 SWD (RM0351 p.2029)
#define STM32_CORE_ID_M33_JTAG      0x0be02477 // unused // L5 JTAG (RM0438 p.2029)
#define STM32_CORE_ID_M3_F1         0x1ba01477 // F1 (RM0008 p.1092)
#define STM32_CORE_ID_M4F_L4        0x1ba01477 // unused // L4 (RM0351 p.1845)
#define STM32_CORE_ID_M4F_F4        0x2ba01477 // unused // F4 (RM0090 p.1695)
#define STM32_CORE_ID_M4F_F4_JTAG   0x4ba00477 // unused // F4 JTAG (RM090 p.1691)
#define STM32_CORE_ID_M7_F7         0x5ba02477 // F7
#define STM32_CORE_ID_M7_H7         0x6ba02477 // H7
#define STM32_CORE_ID_M7_H7_JTAG    0x6ba00477 // H7 JTAG (RM0433 p.3065)

/* STM32 flash types */
// New flash type definitions must go before STM32_FLASH_TYPE_UNDEFINED
// with the latter updated to the highest enum value.
enum stm32_flash_type {
    STM32_FLASH_TYPE_UNKNOWN   =  0,
    STM32_FLASH_TYPE_F0_F1_F3  =  1,
    STM32_FLASH_TYPE_F1_XL     =  2,
    STM32_FLASH_TYPE_F2_F4     =  3,
    STM32_FLASH_TYPE_F7        =  4,
    STM32_FLASH_TYPE_G0        =  5,
    STM32_FLASH_TYPE_G4        =  6,
    STM32_FLASH_TYPE_H7        =  7,
    STM32_FLASH_TYPE_L0_L1     =  8,
    STM32_FLASH_TYPE_L4_L4P    =  9,
    STM32_FLASH_TYPE_L5_U5     = 10,
    STM32_FLASH_TYPE_WB_WL     = 11,
    STM32_FLASH_TYPE_UNDEFINED = 12, // max. value exceeded
};

/* STM32 chip-ids */
// See DBGMCU_IDCODE register (0xE0042000) in appropriate programming manual
// stm32 chipids, only lower 12 bits...

enum stm32_chipids {
    STM32_CHIPID_UNKNOWN                = 0x000,

    STM32_CHIPID_STM32_F1_MD            = 0x410, /* medium density */
    STM32_CHIPID_STM32_F2               = 0x411,
    STM32_CHIPID_STM32_F1_LD            = 0x412, /* low density */
    STM32_CHIPID_STM32_F4               = 0x413,
    STM32_CHIPID_STM32_F1_HD            = 0x414, /* high density */
    STM32_CHIPID_STM32_L4               = 0x415,
    STM32_CHIPID_STM32_L1_MD            = 0x416, /* medium density */
    STM32_CHIPID_STM32_L0               = 0x417,
    STM32_CHIPID_STM32_F1_CONN          = 0x418, /* connectivity line */
    STM32_CHIPID_STM32_F4_HD            = 0x419, /* high density */
    STM32_CHIPID_STM32_F1_VL_MD_LD      = 0x420, /* value line medium & low density */
    STM32_CHIPID_STM32_F446             = 0x421,
    STM32_CHIPID_STM32_F3               = 0x422,
    STM32_CHIPID_STM32_F4_LP            = 0x423,
    STM32_CHIPID_STM32_L0_CAT2          = 0x425,
    STM32_CHIPID_STM32_L1_MD_PLUS       = 0x427, /* medium density plus */
    STM32_CHIPID_STM32_F1_VL_HD         = 0x428, /* value line high density */
    STM32_CHIPID_STM32_L1_CAT2          = 0x429,
    STM32_CHIPID_STM32_F1_XLD           = 0x430, /* extra low density plus */
    STM32_CHIPID_STM32_F411xx           = 0x431,
    STM32_CHIPID_STM32_F37x             = 0x432,
    STM32_CHIPID_STM32_F4_DE            = 0x433,
    STM32_CHIPID_STM32_F4_DSI           = 0x434,
    STM32_CHIPID_STM32_L43x_L44x        = 0x435,
    STM32_CHIPID_STM32_L1_MD_PLUS_HD    = 0x436, /* medium density plus & high density */
    STM32_CHIPID_STM32_L152_RE          = 0x437,
    STM32_CHIPID_STM32_F334             = 0x438,
    STM32_CHIPID_STM32_F3xx_SMALL       = 0x439,
    STM32_CHIPID_STM32_F0               = 0x440,
    STM32_CHIPID_STM32_F412             = 0x441,
    STM32_CHIPID_STM32_F09x             = 0x442,
    STM32_CHIPID_STM32_F0xx_SMALL       = 0x444,
    STM32_CHIPID_STM32_F04              = 0x445,
    STM32_CHIPID_STM32_F303_HD          = 0x446, /* high density */
    STM32_CHIPID_STM32_L0_CAT5          = 0x447,
    STM32_CHIPID_STM32_F0_CAN           = 0x448,
    STM32_CHIPID_STM32_F7               = 0x449, /* Nucleo F746ZG board */
    STM32_CHIPID_STM32_H74xxx           = 0x450, /* RM0433, p.3189 */
    STM32_CHIPID_STM32_F76xxx           = 0x451,
    STM32_CHIPID_STM32_F72xxx           = 0x452, /* Nucleo F722ZE board */
    STM32_CHIPID_STM32_G0_CAT4          = 0x456, /* G051/G061 */
    STM32_CHIPID_STM32_L011             = 0x457,
    STM32_CHIPID_STM32_F410             = 0x458,
    STM32_CHIPID_STM32_G0_CAT2          = 0x460, /* G070/G071/G081 */
    STM32_CHIPID_STM32_L496x_L4A6x      = 0x461,
    STM32_CHIPID_STM32_L45x_L46x        = 0x462,
    STM32_CHIPID_STM32_F413             = 0x463,
    STM32_CHIPID_STM32_L41x_L42x        = 0x464,
    STM32_CHIPID_STM32_G0_CAT1          = 0x466, /* G030/G031/G041 */
    STM32_CHIPID_STM32_G0_CAT3          = 0x467, /* G0B1/G0C1 */
    STM32_CHIPID_STM32_G4_CAT2          = 0x468, /* RM0440, section 46.6.1 "MCU device ID code" */
    STM32_CHIPID_STM32_G4_CAT3          = 0x469,
    STM32_CHIPID_STM32_L4Rx             = 0x470, /* RM0432, p.2247, found on the STM32L4R9I-DISCO board */
    STM32_CHIPID_STM32_L4PX             = 0x471, /* RM0432, p.2247 */
    STM32_CHIPID_STM32_G4_CAT4          = 0x479,
    STM32_CHIPID_STM32_H7Ax             = 0x480, /* RM0455, p.2863 */
    STM32_CHIPID_STM32_H72x             = 0x483, /* RM0468, p.3199 */
    STM32_CHIPID_STM32_WB55             = 0x495,
    STM32_CHIPID_STM32_WLE              = 0x497,
};

/* Constant STM32 memory address */
#define STM32_SRAM_BASE            ((uint32_t)0x20000000)
#define STM32_FLASH_BASE           ((uint32_t)0x08000000)

#define STM32_F1_FLASH_BANK2_BASE  ((uint32_t)0x08080000)
#define STM32_H7_FLASH_BANK2_BASE  ((uint32_t)0x08100000)


/* Constant STM32 option bytes base memory address */
#define STM32_F4_OPTION_BYTES_BASE ((uint32_t)0x40023c14)

#define STM32_H7_OPTION_BYTES_BASE ((uint32_t)0x5200201c)

#define STM32_L0_OPTION_BYTES_BASE ((uint32_t)0x1ff80000)
#define STM32_L1_OPTION_BYTES_BASE ((uint32_t)0x1ff80000)

#define STM32_F7_OPTION_BYTES_BASE ((uint32_t)0x1fff0000)

#define STM32_G0_OPTION_BYTES_BASE ((uint32_t)0x1fff7800)
#define STM32_L4_OPTION_BYTES_BASE ((uint32_t)0x1fff7800)

#define STM32_F2_OPTION_BYTES_BASE ((uint32_t)0x1fffc000)

#define STM32_F0_OPTION_BYTES_BASE ((uint32_t)0x1ffff800)
#define STM32_F1_OPTION_BYTES_BASE ((uint32_t)0x1ffff800)
#define STM32_F3_OPTION_BYTES_BASE ((uint32_t)0x1ffff800)
#define STM32_G4_OPTION_BYTES_BASE ((uint32_t)0x1ffff800)

#endif // STM32_H
