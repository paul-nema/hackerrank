//  https://www.hackerrank.com/contests/projecteuler/challenges/euler014

#include <iostream>
#include <vector>

//  The first line contains an integer T, number of test cases.
//  Next T lines will contain an integers N.
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::ios::sync_with_stdio( false ); //  turn off sync'ing with c libs for efficeny
    std::cin.tie( 0 );

    std::vector< std::pair< unsigned long, unsigned long > > pv = {
        std::make_pair( 1, 1 ), std::make_pair( 2, 2 ), std::make_pair( 3, 8 ), std::make_pair( 3, 3 ),
        std::make_pair( 3, 6 ), std::make_pair( 6, 9 ), std::make_pair( 7, 17 ), std::make_pair( 7, 4 ),
        std::make_pair( 9, 20 ), std::make_pair( 9, 7 )
    };

    auto T{ 0 };
    auto cnt{ 0 };
    unsigned long N{ 0 };
    unsigned long long num{ 0 };
    unsigned long long largest( pv.back().first );

    std::cin >> T;

    while (T--) {
        std::cin >> N;

        if( N - 1 < pv.size() ) {   //  is this in cache
            std::cout << pv[ N - 1 ].first << "\n";

            continue;
        }

        for( unsigned long x{ pv.size() }; x < N; ++x ) {
            num = x + 1;

            while( num != 1 ) {
                if( num < pv.size() && pv[ num - 1 ].first != 0 ) {
                    pv.push_back( std::make_pair( cnt + pv[ num - 1 ].second >= pv[ largest - 1 ].second ? x + 1 : largest,
                        cnt + pv[ num - 1 ].second ) );

                    if( pv.back().first > largest ) {
                        largest = pv.back().first;
                    }

                    break;
                }

                if( num & 1 ) { //  odd
                    num = ( 3 * num ) + 1;
                } else {
                    num /= 2;
                }

                ++cnt;
            }

            cnt = 0;    //  reinit var
        }

        std::cout << largest << "\n";
    }

    return 0;
}
