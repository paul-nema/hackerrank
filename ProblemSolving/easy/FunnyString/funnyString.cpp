//  https://www.hackerrank.com/challenges/funny-string/

#include <bits/stdc++.h>

using namespace std;

// Complete the funnyString function below.
std::string funnyString( const std::string &s ) {
    unsigned long x{ 1 };
    auto y{ s.size() - 1 };
    auto half{ s.size() & 1 ? s.size() / 2 + 1 : s.size() / 2 };

    for( ; x < half; ++x, --y ) {
        if( std::abs( s[ x - 1 ] - s[ x ] ) != std::abs( s[ y ] - s[ y - 1 ] ) ) {
            return( "Not Funny" );
        }
    }

    return( "Funny" );
}

//  The first line contains an integer q, the number of queries. 
//  The next q lines each contain a string, s.
int main() {
    int q;
    cin >> q;
    cin.ignore( numeric_limits<streamsize>::max(), '\n' );

    for ( int q_itr = 0; q_itr < q; q_itr++ ) {
        string s;
        getline( cin, s );

        string result = funnyString( s );

        cout << result << "\n";
    }

    return 0;
}
