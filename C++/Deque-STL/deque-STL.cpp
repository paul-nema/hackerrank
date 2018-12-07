//  https://www.hackerrank.com/challenges/deque-stl/

#include <deque>
#include <iostream>
using namespace std;

void printKMax( int arr[], int n, int k ) {
    // Write your code here.
    std::deque< int > qu( k );   //  deque of size k init to 0

    auto x{ 0 };

    for( x = 0; x < k; ++x ) {
        while ( ( ! qu.empty() ) && arr[ x ] >= arr[ qu.back() ] ) {
            qu.pop_back();  //  get rid of past smaller elements
        }

        qu.push_back( x );
    }

    for( ; x < n; ++x ) { 
        std::cout << arr[ qu.front() ] << " "; 

        while ( ( ! qu.empty() ) && qu.front() <= x - k ) {
            qu.pop_front(); //  remove elements not in window
        }

        while ( ( ! qu.empty() ) && arr[ x ] >= arr[ qu.back() ] ) {
            qu.pop_back(); 
        }

        qu.push_back( x ); 
    } 

    std::cout << arr[ qu.front() ] << std::endl;;  //  print last max element
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
