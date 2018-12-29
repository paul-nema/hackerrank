//  https://www.hackerrank.com/contests/projecteuler/challenges/euler007

//  Test Data - https://primes.utm.edu/lists/small/10000.txt

#include <iostream>
#include <cmath>
#include <vector>

bool isPrime( int num ) {
    //  Quick prime check - prime can expressed as 6*x+1 or 6*x-1 except 2 and 3
    if( ( num - 1 ) % 6 != 0 && ( num + 1 ) % 6 != 0 ) {
        return( false );
    }

    //  start at 3 as we only get odd numbers
    for( auto x{ 3 }; x <= std::sqrt( num ); ++x ) {
        if( num % x == 0 ) {
            return( false );
        }
    } 

    return( true );
}


//  First line contains T that denotes the number of test cases.
//  This is followed by T lines, each containing an integer, N.
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::ios::sync_with_stdio( false ); //  turn off sync'ing with c libs for efficeny
    std::cin.tie( 0 );

    std::vector< int > primes{ 2, 3, 5 };

    auto T{ 0 };
    auto N{ 0 };
    auto x{ 5 };
    auto cnt{ 3 };
    auto largest{ cnt };

    std::cin >> T;

    while (T--) {
        std::cin >> N;

        if( N <= largest ) {
            std::cout << primes[ N - 1 ] << "\n";

            continue;
        }

        while( cnt != N ) {
            x += 2; //  only care about odd numbers

            if( isPrime( x ) ) {
                primes.push_back( x );  //  cache results

                ++cnt;
            }
        }

        std::cout << primes[ cnt - 1 ] << "\n";

        largest = primes.size();
    }

    return 0;
}
