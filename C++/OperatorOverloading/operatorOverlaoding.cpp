//  https://www.hackerrank.com/challenges/operator-overloading/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class Matrix {
    public:
       std::vector< vector< int > > a;

       Matrix operator+ ( const Matrix &m ) {   //  assignment calls for member function + overloaded
           for( unsigned long x = 0; x < a.size(); ++x ) {
               for( unsigned long y = 0; y < a[ x ].size(); ++y ) {
                   a[ x ][ y ] += m.a[ x ][ y ];
               }
           }

           return( *this );
       }

    private:
};


int main() {
  int cases, k;
  cin >> cases;
  for (k = 0; k < cases; k++) {
    Matrix x;
    Matrix y;
    Matrix result;
    int n, m, i, j;
    cin >> n >> m;
    for (i = 0; i < n; i++) {
      vector<int> b;
      int num;
      for (j = 0; j < m; j++) {
        cin >> num;
        b.push_back(num);
      }
      x.a.push_back(b);
    }
    for (i = 0; i < n; i++) {
      vector<int> b;
      int num;
      for (j = 0; j < m; j++) {
        cin >> num;
        b.push_back(num);
      }
      y.a.push_back(b);
    }
    result = x + y;
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        cout << result.a[i][j] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
