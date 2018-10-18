//  https://www.hackerrank.com/challenges/weighted-uniform-string/

#include <bits/stdc++.h>

using namespace std;

// Complete the weightedUniformStrings function below.
vector<string> weightedUniformStrings(string &s, vector<int> &queries) {
    //  Create array to use for weighting values
    std::array<short, 26> alphabet{{ 0 }};

    unsigned long x = 0;

    for( x = 1; x <= alphabet.size(); ++x ) {
        alphabet[ x - 1 ] = x;  // Init array starting at 1
    }

    vector<int> values;
    char currentChar;
    auto cntr = 1;

    for( x = 0;  x < s.size(); ++x ) {
        currentChar = s[ x ];

        //  Does the current char repeat?
        for( auto y = x + 1; y < s.size(); ++y ) {
            if( currentChar != s[ y ] ) {
                break;  // not repeating
            }

            ++cntr;
        }

        for( auto z = 0; z < cntr; ++z ) {
            values.push_back( ( z + 1 ) * alphabet[ currentChar - 'a' ] );
        }

        // Reset tmp vars
        x += cntr - 1;  //  move index past the repeat chars
        cntr = 1;
    }

    //  Record results
    vector<string> result;

    for( auto cnt: queries ) {
        if ( std::find(values.begin(), values.end(), cnt) != values.end() ) {
            result.push_back( "Yes " );
        } else {
            result.push_back( "No" );
        }
    }

    return( result );
}


int main() {
  string s;
  getline(cin, s);

  int queries_count;
  cin >> queries_count;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<int> queries(queries_count);

  for (int i = 0; i < queries_count; i++) {
    int queries_item;
    cin >> queries_item;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    queries[i] = queries_item;
  }

  vector<string> result = weightedUniformStrings(s, queries);

  for (long unsigned i = 0; i < result.size(); i++) {
    cout << result[i];

    if (i != result.size() - 1) {
      cout << "\n";
    }
  }

  cout << "\n";

  return 0;
}
