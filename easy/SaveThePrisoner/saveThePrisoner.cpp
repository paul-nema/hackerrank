//  https://www.hackerrank.com/challenges/save-the-prisoner

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the saveThePrisoner function below.
//  n : the number of prisoners 
//  m : the number of sweets 
//  s : the chair number to start passing out treats at
int saveThePrisoner(int n, int m, int s) {
    auto prisoner( ( ( m % n ) -1 ) + s );

    if( prisoner == 0 ) {
        return( n );
    }

    return( prisoner > n ? prisoner - n : prisoner );
}

//  2
//  7 19 2
//  3 7 3
//  Answer
//  6
//  3
    

int main() {
  int t;
  cin >> t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int t_itr = 0; t_itr < t; t_itr++) {
    string nms_temp;
    getline(cin, nms_temp);

    vector<string> nms = split_string(nms_temp);

    int n = stoi(nms[0]);

    int m = stoi(nms[1]);

    int s = stoi(nms[2]);

    int result = saveThePrisoner(n, m, s);

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
