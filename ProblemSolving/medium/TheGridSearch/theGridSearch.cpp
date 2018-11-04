//  https://www.hackerrank.com/challenges/the-grid-search/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string( string );

// Complete the gridSearch function below.
//  G: the grid to search, an array of strings
//  P: the pattern to search for, an array of strings
//      return: YES or NO, depending on whether P is present in G
string gridSearch( vector<string> &G, vector<string> &P ) {
    auto found( false );
    auto cnt( 0 );

    std::size_t firstFind( 0 );

    unsigned long y( 0 );

    for( unsigned long x( 0 ); x < G.size(); ++x ) {
        firstFind = G[ x ].find( P[ 0 ], firstFind );  // look for 1st line of P in G

        if( firstFind != std::string::npos ) {  //  found 1st line of P
            cnt = x;

            for( y = 1; y < P.size(); ++y ) {
                ++cnt;

                if( G[ cnt ].find( P[ y ].data(), firstFind, P[ y ].size() ) != firstFind
                        || cnt >= G.size() ) {
                    break;
                }
            }

            if( y >= P.size() ) {
                return( "YES" );
            }

            ++firstFind;    //  search rest of line x
            --x;

            continue;
        }

        firstFind = 0;
    }

    return( "NO" );
}


int main() {
    int t;
    cin >> t;
    cin.ignore( numeric_limits<streamsize>::max(), '\n' );

    for ( int t_itr = 0; t_itr < t; t_itr++ ) {
        string RC_temp;
        getline( cin, RC_temp );

        vector<string> RC = split_string( RC_temp );

        int R = stoi( RC[0] );

        int C = stoi( RC[1] );

        vector<string> G( R );

        for ( int i = 0; i < R; i++ ) {
            string G_item;
            getline( cin, G_item );

            G[i] = G_item;
        }

        string rc_temp;
        getline( cin, rc_temp );

        vector<string> rc = split_string( rc_temp );

        int r = stoi( rc[0] );

        int c = stoi( rc[1] );

        vector<string> P( r );

        for ( int i = 0; i < r; i++ ) {
            string P_item;
            getline( cin, P_item );

            P[i] = P_item;
        }

        string result = gridSearch( G, P );

        cout << result << "\n";
    }

    return 0;
}

vector<string> split_string( string input_string ) {
    string::iterator new_end = unique(
        input_string.begin(), input_string.end(),
        []( const char &x, const char &y ) { return x == y and x == ' '; } );

    input_string.erase( new_end, input_string.end() );

    while ( input_string[input_string.length() - 1] == ' ' ) {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find( delimiter );

    while ( pos != string::npos ) {
        splits.push_back( input_string.substr( i, pos - i ) );

        i = pos + 1;
        pos = input_string.find( delimiter, i );
    }

    splits.push_back(
        input_string.substr( i, min( pos, input_string.length() ) - i + 1 ) );

    return splits;
}
