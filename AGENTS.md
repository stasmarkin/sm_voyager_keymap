# AGENTS.md

Guidance for agents working in this repository.

## What this repository is

A **published copy** of my personal ZSA Voyager keymap, plus its visualization. It is a showcase, not the place where the keymap is developed: the working copy lives inside a QMK checkout (`keyboards/zsa/voyager/keymaps/sm/`) and is synced here by hand. If `sm/` and the firmware ever disagree, the firmware wins.

The same keymap also runs on a Cygnus (36-key split). Behaviour — layers, combos, home-row mods, tap dances, timings — is kept identical between the two boards; only the physical layout, RGB and board-specific build flags differ.

## Layout

- `keymap.yaml` — input for the picture: layers and combos as they should be *displayed*. Hand-written, not generated from the C code, so it has to be updated deliberately when the keymap changes.
- `img.svg` — generated from `keymap.yaml`, embedded in `README.md`.
- `sm/` — the keymap sources.

### `sm/`

- `keymap.json` — modules (`zsa/oryx`, `zsa/defaults`, `stasmarkin/sm_td`, `stasmarkin/sm_layouts`), layer arrays and custom keycode declarations. Layers come from here, not from a `keymap.c` `LAYOUT()` macro.
- `keymap.c` — `process_record_user` (unicode macros, RGB timeout), `pre_process_record_user`, `matrix_scan_user`.
- `sm_voyager_keymap.h` — `enum layers` and Spotify hotkey defines.
- `sm_voyager_combo.h` — combo definitions and `process_combo_event`.
- `sm_td_user.h` — `on_smtd_action`: every home-row mod, tap dance and layer key, plus `get_smtd_timeout` overrides.
- `sm_voyager_rgb.h`, `sm_utils.h`, `config.h`, `rules.mk`.

`sm_layouts.h` and `sm_td.h` are **not** in this repository — they come from the community modules declared in `keymap.json`, so `sm/` alone does not compile.

### Layers

`L_EN`, `L_RU`, `L_GAMING`, `L_NUM`, `L_FN`, `L_RU_FAKE`. The last one is never typed on: it holds bare `CYR_*` keycodes so `sm_layouts` can look up which physical key produces which cyrillic letter.

## Things that bite

- **Combos are keyed by keycode, not by position.** `combo_*[]` arrays list keycodes, so moving a key to another position silently breaks every combo it took part in. When rearranging keys, update the combo arrays to the keycodes now sitting on those physical keys.
- **`COMBO_COUNT` must match the array length.** It is `(104 + SM_SECRETS_COMBO_COUNT)` in `config.h`; a mismatch either fails to compile (too small) or leaves zeroed combo slots that QMK still iterates over (too large).
- **Machine-local combos** come from `sm_secrets.h`, which is not in git. Its four hook macros (`SM_SECRETS_COMBO_ENUM` / `_DEFS` / `_ENTRIES` / `_CASES`) have empty fallbacks in `sm_voyager_combo.h`, so a checkout without it builds fine with fewer combos. Do not inline anything from that file into a tracked one.
- **`pre_process_record_user` runs before the modules**, `process_record_user` after. Anything that must see every physical keypress before `sm_td`/`sm_layouts` intercept it belongs in the former.
- **Keep the two boards in sync.** A behaviour change here has to be mirrored in the Cygnus keymap and vice versa.
- `qmk_build.sh` points at a path that no longer exists; build from the QMK checkout instead.

## Commands

```bash
# build (from a QMK checkout that has this keymap and the modules wired up)
qmk compile -kb zsa/voyager -km sm

# regenerate img.svg after editing keymap.yaml
./update_keymap_image.sh
```

Visualization uses [keymap-drawer](https://github.com/caksoylar/keymap-drawer) via `uvx`, so nothing has to be installed globally. There are no tests — verification is on real hardware.
