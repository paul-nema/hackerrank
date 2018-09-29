//  https://www.hackerrank.com/challenges/cpp-sets/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    auto queries( 0 );

    std::cin >> queries;
    std::cin.ignore( numeric_limits<streamsize>::max(), '\n' );

    std::set< int > ints;
    set<int>::iterator itr;

    auto cmd( 0 );
    auto num( 0 );

    for( auto x( 0 ); x < queries; ++x ) {
        std::cin >> cmd >> num;
        std::cin.ignore( numeric_limits<streamsize>::max(), '\n' );

        switch( cmd ) {
            case 1:
                ints.insert( num );

                break;
            case 2:
                if( ( itr = ints.find( num ) ) != ints.end() ) {
                    ints.erase( itr );
                }

                break;
            case 3:
                if( ints.find( num ) != ints.end() ) {
                    std::cout << "Yes\n";
                } else {
                    std::cout << "No\n";
                }
        }
    }

  return 0;
}
