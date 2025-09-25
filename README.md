# QMK Userspace

This is my personal userspace for my keyboards that run [QMK Firmware](https://qmk.fm/). Last updated for QMK 0.30.3.

## Usage

The repository is configured to build firmware automatically as per the default userspace template, so ready-to-flash firmware can be found in under [Releases](https://github.com/Lorech/QMK/releases).

To build the firmware locally, standard userspace instructions apply:

1. Set up your QMK environment as per the [QMK Docs](https://docs.qmk.fm/#/newbs)
2. Clone this repository
3. `cd` into the repository directory
4. Set the userspace path: `qmk config user.overlay_dir="$(realpath .)"`
5. Compile the firmware: `qmk compile -kb <keyboard> -km <keymap>`

## License

As per QMK's requirements, this repository is licensed under the GNU General Public License version 2 or later.

For more information, refer to the [LICENSE](LICENSE) file.
