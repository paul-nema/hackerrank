//  https://www.hackerrank.com/contests/projecteuler/challenges/euler008

#include <iostream>
#include <limits>
#include <deque>
#include <numeric>

//  First line contains T that denotes the number of test cases.
//  First line of each test case will contain two integers N & K.
//  Second line of each test case will contain a N digit integer.
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::ios::sync_with_stdio( false ); //  turn off sync'ing with c libs for efficeny
    std::cin.tie( 0 );

    auto T{ 0 };
    auto N{ 0 };
    auto num{ 0 };  //  this can be dropped but keeping for readability
    auto digit{ '0' };
    auto product{ 1 };
    auto maxNum{ 0 };

    size_t K{ 0 };

    std::deque< int > d;

    std::cin >> T;

    while (T--) {
        std::cin >> N >> K;
        std::cin.ignore( std::numeric_limits< std::streamsize >::max(), '\n' );

        for( ; N > 0; --N ) {
            std::cin.get( digit );
            num = digit - '0';

            if( d.size() == K ) {
                if( product > maxNum ) {
                    maxNum = product;
                }

                if( d.front() != 0 ) {
                    product /= d.front();
                } else {
                    product = std::accumulate( d.begin() + 1, d.end(), 1, std::multiplies< int >() );
                }

                d.pop_front();
            }

            product *= num;

            d.push_back( num );
        }

        std::cout << ( product > maxNum ? product : maxNum ) << "\n";

        product = 1;    //  re-init all vars
        maxNum = 0;
        d.clear();
    }

    return 0;
}
