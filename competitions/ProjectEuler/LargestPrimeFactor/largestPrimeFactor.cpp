//      https://www.hackerrank.com/contests/projecteuler/challenges/euler002

#include <iostream>
#include <cmath>

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::ios::sync_with_stdio( false );   //  turn off sync'ing with c libs for efficeny
    std::cin.tie( 0 );

    int T{ 0 };

    long long N{ 0 };
    long long largestPrime{ -1 };

    //  First line contains T that denotes the number of test cases.
    //  This is followed by T lines, each containing an integer, N.
    std::cin >> T;

    while( T-- ) {
        std::cin >> N;

        while( N % 2 == 0 ) {   //  get rid of the even numbers
            N >>= 1;    //  shift bit to divide by 2
            largestPrime = 2;
        }

        for( auto x{ 3 }; x <= std::sqrt( N ); x += 2 ) {    //  only use odd numbers
            while( N % x == 0 ) {
                largestPrime = x;

                N /= x;
            }
        }

        if( N > 2 ) {
            largestPrime = N;
        }

        std::cout << largestPrime << "\n";

        largestPrime = -1;
    }

    return 0;
}
