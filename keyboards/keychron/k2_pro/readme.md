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

## Build

```sh
make keychron/k2_pro/ansi/rgb:via
```

This compiles the firmware with [VIA](https://usevia.app/) support, which lets you remap keys and change RGB effects from a browser app without reflashing.

> If you don't want VIA, you can use `make keychron/k2_pro/ansi/rgb:default` instead. You only need to build **one**, not both.

## Flash

### Step 1: Set the side switch to Cable (USB) mode

The keyboard must be in wired mode. Flashing does not work over Bluetooth.

### Step 2: Run the flash command

```sh
make keychron/k2_pro/ansi/rgb:via:flash
```

The firmware will compile (if not already built) and then the terminal will print a message saying it's **waiting for the keyboard to enter bootloader mode**. Don't touch anything yet — leave this running.

### Step 3: Put the keyboard into bootloader

While the terminal is waiting:

1. **Unplug** the USB cable from the keyboard.
2. **Press and hold Esc** on the keyboard.
3. **While still holding Esc**, plug the USB cable back in.
4. Keep holding Esc until the flash process starts in the terminal.

The terminal will detect the keyboard in bootloader mode and flash automatically. When it's done the keyboard will reboot and you're good to go.

> **Tip:** If it doesn't work, try the physical reset button underneath the space bar (use a paperclip) instead of holding Esc.
