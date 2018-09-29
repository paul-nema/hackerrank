//  https://www.hackerrank.com/challenges/30-exceptions-string-to-integer/

#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  string S;
  cin >> S;

  try { //  Problem requires the use of try catch
      std::string::size_type sz;

      std::cout << std::stoi ( S, &sz ) << "\n";
  } catch( ... ) {
      std::cout << "Bad String\n";
  }

  return 0;
}
