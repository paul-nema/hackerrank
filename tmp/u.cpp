#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    auto dim( 0 );
    auto queries( 0 );
    std::cin >> dim >> queries;
    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int **arr = new int* [ dim ];

    auto len( 0 );
    auto x( 0 );
    auto y( 0 );
    auto z( 0 );

    for( x = 0; x < dim; ++x ) {
        std::cin >> len;

        arr[ x ] = new int[ len ];

        for( auto y( 0 ); y < len; ++y ) {
            std::cin >> arr[ x ][ y ];
        }

        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for( x = 0; x < queries; ++x ) {
        std::cin >> y >> z;
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

        std::cout << arr[ y ][ z ] << "\n";;
    }

    return 0;
}
