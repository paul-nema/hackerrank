//  https://www.hackerrank.com/challenges/cut-the-sticks

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the cutTheSticks function below.
//  arr: an array of integers representing the length of each stick
vector<int> cutTheSticks(vector<int> arr) {
    sort( arr.begin(), arr.end() ); //  sort to make things easier

    auto counter( 0 );
    auto subtract( arr.at( 0 ) );

    unsigned long x( 0 );
    unsigned long pos( 0 );

    vector< int > count;

    while( true ) {
        for( x = pos; x < arr.size(); ++x, ++counter ) {
            arr.at( x ) -= subtract;

            if( arr.at( x ) == 0 ) {
                pos = x + 1;
            }
        }

        count.push_back( counter );

        if( pos == arr.size() ) {
            return( count );
        }

        counter = 0;
        subtract = arr.at( pos );
    }
}

int main() {
  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string arr_temp_temp;
  getline(cin, arr_temp_temp);

  vector<string> arr_temp = split_string(arr_temp_temp);

  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    int arr_item = stoi(arr_temp[i]);

    arr[i] = arr_item;
  }

  vector<int> result = cutTheSticks(arr);

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
