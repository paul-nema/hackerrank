//  https://www.hackerrank.com/challenges/cavity-map/

#include <bits/stdc++.h>

using namespace std;

// Complete the cavityMap function below.
//  grid: an array of strings, each representing a row of the grid
vector<string> cavityMap(vector<string> &grid) {
    if( grid.size() < 3 ) {
        return( grid );
    }

    auto end = ( grid.size() * grid.size() ) - grid.size() - 1;
    auto row = 0;
    auto col = 0;
    auto cavity = 0;

    for( auto x = grid.size() + 1; x < end; ++x ) {
        col = x % grid.size();

        if( col == 0 || col == static_cast< int >( grid.size() - 1 )  ) {
            continue;   //  ignore left and right grid edges
        }

        row = ( x - col ) / grid.size();
        cavity = grid[ row ][ col ] - '0';

        if( cavity > grid[ row - 1][ col ] - '0' && //  num up
            cavity > grid[ row + 1 ][ col ] - '0' &&    // num down
            cavity > grid[ row ][ col - 1 ] - '0'&& // num left
            cavity > grid[ row ][ col + 1 ] - '0' ) {   // num right
            grid[ row ][ col ] = 'X';
        }
    }

    return( grid );
}

int main() {
  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<string> grid(n);

  for (int i = 0; i < n; i++) {
    string grid_item;
    getline(cin, grid_item);

    grid[i] = grid_item;
  }

  vector<string> result = cavityMap(grid);

  for (unsigned long i = 0; i < result.size(); i++) {
    cout << result[i];

    if (i != result.size() - 1) {
      cout << "\n";
    }
  }

  cout << "\n";

  return 0;
}
