#include <stdio.h>
#include <string.h>

void blockkode(int x1, int y1, int x2, int y2)
{
    FILE *f, *out;
    int i, j;
    char c[100], cc[100], ch;
    printf("%d %d; %d %d\n", x1, y1, x2, y2);
    f = fopen("src/figure.txt", "r");
    out = fopen("src/figure2.txt", "w");
    for (i = 8; i >= 1; i--) {
        int tt = 0;
        while ((ch = getc(f)) != '\n') {
            c[tt] = ch;
            tt++;
        }
        c[tt] = '\n';
        for (int z = 0; c[z] != '\n'; z++)
            fprintf(out, "%c", c[z]);
        fprintf(out, "%c", '\n');
        for (j = 1; j <= 8; j++) {
            int tt = 0;
            while ((ch = getc(f)) != '\n') {
                c[tt] = ch;
                tt++;
            }
            c[tt] = '\n';
            if ((i == y1) && (j == x1)) {
                for (int pp = 0; pp < 100; pp++)
                    cc[pp] = c[pp];
                fprintf(out, "%s", "      <td></td>\n");
            } else if ((i == y2) && (j == x2)) {
                fprintf(out,"%c",'*');
                fprintf(out, "%c", '\n');
            } else {
                for (int z = 0; c[z] != '\n'; z++)
                    fprintf(out, "%c", c[z]);
                fprintf(out, "%c", '\n');
            }
        }
        fscanf(f, "%s", c);
        ch = getc(f);
        fprintf(out, "%s", c);
        fprintf(out, "%c", '\n');
    }

    fclose(out);
    fclose(f);
    out = fopen("src/figure.txt", "w");
    f = fopen("src/figure2.txt", "r");
    while ((ch = getc(f)) != EOF){
        if (ch!='*')
            fprintf(out, "%c", ch);
        else{
            for (int z = 0; cc[z] != '\n'; z++)
                    fprintf(out, "%c", cc[z]);
                //fprintf(out, "%c", '\n');
        }
           
        
    }

    fclose(f);
    fclose(out);
}
