#pragma once


#include QMK_KEYBOARD_H
#include <stdio.h>
#include <timer.h>
#include <sm_td.h>

#define SS(str) if(str != NULL){ SEND_STRING(str); }
#define SSN(str) SS(str); SS("\n");

#define SS_STAGE(pre, stage)    SS(pre);  switch(stage) {    \
                                 case NONE: SS("N"); break;     \
                                 case INIT: SS("I"); break;   \
                                 case TAP: SS("T"); break;     \
                                 case JOIN: SS("J"); break;    \
                                 case HOLD: SS("H"); break;    \
                                 case RELEASE: SS("R"); break;  \
                             }

#define SSN_STAGE(pre, stage) SS_STAGE(pre, stage); SS("\n");

#define SS_STATE(pre, state, var) SS(pre); char var[100]; sprintf(var, "%d:T=%d:", state->macro_keycode % 100, state->timeout); SS(var); SS_STAGE(NULL, state->stage); if (state->freeze) { SS("/FRZ"); }
#define SSN_STATE(pre, state, var) SS_STATE(pre, state, var); SS("\n");

#define SS_REC(pre, keycode, record, var)   SS(pre); \
                                            if (record->event.pressed) { SS("v"); } else { SS("^"); } \
                                            char var[100]; sprintf(var, "%d", keycode % 100); \
                                            SS(var);\
                                            if (record->event.pressed) { SS("v"); } else { SS("^"); }

#define SSN_REC(pre, keycode, record, var) SS_REC(pre, keycode, record, var); SS("\n");


