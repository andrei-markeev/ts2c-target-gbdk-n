#include <gb/gb.h>

typedef short int16_t;
static int16_t backgroundcharacters[64] = { 0xFF, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF9, 0xFF, 0xF0, 0x80, 0xFF, 0x7F, 0xE0, 0x9F, 0xE0, 0xFF, 0xF0, 0xFF, 0xF9, 0xFF, 0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xCF, 0xFF, 0x87, 0xFF, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD, 0xFF, 0xFF, 0x1F, 0xFF, 0xEF, 0x7F, 0x9F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF };
static int16_t spritetiles[16] = { 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0 };
static int16_t bgmap[40] = { 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3 };
static int16_t x;
static int16_t y;
static int16_t counter;
int main(void) {
    x = 40;
    y = 17;
    disable_interrupts();
    display_off();
    set_bkg_data(0, 4, backgroundcharacters);
    counter = 0;
    for (;counter <= 16;counter += 2)
        set_bkg_tiles(0, counter, 20, 2, bgmap);
    SPRITES_8x8;
    set_sprite_data(0, 1, spritetiles);
    set_sprite_tile(0, 0);
    move_sprite(0, x, y);
    SHOW_BKG;
    SHOW_SPRITES;
    DISPLAY_ON;
    enable_interrupts();
    while (1)
    {
        for (counter = 0;counter < 4;counter++)
            wait_vbl_done();
        counter = joypad();
        if (counter & J_UP)
            y--;
        if (counter & J_DOWN)
            y++;
        if (counter & J_LEFT)
            x--;
        if (counter & J_RIGHT)
            x++;
        move_sprite(0, x, y);
    }

    return 0;
}
