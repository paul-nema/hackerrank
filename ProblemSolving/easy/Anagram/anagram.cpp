//  https://www.hackerrank.com/challenges/anagram/

#include <bits/stdc++.h>

using namespace std;

// Complete the anagram function below.
int anagram( std::string &s ) {
    if( s.size() & 1 ) {    //  odd number of chars cannot be an anagram
        return( -1 );
    }

    std::map< char, int > cnt;

    for( char c: s ) {
        cnt[ c ]++;
    }

    return( -1 );
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
