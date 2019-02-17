//  https://www.hackerrank.com/challenges/anagram/

#include <bits/stdc++.h>

using namespace std;

// Complete the anagram function below.
int anagram( std::string &s ) {
    if( s.size() & 1 ) {    //  odd number of chars cannot be an anagram
        return( -1 );
    }

    std::vector< int > left( 26, 0 );
    std::vector< int > right( 26, 0 );

    unsigned long x{ 0 };
    unsigned long total{ 0 };

    for( ; x < s.size(); ++x ) {
        if( x < s.size() / 2 ) {    //  divide word in half
            left[ s[ x ] - 'a' ]++; //  add 1 for each letter
        } else {
            right[ s[ x ] - 'a' ]++;    //  add 1 for each letter
        }
    }

    for( x = 0; x < left.size(); ++x ) {    //  subtract the two vectors
        total += std::abs( left[ x ] - right[ x ] );
    }

    return( total / 2 );
}


int main() {
    int q;
    cin >> q;
    cin.ignore( numeric_limits< streamsize >::max(), '\n' );

    for ( int q_itr = 0; q_itr < q; q_itr++ ) {
        string s;
        getline( cin, s );

        int result = anagram( s );

        cout << result << "\n";
    }

    return 0;
}
