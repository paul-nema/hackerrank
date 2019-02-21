//  https://www.hackerrank.com/challenges/two-arrays/

#include <bits/stdc++.h>

using namespace std;

vector< string > split_string( string );

// Complete the twoArrays function below.
std::string twoArrays( int k, std::vector< int > &A, std::vector< int > &B ) {
    std::sort( A.begin(), A.end(), greater< int >() );
    std::sort( B.begin(), B.end(), less< int >() );

    for( unsigned long x{ 0 }; x < A.size(); ++x ) {
        if( A[ x ] + B[ x ] < k ) {
            return( "NO" );
        }
    }

    return( "YES" );
}

int main() {
    int q;
    cin >> q;
    cin.ignore( numeric_limits< streamsize >::max(), '\n' );

    for ( int q_itr = 0; q_itr < q; q_itr++ ) {
        string nk_temp;
        getline( cin, nk_temp );

        vector< string > nk = split_string( nk_temp );

        int n = stoi( nk[ 0 ] );

        int k = stoi( nk[ 1 ] );

        string A_temp_temp;
        getline( cin, A_temp_temp );

        vector< string > A_temp = split_string( A_temp_temp );

        vector< int > A( n );

        for ( int i = 0; i < n; i++ ) {
            int A_item = stoi( A_temp[ i ] );

            A[ i ] = A_item;
        }

        string B_temp_temp;
        getline( cin, B_temp_temp );

        vector< string > B_temp = split_string( B_temp_temp );

        vector< int > B( n );

        for ( int i = 0; i < n; i++ ) {
            int B_item = stoi( B_temp[ i ] );

            B[ i ] = B_item;
        }

        string result = twoArrays( k, A, B );

        cout << result << "\n";
    }

    return 0;
}

vector< string > split_string( string input_string ) {
    string::iterator new_end = unique(
        input_string.begin(), input_string.end(),
        []( const char &x, const char &y ) { return x == y and x == ' '; } );

    input_string.erase( new_end, input_string.end() );

    while ( input_string[ input_string.length() - 1 ] == ' ' ) {
        input_string.pop_back();
    }

    vector< string > splits;
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
