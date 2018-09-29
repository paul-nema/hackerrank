#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    auto total( 0 );
    std::cin >> total;
    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int arr[ total ];

    auto readIn( 0 );

    for( auto x( 0 ); x < total; ++x ) {
        std::cin >> readIn;

        arr[ x ] = readIn;
    }

    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for( auto x( total - 1 ); x > 0; --x) {
        std::cout << arr[ x ] << " ";
    }

    std::cout << arr[ 0 ] << std::endl;

    return 0;
}
