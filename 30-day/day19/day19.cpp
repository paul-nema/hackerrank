//  https://www.hackerrank.com/challenges/30-interfaces/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class AdvancedArithmetic {
public:
  virtual int divisorSum(int n) = 0;
};

class Calculator : public AdvancedArithmetic {
public:
  int divisorSum( int n ) {
      auto sum = 0;

      for( auto x = 1; x <= std::sqrt( n ); ++x ) {
          if( n % x == 0 ) {
              if( n / x != x ) {
                  sum += n / x;
              }

              sum += x;
          }
      }

      return sum;
  }
};

int main() {
  int n;
  cin >> n;
  AdvancedArithmetic *myCalculator = new Calculator();
  int sum = myCalculator->divisorSum(n);
  cout << "I implemented: AdvancedArithmetic\n" << sum;
  return 0;
}
