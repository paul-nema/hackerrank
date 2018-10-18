//  https://www.hackerrank.com/challenges/permutation-equation/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the permutationEquation function below.
//  p: an array of integers
vector<int> permutationEquation(vector<int> p) {
    std::vector< int > result;

    auto pos = 0;

    for( unsigned long x = 0; x < p.size(); ++x ) {
        pos = std::distance( p.begin(), find( p.begin(), p.end(), x + 1 ) ) + 1;
        result.push_back( std::distance( p.begin(), find( p.begin(), p.end(), pos ) ) + 1 );
    }

    return( result );
}

int main() {
  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string p_temp_temp;
  getline(cin, p_temp_temp);

  vector<string> p_temp = split_string(p_temp_temp);

  vector<int> p(n);

  for (int i = 0; i < n; i++) {
    int p_item = stoi(p_temp[i]);

    p[i] = p_item;
  }

  vector<int> result = permutationEquation(p);

  for (unsigned long i = 0; i < result.size(); i++) {
    cout << result[i];

    if (i != result.size() - 1) {
      cout << "\n";
    }
  }

  cout << "\n";

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
