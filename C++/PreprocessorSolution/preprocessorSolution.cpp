//  https://www.hackerrank.com/challenges/preprocessor-solution/

#define toStr(x) ( #x )
#define io(x) std::cin >> v
#define INF ( 10 ^ 8 )
#define foreach( v, i ) for( unsigned long i = 0; i < v.size(); ++i )
#define FUNCTION( function, operator ) void function( int &x, int &y ) { if( ! ( x operator y ) ) { x = y; } }

#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  foreach (v, i) {
      io(v)[i];
  }
  int mn = INF;
  int mx = -INF;
  foreach (v, i) {
    minimum(mn, v[i]);
    maximum(mx, v[i]);
  }
  int ans = mx - mn;
  cout << toStr(Result =) << ' ' << ans <<endl;
  return 0;
}
