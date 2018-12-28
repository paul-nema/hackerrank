//  https://www.hackerrank.com/contests/projecteuler/challenges/euler006

#include <iostream>

//  First line contains T that denotes the number of test cases.
//  This is followed by T lines, each containing an integer, N.
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::ios::sync_with_stdio( false ); //  turn off sync'ing with c libs for efficeny
    std::cin.tie( 0 );
    std::cout.setf( std::ios::fixed );
    std::cout.precision( 0 );

    auto T{ 0 };

    double N{ 0 };
    double numSq{ 0 };
    double sumSq{ 0 };

    std::cin >> T;

    while (T--) {
        std::cin >> N;

        //  https://en.wikipedia.org/wiki/Arithmetic_progression
        sumSq = ( N * ( N + 1 ) ) / 2;

        //  https://trans4mind.com/personal_development/mathematics/series/sumNaturalSquares.htm
        numSq = ( ( N * N * N ) / 3 ) + ( ( N * N ) / 2 ) + ( N / 6 );

        std::cout << ( sumSq * sumSq ) - numSq << "\n";
    }

    return 0;
}
