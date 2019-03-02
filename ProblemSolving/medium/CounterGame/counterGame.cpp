//  https://www.hackerrank.com/challenges/counter-game/

#include <bits/stdc++.h>

using namespace std;

enum Turn {
    LOUISE,
    RICHARD
};

Turn& operator++(Turn& t) {
        return( t = ( t == Turn::RICHARD ) ? Turn::LOUISE : Turn::RICHARD );
}

bool isPowerOfTwo (unsigned int x) {
      return ((x != 0) && ((x & (~x + 1)) == x));
}

// Complete the counterGame function below.
string counterGame( long n ) {
    Turn whosTurn( Turn::RICHARD );

    long x{ 2 };

    while( n != 1 ) {
        ++whosTurn;
        x = 2;

        if( isPowerOfTwo( n ) ) {
            n /= 2;
        } else {
            while( x * 2 < n ) {
                x *= 2;
            }

            n -= x;
        }
    }

    return( ( whosTurn == Turn::LOUISE ) ? "Louise" : "Richard" );
}

int main() {
    int t;
    cin >> t;
    cin.ignore( numeric_limits<streamsize>::max(), '\n' );

    for ( int t_itr = 0; t_itr < t; t_itr++ ) {
        long n;
        cin >> n;
        cin.ignore( numeric_limits<streamsize>::max(), '\n' );

        string result = counterGame( n );

        cout << result << "\n";
    }

    return 0;
}
