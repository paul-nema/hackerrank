//  https://www.hackerrank.com/challenges/minimum-distances/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumDistances function below.
//  Sort array.  Find pairs (numbers that are next to each other).
//  Record matchs in map. Loop thru original int vector.
//  Record position of matches in map vector. 
//  Process map vector looking for smallest difference.
int minimumDistances(vector<int> &a) {
    auto sortedA( a );
    auto shortest( static_cast< int >( a.size() ) + 1 );
    unsigned long x;

    std::map< int, std::vector< int > * > m;

    std::sort( sortedA.begin(), sortedA.end() );

    for( x = 1; x < sortedA.size(); ++x ) { //  Look for matches
        if( sortedA[ x - 1 ] == sortedA[ x ] ) {
            if( m.count( sortedA[ x ] ) == 0 ) {
                m[ sortedA[ x ] ] = new std::vector< int >;
            }
        }
    }

    if( m.size() == 0 ) {
        return( -1 );   //  no matches
    }

    std::map< int, std::vector< int > * >::iterator it;

    for( x = 0; x < a.size(); ++x ) {
        if( ( it = m.find( a[ x ] ) ) != m.end() ) {
             it->second->push_back( x );    // Record position in vector
        }
    }

    for( it = m.begin(); it != m.end(); ++it ) {    //  Process each vector
        for( x = 1; x < it->second->size(); ++x ) {
            if( it->second->operator[]( x ) - it->second->operator[]( x - 1 ) < shortest ) {
                shortest = it->second->operator[]( x ) - it->second->operator[]( x - 1 );
            }
        }
    }

    return( shortest );
}

int main() {
  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string a_temp_temp;
  getline(cin, a_temp_temp);

  vector<string> a_temp = split_string(a_temp_temp);

  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    int a_item = stoi(a_temp[i]);

    a[i] = a_item;
  }

  int result = minimumDistances(a);

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
