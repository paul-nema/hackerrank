//  https://www.hackerrank.com/challenges/30-sorting/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    auto n( 0 );
    auto i( 0 );
    auto totalSwaps( 0 );
    auto numberOfSwaps( 0 );    // Num of swaps during a single array traversal

    std::cin >> n;

    std::vector< int > a( n );

    for( i = 0; i < n; ++i ) {  //  read in array
        std::cin >> a[ i ];
    }

    for ( i = 0; i < n; ++i ) {
        for ( int j = 0; j < n - 1; ++j ) {
            if (a[ j ] > a[ j + 1 ] ) {   // Swap adjacent elements if they are in decreasing order
                std::swap(a[ j ], a[ j + 1 ] );

                ++numberOfSwaps;
                ++totalSwaps;
            }
        }

        if ( numberOfSwaps == 0 ) { // No elements swapped during a traversal, array is sorted
            break;
        }
    }

    std::cout << "Array is sorted in " << totalSwaps << " swaps.\n"
        << "First Element: " << a[ 0 ]
        << "\nLast Element: " << a.back()
        << std::endl;

  return 0;
}
