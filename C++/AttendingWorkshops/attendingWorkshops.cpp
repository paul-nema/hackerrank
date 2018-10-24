//  https://www.hackerrank.com/challenges/attending-workshops/

#include <bits/stdc++.h>

using namespace std;

// Define the structs Workshops and Available_Workshops.
// Implement the functions initialize and CalculateMaxWorkshops

struct Workshop {
    int start_time;
    int duration;
    int end_time;
};

struct Available_Workshops {
    Available_Workshops( int num ) : n( num ), workshops( n ) {}

    int n;

    std::vector< Workshop > workshops;
};

Available_Workshops* initialize( int start_time[], int duration[], int n ) {
    Available_Workshops *aw = new Available_Workshops( n );

    for( auto x( 0 ); x < n; ++x ) {
        aw->workshops[ x ].start_time = start_time[ x ];
        aw->workshops[ x ].duration = duration[ x ];
        aw->workshops[ x ].end_time = start_time[ x ] + duration[ x ];
    }

    return( aw );
}

int CalculateMaxWorkshops(Available_Workshops* ptr) {
    std::sort( ptr->workshops.begin(), ptr->workshops.end(),
        []( const Workshop &a, const Workshop &b ) {
            return( a.end_time < b.end_time );  //  Sort by end time
        } );

    auto cnt( 1 );  //  we'll always attend the first one
    auto lastEndTm( ptr->workshops[ 0 ].end_time );

    for( auto x( 1 ); x < ptr->n; ++x ) {
        if( ptr->workshops[ x ].start_time >= lastEndTm ) {
            lastEndTm = ptr->workshops[ x ].end_time;
            ++cnt;
        }
    }

    return( cnt );
}

int main( int argc, char* argv[] ) {
    int n;  // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for ( int i = 0; i < n; i++ ) {
        cin >> start_time[i];
    }
    for ( int i = 0; i < n; i++ ) {
        cin >> duration[i];
    }

    Available_Workshops* ptr;
    ptr = initialize( start_time, duration, n );
    cout << CalculateMaxWorkshops( ptr ) << endl;
    return 0;
}
