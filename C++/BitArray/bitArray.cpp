//  https://codingfreak.blogspot.com/2012/09/detecting-loop-in-singly-linked-list_22.html
//  https://en.wikipedia.org/wiki/Cycle_detection

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
#define f( x, p, q ) ( ( x * p ) + q )

typedef unsigned long long ULONG;

int main(  ) {
  ULONG n, s, p, q;
  std::cin >> n >> s >> p >> q;

  ULONG p_231 = static_cast<ULONG>( std::pow( 2, 31 ) );

  ULONG x0 = s % p_231;
  ULONG vals = 1;

  ULONG tort = f( x0, p, q ) % p_231;
  ULONG hare = f( x0, p, q ) % p_231;
  hare = f( hare, p, q ) % p_231;

  while ( tort != hare ) {
    if ( vals >= n ) {
      std::cout << vals << "\n";

      return 0;
    } else {
      ++vals;
    }

    tort = f( tort, p, q ) % p_231;
    hare = f( hare, p, q ) % p_231;
    hare = f( hare, p, q ) % p_231;
  }

  ULONG mu = 0;
  tort = x0;

  while ( tort != hare ) {
    tort = f( tort, p, q ) % p_231;
    hare = f( hare, p, q ) % p_231;
    ++mu;
  }

  ULONG lam = 1;
  hare = f( tort, p, q ) % p_231;

  while ( tort != hare ) {
    hare = f( hare, p, q ) % p_231;
    ++lam;
  }

  std::cout << lam + mu << "\n";

  return 0;
}
