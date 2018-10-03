//  https://www.hackerrank.com/challenges/a-very-big-sum/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string &s) {
  /*
   * Write your code here.
   */
    tm tm = {};

    strptime(s.c_str(), "%I:%M:%S%p", &tm);

    stringstream ssOut;
    ssOut << put_time(&tm, "%H:%M:%S" );

    return( ssOut.str() );
}

int main() {
  string s;
  getline(cin, s);

  string result = timeConversion(s);

  cout << result << "\n";

  return 0;
}
