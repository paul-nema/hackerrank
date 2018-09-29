//  https://www.hackerrank.com/challenges/30-review-loop/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    auto numOfStrs( 0 );

    std::cin >> numOfStrs;
    std::cin.ignore( numeric_limits<streamsize>::max(), '\n' );

    std::string inputStr;
    std::string oddStr;
    std::string evenStr;

    for( auto x = 0; x < numOfStrs; ++x ) {
        std::getline( std::cin, inputStr );

        for( unsigned long y = 0; y < inputStr.size(); ++y ) {
            if( y & 1 ) {   //  odd
                oddStr.push_back( inputStr[ y ] );
            } else {
                evenStr.push_back( inputStr[ y ] );
            }
        }

        evenStr.push_back( ' ' );
        oddStr.push_back( '\n' );

        std::cout << evenStr << oddStr;

        evenStr.clear();
        oddStr.clear();
    }

  return 0;
}
