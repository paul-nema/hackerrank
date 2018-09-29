//  https://www.hackerrank.com/challenges/30-2d-arrays/

#include <bits/stdc++.h>

using namespace std;

int main() {
  std::vector<vector<int>> arr(6);

  for (int i = 0; i < 6; i++) { // Read in array
    arr[i].resize(6);

    for (int j = 0; j < 6; j++) {
      std::cin >> arr[i][j];
    }

    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  auto topRow(0);
  auto middle(0);
  auto bottomRow(0);
  auto largest(-9 * 9); //  Start smallest possible answer

  for (auto x = 0; x < 4; ++x) { //  loop thru the 16 hour glasses
    for (auto y = 0; y < 4; ++y) {
      topRow = arr[x][y] + arr[x][y + 1] + arr[x][y + 2];
      middle = arr[x + 1][y + 1];
      bottomRow = arr[x + 2][y] + arr[x + 2][y + 1] + arr[x + 2][y + 2];

      if (topRow + middle + bottomRow > largest) {
        largest = topRow + middle + bottomRow;
      }
    }
  }

  std::cout << largest << std::endl;

  return 0;
}
