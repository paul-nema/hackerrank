//  https://www.hackerrank.com/challenges/repeated-string/

#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
//  s: a string to repeat
//  n: the number of characters to consider
long repeatedString(string &s, long n) {
    auto repeatStr( n / s.size() );   // num of times str len goes into n
    auto charCnt( repeatStr * s.size() ); // char count of repeated strings
    auto aCount( std::count( s.begin(), s.end(), 'a' ) * repeatStr );  //  Initial count of a's

    for( auto x = charCnt; x < n; ++x ) {    //  loop through last string s
        if( s[ x - charCnt ] == 'a' ) {
            ++aCount;
        }
    }

    return( aCount );
}

//  testcase9
//  epsxyyflvrrrxzvnoenvpegvuonodjoxfwdmcvwctmekpsnamchznsoxaklzjgrqruyzavshfbmuhdwwmpbkwcuomqhiyvuztwvq
//  549382313570
//  Answer
//  16481469408

int main() {
  string s;
  getline(cin, s);

  long n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  long result = repeatedString(s, n);

  cout << result << "\n";

  return 0;
}
