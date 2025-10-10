# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a personal keymap configuration for the ZSA Voyager keyboard using QMK firmware. The project contains both YAML-based keymap configuration and C code for advanced functionality.

## Core Architecture

### Keymap Structure
- `keymap.yaml` - Main keymap configuration with layers (EN, RU, NUM, FN) and combos
- `sm/keymap.c` - QMK C entry point that ties together all modules
- `sm/sm_voyager_keymap.h` - Main keymap definitions and layer constants
- `sm/sm_voyager_combo.h` - Combo key definitions (105 combos total)
- `sm/sm_layouts.h` - Layout switching logic for EN/RU layers
- `sm/sm_td_user.h` - Tap dance user configurations
- `sm/sm_voyager_rgb.h` - RGB lighting configurations
- `sm/modules/sm_td/` - Custom tap dance module (external QMK module)

### Key Design Principles
- Dual layout support (Latin/Cyrillic) with symbols staying in same positions
- Home-row mods work consistently across layouts
- All symbols reachable within 2-key combo maximum
- Left-hand optimized for mouse usage (numpad, hotkeys on left)
- One-shot-mods via combos for both layouts

### Configuration Files
- `sm/config.h` - QMK configuration overrides (tapping terms, combo count, etc.)
- `sm/rules.mk` - QMK build rules and feature flags

## Common Development Commands

### Building and Flashing
```bash
# Build keymap and save timestamped binary to Downloads
./qmk_build.sh

# Compile keymap (requires QMK CLI setup)
qmk compile -kb voyager -km sm

# Flash to device (requires QMK CLI setup)
qmk flash -kb voyager -km sm
```

### Keymap Visualization
```bash
# Generate keymap image once
./update_keymap_image.sh

# Continuously update keymap image (for development)
./update_keymap_image_infinite.sh
```

## Development Workflow

1. **YAML Changes**: Modify `keymap.yaml` for layout/combo changes, then run `./update_keymap_image.sh` to visualize
2. **C Code Changes**: Edit files in `sm/` directory for advanced functionality
3. **Building**: Use `./qmk_build.sh` to compile and get timestamped firmware
4. **Testing**: Flash with QMK CLI and test on actual hardware

## Key Files for Modifications

- **Add/modify key combos**: Edit `keymap.yaml` combos section or `sm/sm_voyager_combo.h`
- **Change layer layouts**: Edit `keymap.yaml` layers section or `sm/sm_voyager_keymap.h`
- **Add custom keycodes**: Edit `sm/sm_layouts_keycodes.h`
- **Modify tap dance**: Edit `sm/sm_td_user.h`
- **RGB customization**: Edit `sm/sm_voyager_rgb.h`
- **Core behavior**: Edit `sm/keymap.c` process_record_user function

## Dependencies

- QMK CLI for building/flashing
- `keymap` CLI tool for generating keymap images from YAML
- ZSA Voyager keyboard for testing

## File Processing Flow

- YAML changes automatically propagate to C headers through QMK build process
- Combos defined in both `keymap.yaml` and `sm/sm_voyager_combo.h` (YAML is source of truth)
- Layer layouts can be modified in either `keymap.yaml` or `sm/sm_voyager_keymap.h`
- Custom keycodes and macros are defined in `sm/sm_layouts_keycodes.h`

## Build System Notes

- `sm/rules.mk` enables required QMK features (combos, RGB, unicode, caps word)
- `sm/config.h` sets timing parameters and combo limits (COMBO_COUNT = 105)
- Build output goes to timestamped files in Downloads directory via `qmk_build.sh`