//      https://www.hackerrank.com/contests/projecteuler/challenges/euler002

#include <iostream>

//  First line contains T that denotes the number of test cases.
//  This is followed by T lines, each containing an integer, N.
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::ios::sync_with_stdio( false );   //  turn off sync'ing with c libs for efficeny
    std::cin.tie( 0 );
    std::cout.setf(std::ios::fixed);
    std::cout.precision( 0 );

    int T{ 0 };

    unsigned long N{ 0 };
    unsigned long fib{ 0 };
    unsigned long prev{ 0 };
    unsigned long curr{ 2 };
    unsigned long evenSum{ 2 };
    
    std::cin >> T;

    while( T-- ) {
        std::cin >> N;

        while( ( fib = ( curr * 4 + prev ) ) <= N ) {
            prev = curr;
            curr = fib;
            evenSum += fib;
        }

        std::cout << evenSum << "\n";

        curr = evenSum = 2;
        prev = 0;
    }

    return 0;
}
