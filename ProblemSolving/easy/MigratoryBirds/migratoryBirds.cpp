#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the migratoryBirds function below.
int migratoryBirds(vector<int> &arr) {
    int birds[ 5 ] = { 0 };

    for( unsigned long x = 0; x < arr.size(); ++x ) {
        birds[ arr[ x ] - 1 ]++;
    }

    int id = 0;

    for( auto x = 1; x < 5; ++x ) {
        if( birds[ x ] > birds[ id ] ) {
            id = x;
        }
    }

    return( id + 1 );
}

int main() {
  string arr_count_temp;
  getline(cin, arr_count_temp);

  int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

  string arr_temp_temp;
  getline(cin, arr_temp_temp);

  vector<string> arr_temp = split(rtrim(arr_temp_temp));

  vector<int> arr(arr_count);

  for (int i = 0; i < arr_count; i++) {
    int arr_item = stoi(arr_temp[i]);

    arr[i] = arr_item;
  }

  int result = migratoryBirds(arr);

  cout << result << "\n";

  return 0;
}

string ltrim(const string &str) {
  string s(str);

  s.erase(s.begin(),
          find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
}

string rtrim(const string &str) {
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end());

  return s;
}

vector<string> split(const string &str) {
  vector<string> tokens;

  string::size_type start = 0;
  string::size_type end = 0;

  while ((end = str.find(" ", start)) != string::npos) {
    tokens.push_back(str.substr(start, end - start));

    start = end + 1;
  }

  tokens.push_back(str.substr(start));

  return tokens;
}
