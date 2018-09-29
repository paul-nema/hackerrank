//  https://www.hackerrank.com/challenges/30-loops/

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for( auto x = 1; x <= 10; ++x ) {
      std::cout << n <<  " x " << x <<  " = " << x * n << "\n";
  }

  return 0;
}
