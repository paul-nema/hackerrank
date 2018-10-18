#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
// n: the number of steps in Gary's hike
// s:  characters describing his path
int countingValleys(int n, string &s) {
    int prev{ 0 };
    int valleys{ 0 };
    int elevation{ 0 };

    for( auto const &step: s ) {
        prev = elevation;

        if( step == 'D' ) {
            --elevation;

            if( prev == 0 && elevation == -1 ) {
                ++valleys;
            }
        } else {
            ++elevation;
        }

    }

    return( valleys );
}

int main() {
  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string s;
  getline(cin, s);

  int result = countingValleys(n, s);

  cout << result << "\n";

  return 0;
}
