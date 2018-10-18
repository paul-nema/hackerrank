//  https://www.hackerrank.com/challenges/vector-sort/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    auto num( 0 );

    std::cin >> num;
    std::cin.ignore( numeric_limits<streamsize>::max(), '\n' );

    vector<int> v( num );

    for( auto x = 0; x < num; ++x ) {
        std::cin >> v[ x ];
    }

    std::cin.ignore( numeric_limits<streamsize>::max(), '\n' );

    std::sort( v.begin(), v.end() );

    for( unsigned long x = 0; x < v.size() - 1; ++x ) {
        std::cout << v[ x ] << " ";
    }

    std::cout << v[ v.size() - 1 ] << std::endl;

  return 0;
}
