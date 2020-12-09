import { disable_interrupts, display_off, DISPLAY_ON, enable_interrupts, joypad, J_DOWN, J_LEFT, J_RIGHT, J_UP, move_sprite, set_bkg_data, set_bkg_tiles, set_sprite_data, set_sprite_tile, SHOW_BKG, SHOW_SPRITES, SPRITES_8x8, wait_vbl_done } from "ts2c-target-gdbk-n/gb/gb.h";

var backgroundcharacters = [
	0xFF,0xDF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
	0xFF,0xFF,0xFF,0xFF,0xFF,0xF9,0xFF,0xF0,

	0x80,0xFF,0x7F,0xE0,0x9F,0xE0,0xFF,0xF0,
	0xFF,0xF9,0xFF,0xBF,0xFF,0xFF,0xFF,0xFF,

	0xFF,0xFF,0xFF,0xCF,0xFF,0x87,0xFF,0xCF,
	0xFF,0xFF,0xFF,0xFF,0xFF,0xFD,0xFF,0xFF,

	0x1F,0xFF,0xEF,0x7F,0x9F,0x7F,0xFF,0xFF,
	0xFF,0xFF,0xFF,0xFF,0xFF,0xF7,0xFF,0xFF
];

var spritetiles = [
    255,0,255,0,255,0,255,0,255,0,255,0,255,0,255,0
];

var bgmap = [
    0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,
	1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3
];

var x = 40;
var y = 17;

disable_interrupts();
display_off();

set_bkg_data(0, 4, backgroundcharacters);
for (var counter = 0; counter <= 16; counter += 2)
    set_bkg_tiles(0, counter, 20, 2, bgmap);

// load sprite
SPRITES_8x8;
set_sprite_data(0, 1, spritetiles);
set_sprite_tile(0, 0);
move_sprite(0,x,y);

SHOW_BKG;
SHOW_SPRITES;
DISPLAY_ON;
enable_interrupts();

while(1) {
    for(counter = 0; counter < 4; counter++){
        wait_vbl_done();
    }
    counter = joypad();

    if(counter & J_UP)
        y--;
    if(counter & J_DOWN)
        y++;
    if(counter & J_LEFT)
        x--;
    if(counter & J_RIGHT)
        x++;

    move_sprite(0, x, y);
}
