//  https://www.hackerrank.com/challenges/deque-stl/

#include <deque>
#include <iostream>
using namespace std;

void printKMax(int arr[], int n, int k) {
    // Write your code here.
    deque< int > dq( k );

    for( auto x = 0; x < k; ++x ) {
        while ( ( ! dq.empty() ) && arr[ x ] >= arr[ dq.back() ] ) {
            dq.pop_back();
        }

        dq.push_back( x );
    }
}

void printKMax1(int arr[], int n, int k) {
    // Write your code here.
    auto max = 0;

    for( auto x = 0; x < ( n - k + 1 ); ++x ) {
        for( auto y = x; y < x + k; ++y ) {
            if( arr[ y ] > max ) {
                max = arr[ y ];
            }
        }

        std::cout << max << " ";

        max = 0;
    }

    std::cout << std::endl;
}

int main() {

  int t;
  cin >> t;
  while (t > 0) {
    int n, k;
    cin >> n >> k;
    int i;
    int arr[n];
    for (i = 0; i < n; i++)
      cin >> arr[i];
    printKMax(arr, n, k);
    t--;
  }
  return 0;
}
