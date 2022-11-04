#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

// add your tests here
TEST_CASE("CAESAR CIPHER SOLVER") {
    SUBCASE("Basic Tests"){
        string test1 = "P svcl Illdi. P svcl illdi h sva. Illdi pz tf iyvdu kvn!";
        //string test2 = 
        string ans1 = "I love Beewb. I love beewb a lot. Beewb is my brown dog!";
        
        CHECK(solve(test1) = ans1);
    }
    
}