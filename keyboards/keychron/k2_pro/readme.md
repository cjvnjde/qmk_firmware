# Keychron K2 Pro

![Keychron K2 Pro](https://github.com/Keychron/ProductImage/blob/main/K_Pro/k2_pro.jpg?raw=true)

A customizable 84-key wireless mechanical keyboard.

* Keyboard Maintainer: [Keychron](https://github.com/keychron)
* Hardware Supported: Keychron K2 Pro
* Hardware Availability: [Keychron K2 Pro QMK/VIA Wireless Mechanical Keyboard](https://www.keychron.com/products/keychron-k2-pro-qmk-via-wireless-mechanical-keyboard)

## My Keyboard

This repo is set up for a **Keychron K2 Pro ANSI RGB** (`keychron/k2_pro/ansi/rgb`).

## Building

```sh
make keychron/k2_pro/ansi/rgb:via
make keychron/k2_pro/ansi/rgb:default
```

## Flashing

```sh
make keychron/k2_pro/ansi/rgb:via:flash
```

### Entering Bootloader Mode

1. Connect the keyboard with a USB cable.
2. Move the side switch to **Off**.
3. Hold **Esc**.
4. While still holding **Esc**, move the switch to **Cable**.
5. Keep holding **Esc** until the flash process starts.

Alternative: press the physical reset button underneath the space bar.

**Note:** flashing must be done over USB, not Bluetooth.
