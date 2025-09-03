#include "tests.h"
#include <mintest/suit.h>

int main()
{
    TestSuit TS;
    register_tests(TS);
    TS.run_tests();
    return 0;
}
