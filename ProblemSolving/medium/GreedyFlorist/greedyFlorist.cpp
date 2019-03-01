//  https://www.hackerrank.com/challenges/greedy-florist/

#include <bits/stdc++.h>

using namespace std;

vector< string > split_string( string );

// Complete the getMinimumCost function below.
int getMinimumCost( int k, std::vector< int > &c ) {
    auto total{ 0 };
    auto diff{ c.size() - k };

    std::sort( c.begin(), c.end() );

    for( auto x{ diff }; x < c.size(); ++x ) {
        total += c[ x ];
    }

    for( int x{ static_cast< int >( diff ) - 1 }, cnt{ k }; x >= 0; --x, ++cnt ) {
        total += c[ x ] * ( 1 + ( cnt / k ) );
    }

    return( total );
}

int main() {
    string nk_temp;
    getline( cin, nk_temp );

    vector< string > nk = split_string( nk_temp );

    int n = stoi( nk[ 0 ] );

    int k = stoi( nk[ 1 ] );

    string c_temp_temp;
    getline( cin, c_temp_temp );

    vector< string > c_temp = split_string( c_temp_temp );

    vector< int > c( n );

    for ( int i = 0; i < n; i++ ) {
        int c_item = stoi( c_temp[ i ] );

        c[ i ] = c_item;
    }

    int minimumCost = getMinimumCost( k, c );

    cout << minimumCost << "\n";

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
