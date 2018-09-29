#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Difference {
private:
  vector<int> elements;

public:
  int maximumDifference;

  // Add your code here
  Difference( vector< int > el ) : elements( el ) {}

  void computeDifference() {
      maximumDifference = std::abs( *std::max_element( elements.begin(), elements.end() ) - 
              *std::min_element( elements.begin(), elements.end() ) );
  }
}; // End of Difference class

int main() {
  int N;
  cin >> N;

  vector<int> a;

  for (int i = 0; i < N; i++) {
    int e;
    cin >> e;

    a.push_back(e);
  }

  Difference d(a);

  d.computeDifference();

  cout << d.maximumDifference;

  return 0;
}
