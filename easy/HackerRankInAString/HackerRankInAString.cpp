#include <bits/stdc++.h>
#include <string>
#include <iostream>

using namespace std;

// Complete the hackerrankInString function below.
string hackerrankInString(string &s) {
    // Keep track of the position in the given string
    auto pos = 0;

    // Looking for this string
    static string str("hackerrank");

    for( auto x = 0; x < str.size(); ++x ) {
        pos = s.find( str[ x ], pos );

        if( pos == std::string::npos ) {
            return( "NO" );
        }

        ++pos;
    }

    return( "YES" );
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        string result = hackerrankInString(s);

        cout << result << "\n";
    }

    return 0;
}

