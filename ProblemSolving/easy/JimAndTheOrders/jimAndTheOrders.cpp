//  https://www.hackerrank.com/challenges/jim-and-the-orders/

#include <bits/stdc++.h>

using namespace std;

struct cmp {
    bool operator() ( std::pair< int, int > lhs, std::pair< int, int > rhs ) {
        return( lhs.first < rhs.first );
    }
};

// Complete the jimOrders function below.
std::vector< int > jimOrders( std::vector< std::vector< int > > &orders ) {
    std::vector< int > result( orders.size(), 0 );  //  orders.size() = # of customers

    std::multiset< std::pair< int, int >, cmp > serve;

    unsigned long x{ 0 };   //  array index

    for( ; x < orders.size(); ++x ) {
        //  Pair:   first = order number,   second = customer number
        serve.insert( std::make_pair( orders[ x ][ 0 ] + orders[ x ][ 1 ], x ) );
    }

    x = -1;

    for( auto it = serve.begin(); it != serve.end(); ++it ) {
        result[ ++x ] = it->second + 1;
    }

    return( result );
}

int main() {
    int n;
    cin >> n;
    cin.ignore( numeric_limits< streamsize >::max(), '\n' );

    vector< vector< int > > orders( n );

    for ( int i = 0; i < n; i++ ) {
        orders[ i ].resize( 2 );

        for ( int j = 0; j < 2; j++ ) {
            cin >> orders[ i ][ j ];
        }

        cin.ignore( numeric_limits< streamsize >::max(), '\n' );
    }

    vector< int > result = jimOrders( orders );

    for ( unsigned long i = 0; i < result.size(); i++ ) {
        cout << result[ i ];

        if ( i != result.size() - 1 ) {
            cout << " ";
        }
    }

    cout << "\n";

    return 0;
}
