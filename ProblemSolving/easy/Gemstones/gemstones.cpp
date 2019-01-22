//  https://www.hackerrank.com/challenges/gem-stones/

#include <bits/stdc++.h>

using namespace std;

const auto numOfLetters{ 26 };

// Complete the gemstones function below.
int gemstones( std::vector< std::string > &arr ) {
    std::vector< unsigned long > gems( numOfLetters, 0 );
    std::vector< bool > seen( numOfLetters, false );

    auto numOfGems{ 0 };

    for( unsigned long x{ 0 }; x < arr.size(); ++x ) {
        for( unsigned long y{ 0 }; y < arr[ x ].size(); ++y ) {
            if( seen[ arr[ x ][ y ] - 'a' ] == false ) {
                seen[ arr[ x ][ y ] - 'a' ] = true;
                gems[ arr[ x ][ y ] - 'a' ]++;
            }
        }

        std::fill( seen.begin(), seen.end(), false );
    }

    for( unsigned long g: gems ) {
        if( g == arr.size() ) {
            ++numOfGems;
        }
    }

    return( numOfGems );
}

int main() {
  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<string> arr(n);

  for (int i = 0; i < n; i++) {
    string arr_item;
    getline(cin, arr_item);

    arr[i] = arr_item;
  }

  int result = gemstones(arr);

  cout << result << "\n";

  return 0;
}
