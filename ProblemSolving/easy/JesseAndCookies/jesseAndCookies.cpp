//  https://www.hackerrank.com/challenges/jesse-and-cookies/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the cookies function below.
 */
//
//  k:  minimum required sweetness
//  A:  sweetness of each cookie
//
int cookies( int k, vector< int > A ) {
    std::multiset< int > s( A.begin(), A.end() );

    auto it{ s.begin() };
    auto sweetness{ 0 };
    auto cnt{ 0 };

    while( true ) {
        it = s.begin();

        if( *it >= k ) {
            return( cnt );
        }

        if( s.size() < 2 ) {
            return( -1 );
        }

        sweetness = *it;
        sweetness += *( ++it ) * 2;

        s.erase( it );  //  remove 2nd element
        s.erase( --it );    //  remove 1st element

        s.insert( sweetness );

        ++cnt;
    }

    return( -1 );
}

int main() {
  string nk_temp;
  getline(cin, nk_temp);

  vector<string> nk = split_string(nk_temp);

  int n = stoi(nk[0]);

  int k = stoi(nk[1]);

  string A_temp_temp;
  getline(cin, A_temp_temp);

  vector<string> A_temp = split_string(A_temp_temp);

  vector<int> A(n);

  for (int A_itr = 0; A_itr < n; A_itr++) {
    int A_item = stoi(A_temp[A_itr]);

    A[A_itr] = A_item;
  }

  int result = cookies(k, A);

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
