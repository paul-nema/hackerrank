#include <bits/stdc++.h>

using namespace std;

// Complete the utopianTree function below.
//  n: an integer, the number of growth cycles to simulate
int utopianTree(int n) {
    auto height = 1;

    for( auto x = 1; x <= n; ++x ) {
        if( x & 1  ) {
            height *= 2;
        } else {
            ++height;
        }
    }

    return( height );
}

int main() {
  int t;
  cin >> t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int t_itr = 0; t_itr < t; t_itr++) {
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = utopianTree(n);

    cout << result << "\n";
  }

  return 0;
}
