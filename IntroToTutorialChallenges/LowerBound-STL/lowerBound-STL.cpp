//  https://www.hackerrank.com/challenges/cpp-lower-bound/

#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    auto num( 0 );

    std::cin >> num;

    vector<int> v( num );

    for( auto x = 0; x < num; ++x ) {   //  Read in vector
        std::cin >> v[ x ];
    }

    auto queries( 0 );

    std::cin >> queries;

    for( auto x = 0; x < queries; ++x ) {   //  Read in queries and process them
        std::cin >> num;

        auto searchResult = std::lower_bound( v.begin(), v.end(), num );

        if( v[ ( searchResult - v.begin() ) ] == num ) {
            std::cout << "Yes " << ( searchResult - v.begin() ) + 1 << "\n";
        } else {
            std::cout << "No " << ( searchResult - v.begin() ) + 1 << "\n";
        }
    }

  return 0;
}
