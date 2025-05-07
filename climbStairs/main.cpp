#include <iostream>
#include <cassert>
#include "climb_stairs_solution.cpp"
using namespace std;

int main() {
    Solution sol;

    // test cases: climbStairs(n) == Fibonacci(n+1)
    assert(sol.climbStairs(1) == 1);   // F(2)
    assert(sol.climbStairs(2) == 2);   // F(3)
    assert(sol.climbStairs(3) == 3);   // F(4)
    assert(sol.climbStairs(4) == 5);   // F(5)
    assert(sol.climbStairs(5) == 8);   // F(6)
    assert(sol.climbStairs(6) == 13);  // F(7)
    assert(sol.climbStairs(7) == 21);  // F(8)
    assert(sol.climbStairs(8) == 34);  // F(9)
    assert(sol.climbStairs(9) == 55);  // F(10)
    assert(sol.climbStairs(10) == 89); // F(11)
    assert(sol.climbStairs(11) == 144);// F(12)
    assert(sol.climbStairs(12) == 233);// F(13)

    cout << "All test cases passed ✅" << endl;

    return 0;
}
