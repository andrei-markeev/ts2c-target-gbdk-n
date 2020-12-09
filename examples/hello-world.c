#include <stdio.h>
#include <gb/gb.h>
int main(void) {
    printf("Press START!\n\n");
    waitpad(J_START);
    printf("> Good!\n");

    return 0;
}
