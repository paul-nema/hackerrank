//  https://www.hackerrank.com/challenges/kaprekar-numbers/

#include <bits/stdc++.h>

using namespace std;

// Complete the kaprekarNumbers function below.
void kaprekarNumbers(int p, int q) {
    long squared;

    int numOfDigits = floor(log10( pow( q, 2 ) )) + 1;  // How many digits in the squared number
    int origLen;
    int cnt = 0;
    int right = 0;
    int left = 0;
    int multiplyBy = 1;
    
    vector< int > digits( numOfDigits );    // Allocate a vec with the max # of int's

    for( auto x = p; x <= q; ++x ) {
        squared = pow( x, 2 );
        numOfDigits = floor(log10( squared )) + 1;
        origLen = floor(log10( x )) + 1;

        for( auto y = 0; y < numOfDigits; ++y ) {   // assign digits to a vec in reverse order
            digits[ y ] = squared % 10;
            squared /= 10;
        }

        for( auto z = 0; z < numOfDigits; ++z ) {
            if( z < origLen ) {
                right += digits[ z ] * multiplyBy;
            } else {
                if( numOfDigits / 2 == z || ( numOfDigits & 1 ) && numOfDigits / 2 + 1 == z ) {
                    multiplyBy = 1;
                }

                left += digits[ z ] * multiplyBy;
            }

            multiplyBy *= 10;
        }

        if( left + right == x ) {
            cout << x << " ";
            ++cnt;
        }

        left = 0;
        right = 0;
        multiplyBy = 1;
    }

    if( cnt == 0 ) {
        cout << "INVALID RANGE";
    }

    cout << endl;
}
// 1 - 99999 = 1 9 45 55 99 297 703 999 2223 2728 4950 5050 7272 7777 9999 17344 22222 77778 82656 95121 99999

int main() {
  int p;
  cin >> p;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  int q;
  cin >> q;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  kaprekarNumbers(p, q);

  return 0;
}
