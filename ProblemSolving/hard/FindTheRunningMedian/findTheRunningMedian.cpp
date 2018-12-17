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

    std::priority_queue< int, std::vector< int >, std::greater< int > > minHeap;
    std::priority_queue< int > maxHeap;

    double medium = a[ 0 ];

    for( unsigned long x{ 0 }; x < a.size(); ++x ) {
        if( a[ x ] > medium ) {
            minHeap.push( a[ x ] );
        } else {
            maxHeap.push( a[ x ] );
        }

        if( minHeap.size() > maxHeap.size() + 1 ) {
            maxHeap.push( minHeap.top() );

            minHeap.pop();
        }

        if( maxHeap.size() > minHeap.size() + 1 ) {
            minHeap.push( maxHeap.top() );

            maxHeap.pop();
        }

        if( minHeap.size() == maxHeap.size() ) {
            result[ x ] = medium = ( maxHeap.top() + minHeap.top() ) / 2.0;

        } else if( minHeap.size() > maxHeap.size() ) {
            result[ x ] = medium = static_cast< double >( minHeap.top() );

        } else {
            result[ x ] = medium = static_cast< double >( maxHeap.top() );
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
