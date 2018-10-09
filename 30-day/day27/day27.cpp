//  https://www.hackerrank.com/challenges/30-testing/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <stdexcept>
#include <vector>

using namespace std;

int minimum_index(vector<int> seq) {
  if (seq.empty()) {
    throw invalid_argument(
        "Cannot get the minimum value index from an empty sequence");
  }
  int min_idx = 0;
  for (int i = 1; i < seq.size(); ++i) {
    if (seq[i] < seq[min_idx]) {
      min_idx = i;
    }
  }
  return min_idx;
}

class TestDataEmptyArray {
public:
  static vector<int> get_array() {
    // complete this function
      return( emptyArray );
  }

  static std::vector< int > emptyArray;
};

std::vector< int > TestDataEmptyArray::emptyArray;

class TestDataUniqueValues {
public:
  static vector<int> get_array() {
    // complete this function
      for( auto x( 1 ); x < 5; ++x ) {
          uniqueValArr.push_back( x );
      }

      return( uniqueValArr );
  }

  static int get_expected_result() {
    // complete this function
      returnVal = std::min_element( uniqueValArr.begin(), uniqueValArr.end() ) - uniqueValArr.begin();

      return( returnVal );
  }

  static std::vector< int > uniqueValArr;

  static int returnVal;
};

std::vector< int > TestDataUniqueValues::uniqueValArr;
int TestDataUniqueValues::returnVal = 0;


class TestDataExactlyTwoDifferentMinimums {
public:
  static vector<int> get_array() {
    // complete this function
      for( auto x( 1 ); x < 3; ++x ) {
          twoDiffArr[ x ];
      }

      return( twoDiffArr );
  }

  static int get_expected_result() {
    // complete this function
      returnVal = std::min_element( twoDiffArr.begin(), twoDiffArr.end() ) - twoDiffArr.begin();

      return( returnVal );
  }

  static std::vector< int > twoDiffArr;

  static int returnVal;
};

std::vector< int > TestDataExactlyTwoDifferentMinimums::twoDiffArr( 2 );
int TestDataExactlyTwoDifferentMinimums::returnVal = 0;

void TestWithEmptyArray() {
  try {
    auto seq = TestDataEmptyArray::get_array();
    auto result = minimum_index(seq);
  } catch (invalid_argument &e) {
    return;
  }
  assert(false);
}

void TestWithUniqueValues() {
  auto seq = TestDataUniqueValues::get_array();
  assert(seq.size() >= 2);

  assert(set<int>(seq.begin(), seq.end()).size() == seq.size());

  auto expected_result = TestDataUniqueValues::get_expected_result();
  auto result = minimum_index(seq);
  assert(result == expected_result);
}

void TestWithExactlyTwoDifferentMinimums() {
  auto seq = TestDataExactlyTwoDifferentMinimums::get_array();
  assert(seq.size() >= 2);

  auto tmp = seq;
  sort(tmp.begin(), tmp.end());
  assert(tmp[0] == tmp[1] and (tmp.size() == 2 or tmp[1] < tmp[2]));

  auto expected_result =
      TestDataExactlyTwoDifferentMinimums::get_expected_result();
  auto result = minimum_index(seq);
  assert(result == expected_result);
}

int main() {
  TestWithEmptyArray();
  TestWithUniqueValues();
  TestWithExactlyTwoDifferentMinimums();
  cout << "OK" << endl;
  return 0;
}
