//  https://www.hackerrank.com/contests/projecteuler/challenges/euler001

#include <iostream>

//  First line contains T that denotes the number of test cases.
//  This is followed by T lines, each containing an integer, N.
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::ios::sync_with_stdio( false );   //  turn off sync'ing with c libs for efficeny

    auto T{ 0 };

    unsigned long N{ 0 };
    unsigned long seq{ 0 };
    unsigned long sum{ 0 };

    std::cin >> T;

    while( T-- ) {
        std::cin >> N;

        seq = ( N - 1 ) / 3;
        sum = ( 3 * seq * ( seq + 1 ) ) / 2;

        seq = ( N - 1 ) / 5;
        sum += ( 5 * seq * ( seq + 1 ) ) / 2;

        seq = ( N - 1 ) / 15;   //  get rid of 3 * 5
        if( seq ) { //  ignore if seq == 0
            sum -= ( 15 * seq * ( seq + 1 ) ) / 2;
        }

        std::cout << sum << "\n";

        sum = 0;
    }

    return 0;
}
