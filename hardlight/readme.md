# edi/hardlight/qss

![edi/hardlight/qss](imgur.com image replace me!)

*A short description of the keyboard/project*

* Keyboard Maintainer: [FateEverywhere](https://github.com/FateEverywhere)
* Hardware Supported: Mark Zero Quicksilver Storm, Hard Light Final Revision
* Hardware Availability: *Links to where you can find this hardware*

Make example for this keyboard (after setting up your build environment):

    make edi/hardlight/qss:default

Flashing example for this keyboard:

    make edi/hardlight/qss:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (the top left key) and plug in the keyboard
* **Physical reset button**: Double-tap the button on the back of the PCB
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
