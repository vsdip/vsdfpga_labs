#include <stdio.h>

#define DELAY 700000

// Software delay for bare-metal RISC-V
void wait_cycles(volatile int count) {
    while (count-- > 0) {
        __asm__ volatile("nop");
    }
}

// Clear screen using ANSI escape codes
void clear_screen() {
    printf("\033[2J\033[H");  // Clear terminal and move cursor to top
}

// Print the ASCII banner
void print_banner() {
    printf("************************************************************\n");
    printf("*                                                          *\n");
    printf("*   L E A R N   T O   T H I N K   L I K E   A   C H I P    *\n");
    printf("*                                                          *\n");
    printf("*      V S D S Q U A D R O N  F P G A   M I N I            *\n");
    printf("*                                                          *\n");
    printf("*B R I N G S   R I S C - V   T O   V S D  C L A S S R O O M*\n");
    printf("*                                                          *\n");
    printf("************************************************************\n\n");
}

int main() {
    while (1) {
        print_banner();      // Show banner
        wait_cycles(DELAY);  // Pause
        clear_screen();      // Clear banner (unprint)
        wait_cycles(DELAY);  // Pause again
    }

    return 0;
}

