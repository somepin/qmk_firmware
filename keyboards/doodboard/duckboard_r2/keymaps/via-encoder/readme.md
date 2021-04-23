Default keymap with unoffical support for remapping the rotary encoder in [VIA](https://caniusevia.com).

<img src="https://i.postimg.cc/sxMYpqsJ/via-encoder-annotated.png" width="750">

## Usage

1. Flash `doodboard_duckboard_via-encoder.hex` to your R2 duckboard using QMK Toolbox
2. Open VIA > Settings > Show Design Tab
3. Design > Load > `doodboard_duckboard_r2_via-encoder.json`
4. You can now remap rotary encoder turns in VIA :)

_\*\* You'll have to load `duckboard_r2-via-encoder.json` each time you open VIA and want to change the encoder turns_

## Issues

-   Encoder turns can't be remapped to RGB keycodes, or advanced features like Super Alt Tab
