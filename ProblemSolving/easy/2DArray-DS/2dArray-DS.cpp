//  https://www.hackerrank.com/challenges/2d-array/

#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum( vector< vector< int > > arr ) {
    const auto hourglass( 3 );  //  hard code size

    auto result( numeric_limits<int>::min() );  //  smallest possible int
    auto largest( 0 );

    //  dynamically determine # of hourglasses that will fit into the array
    for( auto x( 0 ); x < ( arr[ x ].size() - hourglass + 1 ); ++x ) {    //  row
        for( auto y( 0 ); y < ( arr[ x ].size() - hourglass + 1 ); ++y ) {    //  column
            for( auto z( 0 ); z < hourglass; ++z ) {    //  hourglasss
                largest += arr[ x ][ z + y ] + arr[ x + 2 ][ z + y ];

                if( z == 1 ) {
                    largest += arr[ x + 1 ][ z + y ];
                }
            }

            if( largest > result ) {
                result = largest;
            }

            largest = 0;
        }
    }

    return( result );
}

int main() {
    vector<vector<int>> arr( 6 );
    for ( int i = 0; i < 6; i++ ) {
        arr[i].resize( 6 );

        for ( int j = 0; j < 6; j++ ) {
            cin >> arr[i][j];
        }

        cin.ignore( numeric_limits<streamsize>::max(), '\n' );
    }

    int result = hourglassSum( arr );

    cout << result << "\n";

    return 0;
}
