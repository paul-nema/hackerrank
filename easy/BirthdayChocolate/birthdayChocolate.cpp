//  https://www.hackerrank.com/challenges/the-birthday-bar/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int birthday2(vector<int> s, int d, int m) {
    int numberFound = 0;
    int monthCount = 1;
    int daySum = 0;
    int savePos = 0;

    // Can use two loops but lets use one for efficiency
    for( auto x = 0; x < s.size(); ++x ) {
        daySum += s[ x ];

        if( daySum == d && monthCount == m ) {
            ++numberFound;

            monthCount = 0;
            daySum = 0;
            x = savePos++;
        } else if( daySum > d || monthCount > m ) {
            x = savePos++;  // not possible as we exceeded d or m so move on!
        } else if ( x + 1 == s.size() && savePos != x ) {
            x = savePos++;
        }

        ++monthCount;
    }

    return( numberFound ) ;
}

// Complete the birthday function below.
int birthday(vector<int> s, int d, int m) {
    int numberFound = 0;
    int monthCount = 1;
    int daySum = 0;

    for( auto x = 0; x < s.size(); ++x ) {
        for( auto y = x, monthCount = 1; y - x < m && m < s.size() + 1; ++y, ++monthCount ) {
            daySum += s[ y ];

            if( daySum == d && monthCount == m ) {
                ++numberFound;

                break;
            } else if( daySum > d || monthCount > m ) {
                break;  // not possible as we exceeded d or m so move on!
            }
        }

        daySum = 0;
    }

    return( numberFound );
}

int main() {
  string n_temp;
  getline(cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp)));

  string s_temp_temp;
  getline(cin, s_temp_temp);

  vector<string> s_temp = split(rtrim(s_temp_temp));

  vector<int> s(n);

  for (int i = 0; i < n; i++) {
    int s_item = stoi(s_temp[i]);

    s[i] = s_item;
  }

  string dm_temp;
  getline(cin, dm_temp);

  vector<string> dm = split(rtrim(dm_temp));

  int d = stoi(dm[0]);

  int m = stoi(dm[1]);

  int result = birthday2(s, d, m);

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
