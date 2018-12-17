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
    std::vector< double > tmp( a.size() );

    for( unsigned long x{ 0 }; x <= a.size(); ++x ) {
        tmp.clear();

        tmp.assign( a.begin(), a.begin() + x + 1 );

        if( tmp.size() == 1 ) {
            result[ x ] = tmp[ 0 ];

            continue;
        }

        if( tmp.size() > 2 ) {  //  only sort when more than two elements
            std::sort( tmp.begin(), tmp.end() ) ;
        }

        if( tmp.size() & 1 ) {  //  odd
            result[ x ] = tmp[ tmp.size() / 2 ];
        } else {
            result[ x ] = ( ( tmp[ tmp.size() / 2 - 1 ] ) + tmp[ tmp.size() / 2 ] ) / 2;
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
