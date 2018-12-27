//  https://www.hackerrank.com/contests/projecteuler/challenges/euler005

#include <iostream>
#include <vector>

//  First line contains T that denotes the number of test cases.
//  This is followed by T lines, each containing an integer, N.
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::ios::sync_with_stdio( false ); //  turn off sync'ing with c libs for efficeny
    std::cin.tie( 0 );

    auto T{ 0 };
    auto x{ 0 };
    auto y{ 0 };
    auto N{ 0 };
    auto smallest{ false };

    unsigned long long val{ 1 };
    unsigned long long increase{ 1 };

    std::vector< int > primes{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41 };

    std::cin >> T;

    while (T--) {
        std::cin >> N;

        for( x = 0; x < static_cast< int >( primes.size() ); ++x ) {
            if( primes[ x ] > N ) {
                for( y = 0; y < x; ++y ) {
                    val *= primes[ y ]; //  get product of all primes <= N
                }

                increase = val;

                break;
            }
        }

        for( ; smallest == false; val += increase ) {
            smallest = true;

            for( x = N; x > 1; --x ) {
                if( ( val % x ) != 0 ) {
                    smallest = false;

                    break;
                }
            }

            if( smallest == true ) {
                std::cout << val << "\n";

                smallest = false;

                val = 1;

                break;
            }
        }
    }

    return 0;
}
