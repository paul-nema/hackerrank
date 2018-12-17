//  https://www.hackerrank.com/challenges/find-the-running-median/

#include <bits/stdc++.h>

using namespace std;

/*
*   Complete the runningMedian function below.
*/
std::vector< double > runningMedian( vector< int > &a ) {
    /*
    *   Write your code here.
    */
    std::vector< double > result( a.size() );

    auto tmp{ 0 };

    for( unsigned long x{ 0 }; x < a.size(); ++x ) {
        if( x == 0 ) {
            result[ 0 ] = a[ 0 ];

            continue;
        }

        for( unsigned long y{ 0 }; y < x; ++y ) {
            if( a[ y ] > a[ x ] ) {   //  only sort the last value in the set
                tmp = a[ y ];
                a[ y ] = a[ x ];
                a[ x ] = tmp;
            }
        }

        tmp = ( x + 1 ) / 2;

        if( ( x + 1 ) & 1 ) {  //  even
            result[ x ] = a[ tmp ];
        } else {
            result[ x ] = ( ( a[ tmp - 1 ] + a[ tmp ] ) / 1.0 ) / 2;
        }
    }

    return( result );
}


int main() {
  int a_count;
  cin >> a_count;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<int> a(a_count);

  for (int a_itr = 0; a_itr < a_count; a_itr++) {
    int a_item;
    cin >> a_item;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    a[a_itr] = a_item;
  }

  vector<double> result = runningMedian(a);

  for (unsigned long result_itr = 0; result_itr < result.size(); result_itr++) {
    cout << result[result_itr];

    if (result_itr != result.size() - 1) {
      cout << "\n";
    }
  }

  cout << "\n";

  return 0;
}
