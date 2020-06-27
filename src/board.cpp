#include "board_print_html.h"
#include "figure.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "check.h"
void input()
{
    char ch;
    FILE* f;
    int x1, x2, y1, y2, elem, counter = 0;
    char figure, type, create;
    f = fopen("test.txt", "r");
    if (f == 0)
        printf("%s",
               "\n\nERROR FILE PATH, TRY GO OUT FROM BIN AND WRITE make\nor "
               "make "
               "start if project already builded");
    else {
        printdeck();
        system("firefox bin/chess.html");
        sleep(2);
        while ((ch = getc(f)) != EOF) {
            if (ch == ' ') {
                counter++;
                figure = 'P';
                elem = getc(f);
                if (elem > 64 && elem < 91) {
                    figure = elem;
                    x1 = getc(f) - 96;
                    y1 = getc(f) - 48;
                    type = getc(f);
                    x2 = getc(f) - 96;
                    y2 = getc(f) - 48;
                    if (!check(x1,y1,x2,y2)){
                        printf("%s","\n\nFAILED SIZE OF VAR X1(2) OR Y1(2)");
                        break;
                    }
                    blockkode(x1, y1, x2, y2);
                    printdeck();
                } else if (elem > 96 && elem < 123) {
                    x1 = elem - 96;
                    y1 = getc(f) - 48;
                    type = getc(f);
                    x2 = getc(f) - 96;
                    y2 = getc(f) - 48;
                    if (!check(x1,y1,x2,y2)){
                        printf("%s","\n\nFAILED SIZE OF VAR X1(2) OR Y1(2)");
                        break;
                    }
                    create = '0';
                    if ((y1 == 7 && y2 == 8) || (y1 == 2 && y2 == 1)) {
                        create = getc(f);
                    }
                    blockkode(x1, y1, x2, y2, create);
                    printdeck();
                } else if (elem == '0') {
                    type = '-';
                    if (counter % 2 != 0) {
                        x1 = 5;
                        y1 = 1;
                        getc(f);
                        getc(f);
                        x2 = 7;
                        y2 = 1;
                        blockkode(x1, y1, x2, y2);
                        x1 = 8;
                        y1 = 1;
                        x2 = 6;
                        y2 = 1;
                        blockkode(x1, y1, x2, y2);
                        printdeck();
                    } else {
                        x1 = 5;
                        y1 = 8;
                        getc(f);
                        getc(f);
                        x2 = 7;
                        y2 = 8;
                        blockkode(x1, y1, x2, y2);
                        x1 = 8;
                        y1 = 8;
                        x2 = 6;
                        y2 = 8;
                        blockkode(x1, y1, x2, y2);
                        printdeck();
                    }
                }
                sleep(2);
            }
        }
        printdeck(false);
        fclose(f);
        // for Werror
        type++;
        figure++;
    }
}
