//  https://www.hackerrank.com/challenges/library-fine/

#include <iostream>

using namespace std;

// Complete the libraryFine function below.
//  d1, m1, y1: returned date day, month and year
//  d2, m2, y2: due date day, month and year
int libraryFine(int d1, int m1, int y1, int d2, int m2, int y2) {
    constexpr auto yearlyFine( 10000 );
    constexpr auto monthlyFine( 500 );
    constexpr auto dailyFine( 15 );
    constexpr auto noFine( 0 );

    if( y1 < y2 ) {
        return( noFine );
    } else if ( y1 > y2 ) {
        return( yearlyFine );
    }

    if( m1 < m2 ) { //  y1 == y2
        return( noFine );
    } else if ( m1 > m2 ) {
        return( monthlyFine * ( m1 - m2 ) );
    }

    if( d1 <= d2 ) {    //  y1 == y2 && m1 == m2
        return( noFine );
    } else if ( d1 > d2 ) {
        return( dailyFine * ( d1 - d2 ) );
    }

    return( noFine );
}

int main() {
    auto y1( 0 );
    auto m1( 0 );
    auto d1( 0 );
    auto y2( 0 );
    auto m2( 0 );
    auto d2( 0 );

    std::cin >> d1 >> m1 >> y1;
    std::cin >> d2 >> m2 >> y2;

    int result = libraryFine(d1, m1, y1, d2, m2, y2);

    cout << result << "\n";

  return 0;
}
