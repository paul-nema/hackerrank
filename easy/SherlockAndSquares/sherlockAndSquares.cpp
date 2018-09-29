//  https://www.hackerrank.com/challenges/sherlock-and-squares/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the squares function below.
//  a: an integer, the lower range boundary
//  b: an integer, the uppere range boundary
int squares(int a, int b) {
    auto result( 0 );
    long double sq;

    for( double x = a; x <= b; ++x ) {
        sq = std::sqrt( x );

        if( ( sq - std::floor( sq ) ) == 0 ) {   //  find the first perfect square
            ++result;

            while( std::pow( ++sq , 2 ) <= b ) {
                ++result;
            }

            return( result );
        }
    }

    return( result );
}

int main() {
  int q;
  cin >> q;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int q_itr = 0; q_itr < q; q_itr++) {
    string ab_temp;
    getline(cin, ab_temp);

    vector<string> ab = split_string(ab_temp);

    int a = stoi(ab[0]);

    int b = stoi(ab[1]);

    int result = squares(a, b);

    cout << result << "\n";
  }

  return 0;
}

vector<string> split_string(string input_string) {
  string::iterator new_end =
      unique(input_string.begin(), input_string.end(),
             [](const char &x, const char &y) { return x == y and x == ' '; });

  input_string.erase(new_end, input_string.end());

  while (input_string[input_string.length() - 1] == ' ') {
    input_string.pop_back();
  }

  vector<string> splits;
  char delimiter = ' ';

  size_t i = 0;
  size_t pos = input_string.find(delimiter);

  while (pos != string::npos) {
    splits.push_back(input_string.substr(i, pos - i));

    i = pos + 1;
    pos = input_string.find(delimiter, i);
  }

  splits.push_back(
      input_string.substr(i, min(pos, input_string.length()) - i + 1));

  return splits;
}
