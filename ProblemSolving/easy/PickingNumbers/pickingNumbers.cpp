#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the pickingNumbers function below.
int pickingNumbers(vector<int> &a) {
    std::sort( a.begin(), a.end() );

    int largest = 0;
    int cnt = 1;
    int reIndex = 0;
    int prev = a[0];
    bool resetIndex = false;

    for( auto x = 1; x < a.size(); ++x ) {
        if( a[ x ] - prev <= 1 ) {
            ++cnt;

            if( a[ x ] != prev && resetIndex == false ) {
                reIndex = x;
                resetIndex = true;
            }
        } else {
            if( cnt >= largest ) {
                largest = cnt;
                cnt = 1;
            }

            if( resetIndex == true ) {
                x = reIndex;
                resetIndex = false;
                cnt = 1;
            }

            prev = a[ x ];
        }
    }

    return ( largest );
}
// 73
// 4 2 3 4 4 9 98 98 3 3 3 4 2 98 1 98 98 1 1 4 98 2 98 3 9 9 3 1 4 1 98 9 9 2 9 4 2 2 9 98 4
// 98 1 3 4 9 1 98 98 4 2 3 98 98 1 99 9 98 98 3 98 98 4 98 2 98 4 2 1 1 9 2 4
// Same as above but sorted
// 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 3 3 3 3 3 3 3 3 3 4 4 4 4 4 4 4 4 4 4 4 4 4
// 9 9 9 9 9 9 9 9 9 9 98 98 98 98 98 98 98 98 98 98 98 98 98 98 98 98 98 98 98 98 99
// Answer 22

// 98
// 12 13 19 17 7 3 18 9 18 13 12 3 13 7 9 18 9 18 9 13 18 13 13 18 18 17 17 13 3 12 13 19
// 17 19 12 18 13 7 3 3 12 7 13 7 3 17 9 13 13 13 12 18 18 9 7 19 17 13 18 19 9 18 18 18
// 19 17 7 12 3 13 19 12 3 9 17 13 19 12 18 13 18 18 18 17 13 3 18 19 7 12 9 18 3 13 13 9 7
// Answer: 30
// Sorted
// 3 3 3 3 3 3 3 3 3 3 7 7 7 7 7 7 7 7 7 7 9 9 9 9
// 9 9 9 9 9 9 12 12 12 12 12 12 12 12 12 12 13 13 13 13 13 13 13 13 13 13 13 13 13 13
// 13 13 13 13 13 13 17 17 17 17 17 17 17 17 17 18 18 18 18 18 18 18 18 18 18 18 18 18 18
// 18 18 18 18 18 18 19 19 19 19 19 19 19 19 19

int main() {
  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string a_temp_temp;
  getline(cin, a_temp_temp);

  vector<string> a_temp = split_string(a_temp_temp);

  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    int a_item = stoi(a_temp[i]);

    a[i] = a_item;
  }

  int result = pickingNumbers(a);

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
