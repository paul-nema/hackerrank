//  https://www.hackerrank.com/challenges/manasa-and-stones/

#include <bits/stdc++.h>

using namespace std;

// Complete the stones function below.
//  n: an integer, the number of non-zero stones
//  a: one possible integer difference
//  b: another possible integer difference
vector<int> stones( int n, int a, int b ) {
    vector<int> result;
    vector<int> tmp( n, 0 );

    auto sz( ( n - 1 ) * 2 );
    auto y( 0 );
    auto z( 0 );
    auto tmpN( n );

    for( auto x( 0 ); x < sz; ++x ) {
        for( y = 1; y < tmpN; ++y ) {
            tmp[ y ] = ( ( x < sz / 2 ) ? a : b ) + tmp[ y - 1 ];
        }

        for( z = y; z < n; ++z ) {
            tmp[ z ] = ( ( x < sz / 2 ) ? b : a ) + tmp[ z - 1 ];
        }

        if( tmpN == 1 ) {
            tmpN = n;
        } else {
            --tmpN;
        }

        if( std::find( result.begin(), result.end(), tmp.back() ) == result.end() ) {
            result.push_back( tmp.back() );
        }
    }

    std::sort( result.begin(), result.end() );

    return ( result );
}

int main() {
    int T;
    cin >> T;
    cin.ignore( numeric_limits<streamsize>::max(), '\n' );

    for ( int T_itr = 0; T_itr < T; T_itr++ ) {
        int n;
        cin >> n;
        cin.ignore( numeric_limits<streamsize>::max(), '\n' );

        int a;
        cin >> a;
        cin.ignore( numeric_limits<streamsize>::max(), '\n' );

        int b;
        cin >> b;
        cin.ignore( numeric_limits<streamsize>::max(), '\n' );

        vector<int> result = stones( n, a, b );

        for ( int i = 0; i < result.size(); i++ ) {
            cout << result[i];

            if ( i != result.size() - 1 ) {
                cout << " ";
            }
        }

        cout << "\n";
    }

    return 0;
}
