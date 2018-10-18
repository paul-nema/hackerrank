//  https://www.hackerrank.com/challenges/insertionsort1/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the insertionSort1 function below.
//  n: an integer, the size of arr
//  arr: an array of integers to sort
void insertionSort1(int n, vector<int> &arr) {
    auto store( arr[ n - 1 ] );
    auto x( n - 1 );

    bool sorted( false );

    while( sorted == false && --x > -1 ) {
        if( arr[ x ] > store ) {
            arr[ x + 1 ] = arr[ x ];
        } else {
            arr[ x + 1 ] = store;
            sorted = true;
        }

        for( unsigned long y = 0; y < arr.size(); ++y ) {    //  print arr
            if( y != arr.size() - 1 ) {
                std::cout << arr[ y ] << " ";
            } else {
                std::cout << arr[ y ] << "\n";
            }
        }
    }

    if( x == -1 ) {
        arr[ 0 ] = store;

        for( unsigned long y = 0; y < arr.size(); ++y ) {    //  print arr
            if( y != arr.size() - 1 ) {
                std::cout << arr[ y ] << " ";
            } else {
                std::cout << arr[ y ] << "\n";
            }
        }
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

  insertionSort1(n, arr);

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
