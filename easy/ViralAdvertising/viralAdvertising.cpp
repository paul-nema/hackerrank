//  https://www.hackerrank.com/challenges/strange-advertising/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the viralAdvertising function below.
//  n: denoting a number of days
int viralAdvertising(int n) {
    auto liked = 2;
    auto cumalative = 2;

    for( auto x = 2; x <= n; ++x ) {
        liked = ( liked * 3 ) / 2;
        cumalative += liked;
    }

    return( cumalative );
}

int main() {
  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  int result = viralAdvertising(n);

  cout << result << "\n";

  return 0;
}
