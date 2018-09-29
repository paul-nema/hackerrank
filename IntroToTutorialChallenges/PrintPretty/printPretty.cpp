//  https://www.hackerrank.com/challenges/prettyprint/

#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  cout << setiosflags(ios::uppercase);
  cout << setw(0xf) << internal;
  while (T--) {
    double A;
    cin >> A;
    double B;
    cin >> B;
    double C;
    cin >> C;

    std::cout << std::hex << std::setprecision( 0 ) << std::nouppercase
        << setiosflags(std::ios::showbase) << std::setw( 0 )
        << static_cast< long long >(A)
        << "\n";

    std::cout << std::fixed << std::right << std::showpos
        << std::setprecision( 2 ) << std::setw( 15 ) << std::setfill( '_' )
        <<  B
        << "\n";

    std::cout << std::noshowpos << std::scientific
        << std::setprecision( 9 ) << std::uppercase
        << C
        << std::endl;
  }
  return 0;
}
