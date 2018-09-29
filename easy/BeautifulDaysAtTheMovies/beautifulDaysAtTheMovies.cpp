//  https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the beautifulDays function below.
//  i: the starting day number
//  j: the ending day number
//  k: the divisor
int beautifulDays( int i, int j, int k ) {
    unsigned int numOfBeautifulDays = 0;
    unsigned int origNumOfDigits = 0;
    unsigned int numOfDigits = 0;
    unsigned int ttmp = i;

    auto runAgain = 0;
    auto result = 0;

    while( ttmp != 0 ) {    //  # of digits of int i
        ttmp /= 10;
        ++origNumOfDigits;
    }

    runAgain = pow( 10, origNumOfDigits );   //  Use to prevent running while loop above
    
    for( auto x = i; x <= j; ++x ) {
        if( x == runAgain ) {
            runAgain *= 10; // Determine next time to increment comparison
            ++origNumOfDigits;
        }

        numOfDigits = origNumOfDigits;
        ttmp = x;
        result = 0;

        while( ttmp != 0 ) {    //  Reserve the number
            result += ( ttmp % 10 ) * pow( 10, --numOfDigits );
            ttmp /= 10;
        }

        if( std::abs( x - result ) % k == 0 ) { // Beautiful number ?
            ++numOfBeautifulDays;
        }
    }

    return( numOfBeautifulDays );
}

// Test case
// 49860 205494 155635764
//  Anwser 607

int main() {
  string ijk_temp;
  getline(cin, ijk_temp);

  vector<string> ijk = split_string(ijk_temp);

  int i = stoi(ijk[0]);

  int j = stoi(ijk[1]);

  int k = stoi(ijk[2]);

  int result = beautifulDays(i, j, k);

  cout << result << "\n";

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
