//  https://www.hackerrank.com/challenges/30-running-time-and-complexity/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    auto howMany( 0 );
    auto isPrime( true );
    auto y( 5 );
    auto z( 2 );

    long long num( 0 );

    std::cin >> howMany;

    for( auto x( 0 ); x < howMany; ++x ) {
        std::cin >> num;

        if( num == 2 || num == 3 || num == 5 ) {    // Simple checks 1st
            std::cout << "Prime\n";

            continue;
        }

        if( num == 1 || ! ( num & 1 ) ) {   //  If one or even, not prime
            std::cout << "Not prime\n";

            continue;
        }

        while( y * y <= num ) {
            if( num % y == 0 ) {
                isPrime = false;

                break;
            }

            y += z;
            z = 6 - z;
        }

        if( isPrime == true ) {
            std::cout << "Prime\n";
        } else {
            std::cout << "Not prime\n";
        }

        isPrime = true; //  reset variables
        y = 5;
        z = 2;
    }

    return 0;
}
