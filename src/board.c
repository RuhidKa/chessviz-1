#include <stdio.h>
void input()
{
    char ch;
    FILE* f;
    int x1, x2, y1, y2;
    f = fopen("test.txt", "r");
    while ((ch = getc(f)) != EOF) {
        if (ch == ' ') {
            x1 = getc(f) - 96;
            y1 = getc(f) - 48;
            getc(f);
            x2 = getc(f) - 96;
            y2 = getc(f) - 48;
            printf("%d %d; %d %d\n", x1, y1, x2, y2);
        }
    }

    fclose(f);
}
