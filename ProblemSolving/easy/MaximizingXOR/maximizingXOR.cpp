//  https://www.hackerrank.com/challenges/maximizing-xor/

#include <bits/stdc++.h>

using namespace std;

// Complete the maximizingXor function below.
int maximizingXor( int l, int r ) {
    auto xored{ l ^ r };

    const int bits = sizeof( xored ) * 8 - 1; //  don't include sign bit

    std::bitset< bits > b( xored );   //  easier to use STL

    auto cnt{ 0 };

    for( auto x{ bits - 1 }; x >= 0 && b[ x ] != 1; --x ) {
        ++cnt;  //  count leading zeros
    }

    //  return most significant bit that is different between l and r
    return( ( 1 << ( bits - cnt ) ) - 1 );
}

int main() {
    int l;
    cin >> l;
    cin.ignore( numeric_limits< streamsize >::max(), '\n' );

    int r;
    cin >> r;
    cin.ignore( numeric_limits< streamsize >::max(), '\n' );

    int result = maximizingXor( l, r );

    cout << result << "\n";

    return 0;
}
