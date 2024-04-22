#pragma once

#ifndef SM_LAYOUTS_SHORTCUT_LAYER
#define SM_LAYOUTS_SHORTCUT_LAYER 0
#endif


#ifndef SM_LAYOUTS_CYR_ENABLED
#define SM_LAYOUTS_CYR_SIZE 0
#define SM_LAYOUTS_CYR_KEYCODES
#else
#define SM_LAYOUTS_CYR_SIZE 33
#define SM_LAYOUTS_CYR_KEYCODES                                          \
   CYR_YY, CYR_CC, CYR_U, CYR_K, CYR_E, CYR_F, CYR_YI, CYR_V, CYR_A,     \
   CYR_P, CYR_YA, CYR_CH, CYR_SS, CYR_M, CYR_I, CYR_N, CYR_G, CYR_SH,    \
   CYR_SCH, CYR_ZZ, CYR_H, CYR_R, CYR_O, CYR_YO, CYR_L, CYR_D, CYR_YE,   \
   CYR_T, CYR_SFT, CYR_B, CYR_YU, CYR_ZH, CYR_SLD,
#endif


#ifndef SM_LAYOUTS_CYR_WIN_SYMBOLS_ENABLED
#define SM_LAYOUTS_CYR_WIN_SYMBOLS_SIZE 0
#define SM_LAYOUTS_CYR_WIN_SYMBOLS_KEYCODES
#else
#define SM_LAYOUTS_CYR_WIN_SYMBOLS_SIZE 12
#define SM_LAYOUTS_CYR_WIN_SYMBOLS_KEYCODES \
   CYR_W1, CYR_W2, CYR_W3, CYR_W4, CYR_W5, CYR_W6, CYR_W7, CYR_W8, CYR_W9, CYR_W0, CYR_WDOT, CYR_WSLASH,
#endif


#ifndef SM_LAYOUTS_CYR_MAC_SYMBOLS_ENABLED
#define SM_LAYOUTS_CYR_MAC_SYMBOLS_SIZE 0
#define SM_LAYOUTS_CYR_MAC_SYMBOLS_KEYCODES
#else
#define SM_LAYOUTS_CYR_MAC_SYMBOLS_SIZE 12
#define SM_LAYOUTS_CYR_MAC_SYMBOLS_KEYCODES \
   CYR_M1, CYR_M2, CYR_M3, CYR_M4, CYR_M5, CYR_M6, CYR_M7, CYR_M8, CYR_M9, CYR_M0, CYR_MSLASH, CYR_MBRC,
#endif


#define SM_LAYOUTS_SIZE (SM_LAYOUTS_CYR_SIZE + SM_LAYOUTS_CYR_WIN_SYMBOLS_SIZE + SM_LAYOUTS_CYR_MAC_SYMBOLS_SIZE)

#define SM_LAYOUTS_KEYCODES            \
   SM_LAYOUTS_BEGIN,                   \
   SM_LAYOUTS_CYR_KEYCODES             \
   SM_LAYOUTS_CYR_WIN_SYMBOLS_KEYCODES \
   SM_LAYOUTS_CYR_MAC_SYMBOLS_KEYCODES \
   SM_LAYOUTS_END                      \
