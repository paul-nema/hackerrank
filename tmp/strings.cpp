#include <iostream>
#include <string>
using namespace std;

int main() {
  // Complete the program
    std::string strA;
    std::string strB;

    std::getline( std::cin, strA );
    std::getline( std::cin, strB );

    std::cout << strA.size() << " " << strB.size() << "\n";
    std::cout << strA + strB << "\n";

    std::swap( strA[ 0 ], strB[ 0 ] );
    std::cout << strA << " " << strB << std::endl;

  return 0;
}
