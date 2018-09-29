#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// Complete the pangrams function below.
string pangrams(string &s) {
    std::array<bool, 26> alphabet{{ false }};

    auto total = 0; // count each letter found

    for( char c: s ) {
        if( ! std::isalpha( c ) ) {
            continue;   // Ignore whitespace
        }

        // Use c to index the array
        c = std::tolower( c ) - 'a';

        if( alphabet[ c ] == false ) {
            alphabet[ c ] = true;
            ++total;
        }
    }

    if( total == 26 ) {
        return( string("pangram") );
    }

    return( string("not pangram") );
}

int main()
{
    string s;
    getline(cin, s);

    string result = pangrams(s);

    cout << result << "\n";

    return 0;
}
