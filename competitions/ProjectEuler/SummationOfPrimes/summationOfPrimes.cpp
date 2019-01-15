//  https://www.hackerrank.com/contests/projecteuler/challenges/euler007

#include <iostream>
#include <cmath>
#include <vector>

//  First line contains T that denotes the number of test cases.
//  The next T lines will contains an integer N.
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::ios::sync_with_stdio( false ); //  turn off sync'ing with c libs for efficeny
    std::cin.tie( 0 );

    int maxVal{ 1000001 };
    int sq{ static_cast< int >( std::sqrt( maxVal ) + 1 ) };
    int x{ 0 };
    int i{ 0 };

    std::vector< unsigned long > primes( maxVal, 0 );

    primes[ 1 ] = -1;

    for( int k{ 1 }; k <= sq; k = x ) {   //  sieve
        for ( x = k + 1; x < maxVal; ++x ) {
            if( ! primes[ x ] ) {
                break;
            }
        }

        for ( i = x * 2; i < maxVal; i += x ) {
            primes[ i ] = -1;
        }
    }

    for( x = 1; x <= maxVal; ++x ) { //  summation
        if( ! primes[ x ] ) {
            primes[ x ] = x + primes[ x - 1 ];
        } else {
            primes[ x ] = primes[ x - 1 ];
        }
    }

    auto T{ 0 };
    auto N{ 0 };

    std::cin >> T;

    while (T--) {
        std::cin >> N;

        std::cout << primes[ N ] << "\n";
    }

    return 0;
}
