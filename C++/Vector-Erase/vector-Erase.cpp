//  https://www.hackerrank.com/challenges/vector-erase/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    auto numStart( 0 );
    auto numEnd( 0 );

    std::cin >> numStart;
    std::cin.ignore( numeric_limits<streamsize>::max(), '\n' );

    vector<int> v( numStart );

    for( auto x = 0; x < numStart; ++x ) {   //  Read in vector
        std::cin >> v[ x ];
    }

    std::cin.ignore( numeric_limits<streamsize>::max(), '\n' );

    std::cin >> numStart;
    std::cin.ignore( numeric_limits<streamsize>::max(), '\n' );

    v.erase( v.begin() + numStart - 1 );    // erase one number

    std::cin >> numStart >> numEnd;
    std::cin.ignore( numeric_limits<streamsize>::max(), '\n' );

    v.erase( v.begin() + numStart - 1, v.begin() + numEnd - 1 );    //  erase range

    std::cout << v.size() << "\n";

    for( unsigned long x = 0; x < v.size() - 1; ++x ) { //  print results
        std::cout << v[ x ] << " ";
    }

    std::cout << v[ v.size() - 1 ] << std::endl;

  return 0;
}
