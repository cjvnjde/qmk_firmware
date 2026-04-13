# Keychron K2 Pro

![Keychron K2 Pro](https://github.com/Keychron/ProductImage/blob/main/K_Pro/k2_pro.jpg?raw=true)

A customizable 84-key keyboard.

* Keyboard Maintainer: [Keychron](https://github.com/keychron)
* Hardware Supported: Keychron K2 Pro
* Hardware Availability: [Keychron K2 Pro QMK/VIA Wireless Mechanical Keyboard](https://www.keychron.com/products/keychron-k2-pro-qmk-via-wireless-mechanical-keyboard)

## My Keyboard

This repo is set up around a **Keychron K2 Pro ANSI** (`keychron/k2_pro/ansi`).

The custom keymap currently documented here is:

- [`keychron/k2_pro/ansi/white:candysign`](ansi/white/keymaps/candysign/)

Notes:

- `candysign` currently uses the same layer layout as the stock ANSI white `default` keymap.
- `candysign` enables VIA (`rules.mk`) and changes the advertised product name to `CANDYSIGN KB1 Pro` (`config.h`).
- If you are using the RGB variant, use the `ansi/rgb` targets instead of `ansi/white`.

## Building

### QMK CLI

Build the documented custom keymap:

```sh
qmk compile -kb keychron/k2_pro/ansi/white -km candysign
```

Build the stock ANSI keymaps:

```sh
qmk compile -kb keychron/k2_pro/ansi/white -km default
qmk compile -kb keychron/k2_pro/ansi/white -km via
qmk compile -kb keychron/k2_pro/ansi/rgb -km default
qmk compile -kb keychron/k2_pro/ansi/rgb -km via
```

### Make

```sh
make keychron/k2_pro/ansi/white:candysign
make keychron/k2_pro/ansi/white:default
make keychron/k2_pro/ansi/white:via
make keychron/k2_pro/ansi/rgb:default
make keychron/k2_pro/ansi/rgb:via
```

## Flashing

### Flash with QMK CLI

```sh
qmk flash -kb keychron/k2_pro/ansi/white -km candysign
```

### Flash with make

```sh
make keychron/k2_pro/ansi/white:candysign:flash
```

If you want to flash one of the stock layouts instead, swap `candysign` for `default` or `via`, and swap `ansi/white` for `ansi/rgb` if needed.

### Entering Bootloader Mode

1. Connect the keyboard with a USB cable.
2. Move the side switch to **Off**.
3. Hold **Esc**.
4. While still holding **Esc**, move the switch to **Cable**.
5. Keep holding **Esc** until the flash process starts.

Alternative reset method:

- Press the physical reset button underneath the space bar instead of holding **Esc**.

### Flashing Notes

- Flashing must be done over USB, not Bluetooth.
- If the keyboard is not detected, try unplugging it, repeating the bootloader steps, and then running the flash command again.
- The `BT_HST1`, `BT_HST2`, and `BT_HST3` bindings are for Bluetooth host selection in normal keyboard use; they are not used for flashing.

## Keybindings

The tables below describe the documented ANSI white `candysign` keymap in:

- [`ansi/white/keymaps/candysign/keymap.c`](ansi/white/keymaps/candysign/keymap.c)

Layer names:

- `MAC_BASE`
- `MAC_FN`
- `WIN_BASE`
- `WIN_FN`

`MAC_BASE` and `WIN_BASE` are selected by the keyboard's Mac/Windows hardware switch.
The `Fn` key is the key that momentarily activates `MAC_FN` or `WIN_FN` when held.
On this keymap it is the key between the right command/alt key and right control.

Transparent keys on an `FN` layer fall through to the key from the matching base layer.

### MAC_BASE

| Physical row | Bindings |
| --- | --- |
| Esc row | `Esc`, `Brightness Down`, `Brightness Up`, `Mission Control`, `Launchpad`, `Backlight Down`, `Backlight Up`, `Previous Track`, `Play/Pause`, `Next Track`, `Mute`, `Volume Down`, `Volume Up`, `Screenshot`, `Delete`, `Backlight Step` |
| Number row | `` ` ``, `1`, `2`, `3`, `4`, `5`, `6`, `7`, `8`, `9`, `0`, `-`, `=`, `Backspace`, `Page Up` |
| Tab row | `Tab`, `Q`, `W`, `E`, `R`, `T`, `Y`, `U`, `I`, `O`, `P`, `[`, `]`, `\`, `Page Down` |
| Caps row | `Caps Lock`, `A`, `S`, `D`, `F`, `G`, `H`, `J`, `K`, `L`, `;`, `'`, `Enter`, `Home` |
| Shift row | `Left Shift`, `Z`, `X`, `C`, `V`, `B`, `N`, `M`, `,`, `.`, `/`, `Right Shift`, `Up`, `End` |
| Bottom row | `Left Control`, `Left Option`, `Left Command`, `Space`, `Right Command`, `Fn`, `Right Control`, `Left`, `Down`, `Right` |

### MAC_FN

Only the keys below change when `Fn` is held on the Mac base layer.
Everything not listed here stays the same as `MAC_BASE`.

| Key | Binding with `Fn` |
| --- | --- |
| Top row key 2 | `F1` |
| Top row key 3 | `F2` |
| Top row key 4 | `F3` |
| Top row key 5 | `F4` |
| Top row key 6 | `F5` |
| Top row key 7 | `F6` |
| Top row key 8 | `F7` |
| Top row key 9 | `F8` |
| Top row key 10 | `F9` |
| Top row key 11 | `F10` |
| Top row key 12 | `F11` |
| Top row key 13 | `F12` |
| Top-right light key | `Backlight Toggle` |
| `1` | `Bluetooth Host 1` |
| `2` | `Bluetooth Host 2` |
| `3` | `Bluetooth Host 3` |
| `Tab` | `Backlight Toggle` |
| `Q` | `Backlight Step` |
| `W` | `Backlight Up` |
| `S` | `Backlight Down` |
| `N` | `Battery Level` |
| `M` | `NKRO Toggle` |

### WIN_BASE

| Physical row | Bindings |
| --- | --- |
| Esc row | `Esc`, `F1`, `F2`, `F3`, `F4`, `F5`, `F6`, `F7`, `F8`, `F9`, `F10`, `F11`, `F12`, `Print Screen`, `Delete`, `Backlight Step` |
| Number row | `` ` ``, `1`, `2`, `3`, `4`, `5`, `6`, `7`, `8`, `9`, `0`, `-`, `=`, `Backspace`, `Page Up` |
| Tab row | `Tab`, `Q`, `W`, `E`, `R`, `T`, `Y`, `U`, `I`, `O`, `P`, `[`, `]`, `\`, `Page Down` |
| Caps row | `Caps Lock`, `A`, `S`, `D`, `F`, `G`, `H`, `J`, `K`, `L`, `;`, `'`, `Enter`, `Home` |
| Shift row | `Left Shift`, `Z`, `X`, `C`, `V`, `B`, `N`, `M`, `,`, `.`, `/`, `Right Shift`, `Up`, `End` |
| Bottom row | `Left Control`, `Left GUI`, `Left Alt`, `Space`, `Right Alt`, `Fn`, `Right Control`, `Left`, `Down`, `Right` |

### WIN_FN

Only the keys below change when `Fn` is held on the Windows base layer.
Everything not listed here stays the same as `WIN_BASE`.

| Key | Binding with `Fn` |
| --- | --- |
| Top row key 2 | `Brightness Down` |
| Top row key 3 | `Brightness Up` |
| Top row key 4 | `Task View` |
| Top row key 5 | `File Explorer` |
| Top row key 6 | `Backlight Down` |
| Top row key 7 | `Backlight Up` |
| Top row key 8 | `Previous Track` |
| Top row key 9 | `Play/Pause` |
| Top row key 10 | `Next Track` |
| Top row key 11 | `Mute` |
| Top row key 12 | `Volume Down` |
| Top row key 13 | `Volume Up` |
| Top-right light key | `Backlight Toggle` |
| `1` | `Bluetooth Host 1` |
| `2` | `Bluetooth Host 2` |
| `3` | `Bluetooth Host 3` |
| `Tab` | `Backlight Toggle` |
| `Q` | `Backlight Step` |
| `W` | `Backlight Up` |
| `S` | `Backlight Down` |
| `N` | `Battery Level` |
| `M` | `NKRO Toggle` |

## Special Key Reference

| Keycode / label | Meaning |
| --- | --- |
| `Fn` / `MO(MAC_FN)` / `MO(WIN_FN)` | Momentarily switches to the function layer while held |
| `KC_MCTL` | Mission Control on macOS |
| `KC_LPAD` | Launchpad on macOS |
| `KC_SNAP` | macOS screenshot (`Shift` + `Command` + `4`) |
| `KC_TASK` | Windows Task View (`Win` + `Tab`) |
| `KC_FILE` | Windows File Explorer (`Win` + `E`) |
| `BT_HST1` / `BT_HST2` / `BT_HST3` | Bluetooth host selection; hold for about 2 seconds to pair to that slot |
| `BAT_LVL` | Shows battery level indication when using Bluetooth and USB power is not connected |
| `NK_TOGG` | Toggles N-key rollover |
| `BL_DOWN` / `BL_UP` | White backlight brightness down / up |
| `BL_STEP` | Cycles white backlight effects |
| `BL_TOGG` | Toggles white backlight on or off |

## Resources

- [Build environment setup](https://docs.qmk.fm/#/getting_started_build_tools)
- [QMK make instructions](https://docs.qmk.fm/#/getting_started_make_guide)
- [QMK CLI](https://docs.qmk.fm/#/cli)
- [Complete Newbs Guide](https://docs.qmk.fm/#/newbs)
