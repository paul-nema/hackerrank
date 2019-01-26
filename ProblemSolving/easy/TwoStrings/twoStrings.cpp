//  https://www.hackerrank.com/challenges/two-strings/

#include <bits/stdc++.h>

using namespace std;

// Complete the twoStrings function below.
//  Complete the function twoStrings in the editor below.
//  It should return a string, either YES or NO based on whether the strings
//  share a common substring.
string twoStrings( const string &s1, const string &s2 ) {
    int letters[ 26 ] = { 0 };

    unsigned long x{ 0 };

    for( ; x < s1.size(); ++x ) {   //  set array element to non zero for each letter
        letters[ s1[ x ] - 'a' ]++;
    }

    for( x = 0; x < s2.size(); ++x ) {
        if( letters[ s2[ x ] - 'a' ] != 0 ) {
            return( "YES" );    //  If not zero return YES
        }
    }

    return( "NO" );
}

int main() {
    int q;
    cin >> q;
    cin.ignore( numeric_limits< streamsize >::max(), '\n' );

    for ( int q_itr = 0; q_itr < q; q_itr++ ) {
        string s1;
        getline( cin, s1 );

        string s2;
        getline( cin, s2 );

        string result = twoStrings( s1, s2 );

        cout << result << "\n";
    }

    return 0;
}
