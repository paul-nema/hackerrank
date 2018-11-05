//  https://www.hackerrank.com/challenges/append-and-delete/

#include <bits/stdc++.h>

using namespace std;

// Complete the appendAndDelete function below.
//  s: the initial string. 
//  t: the desired final string. 
//  k: the number of operations.
//      return: Yes or No
string appendAndDelete(string s, string t, int k) {
    unsigned long inCommon( 0 );

    for( unsigned long x( 0 ); x < std::min( s.size(), t.size() ); ++x ) {
        if( s[ x ] == t[ x ] ) {
            ++inCommon;
        } else {
            break;
        }
    }

    if( ( s.size() == t.size() && inCommon == t.size() )
            || ( s.size() - inCommon ) + ( t.size() - inCommon ) == static_cast< unsigned long >( k ) ) {
        return( "Yes" );
    }

    if( ( s.size() - inCommon ) + ( t.size() - inCommon ) < static_cast< unsigned long >( k ) ) {
        if( k & 1 ) {
            return( "Yes" );
        }

        if( ! ( ( s.size() + t.size() - k ) & 1 ) ) {
            return( "Yes" );
        }
    }

    return( "No" );
}

int main() {
  string s;
  getline(cin, s);

  string t;
  getline(cin, t);

  int k;
  cin >> k;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string result = appendAndDelete(s, t, k);

  cout << result << "\n";

  return 0;
}
