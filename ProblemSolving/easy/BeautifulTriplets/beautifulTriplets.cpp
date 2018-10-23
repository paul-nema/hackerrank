#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the beautifulTriplets function below.
//  d: an integer to match to determine if value is a beautiful triplet
//  arr: an array of integers, sorted ascending
int beautifulTriplets(int d, const vector<int> &arr) {
    if( arr.size() < 3 ) {
        return( 0 );
    }

    auto cnt( 0 );

    for( unsigned long x( 0 ); x < arr.size(); ++x ) {
        for( unsigned long y( x + 1 ); y < arr.size() - 1; ++y ) {
            if( arr[ y ] - arr[ x ] == d ) {    //  first match
                for( unsigned long z( y + 1 ); z < arr.size(); ++z ) {
                    if( arr[ z ] - arr[ y ] == d ) {    //  second match
                        ++cnt;
                    } else if( arr[ z ] - arr[ y ] > d ) {
                        break;
                    }
                }
            } else if( arr[ y ] - arr[ x ] > d ) {
                break;  //  further numbers will be even greater than d
            }
        }
    }

    return( cnt );
}

int main() {
  string nd_temp;
  getline(cin, nd_temp);

  vector<string> nd = split_string(nd_temp);

  int n = stoi(nd[0]);

  int d = stoi(nd[1]);

  string arr_temp_temp;
  getline(cin, arr_temp_temp);

  vector<string> arr_temp = split_string(arr_temp_temp);

  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    int arr_item = stoi(arr_temp[i]);

    arr[i] = arr_item;
  }

  int result = beautifulTriplets(d, arr);

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
