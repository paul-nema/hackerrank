//  https://www.hackerrank.com/challenges/beautiful-binary-string/

#include <bits/stdc++.h>

using namespace std;

// Complete the beautifulBinaryString function below.
int beautifulBinaryString( const std::string &b ) {
    auto cnt{ 0 };

    for( unsigned long x{ 2 }; x < b.size(); ++x ) {
        if( b[ x ] == '0' && b[ x - 1 ] == '1' && b[ x - 2] == '0' ) {
            ++cnt;

            x += 2; //  only add 2 as the for loop will add one too
        }
    }

    return( cnt );
}

int main() {
  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string b;
  getline(cin, b);

  int result = beautifulBinaryString(b);

  cout << result << "\n";

  return 0;
}
