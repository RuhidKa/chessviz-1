#include "check.h"
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
    void test_input(void)
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

};
