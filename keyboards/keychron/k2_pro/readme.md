# Keychron K2 Pro

![Keychron K2 Pro](https://github.com/Keychron/ProductImage/blob/main/K_Pro/k2_pro.jpg?raw=true)

A customizable 84-key wireless mechanical keyboard.

* Keyboard Maintainer: [Keychron](https://github.com/keychron)
* Hardware Supported: Keychron K2 Pro
* Hardware Availability: [Keychron K2 Pro QMK/VIA Wireless Mechanical Keyboard](https://www.keychron.com/products/keychron-k2-pro-qmk-via-wireless-mechanical-keyboard)

## My Keyboard

This repo is set up for a **Keychron K2 Pro ANSI RGB**.

## Prerequisites

Install the QMK toolchain:

```sh
pip install qmk
qmk setup
```

The ARM cross-compiler must be in your PATH. If `make` fails with `arm-none-eabi-gcc: command not found`, run:

```sh
export PATH="$HOME/.local/share/qmk/bin:$PATH"
```

Add that line to your `~/.bashrc` or `~/.zshrc` to make it permanent.

## Build & Flash

### Step 1: Build the firmware

```sh
make keychron/k2_pro/ansi/rgb:via
```

This compiles the firmware with [VIA](https://usevia.app/) support, which lets you remap keys and change RGB effects from a browser app without reflashing. The output file is `keychron_k2_pro_ansi_rgb_via.bin` in the repo root.

> If you don't want VIA, you can use `make keychron/k2_pro/ansi/rgb:default` instead. You only need to build **one**, not both.

### Step 2: Enter bootloader mode

1. Connect the keyboard with a USB cable.
2. Move the side switch to **Off**.
3. Hold **Esc**.
4. While still holding **Esc**, move the switch to **Cable**.
5. Keep holding **Esc** until the keyboard is detected by your computer.

Alternative: press the physical reset button underneath the space bar.

### Step 3: Flash

```sh
make keychron/k2_pro/ansi/rgb:via:flash
```

This builds (if needed) and flashes in one step. The keyboard will reboot automatically when done.

> **Note:** Flashing must be done over USB, not Bluetooth.
