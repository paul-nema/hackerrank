//  https://www.hackerrank.com/challenges/alternating-characters/

#include <bits/stdc++.h>

using namespace std;

// Complete the alternatingCharacters function below.
int alternatingCharacters( const std::string &s ) {
    auto cnt{ 0 };

    for( unsigned long x{ 1 }; x < s.size(); ++x ) {
        if( s[ x - 1 ] == s[ x ] ) {
            ++cnt;
        }
    }

    return( cnt );
}

int main() {
  int q;
  cin >> q;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int q_itr = 0; q_itr < q; q_itr++) {
    string s;
    getline(cin, s);

    int result = alternatingCharacters(s);

    cout << result << "\n";
  }

  return 0;
}
