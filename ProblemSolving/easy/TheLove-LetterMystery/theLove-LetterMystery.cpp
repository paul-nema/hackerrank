//  https://www.hackerrank.com/challenges/the-love-letter-mystery/

#include <bits/stdc++.h>

using namespace std;

// Complete the theLoveLetterMystery function below.
int theLoveLetterMystery( std::string &s ) {
    auto changes{ 0 };

    for( unsigned long x{ 0 }; x < s.size() / 2; ++x ) {
        changes += std::abs( s[ x ] - s[ s.size() - x - 1 ] );
    }

    return( changes );
}

int main() {
    int q;
    cin >> q;
    cin.ignore( numeric_limits< streamsize >::max(), '\n' );

    for ( int q_itr = 0; q_itr < q; q_itr++ ) {
        string s;
        getline( cin, s );

        int result = theLoveLetterMystery( s );

        cout << result << "\n";
    }

    return 0;
}
