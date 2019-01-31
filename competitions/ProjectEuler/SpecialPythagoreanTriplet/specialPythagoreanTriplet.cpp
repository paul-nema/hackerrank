//  https://www.hackerrank.com/contests/projecteuler/challenges/euler009
//  https://en.wikipedia.org/wiki/Pythagorean_triple

#include <iostream>

//  First line contains an integer T i.e. number of test cases.
//  The next T lines will contain an integer N.
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::ios::sync_with_stdio( false ); //  turn off sync'ing with c libs for efficeny
    std::cin.tie( 0 );

    auto T{ 0 }, N{ 0 };
    auto a{ 0 }, b{ 0 }, c { 0 }, max{ 0 };

    std::cin >> T;

    while (T--) {
        std::cin >> N;

        max = -1;

        for( a = 1; a < N / 3; ++a ) {
            //  https://www.dropbox.com/s/kep0cbtbkdd011a/formula.png
            b = (2 * a * N - N * N) / (2 * a - 2 * N);
            c = N - b - a;

            if( a * a + b * b == c * c && a < b &&  b < c ) {
                max = a * b * c;
            }
        }

        std::cout << max << "\n";
    }

    return 0;
}
