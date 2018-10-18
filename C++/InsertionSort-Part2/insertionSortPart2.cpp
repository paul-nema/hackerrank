//  https://www.hackerrank.com/challenges/insertionsort2/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the insertionSort2 function below.
//  n: an integer representing the length of the array 
//  arr: an array of integers
void insertionSort2(int n, vector<int> &arr) {
    if( n == 1) {
        std::cout << arr[ 0 ] << std::endl;
    }

    unsigned long y = 0;

    for( auto x = 1; x < n; ++x ) {
        if( arr[ x ] < arr[ x - 1 ] ) {
            std::swap( arr[ x ], arr[ x - 1 ] );    // swap the one just found

            for( y = x - 1; y > 0; --y ) {  //  swap the rest if necessary
                if( arr[ y ] < arr[ y - 1 ] ) {
                    std::swap( arr[ y ], arr[ y - 1 ] );
                }
            }

        }

        for( y = 0; y < arr.size() - 1; ++y ) { //  print out arr
            std::cout << arr[ y ] << " ";
        }
        std::cout << arr[ y ] << endl;
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

  insertionSort2(n, arr);

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
