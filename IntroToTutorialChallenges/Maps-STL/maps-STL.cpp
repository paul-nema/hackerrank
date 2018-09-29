//  https://www.hackerrank.com/challenges/cpp-maps/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    auto queries( 0 );

    std::cin >> queries;

    auto type( 0 );
    auto score( 0 );

    std::string student( "" );

    std::map< std::string, int > students;

    for( auto x( 0 ); x < queries; ++x ) {
        std::cin >> type;

        switch( type ) {
            case 1:
                std::cin >> student >> score;
                students[ student ] += score;

                break;
            case 2:
                std::cin >> student;
                students[ student ] = 0;

                break;
            case 3:
                std::cin >> student;
                std::cout << students[ student ] << "\n";
        }
    }

  return 0;
}
