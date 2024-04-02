#pragma once

#ifndef SM_LAYERS_SHORTCUT_LAYER
#define SM_LAYERS_SHORTCUT_LAYER 0
#endif

#ifndef SM_LAYERS_CYR_ENABLED
#define SM_LAYERS_CYR_ENABLED 0
#define SM_LAYERS_CYR_SIZE 0
#define SM_LAYERS_CYR_KEYCODES
#else
#define SM_LAYERS_CYR_SIZE 33
#define SM_LAYERS_CYR_KEYCODES                                           \
   CYR_YY, CYR_CC, CYR_U, CYR_K, CYR_E, CYR_F, CYR_YI, CYR_V, CYR_A,     \
   CYR_P, CYR_YA, CYR_CH, CYR_SS, CYR_M, CYR_I, CYR_N, CYR_G, CYR_SH,     \
   CYR_SCH, CYR_ZZ, CYR_H, CYR_R, CYR_O, CYR_YO, CYR_L, CYR_D, CYR_YE,    \
   CYR_T, CYR_SFT, CYR_B, CYR_YU, CYR_ZH, CYR_SLD
#endif


#define SM_LAYERS_SIZE (0 + SM_LAYERS_CYR_SIZE)

#define SM_LAYERS_KEYCODES   \
   SM_LAYERS_BEGIN,          \
   SM_LAYERS_CYR_KEYCODES,   \
   SM_LAYERS_END             \

