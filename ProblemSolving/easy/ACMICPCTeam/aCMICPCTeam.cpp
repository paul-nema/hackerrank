//  https://www.hackerrank.com/challenges/acm-icpc-team/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string( string );

// Complete the acmTeam function below.
vector<int> acmTeam( vector<string> topic ) {
    vector< int > result = { 0, 0 };

    std::map< int, int > teams;

    auto maxTopics( 0 );

    for( unsigned long x( 0 ); x < topic.size(); ++x ) {
        for( unsigned long y( x + 1 ); y < topic.size(); ++y ) {
            for( unsigned long z( 0 ); z < topic[ x ].size(); ++z ) {
                if( topic[ x ][ z ] == '1' || topic[ y ][ z ] == '1' ) {
                    ++maxTopics;
                }
            }

            teams[ maxTopics ]++;   //  count teams

            if( maxTopics > result[ 0 ] ) {
                result[ 0 ] = maxTopics;  //  max num of topics
            }

            maxTopics = 0;  //  reset variable
        }

    }

    //  Find the largest key which gives the # of teams
    result[ 1 ] = std::max_element( std::begin( teams ), std::end( teams ),
            [] ( const auto & p1, const auto & p2 ) {
                return p1.first < p2.first;
            })->second;

    return( result );
}

int main() {
    string nm_temp;
    getline( cin, nm_temp );

    vector<string> nm = split_string( nm_temp );

    int n = stoi( nm[0] );

    int m = stoi( nm[1] );

    vector<string> topic( n );

    for ( int i = 0; i < n; i++ ) {
        string topic_item;
        getline( cin, topic_item );

        topic[i] = topic_item;
    }

    vector<int> result = acmTeam( topic );

    for ( int i = 0; i < result.size(); i++ ) {
        cout << result[i];

        if ( i != result.size() - 1 ) {
            cout << "\n";
        }
    }

    cout << "\n";

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
