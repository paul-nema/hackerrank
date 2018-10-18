#include <bits/stdc++.h>

using namespace std;

// Complete the strangeCounter function below.
long strangeCounter(long t) {
    long current = 1;
    long counter = 3;

    do {
        if( current == t ) {
            return( t + 2 );
        }

        current += counter;
        counter *= 2;
    } while( t >= current );

    return( current - t ) ;
}

int main() {
  long t;
  cin >> t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  long result = strangeCounter(t);

  cout << result << "\n";

  return 0;
}
