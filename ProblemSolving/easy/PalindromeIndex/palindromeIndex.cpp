//  https://www.hackerrank.com/challenges/palindrome-index/

#include <bits/stdc++.h>

using namespace std;

bool isPalidrome( std::string &s, int begin, int end ) {
    for( ; begin < end; ++begin, --end ) {
        if( s[ begin ] != s[ end ] ) {
            return( false );
        }
    }

    return ( true );
}

// Complete the palindromeIndex function below.
int palindromeIndex( std::string &s ) {
    unsigned long begin{ 0 };
    unsigned long end{ s.size() -1 };

    for( ; begin < end; ++begin, --end ) {
        if( s[ begin ] != s[ end ] ) {
            if( isPalidrome( s, begin, end - 1 ) ) {
                return( end );
            } else if ( isPalidrome( s, begin + 1, end ) ) {
                return( begin );
            } else {
                return( -1 );
            }
        }
    }

    return( -1 );
}

int main() {
    int q;
    cin >> q;
    cin.ignore( numeric_limits< streamsize >::max(), '\n' );

    for ( int q_itr = 0; q_itr < q; q_itr++ ) {
        std::string s;
        getline( cin, s );

        int result = palindromeIndex( s );

        std::cout << result << "\n";
    }

    return 0;
}
