//  https://www.hackerrank.com/challenges/magic-square-forming/

#include <bits/stdc++.h>

using namespace std;

//  8 possible combinations of magic squares
//  https://www.youtube.com/watch?v=zPnN046OM34
const std::vector< std::vector< std::vector< int > > > magic = {
    { { 8, 1, 6 }, { 3, 5, 7 }, { 4, 9, 2 } },
    { { 6, 1, 8 }, { 7, 5, 3 }, { 2, 9, 4 } },
    { { 4, 9, 2 }, { 3, 5, 7 }, { 8, 1, 6 } },
    { { 2, 9, 4 }, { 7, 5, 3 }, { 6, 1, 8 } }, 
    { { 8, 3, 4 }, { 1, 5, 9 }, { 6, 7, 2 } },
    { { 4, 3, 8 }, { 9, 5, 1 }, { 2, 7, 6 } }, 
    { { 6, 7, 2 }, { 1, 5, 9 }, { 8, 3, 4 } }, 
    { { 2, 7, 6 }, { 9, 5, 1 }, { 4, 3, 8 } }
};

//  Complete the formingMagicSquare function below.
//  Compare the 8 possible magic square and get lowest count
int formingMagicSquare(const vector< vector< int > > &s ) {
    auto lowest{ std::numeric_limits< int >::max() };
    auto cnt{ 0 };

    for( auto ms: magic ) {
        for( unsigned long sq{ 0 } ; sq < s.size(); ++sq ) {
            for( unsigned long cell{ 0 }; cell < s[ sq ].size(); ++cell ) {
                cnt += std::abs( s[ sq ][ cell ] - ms[ sq ][ cell ] );
            }
        }

        if( cnt < lowest ) {
            lowest = cnt;
        }

        cnt = 0;    //  reinitialize for the next run
    }

    return( lowest );
}


int main() {
  vector< vector< int > > s( 3 );

  for ( int i = 0; i < 3; i++ ) {
    s[ i ].resize( 3 );

    for ( int j = 0; j < 3; j++ ) {
      cin >> s[ i ][ j ];
    }

    cin.ignore( numeric_limits< streamsize >::max(), '\n' );
  }

  int result = formingMagicSquare( s );

  cout << result << "\n";

  return 0;
}
