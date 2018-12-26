//      https://www.hackerrank.com/contests/projecteuler/challenges/euler004

#include <iostream>

bool isPalindrome( int num ) {
    auto div{ 100000 };

    for( auto x{ 3 }; x > 0; --x ) {
        if( ( num / div ) != ( num % 10 ) ) {
            return( false );
        }

        num = ( num - ( ( num / div ) * div ) ) / 10;
        div /= 100;
    }

    return( true );
}

//  First line contains T that denotes the number of test cases.
//  This is followed by T lines, each containing an integer, N.
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::ios::sync_with_stdio( false );   //  turn off sync'ing with c libs for efficeny
    std::cin.tie( 0 );

    auto T{ 0 };
    auto N{ 0 };
    auto val{ 0 };
    auto largest{ 0 };
    
    std::cin >> T;

    while( T-- ) {
        std::cin >> N;

        for( auto x{ 999 }; x >= 100; --x ) {
            for( auto y{ x }; y >= 100; --y ) {
                val = x * y;

                if( ( val < N ) && isPalindrome( val ) ) {
                    if( val > largest ) {
                        largest = val;
                    }
                }
            }
        }

        std::cout << largest << "\n";

        largest = -1;
    }

    return 0;
}
