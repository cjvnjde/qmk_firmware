# Keychron K2 Pro

![Keychron K2 Pro](https://github.com/Keychron/ProductImage/blob/main/K_Pro/k2_pro.jpg?raw=true)

A customizable 84 keys TKL keyboard.

* Keyboard Maintainer: [Keychron](https://github.com/keychron)
* Hardware Supported: Keychron K2 Pro
* Hardware Availability: [Keychron K2 Pro QMK/VIA Wireless Mechanical Keyboard](https://www.keychron.com/products/keychron-k2-pro-qmk-via-wireless-mechanical-keyboard)

## Building

Navigate to the root of the repository and use the following command to build the firmware (after setting up your build environment):

    make keychron/k2_pro/ansi/rgb:default

## Flashing

To flash the firmware to your keyboard:

    make keychron/k2_pro/ansi/rgb:default:flash

### Entering Bootloader Mode

Before flashing, you need to switch the keyboard to bootloader mode:

1. Switch the keyboard to USB mode (using the mode switch)
2. Disconnect the keyboard from your PC
3. Press and hold the **Esc** key
4. Connect the keyboard to your PC while continuing to hold **Esc**
5. Keep pressing **Esc** until the flashing process begins

## Resources

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
