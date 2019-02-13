//  https://www.hackerrank.com/challenges/grid-challenge/

#include <bits/stdc++.h>

using namespace std;

// Complete the gridChallenge function below.
std::string gridChallenge( std::vector< std::string > &grid ) {
    unsigned long x{ 1 }, y{ 0 };

    std::sort( grid[ 0 ].begin(), grid[ 0 ].end() );

    for( ; x < grid.size(); ++x ) {
        std::sort( grid[ x ].begin(), grid[ x ].end() );

        for( y = 0; y < grid[ x ].size(); ++y ) {
            if( grid[ x ][ y ] < grid[ x - 1 ][ y ] ) {
                return( "NO" );
            }
        }
    }

    return( "YES" );
}

int main() {
    int t;
    cin >> t;
    cin.ignore( numeric_limits< streamsize >::max(), '\n' );

    for ( int t_itr = 0; t_itr < t; t_itr++ ) {
        int n;
        cin >> n;
        cin.ignore( numeric_limits< streamsize >::max(), '\n' );

        vector< string > grid( n );

        for ( int i = 0; i < n; i++ ) {
            string grid_item;
            getline( cin, grid_item );

            grid[ i ] = grid_item;
        }

        string result = gridChallenge( grid );

        cout << result << "\n";
    }

    return 0;
}
