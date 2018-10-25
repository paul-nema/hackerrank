//  https://www.hackerrank.com/challenges/halloween-sale/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the howManyGames function below.
//  p = standard game rice
//  d = every subsequent game deduction
//  m = lowest price
//  s = money you have to spend
int howManyGames( int p, int d, int m, int s ) {
  // Return the number of games you can buy
    auto num( 0 );

    while( s > 0 ) {
        if( s < p ) {
            return( num );
        }

        ++num;
        s -= p;
        p -= d;

        if( p < m ) {
            p = m;
        }
    }

    return( num );
}

int main() {
  string pdms_temp;
  getline(cin, pdms_temp);

  vector<string> pdms = split_string(pdms_temp);

  int p = stoi(pdms[0]);

  int d = stoi(pdms[1]);

  int m = stoi(pdms[2]);

  int s = stoi(pdms[3]);

  int answer = howManyGames(p, d, m, s);

  cout << answer << "\n";

  return 0;
}

vector<string> split_string(string input_string) {
  string::iterator new_end = unique(input_string.begin(), input_string.end(),
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
