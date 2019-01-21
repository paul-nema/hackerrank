//  https://www.hackerrank.com/challenges/two-characters/

#include <bits/stdc++.h>

using namespace std;

bool isAlternating( std::string &str ) {
    for( unsigned long x{ 2 }; x < str.size(); ++x ) {
        if( x & 1 ) {   //  odd
            if( str[ x ] != str[ 1 ] ) {
                return( false ) ;
            }
        } else {
            if( str[ x ] != str[ 0 ] ) {
                return( false ) ;
            }
        }
    }

    return( true );
}

// Complete the alternate function below.
int alternate( std::string &s ) {
    if( s.size() < 2 ) {    //  edge cases
        return( 0 );
    } else if ( s.size() == 2 ) {
        if( s[ 0 ] != s[ 1 ] ) {
            return( s.size() );
        } else {
            return( 0 );
        }
    }

    std::string tmp( s );
    std::sort( tmp.begin(), tmp.end() );    //  create list of unique letters
    std::vector< char > uniq( tmp.begin(), tmp.end() );
    uniq.erase( std::unique( uniq.begin(), uniq.end() ), uniq.end() );

    unsigned long cnt{ 0 };
    unsigned long x{ 0 };
    unsigned long y{ 0 };

    std::vector< std::pair< char, char > > pairs;

    for( ; x < uniq.size(); ++x ) { //  create list of valid pairs
        for( y = x + 1; y < uniq.size(); ++y ) {
            pairs.push_back( std::make_pair( uniq[ x ], uniq[ y ] ) );
        }
    }

    for( x = 0; x < pairs.size(); ++x ) {    //  test each pair
        tmp = s;

        for( y = 0; y < uniq.size(); ++y ) {    //  erase all non pair chars
            if( uniq[ y ] == pairs[ x ].first || uniq[ y ] == pairs[ x ].second ) {
                continue;
            }

            tmp.erase( std::remove( tmp.begin(),  tmp.end(), uniq[ y ] ), tmp.end());
        }

        if ( isAlternating( tmp ) ) {
            if( tmp.size() > cnt ) {
                cnt = tmp.size();
            }
        }
    }

    return( cnt );
}

int main() {
  int l;
  std::cin >> l;
  std::cin.ignore( numeric_limits< streamsize >::max(), '\n' );

  std::string s;
  getline(cin, s);

  int result = alternate(s);

  cout << result << "\n";

  return 0;
}
