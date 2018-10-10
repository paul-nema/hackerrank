//  https://www.hackerrank.com/challenges/30-regex-patterns/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int main() {
  int N( 0 );

  cin >> N;
  cin.ignore( numeric_limits<streamsize>::max(), '\n' );

  std::regex re( "@gmail.com" );
  std::smatch match;

  std::vector<string> matches;

  std::string str;

  for ( auto N_itr = 0; N_itr < N; ++N_itr ) {
    getline( std::cin, str );

    try {
        if( std::regex_search( str, match, re) ) {
            matches.push_back( split_string(str)[ 0 ] );
        }
    } catch( std::regex_error &e) {
        std::cout << "Regex error: " << e.what() << std::endl;
    }
  }

  std::sort( matches.begin(), matches.end() );

  for( auto name: matches ) {
      std::cout << name << "\n";
  }

  return( 0 );
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
