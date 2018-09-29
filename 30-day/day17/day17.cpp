//  https://www.hackerrank.com/challenges/30-more-exceptions/

#include <cmath>
#include <exception>
#include <iostream>
#include <stdexcept>
using namespace std;

// Write your code here
class Calculator {
    public:
        int power( int n, int p ) {
            if( n < 0 || p < 0 ) {
                throw std::invalid_argument( "n and p should be non-negative" );
            }

            return( std::pow( n, p ) );
        }
};

int main() {
  Calculator myCalculator = Calculator();
  int T, n, p;
  cin >> T;
  while (T-- > 0) {
    if (scanf("%d %d", &n, &p) == 2) {
      try {
        int ans = myCalculator.power(n, p);
        cout << ans << endl;
      } catch (exception &e) {
        cout << e.what() << endl;
      }
    }
  }
}
