//  https://www.hackerrank.com/challenges/30-conditional-statements/problem

#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  if( N & 1 ) {
      std::cout << "Weird\n";
  } else if( N <= 5 && N >= 2 ) {
      std::cout << "Not Weird\n";
  } else if( N <= 20 && N >= 6 ) {
      std::cout << "Weird\n";
  } else {
      std::cout << "Not Weird\n";
  }

  return 0;
}
