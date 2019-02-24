//  https://www.hackerrank.com/challenges/happy-ladybugs/

#include <bits/stdc++.h>

using namespace std;

// Complete the happyLadybugs function below.
string happyLadybugs( string &b ) {
    std::map< char, int > cells;

    for( const auto &x: b ) {
        cells[ x ]++;   //  map count for each char
    }

    if( cells.count( '_' ) == 0 ) {
        if( cells.size() == 1 ) {
            //  if only one char, must be more than one
            if( cells.begin()->second == 1 ) {
                return( "NO" );
            }

            return( "YES" );
        }

        for( const auto &x: cells ) {
            if( x.second == 1 ) {
                return( "NO");
            }

            for( unsigned long z{ 0 }; z < b.size() - 1; ++z ) {
                if( x.first == b[ z ] ) {
                    if( b[ z ] != b [ z + 1 ] ) {
                        if( b[ z ] != b[ z - 1] ) {
                            return( "NO" );
                        }
                    }

                    ++z;
                }
            }
        }
    }

    for( auto const &x: cells ) {
        if( x.first != '_' && x.second == 1 ) {
            return( "NO");
        }
    }

    return( "YES" );
}

int main() {
  int g;
  cin >> g;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int g_itr = 0; g_itr < g; g_itr++) {
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string b;
    getline(cin, b);

    string result = happyLadybugs(b);

    cout << result << "\n";
  }

  return 0;
}
