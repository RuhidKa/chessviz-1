#include "board_print_html.h"
#include "figure.h"
#include "board.h"
#include "check.h"
#include <stdlib.h>
#include <stdio.h>
#include <cxxtest/TestSuite.h>
class MoveTest : public CxxTest::TestSuite {
public:
    void test_check(void)
    {
        int x1=0,x2=0,y1=0,y2=0;
        TS_ASSERT(check(x1,y1,x2,y2)==0);
        x1=1,x2=1,y1=1,y2=0;
        TS_ASSERT(check(x1,y1,x2,y2)==0);
        x1=1,x2=1,y1=1,y2=1;
        TS_ASSERT(check(x1,y1,x2,y2)==1);
        x1=8,x2=8,y1=8,y2=8;
        TS_ASSERT(check(x1,y1,x2,y2)==1);
        x1=1,x2=2,y1=6,y2=7;
        TS_ASSERT(check(x1,y1,x2,y2)==1);
        x1=9,x2=1,y1=1,y2=1;
        TS_ASSERT(check(x1,y1,x2,y2)==0);
        x1=1,x2=-1,y1=1,y2=1;
        TS_ASSERT(check(x1,y1,x2,y2)==0);
        x1=1,x2=1,y1=10,y2=1;
        TS_ASSERT(check(x1,y1,x2,y2)==0);
    }
public:
    void test_zapoln(void)
    {
        FILE *f1,*f2;
        char ch1,ch2;
        f1=fopen("test/files/zapoln.txt","r");
        zapoln();
        f2=fopen("src/figure.txt","r");
        while (((ch1=getc(f1))!=EOF)&&((ch2=getc(f2))!=EOF)){
            TS_ASSERT(ch1==ch2);
        }
        fclose(f1);
        fclose(f2);
    }
public:
    void test_blockkode(void)
    {
        FILE *f1,*f2;
        char ch1,ch2;
        f1=fopen("test/files/block.txt","r");
        zapoln();
        blockkode(1,2,1,8,'Q');
        blockkode(3,1,4,2);
        blockkode(1,8,2,8);
        f2=fopen("src/figure.txt","r");
        while (((ch1=getc(f1))!=EOF)&&((ch2=getc(f2))!=EOF)){
            TS_ASSERT(ch1==ch2);
        }
        fclose(f1);
        fclose(f2);
    }
public:
    void test_input(void)
    {
        FILE *f1,*f2;
        char ch1,ch2;
        zapoln();
        input();
        f1=fopen("test/files/input.txt","r");
        f2=fopen("src/figure.txt","r");
        while (((ch1=getc(f1))!=EOF)&&((ch2=getc(f2))!=EOF)){
            TS_ASSERT(ch1==ch2);
        }
        fclose(f1);
        fclose(f2);
    }
};
