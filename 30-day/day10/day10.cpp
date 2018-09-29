#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  auto numOfOnes( 0 );
  auto prevCnt( 0 );

  while( n > 0 ) {
      if( ( n % 2 ) == 1 ) {  //  Count the ones as we find them
          ++numOfOnes;
      } else {
          if( numOfOnes > prevCnt ) {
              prevCnt = numOfOnes;
          }

          numOfOnes = 0;
      }

      n /= 2;
  }


  std::cout << ( numOfOnes > prevCnt ? numOfOnes : prevCnt ) << std::endl;

  return 0;
}
