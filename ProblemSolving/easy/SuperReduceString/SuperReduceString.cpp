//  https://www.hackerrank.com/challenges/reduced-string/

#include <bits/stdc++.h>

using namespace std;

// Complete the superReducedString function below.
string superReducedString(string &s) {
    bool done = false;

    auto x = 0;
    auto strSize = s.size();

    while( done == false ) {
        if( s.size() == 0 ) {
            return( "Empty String" );
        }

        for( x = 0; x < s.size() - 1; ++x ){
            if( s[ x ] == s[ x + 1 ] ) {
                s.erase( x, 2 );
                break;
            }
        }

        if( x + 1 == strSize ) {
            done = true;
        }

        strSize = s.size();
    }

    return( s );
}

int main()
{
    string s;
    getline(cin, s);

    string result = superReducedString(s);

    cout << result << "\n";

    return 0;
}

