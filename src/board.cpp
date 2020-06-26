#include "board_print_html.h"
#include "figure.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void input()
{
    char ch;
    FILE* f;
    int x1, x2, y1, y2;
    f = fopen("test.txt", "r");
    printdeck();
    system("firefox bin/chess.html");
    sleep(2);
    while ((ch = getc(f)) != EOF) {
        if (ch == ' ') {
            x1 = getc(f) - 96;
            y1 = getc(f) - 48;
            getc(f);
            x2 = getc(f) - 96;
            y2 = getc(f) - 48;
            blockkode(x1, y1, x2, y2);
            // printf("%d %d; %d %d\n", x1, y1, x2, y2);
            printdeck();
            // gets();
            sleep(2);
        }
    }

    fclose(f);
}
