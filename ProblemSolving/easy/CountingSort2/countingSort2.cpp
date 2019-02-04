//  https://www.hackerrank.com/challenges/countingsort2/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string( string );

const int MAX_ARRAY_SIZE{100};

// Complete the countingSort function below.
std::vector<int> countingSort( const std::vector<int> &arr ) {
    std::vector<int> sorted( MAX_ARRAY_SIZE, 0 );
    std::vector<int> result;

    auto y{ 0 };

    for ( const auto x : arr ) {
        sorted[x]++;
    }

    for ( unsigned long x{0}; x < sorted.size(); ++x ) {
        if( sorted[ x ] == 0 ) {
            continue;
        }

        for( y = 0; y < sorted[ x ]; ++y ) {
            result.push_back( x );
        }
    }

    return ( result );
}

int main() {
    int n;
    cin >> n;
    cin.ignore( numeric_limits<streamsize>::max(), '\n' );

    string arr_temp_temp;
    getline( cin, arr_temp_temp );

    vector<string> arr_temp = split_string( arr_temp_temp );

    vector<int> arr( n );

    for ( int i = 0; i < n; i++ ) {
        int arr_item = stoi( arr_temp[i] );

        arr[i] = arr_item;
    }

    vector<int> result = countingSort( arr );

    for ( int i = 0; i < result.size(); i++ ) {
        cout << result[i];

        if ( i != result.size() - 1 ) {
            cout << " ";
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
